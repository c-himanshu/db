
#include "query/SelectNode.h"

#include "model/ResultSet.h"
#include "util/Collections.h"
#include "query/FetchSpec.h"
#include <boost/optional/optional.hpp>
#include <map>
#include "model/RelationSet.h"
#include "metadata/DBCatalog.h"

#include "log/Log.h"

#include "fileops/CSVReader.h"

using namespace query;
using namespace std;
void addColumnToMatchingTableSpecWithName(std::vector<FetchSpec> &specs,
                                          const model::ColumnSpec &colSpec,
                                          const std::string tname,
                                          std::string tAlias = constants::NO_TBL_ALIAS_GIVEN)
{
    if (tAlias == constants::NO_TBL_ALIAS_GIVEN)
    {
        tAlias = tname;
    }
    for (auto &tfc : specs)
    {
        if (tfc.getTableAlias() == tAlias)
        {
            tfc.addColumnToFetch(colSpec.getColumnName(), colSpec.getColumnPosition(), colSpec.getColType());
            return;
        }
    }
    //didn't find the table spec with that name,
    //create a new one and add
    FetchSpec fspec(tname, colSpec.getColumnName(), colSpec.getColumnPosition(), colSpec.getColType(), tAlias);
    specs.push_back(fspec);
}

std::pair<string, string> extractTableColumnNames(string qualColName)
{
    string emptyTbl("");
    auto dotPos = qualColName.find(".");
    if (dotPos == std::string::npos)
        return make_pair(emptyTbl, qualColName);

    return make_pair(qualColName.substr(0, dotPos), qualColName.substr(dotPos + 1));
}

void addWhereToMatchingTableSpecWithName(std::vector<FetchSpec> &specs,
                                         const model::ColumnSpec &colSpec,
                                         const WhereClause &where,
                                         const std::string tname,
                                         std::string tAlias = constants::NO_TBL_ALIAS_GIVEN)
{
    if (tAlias == constants::NO_TBL_ALIAS_GIVEN)
    {
        tAlias = tname;
    }
    debug("in addWhere talias "+tAlias);
    for (auto &tfc : specs)
    {
        debug("in addWhere comparing talias "+tAlias+" with "+tfc.getTableAlias());
        if (tfc.getTableAlias() == tAlias)
        {
            //tfc.addColumnToFetch(colSpec.getColumnName(), colSpec.getColumnPosition(), colSpec.getColType());
            tfc.addToWheres(colSpec.getColumnPosition(), where.getValue(), where.getOp(), colSpec.getColType());
            return;
        }
    }
    //didn't find the table spec with that name,
    //throw
    throw InvalidQueryException("No matching table found for " + tAlias);
}

boost::optional<model::ColumnSpec> columnSpecForTable(const string &colname, const string &tname, const catalog::TableCatalog &tableCatalog)
{
    auto colSpecOpt = tableCatalog.getColumnSpecForTable(colname, tname);
    if (colSpecOpt)
        return colSpecOpt;
    //now try global db catalog
    return catalog::DBCatalog::instance()->getColumnSpecForTable(colname, tname);
}

vector<model::ColumnSpec> fullTableSpec(const string &tname, const catalog::TableCatalog &tableCatalog)
{
    auto colSpecsOpt = tableCatalog.getFullSpecForTable(tname);
    if (colSpecsOpt)
        return colSpecsOpt.get();
    //now try global db catalog
    auto specOptGlobal = catalog::DBCatalog::instance()->getFullSpecForTable(tname);
    if (specOptGlobal)
        return specOptGlobal.get();

    //found in neither catalogs, throw
    throw NoSuchEntryException(tname);
}

