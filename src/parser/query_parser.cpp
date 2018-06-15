#include "query_parser.h"

#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <string>

#include "antlr4-runtime.h"
#include <boost/algorithm/string.hpp>

#include "../constants/Constants.h"
#include "grammar/SqlParser.h"
#include "grammar/SqlLexer.h"
#include "grammar/SqlVisitor.h"
#include "grammar/SqlBaseVisitor.h"
#include "grammar/SqlBaseListener.h"
#include "grammar/ListenerExtension.h"
#include "tree/ParseTreeWalker.h"

#include "exception/TableNotInQueryException.h"
#include "exception/NoParamsException.h"
#include "exception/NoSuchEntryException.h"
#include "metadata/collect.h"
#include "util/collections.h"

using namespace std;
using namespace antlr4;

namespace sqlparser
{
void insertColForTable(std::unordered_map<std::string, std::set<std::string>> &tblColSetMap, const std::string &tblname, const std::string &colname)
{
    auto colSet = tblColSetMap.find(tblname);
    if (colSet == tblColSetMap.end())
    {
        //do not have any tables mapped to the column
        std::set<std::string> tblCols = {colname};
        tblColSetMap[tblname] = tblCols;
    }
    else
    {
        colSet->second.insert(colname);
    }
}

template <typename T>
void insertColEntryForTable(std::unordered_map<std::string, std::set<T>> &tblColSetMap, const std::string &tblname, const T &col)
{
    auto colSet = tblColSetMap.find(tblname);
    if (colSet == tblColSetMap.end())
    {
        //do not have any tables mapped to the column
        std::set<T> tblCols = {col};
        tblColSetMap[tblname] = tblCols;
    }
    else
    {
        colSet->second.insert(col);
    }
}

template <typename T>
void insertTableEntryInMapSet(std::map<std::string, std::set<T>> &tblSetMap, const std::string &tblname, const T &info)
{
    auto colSet = tblSetMap.find(tblname);
    if (colSet == tblSetMap.end())
    {
        //do not have any tables mapped to the column
        std::set<T> tblCols = {info};
        tblSetMap[tblname] = tblCols;
    }
    else
    {
        colSet->second.insert(info);
    }
}

void handleStarColumn(const std::set<std::string> &tablesInQuery)
{
    //do nothing for now
    //TODO: implement after checking assumptions with John
}

void fixWhereClause(ConditionColumn &clause, const std::set<std::string> &tablesInQuery, const std::unordered_map<std::string, model::DBTableInfo> &tableCatalog)
{
    std::string tblname = "", standaloneColName = "";
    int colIndex = -1;
    data_types::DATA_TYPE colDataType = data_types::INT;
    //check if column is not qualified with <tablename>.

    auto qualColname = clause.getColumnName();
    auto dotPos = qualColname.find(".");
    if (dotPos == std::string::npos)
    { //no dot based qualified name used
        //try to assign the column to a table given in query
        for (auto tbl : tablesInQuery)
        {
            auto tblModel = tableCatalog.find(tbl)->second.getModel(); // guaranteed to hit a valid result if we are here, o/w the exception must have been thrown above
            auto dtype = tblModel.getColumnType(qualColname);
            if (dtype)
            {
                tblname = tbl;
                colIndex = tblModel.getColumnPos(qualColname).get();
                colDataType = dtype.get();
                break;
            }
        }
        if (tblname.empty())
            throw NoSuchEntryException(qualColname, true /*is column */); //no table has column name in its model catalog
        standaloneColName = qualColname;
    }
    else
    {
        //the column is qualified with a table name
        tblname = qualColname.substr(0, dotPos);
        if (tablesInQuery.find(tblname) == tablesInQuery.end())
            throw InvalidQueryException("Invalid tablename: " + tblname); //tablename not present in tables requested

        standaloneColName = qualColname.substr(dotPos + 1);
        auto tblModel = tableCatalog.find(tblname)->second.getModel();
        auto dtype = tblModel.getColumnType(standaloneColName);
        if (!dtype)
            throw NoSuchEntryException(standaloneColName, true /*is column */);
        colIndex = tblModel.getColumnPos(standaloneColName).get();
        colDataType = dtype.get();
    }
    //set correct values:
    clause.setColumnName(standaloneColName);
    clause.setIndexInTable(colIndex);
    clause.setTableName(tblname);
    clause.setColDataType(colDataType);
    //return ColumnInTable(tblname, standaloneColName, colIndex, colDataType);
}

ColumnInTable getColumnInTable(const std::string &qualColname, const std::set<std::string> &tablesInQuery, const std::unordered_map<std::string, model::DBTableInfo> &tableCatalog)
{
    std::string tblname = "", standaloneColName = "";
    int colIndex = -1;
    data_types::DATA_TYPE colDataType = data_types::INT;
    //check if column is not qualified with <tablename>.
    auto dotPos = qualColname.find(".");
    if (dotPos == std::string::npos)
    { //no dot based qualified name used
        //try to assign the column to a table given in query
        for (auto tbl : tablesInQuery)
        {
            auto tblModel = tableCatalog.find(tbl)->second.getModel(); // guaranteed to hit a valid result if we are here, o/w the exception must have been thrown above
            auto dtype = tblModel.getColumnType(qualColname);
            if (dtype)
            {
                tblname = tbl;
                colIndex = tblModel.getColumnPos(qualColname).get();
                colDataType = dtype.get();
                break;
            }
        }
        if (tblname.empty())
            throw NoSuchEntryException(qualColname, true /*is column */); //no table has column name in its model catalog
        standaloneColName = qualColname;
    }
    else
    {
        //the column is qualified with a table name
        tblname = qualColname.substr(0, dotPos);
        if (tablesInQuery.find(tblname) == tablesInQuery.end())
            throw InvalidQueryException("Invalid tablename: " + tblname); //tablename not present in tables requested

        standaloneColName = qualColname.substr(dotPos + 1);
        auto tblModel = tableCatalog.find(tblname)->second.getModel();
        auto dtype = tblModel.getColumnType(standaloneColName);
        if (!dtype)
            throw NoSuchEntryException(standaloneColName, true /*is column */);
        colIndex = tblModel.getColumnPos(standaloneColName).get();
        colDataType = dtype.get();
    }
    return ColumnInTable(tblname, standaloneColName, colIndex, colDataType);
}

void checkTables(const std::set<std::string> &tablesInQuery)
{
    auto tableCatalog = dbinfo::getTableCatalog();
    for (auto tableName : tablesInQuery)
    {
        if (!util::Collections::map_has_key(tableCatalog, tableName)) //no such table in our catalog
            throw NoSuchEntryException(tableName);
    }
}
vector<ColumnInTable> planColumnsToFetch(std::vector<std::string> &qualColumns, const std::set<std::string> &tablesInQuery, bool forGroupBy = false)
{
    using namespace std;
    //base checks
    size_t colCount = qualColumns.size();
    size_t tableCount = tablesInQuery.size();

    if (colCount == 0 || tableCount == 0)
        throw NoParamsException(colCount == 0);
    //convert column and table names to upper cases

    for (auto name : qualColumns)
    {
        boost::to_lower(name);
    }
    for (auto name : tablesInQuery)
    {
        boost::to_lower(name);
    }

    auto tableCatalog = dbinfo::getTableCatalog();
    //for now we will just assume that when multiple tablesInQuery
    // are involved, then each column will be prefixed with a <tablename>.
    // thus, lets go over the columns, and collect the table names from them
    vector<ColumnInTable> columnsToFetch;
    for (auto qualColname : qualColumns)
    {
        if (qualColname == "_all")
        { //handle star denoted by _all
            //add all columns of the first table -- default behavior
            // and then continue
            auto firstTableName = *(tablesInQuery.begin());
            auto allColsOfFirstTable = tableCatalog.find(firstTableName)->second.getModel().getColumnFullInfo();
            for (auto ac : allColsOfFirstTable)
            {
                columnsToFetch.push_back(ac);
            }
            continue;
        }
        auto colFetch = getColumnInTable(qualColname, tablesInQuery, tableCatalog);
        columnsToFetch.push_back(colFetch);
    }
    return columnsToFetch;
}

boost::optional<SelectQuery> parseQuery(const std::string &query)
{
    //boilerplate for parsing start
    ANTLRInputStream input(query);
    SqlLexer lexer(&input);
    CommonTokenStream tokens(&lexer);
    SqlParser parser(&tokens);
    //add listeners
    BaseErrorListener errorListner;
    parser.addErrorListener(&errorListner);
    ListenerExtension listener;
    SqlBaseListener &sqlListener = listener;
    parser.addParseListener(&sqlListener);

    //parse the sql statement
    SqlParser::ParseContext *context = parser.parse();
    //walk AST and collect items of interest
    tree::ParseTreeWalker::DEFAULT.walk(&sqlListener, context);

    auto tableNames = listener.getTableNames();
    checkTables(tableNames);
    //handle describe queries:
    if (listener.isDescribeQuery())
    {
        dbinfo::describeTables(tableNames);
        return boost::optional<SelectQuery>{};
    }
    //not a describe query, must be select
    auto cols = listener.getColsToFetch();
    auto colsToFetch = planColumnsToFetch(cols, tableNames);
    //finally add conditions if any
    auto conditions = listener.getWhereClauses();
    set<ConditionColumn> fixedConditions;
    for (auto clause : conditions)
    {
        ConditionColumn cond = clause;
        fixWhereClause(cond, tableNames, dbinfo::getTableCatalog());
        fixedConditions.insert(cond);
    }
    //now get correctly marked columns for groupbys
    auto groupBys = listener.getGroupBys();
    vector<ColumnInTable> groupByCols;
    if (!groupBys.empty())
    {
        groupByCols = planColumnsToFetch(groupBys, tableNames);
        // add these cols to columns to fetch
        for (auto &gc : groupByCols)
        {
            if (std::find(colsToFetch.begin(), colsToFetch.end(), gc) == colsToFetch.end())
            {
                gc.donotPrint(); //mark for not printing
                colsToFetch.push_back(gc);
            }
        }
    }
    auto aggFunctions = listener.getAggFunctions();
    bool hasAggregation = !aggFunctions.empty();
    if (hasAggregation) //if aggregations are required
    {
        for (size_t index = 0; index < colsToFetch.size(); index++)
        {
            if (aggFunctions[index] != constants::NO_FUN)
            { //indicate aggregation
                //std::cout << "applying aggregation code " << aggFunctions[index] << std::endl;
                colsToFetch[index].setAggregationCode(aggFunctions[index]);
            }
        }
    }
    return SelectQuery(tableNames, colsToFetch, fixedConditions, groupByCols, hasAggregation);
}
} // namespace sqlparser