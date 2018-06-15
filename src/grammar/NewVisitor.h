#pragma once

#include <memory>
#include <stack>

#include "grammar/SqlBaseVisitor.h"
#include "grammar/LogicalQueryNode.h"
#include "grammar/LogicalBinaryNode.h"
#include "constants/Constants.h"
#include "util/Collections.h"
#include "util/StringUtil.h"
#include <set>

#include "log/Log.h"

using namespace std;
class NewVisitor : public SqlBaseVisitor
{
private:
    string spacing;
    //size_t selectCount = 0;
    LogicalQueryNode queryNod;
    shared_ptr<LogicalQueryNode> root;
    stack<shared_ptr<LogicalQueryNode>> nodeStack;
    stack<string> tblAliasStack;
    stack<string> colMathExpressions;
    size_t nodeCount = 0;
    std::set<string> SUPPORTED_AGG_FUNCTIONS{"avg", "sum", "count", "countd"};
    std::set<string> ignoreAliases{"inner", "outer"};
    
    void addCurrentSelectCoreAsChild()
    {
        if (nodeStack.empty())
            return;
        if (nodeStack.size() == 1)
        {
            // in the top most select core
            // just pop the node and return
            nodeStack.pop();
            return;
        }
        //nodeStack size must be 2 or more now
        //current selectCore which we are about to exit
        auto curr = nodeStack.top();
        nodeStack.pop();
        if (!tblAliasStack.empty())
        {
            auto alias = tblAliasStack.top();
            curr->name = alias;
            tblAliasStack.pop();
        }
        //make this the child of the new node at the top
        // of the stack
        auto parent = nodeStack.top();
        parent->addChild(*curr);
    }
    
    std::pair<string, string> tableAndColumnFromFunctionArg(std::string fstr)
    {
        std::vector<std::string> splits;
        boost::erase_last(fstr, ")");
        boost::algorithm::split(splits, fstr,
                                boost::is_any_of("("));
        
        return util::StringUtil::extractTableColumnNames(splits[1]);
    }
    
public:
    shared_ptr<LogicalQueryNode> currentNode()
    {
        return nodeStack.top();
    }
    const shared_ptr<LogicalQueryNode> getQueryNode()
    {
        return root;
    }
    
    virtual antlrcpp::Any visitResult_column(SqlParser::Result_columnContext *ctx) override
    {
        this->currentNode()->inResultCol = true;
        debug("visiting result column: "+ctx->getText());
        ResultColumn rcol;
         auto exprPtr = ctx->expr();
        if(ctx->getText() == "*"){
            rcol.columnName = "*";
        }
        if(exprPtr && exprPtr->oper){
            this->currentNode()->inColMathExpr = true;
            colMathExpressions.push(exprPtr->getText());
            //std::cout << "got math oper in result col: " << exprPtr->getText() << std::endl;
        }
        auto res = visitChildren(ctx);
        if(this->currentNode()->inColMathExpr){
            this->currentNode()->inColMathExpr = false;
        }
        
        if(exprPtr && ! exprPtr->oper){
            //debug(exprPtr->getText());
            if(exprPtr->table_name()){
                rcol.tableName = exprPtr->table_name()->getText();
            }
            if(exprPtr->column_name()){
                rcol.columnName = exprPtr->column_name()->getText();
            }
            if(exprPtr->function_name()){
                auto fnamePtr = exprPtr->function_name();
                FunctionOnColumn fc;
                fc.fullFunctionString = ctx->getText();
                auto tcPair = tableAndColumnFromFunctionArg(fc.fullFunctionString);
                if(tcPair.first.size()){
                    rcol.tableName = tcPair.first;
                }
                rcol.columnName = tcPair.second;
                fc.functionName = fnamePtr->getText();
                if (!util::Collections::containerHasValue(SUPPORTED_AGG_FUNCTIONS, fc.functionName))
                {
                    throw InvalidQueryException(fc.functionName + ": function not supported.");
                }
                this->currentNode()->functionsOnColumns.push_back(fc);
            }
        }
        if(rcol.columnName.size()){
            this->currentNode()->resultColumns.push_back(rcol);
        }
        debug("exiting result column");
        this->currentNode()->inResultCol = false;
        return res;
    }
    