std::vector<FetchSpec> planAllColumnFetch(const std::vector<std::string> &qualColnames, const std::vector<std::string> &tablesInQuery,
                                          const catalog::TableCatalog &tableCatalog,
                                          const map<string, string> &tblAliases)
{
    if (qualColnames.size() > 1)
    {
        //ambiguos fetch, throw
        throw InvalidQueryException("Column list is ambiguous.");
    }
    if (tablesInQuery.empty())
        throw InvalidQueryException("No tables given.");
    //being here means one * column, possibly many tables
    //return (tablesInQuery, dbCatalog, tblAliases);
    std::vector<FetchSpec> fetches;
    std::vector<string> starTables;
    for (auto qname : qualColnames)
    {
        auto pos = qname.find(".*");
        if (pos != string::npos)
        {
            auto tblnameOrAlias = qname.substr(0, pos);
            starTables.push_back(tblnameOrAlias);
        }
    }
    for (auto st : starTables)
    {
        auto aliasIter = tblAliases.find(st);
        auto tname = (aliasIter == tblAliases.end()) ? st : aliasIter->second;
        if (std::find(tablesInQuery.begin(), tablesInQuery.end(), tname) == tablesInQuery.end())
            throw InvalidQueryException("No table for " + st);
    }
    for (auto tbl : tablesInQuery)
    {
        //auto tblModel = tableCatalog.find(tbl)->second.getModel(); // guaranteed to hit a valid result if we are here, o/w the exception must have been thrown above
        auto colSpecs = fullTableSpec(tbl, tableCatalog);
        auto aliasIter = tblAliases.find(tbl);
        auto tAlias = (aliasIter == tblAliases.end()) ? tbl : aliasIter->first;
        assert(colSpecs.size());
        auto cspec = colSpecs[0];
        FetchSpec fetch(tbl, cspec.getColumnName(), cspec.getColumnPosition(), cspec.getColType(), tAlias);
        //now push the remaining columns
        for (size_t i = 1; i < colSpecs.size(); i++)
        {
            cspec = colSpecs[i];
            fetch.addColumnToFetch(cspec.getColumnName(), cspec.getColumnPosition(), cspec.getColType());
        }
        fetches.push_back(fetch);
    }
    return fetches;
}

std::vector<FetchSpec> getStarFetches(const std::vector<std::string> &qualColnames, const std::vector<std::string> &tablesInQuery,
                                      const map<string, string> &tblAliases)
{
    if (qualColnames.size() > 1)
    {
        //ambiguos fetch, throw
        throw InvalidQueryException("Column list is ambiguous.");
    }
    if (tablesInQuery.empty())
        throw InvalidQueryException("No tables given.");
    //being here means one * column, possibly many tables
    //return (tablesInQuery, dbCatalog, tblAliases);
    std::vector<FetchSpec> fetches;
    std::vector<string> starTables;
    for (auto qname : qualColnames)
    {
        auto pos = qname.find(".*");
        if (pos != string::npos)
        {
            auto tblnameOrAlias = qname.substr(0, pos);
            starTables.push_back(tblnameOrAlias);
        }
    }
    for (auto st : starTables)
    {
        auto aliasIter = tblAliases.find(st);
        auto tname = (aliasIter == tblAliases.end()) ? st : aliasIter->second;
        if (std::find(tablesInQuery.begin(), tablesInQuery.end(), tname) == tablesInQuery.end())
            throw InvalidQueryException("No table for " + st);
    }
    auto dbCatalogPtr = catalog::DBCatalog::instance();
    for (auto tbl : tablesInQuery)
    {
        //auto tblModel = tableCatalog.find(tbl)->second.getModel(); // guaranteed to hit a valid result if we are here, o/w the exception must have been thrown above
        auto colSpecsOpt = dbCatalogPtr->getFullSpecForTable(tbl);
        if (!colSpecsOpt)
        {
            throw NoSuchEntryException(tbl);
        }
        auto aliasIter = tblAliases.find(tbl);
        auto tAlias = (aliasIter == tblAliases.end()) ? tbl : aliasIter->first;
        auto colSpecs = colSpecsOpt.get();
        assert(colSpecs.size());
        auto cspec = colSpecs[0];
        FetchSpec fetch(tbl, cspec.getColumnName(), cspec.getColumnPosition(), cspec.getColType(), tAlias);
        //now push the remaining columns
        for (size_t i = 1; i < colSpecs.size(); i++)
        {
            cspec = colSpecs[i];
            fetch.addColumnToFetch(cspec.getColumnName(), cspec.getColumnPosition(), cspec.getColType());
        }
        fetches.push_back(fetch);
    }
    return fetches;
}

bool starColumnAsked(const std::vector<std::string> &qualColnames)
{
    for (auto qname : qualColnames)
    {
        if (qname == constants::STAR)
            return true;
        if (qname.find(".*") != string::npos)
            return true;
    }
    return false;
}

