#pragma once

#include <memory>
#include <stack>

#include "grammar/SqlBaseListener.h"
#include "grammar/LogicalQueryNode.h"

#include "log/Log.h"

using namespace std;
class ExtendedListener : public SqlBaseListener
{
  private:
    string spacing;
    size_t selectCount = 0;
    LogicalQueryNode queryNod;
    shared_ptr<LogicalQueryNode> root;
    stack<shared_ptr<LogicalQueryNode>> nodeStack;
    stack<string> tblAliasStack;

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

  public:
    shared_ptr<LogicalQueryNode> currentNode()
    {
        return nodeStack.top();
    }
    const LogicalQueryNode &getQueryNode()
    {
        return *root;
    }

    virtual void enterResult_column(SqlParser::Result_columnContext *ctx) override
    {
        debug("entering result column");
        this->currentNode()->inResultCol = true;
        ResultColumn rcol;
        this->currentNode()->resultColumns.push_back(rcol);
    }

    virtual void exitResult_column(SqlParser::Result_columnContext * /*ctx*/) override
    {
        debug("exiting result column");
        this->currentNode()->inResultCol = false;
    }
    virtual void enterSelect_core(SqlParser::Select_coreContext *ctx) override
    {
        debug("entering select core");
        auto ptr = make_shared<LogicalQueryNode>();
        if (!root)
        {
            root = ptr;
        }
        nodeStack.push(ptr);
    }
    virtual void enterColumn_alias(SqlParser::Column_aliasContext *ctx) override
    {
        if (currentNode()->inResultCol)
        {
            size_t rColsCount = this->currentNode()->resultColumns.size();
            assert(rColsCount);
            ResultColumn &rcol = this->currentNode()->resultColumns[rColsCount - 1];
            rcol.columnAlias = ctx->getText();
        }
    }
    virtual void exitColumn_alias(SqlParser::Column_aliasContext * /*ctx*/) override {}

    virtual void enterTable_or_subquery(SqlParser::Table_or_subqueryContext *ctx) override
    {
        if (ctx->select_core())
        { // subquery
            this->currentNode()->inSubQuery = true;
        }
        else if (ctx->table_name())
        {
            this->currentNode()->inTableName = true;
        }
    }
    virtual void exitTable_or_subquery(SqlParser::Table_or_subqueryContext *ctx) override
    {
        if (ctx->select_core())
        { // subquery
            this->currentNode()->inSubQuery = false;
        }
        else if (ctx->table_name())
        {
            this->currentNode()->inTableName = false;
        }
    }

    virtual void enterTable_name(SqlParser::Table_nameContext *ctx) override
    {
        if (this->currentNode()->inResultCol)
        {
            debug("in resultcol tablname ");
            size_t rColsCount = this->currentNode()->resultColumns.size();
            assert(rColsCount);
            ResultColumn &rcol = this->currentNode()->resultColumns[rColsCount - 1];
            rcol.tableName = ctx->getText();
            return;
        }
        if (this->currentNode()->inTableName)
        {
            debug("in tbl or sub, pushing tbl object");
            TableInQuery tbl(ctx->getText());
            this->currentNode()->datasources.push_back(tbl);
        }
    }

    virtual void exitTable_name(SqlParser::Table_nameContext *ctx) override
    {
    }

    virtual void enterTable_alias(SqlParser::Table_aliasContext *ctx) override
    {
        debug("in enter table alias");
        if (this->currentNode()->inTableName)
        {
            size_t tblsCount = this->currentNode()->datasources.size();
            assert(tblsCount);
            this->currentNode()->datasources.at(tblsCount - 1).alias = ctx->getText();
            return;
        }
        if (this->currentNode()->inSubQuery)
        {
        }
    }

    virtual void enterColumn_name(SqlParser::Column_nameContext *ctx) override
    {
        if (this->currentNode()->inResultCol)
        {
            size_t rColsCount = this->currentNode()->resultColumns.size();
            assert(rColsCount);
            ResultColumn &rcol = this->currentNode()->resultColumns[rColsCount - 1];
            rcol.columnName = ctx->getText();
        }
    }
    virtual void exitColumn_name(SqlParser::Column_nameContext * /*ctx*/) override {}

    virtual void exitSelect_core(SqlParser::Select_coreContext * /*ctx*/) override
    {
        debug("exiting select_core");
        addCurrentSelectCoreAsChild();
    }
};