    virtual antlrcpp::Any visitSelect_core(SqlParser::Select_coreContext *ctx) override
    {
        debug("visiting select core");
        auto ptr = make_shared<LogicalQueryNode>();
        if (!root)
        {
            root = ptr;
        }
        nodeStack.push(ptr);
        auto res = visitChildren(ctx);
        debug("exiting select_core");
        addCurrentSelectCoreAsChild();
        return res;
    }
    virtual antlrcpp::Any visitColumn_alias(SqlParser::Column_aliasContext *ctx) override
    {
        if (currentNode()->inResultCol)
        {
            size_t rColsCount = this->currentNode()->resultColumns.size();
            assert(rColsCount);
            ResultColumn &rcol = this->currentNode()->resultColumns[rColsCount - 1];
            rcol.columnAlias = ctx->getText();
        }
        return visitChildren(ctx);
    }
    
    virtual antlrcpp::Any visitTable_or_subquery(SqlParser::Table_or_subqueryContext *ctx) override
    {
        auto tname = ctx->table_name();
        auto talias = ctx->table_alias();
        auto childSelCore = ctx->select_core();
        auto node = this->currentNode();
        if(tname){
            auto tblName = tname->getText();
            //debug("in tbl or sub, pushing tbl object");
            TableInQuery tbl(tblName);
            if (talias)
            {
                tbl.alias = talias->getText();
            }
            node->datasources.push_back(tbl);
            if(node->inJoinClause && !node->inJoinConstraint){
                //debug("in tbl or sub, pushing tbl object");
                //node->datasources.push_back(tbl);
                node->joinTables.push_back(tbl);
                if(node->nextTableIsRightTable){
                    JoinCondition &clause = node->joins.back();
                    clause.rightTableName = tblName;
                    node->nextTableIsRightTable = false;
                }
            }
        }
        
        if (childSelCore)
        { //its a subquery
            this->currentNode()->inSubQuery = true;
            if (talias)
            {
                tblAliasStack.push(talias->getText());
            }
            else
            {
                //generate a name and set it
                ++nodeCount;
                auto name = "node_" + to_string(nodeCount);
                tblAliasStack.push(name);
            }
        }
        
        else if (!this->currentNode()->inJoinClause && tname)
        {
            this->currentNode()->inFromTable = true;
        }
        auto res = visitChildren(ctx);
        if (childSelCore)
        { // subquery
            this->currentNode()->inSubQuery = false;
        }
        else if (tname)
        {
            this->currentNode()->inFromTable = false;
        }
        return res;
    }
    
    virtual antlrcpp::Any visitTable_name(SqlParser::Table_nameContext *ctx) override
    {
        //        if(node->inJoinConstraint) {
        //            //find the table in query that matches this table name
        //            // that would the left table
        //            bool rightTable = true;
        //            for(const auto & t : node->datasources){
        //                if(t.name == tblName || t.alias == tblName){
        //                    debug("adding join left tablename "+tblName);
        //
        //                    rightTable = false;
        //                    break;
        //                }
        //            }
        //            //this->currentNode()->joinColumns.back().tableName = tblName;
        //            if(rightTable){
        //                debug("adding join right tablename "+tblName);
        //                joinClause.rightTableName = tblName;
        //            }
        
        auto tblName = ctx->getText();
        if(this->currentNode()->inGroupBy){
            debug("adding groupby table");
            this->currentNode()->groupByColumns.back().tableName = tblName;
        }
        
        return visitChildren(ctx);
    }
    
    virtual antlrcpp::Any visitTable_alias(SqlParser::Table_aliasContext *ctx) override
    {
        //debug("in visit table alias");
        auto res = visitChildren(ctx);
        auto alias = ctx->getText();
        if (this->currentNode()->inFromTable && ! util::Collections::containerHasValue(ignoreAliases, alias))
        {
            size_t tblsCount = this->currentNode()->datasources.size();
            assert(tblsCount);
            this->currentNode()->datasources.back().alias = alias;
        }
        return res;
    }
    
    virtual antlrcpp::Any visitWhere_clause(SqlParser::Where_clauseContext *ctx) override
    {
        this->currentNode()->inWhere = true;
        //auto exprPtr = ctx->expr();
        auto res = visitChildren(ctx);
//        if(exprPtr){
//            debug(exprPtr->getText());
//            WhereClause where;
//            where.setOp(exprPtr->oper->getText());
//            if(exprPtr->left->column_name())
//                where.setColumnName(exprPtr->left->column_name()->getText());
//            if(exprPtr->left->table_name())
//                where.setTableName(exprPtr->left->table_name()->getText());
//            where.setValue(exprPtr->right->literal_value()->getText());
//            this->currentNode()->whereConditionsAnd.push_back(where);
//        }
        this->currentNode()->inWhere = false;
        return res;
    }
    
    
    
    
    virtual antlrcpp::Any visitGroup_by_clause(SqlParser::Group_by_clauseContext *ctx) override
    {
        this->currentNode()->inGroupBy = true;
        auto res = visitChildren(ctx);
        this->currentNode()->inGroupBy = false;
        return res;
    }
    