void expandTableFetchesWithWhere(std::vector<FetchSpec> &fetches, const std::vector<std::string> &tablesInQuery,
                                 const map<string, string> &tblAliases,
                                 const std::vector<WhereClause> &wheres)
{
    if (tablesInQuery.empty() || wheres.empty())
    {
        return;
    }
    auto dbCatalogPtr = catalog::DBCatalog::instance();
    //handle presence of * in columns first
    for (auto &wc : wheres)
    {
        auto qualColname = wc.getColumnName();
        if (util::StringUtil::string_contains(qualColname, "*"))
            throw InvalidQueryException("* not allowed in where conditions");

        auto tblColPair = extractTableColumnNames(qualColname);
        std::string tblname = tblColPair.first, standaloneColName = tblColPair.second;
        std::string tblAlias = constants::NO_TBL_ALIAS_GIVEN;
        if (tblname.empty())
        { //no dot based qualified name used
            //try to assign the column to a table given in query
            for (auto tbl : tablesInQuery)
            {
                auto colSpecOpt = dbCatalogPtr->getColumnSpecForTable(standaloneColName, tbl);
                if (colSpecOpt)
                {
                    tblname = tbl;
                    auto cspec = colSpecOpt.get();
                    auto iter = tblAliases.find(tbl);
                    if (iter != tblAliases.end())
                    { //indeed an alias
                        tblname = iter->second;
                        tblAlias = iter->first;
                    }
                    //addColumnToMatchingTableSpecWithName(fetches, cspec, tbl, tbl);
                    //cout << "adding wc " << wc.str() << " to " << cspec << " with table " << tblname << " alias " << tblAlias << endl;
                    addWhereToMatchingTableSpecWithName(fetches, cspec, wc, tblname, tblAlias);
                    // colIndex = spec.getColumnPosition();
                    // colDataType = spec.getColType();
                    break;
                }
            }
            if (tblname.empty())
                throw NoSuchEntryException(qualColname, true /*is column */); //no table has column name in its model catalog
        }
        else
        {
            //the column is qualified with a table name
            //check if its an alias
            auto iter = tblAliases.find(tblname);
            if (iter != tblAliases.end())
            { //indeed an alias
                tblname = iter->second;
                tblAlias = iter->first;
            }
            else if (!util::Collections::containerHasValue(tablesInQuery, tblname))
                throw InvalidQueryException("Invalid tablename: " + tblname); //tablename not present in tables requested

            auto colSpecOpt = dbCatalogPtr->getColumnSpecForTable(standaloneColName, tblname);
            if (!colSpecOpt)
                throw NoSuchEntryException(standaloneColName, true /*is column */);
            auto cspec = colSpecOpt.get();
            //addColumnToMatchingTableSpecWithName(fetches, cspec, tblname, tblAlias);
            //cout << "adding wc " << wc.str() << " to " << cspec << " with table " << tblname << " alias " << tblAlias << endl;
            addWhereToMatchingTableSpecWithName(fetches, cspec, wc, tblname, tblAlias);
        }
    }
}

boost::optional<std::vector<FetchSpec>> planTableFetches(const std::vector<std::string> &qualColnames, const std::vector<std::string> &tablesInQuery,
                                                         const map<string, string> &tblAliases,
                                                         const std::vector<WhereClause> &wheres)
{
    if (tablesInQuery.empty() || qualColnames.empty())
    {
        return boost::optional<std::vector<FetchSpec>>{};
    }
    //handle presence of * in columns first
    if (starColumnAsked(qualColnames))
        return getStarFetches(qualColnames, tablesInQuery, tblAliases);
    std::vector<FetchSpec> fetches;
    auto dbCatalogPtr = catalog::DBCatalog::instance();
    for (auto qualColname : qualColnames)
    {
        auto tblColPair = extractTableColumnNames(qualColname);
        std::string tblname = tblColPair.first, standaloneColName = tblColPair.second;
        std::string tblAlias = constants::NO_TBL_ALIAS_GIVEN;
        if (tblname.empty())
        { //no dot based qualified name used
            //try to assign the column to a table given in query
            for (auto tbl : tablesInQuery)
            {
                //auto tblModel = tableCatalog.find(tbl)->second.getModel(); // guaranteed to hit a valid result if we are here, o/w the exception must have been thrown above

                auto colSpecOpt = dbCatalogPtr->getColumnSpecForTable(qualColname, tbl);
                if (colSpecOpt)
                {
                    tblname = tbl;
                    auto cspec = colSpecOpt.get();
                    auto iter = tblAliases.find(tbl);
                    if (iter != tblAliases.end())
                    { //indeed an alias
                        tblAlias = iter->first;
                    }
                    addColumnToMatchingTableSpecWithName(fetches, cspec, tbl, tblAlias);
                    // colIndex = spec.getColumnPosition();
                    // colDataType = spec.getColType();
                    break;
                }
            }
            if (tblname.empty())
                throw NoSuchEntryException(qualColname, true /*is column */); //no table has column name in its model catalog
        }
        else
        {
            //the column is qualified with a table name
            //check if its an alias
            auto iter = tblAliases.find(tblname);
            if (iter != tblAliases.end())
            { //indeed an alias
                tblname = iter->second;
                tblAlias = iter->first;
            }
            else if (!util::Collections::containerHasValue(tablesInQuery, tblname))
                throw InvalidQueryException("Invalid tablename: " + tblname); //tablename not present in tables requested

            auto colSpecOpt = dbCatalogPtr->getColumnSpecForTable(standaloneColName, tblname);
            if (!colSpecOpt)
                throw NoSuchEntryException(standaloneColName, true /*is column */);
            auto cspec = colSpecOpt.get();
            addColumnToMatchingTableSpecWithName(fetches, cspec, tblname, tblAlias);
        }
    }
    return fetches;
}

