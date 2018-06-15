#include "QueryParser.h"

#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <string>

#include "antlr4-runtime.h"
#include <boost/algorithm/string.hpp>

#include "constants/Constants.h"
#include "grammar/SqlParser.h"
#include "grammar/SqlLexer.h"
#include "grammar/SqlVisitor.h"
#include "grammar/SqlBaseVisitor.h"
#include "tree/ParseTreeWalker.h"
#include "query/SelectNode.h"

#include "exception/TableNotInQueryException.h"
#include "exception/NoParamsException.h"
#include "exception/NoSuchEntryException.h"
#include "exception/InvalidQueryException.h"
#include "parser/ThrowingErrorListener.h"
#include "grammar/NewVisitor.h"
#include "grammar/LogicalQueryNode.h"
#include "metadata/DBCatalog.h"

using namespace std;
using namespace antlr4;

const boost::optional<string> tableNameForPossibleAlias(const string &possibleAlias, const vector<DataSource> &tbls)
{
    for (const auto &t : tbls)
    {
        if (t.alias == possibleAlias || t.name == possibleAlias)
            return t.name;
    }
    return boost::optional<string>{};
}

const boost::optional<string> colNameForPossibleAlias(const string &possibleAlias, const vector<ResultColumn> &columns)
{
    for (const auto &t : columns)
    {
        if (t.columnAlias == possibleAlias || t.columnName == possibleAlias)
            return t.columnName;
    }
    return boost::optional<string>{};
}

void validateLogicalQuery(const LogicalQueryNode &queryNode)
{
    //do post order validation
    for (const auto &child : queryNode.children)
    {
        validateLogicalQuery(child);
    }
    //now validate self
    //get catalog
    const auto &dbCatalog = catalog::DBCatalog::instance();
    //check tables
    for (const auto &source : queryNode.datasources)
    {
        if (!dbCatalog->hasTable(source.name))
            throw NoSuchEntryException(source.name);
    }
    //check result columns
    for (const auto &rCol : queryNode.resultColumns)
    {
        auto tbl = rCol.tableName;
        if (!tbl.empty())
        {
            //this could be an alias, get the table name
            auto tblNameOpt = tableNameForPossibleAlias(tbl, queryNode.datasources);
            if (!tblNameOpt)
                throw NoSuchEntryException(tbl);
            tbl = tblNameOpt.get();
            const auto opt = dbCatalog->getColumnSpecForTable(rCol.columnName, tbl);
            if (!opt)
                throw NoSuchEntryException(tbl + "." + rCol.columnName, true);
        }
    }
    //check where columns
    for (const auto &wc : queryNode.whereConditionsAnd)
    {
        auto tbl = wc.getTableName();
        auto col = wc.getColumnName();
        auto colOpt = colNameForPossibleAlias(col, queryNode.resultColumns);
        if (!colOpt)
            throw NoSuchEntryException(col, true);
        if (!tbl.empty())
        {
            auto tblNameOpt = tableNameForPossibleAlias(tbl, queryNode.datasources);
            if (!tblNameOpt)
                throw NoSuchEntryException(tbl);
            tbl = tblNameOpt.get();
            //the columnname in where condition can be an alias for column

            if (!tbl.empty() && dbCatalog->hasTable(tbl))
            { //we now know both column and table names for where condition,
                // ensure that they exist
                col = colOpt.get();
                const auto opt = dbCatalog->getColumnSpecForTable(col, tbl);
                if (!opt)
                    throw NoSuchEntryException(tbl + "." + wc.getColumnName(), true);
            }
        }
    }

    //check group by columns
    for (const auto &gbCol : queryNode.groupByColumns)
    {
        auto tbl = gbCol.tableName;
        auto col = gbCol.columnName;
        if (!tbl.empty())
        {
            auto tblNameOpt = tableNameForPossibleAlias(tbl, queryNode.datasources);
            if (!tblNameOpt) //table name was given but no such table exists
                throw NoSuchEntryException(tbl);
            tbl = tblNameOpt.get();
            //checl for col spec
            auto colOpt = colNameForPossibleAlias(col, queryNode.resultColumns);
            if (colOpt)
                col = colOpt.get();
            
            auto specOpt = dbCatalog->getColumnSpecForTable(col, tbl);
            if(!specOpt){
                throw NoSuchEntryException(tbl+"."+col, true);
            }
        }
    }
}

const shared_ptr<LogicalQueryNode> parser::QueryParser::parseQuery()
{
    //boilerplate for parsing start
    string query(qString);
    ANTLRInputStream input(query);
    SqlLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    SqlParser parser(&tokens);
    //add listeners
    ThrowingErrorListener errorListner;
    parser.addErrorListener(&errorListner);
    // ExtendedListener listener;
    // SqlBaseListener &sqlListener = listener;
    // parser.addParseListener(&sqlListener);

    //parse the sql statement
    SqlParser::ParseContext *context = parser.parse();
    NewVisitor visitor;
    try
    {
        visitor.visit(context);
        //walk AST and collect items of interest
        //tree::ParseTreeWalker::DEFAULT.walk(&sqlListener, context);
       // const auto node = visitor.getQueryNode();
        //do primary validation 
        //validateLogicalQuery(*node);
        //return make_shared<LogicalQueryNode>();
        return visitor.getQueryNode();
    }
    catch (InvalidQueryException aex)
    {
        throw aex;
    }
    
    //return visitor.getSelectNode();
        //   for (const auto &child : node.children)
        // {
        //     std::cout << child.str();
        // }
        // std::cout << node.str();
        // std::cout << endl;
    //walk AST and collect items of interest
    // tree::ParseTreeWalker::DEFAULT.walk(&sqlListener, context);
    // auto nodes = listener.getQueryNodes();
    // for(auto n : nodes){
    //     n.print();
    // }
    //auto tableNames = listener.getTableNames();
}