    virtual antlrcpp::Any visitExpr(SqlParser::ExprContext *ctx) override
    {
        auto node = this->currentNode();
        if (node->inGroupBy)
        {
            debug("in groupby expr ");
            GroupByColumn gbc;
            auto tbl = ctx->table_name();
            if (tbl)
            {
                gbc.tableName = tbl->getText();
            }
            assert(ctx->column_name());
            gbc.columnName = ctx->column_name()->getText();
            debug("set groupby colname "+gbc.columnName);
            this->currentNode()->groupByColumns.push_back(gbc);
        }
        else if(node->inWhere){
            auto exprPtr = ctx->expr();
            debug("where " +ctx->getText());
            if(ctx->oper){
                WhereClause where;
                where.setOp(ctx->oper->getText());
                if(ctx->left->column_name())
                    where.setColumnName(ctx->left->column_name()->getText());
                if(ctx->left->table_name())
                    where.setTableName(ctx->left->table_name()->getText());
                where.setValue(ctx->right->literal_value()->getText());
                this->currentNode()->whereConditionsAnd.push_back(where);
            }
        } else if (node->inColMathExpr && ctx->column_name()){
            ResultColumn rcol;
            rcol.columnName = ctx->column_name()->getText();
            rcol.mathOperation = colMathExpressions.top();
            colMathExpressions.pop();
            node->resultColumns.push_back(rcol);
        }
        return visitChildren(ctx);
    }
    
    virtual antlrcpp::Any visitJoin_clause(SqlParser::Join_clauseContext *ctx) override
    {
        this->currentNode()->inJoinClause = true;
        auto fulltext = ctx->getText();
        //debug("join clause: "+ctx->getText());
        auto res = visitChildren(ctx);
        this->currentNode()->inJoinClause = false;
        return res;
    }
    
    virtual antlrcpp::Any visitJoin_operator(SqlParser::Join_operatorContext *ctx) override
    {
        auto node = this->currentNode();
        node->inJoinOperator = true;
        JoinCondition join;
        auto fulltext = ctx->getText();
        join.isLeftOuter = fulltext == "leftouterjoin";
        join.isRightOuter = fulltext == "rightouterjoin";
        //        if(leftouter) {
        //            join.joinOp = "left_outer";
        //            join.isLeftOuter = true;
        //        }else if(rightouter){
        //            join.joinOp = "right_outer";
        //            join.isRightOuter = true;
        //        }
        node->joins.push_back(join);
        node->nextTableIsRightTable = true;
        auto res = visitChildren(ctx);
        node->inJoinOperator = false;
        return res;
    }
    
    virtual antlrcpp::Any visitJoin_constraint(SqlParser::Join_constraintContext *ctx) override
    {
        auto node = this->currentNode();
        //auto fulltext = ctx->getText();
        //this->currentNode()->joins.push_back(JoinClause());
        //ctx->
        node->inJoinConstraint = true;
        //        auto constraintExpr = ctx->expr();
        //        if(constraintExpr){
        //            this->currentNode()->joins.back().condition = constraintExpr->getText();
        //debug("join constraint: "+constraintExpr->getText());
        //        }
        auto res = visitChildren(ctx);
        auto joinExpr = ctx->expr();
        if(joinExpr){
            auto exprText = joinExpr->getText();
            auto leftPtr = joinExpr->left;
            auto rightPtr = joinExpr->right;
            JoinCondition &clause = node->joins.back();
            if(leftPtr){
                auto leftExprTablName = leftPtr->table_name()->getText();
                auto leftExprColName = leftPtr->column_name()->getText();
                if (leftExprTablName == clause.rightTableName){
                    clause.rightColumnName = leftExprColName;
                } else if (clause.leftTableName.empty()){
                    clause.leftTableName = leftExprTablName;
                    clause.leftColumnName = leftExprColName;
                }
            }
            if(rightPtr){
                auto rightExprTablName = rightPtr->table_name()->getText();
                auto rightExprColName = rightPtr->column_name()->getText();
                if(rightExprTablName == clause.rightTableName){
                    clause.rightColumnName = rightExprColName;
                } else if (clause.leftTableName.empty()){
                    clause.leftTableName = rightExprTablName;
                    clause.leftColumnName = rightExprColName;
                }
            }
        }
        this->currentNode()->inJoinConstraint = false;
        return res;
    }
};