model::RelationSet combineRelationtSets(model::RelationSet first, model::RelationSet second)
{
    model::ResultSet answer;

    //answer.appendData(rs.getData());
    return answer;
}

model::RelationSet combineRelationtSets(std::initializer_list<model::RelationSet> rsList)
{
    model::ResultSet answer;
    for (auto rs : rsList)
    {
        answer.appendData(rs.getData());
    }
    return answer;
}

boost::optional<string> getTableAlias(string tableName, const map<string, string> &aliases)
{
    for (auto pair : aliases)
    {
        if (pair.second == tableName)
            return pair.first;
    }
    return boost::optional<string>{};
}

bool matchingSubqueryRelationNameForColumn(string relationName, string qualColName, const vector<model::ColumnSpec> &columnSpecs)
{
    auto tblColPair = extractTableColumnNames(qualColName);
    assert(!relationName.empty());
    if (relationName == tblColPair.first)
    {
        return true;
    }
    if (tblColPair.first.empty())
    {
        //match column to specs
        for (auto &spec : columnSpecs)
        {
            if (spec.getColumnName() == tblColPair.second)
                return true;
        }
    }
    return false;
}

int subQueryResultMatchesColumn(shared_ptr<model::RelationSet> resultPtr, vector<string> &columnsToGet, shared_ptr<model::RelationSet> accumulationPtr){
    for(auto &colName : columnsToGet){
        auto namePair = extractTableColumnNames(colName);
        auto table = namePair.first;
        auto column = namePair.second;
        if(!table.empty() && table != resultPtr->getRelationName()) {
            return -1;
        }
        //either table name is empty or they match 
        if(!table.empty() && table == resultPtr->getRelationName()){
            //check against column names 
            auto colInfo = resultPtr->getColumnInfo();
            for(int i=0; i<colInfo.size(); i++){
                auto cspec = colInfo[i];
                if(cspec.getColumnName() == column) {
                    return i;
                }
            }
        }

    }
}

void populateResultFromSubQueryResults(shared_ptr<model::RelationSet> resultPtr, vector<string> &columnsToGet, vector<WhereClause> &whereClauses){

}

const shared_ptr<model::RelationSet> query::SelectNode::getQueryResult()
{
    //first resolve the dependencies of this query
    //now we are in a select and need to check if
    // there are subqueries of this select that need to be resolved first
    catalog::TableCatalog subQueryCatalog(getNodeName());
    //vector<string> satisfiedFromSubQuery;
    for (auto t : groupByNames)
        debug("groupby: " + t);
    debug("---------");
    auto subQResultPtr = make_shared<model::RelationSet>(getNodeName()+"_subResults");
    for (auto &sub : getSubqueries())
    {
        auto relationPtr = sub.getQueryResult();
        //debug("looking at subq " + relationPtr->getRelationName());
        catalog::TableSpec subQuerySpec(relationPtr->getRelationName(), relationPtr->getColumnInfo());
        subQueryCatalog.addTableSpec(relationPtr->getRelationName(), subQuerySpec);
        subQResultPtr->appendColumnInfo(relationPtr->getColumnInfo());
        subQResultPtr->appendData(relationPtr->getData());
    }
    auto fetchesOpt = planTableFetches(columnNames, tableNames, tableAliases, whereClauses);
    auto fullResultPtr = make_shared<model::RelationSet>(getNodeName());
    if (fetchesOpt)
    {
        auto fetches = fetchesOpt.get();
        for(auto &fc : fetches){
            fc.print(std::cout);
        }
        expandTableFetchesWithWhere(fetches, tableNames, tableAliases, whereClauses);
        auto dbCatalogPtr = catalog::DBCatalog::instance();
        for (auto &toFetch : fetches)
        {
            auto path = dbCatalogPtr->getTableDataPath(toFetch.getTableName());
            debug("fetching data from " + path);
            csvops::CSVReader reader(path, toFetch);
            auto rows = reader.getDataFromFile();
            fullResultPtr->appendColumnInfo(toFetch.computedColumnInfo());
            fullResultPtr->appendData(rows);
        }
    }
    //now ensure that we can resolve everything with the data we have
    //auto fetches = planFetches(colNames, tblNames, subqueryTableCatalog, tblAliases);
    //auto result =
    return fullResultPtr;
}
