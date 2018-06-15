#include "run/SelectQueryExecutor.h"

#include "query/SelectNode.h"
#include "query/WorkNode.h"
#include "model/ResultSet.h"
#include "util/Collections.h"
#include "query/FetchSpec.h"
#include <boost/optional/optional.hpp>
#include <map>
#include "model/RelationSet.h"

#include "fileops/CSVReader.h"

namespace executor
{
using namespace query;
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
    specs.push_back(FetchSpec(tname, colSpec.getColumnName(), colSpec.getColumnPosition(), colSpec.getColType(), tAlias));
}
std::vector<FetchSpec> planAllColumnFetch(const std::vector<std::string> &qualColnames, const std::vector<std::string> &tablesInQuery,
                                               const catalog::DBCatalog &dbCatalog,
                                               const map<string, string> &tblAliases)
{
    if (qualColnames.size() > 1)
    {
        //ambiguos fetch, throw
        throw InvalidQueryException("Column list is ambiguous.");
    }
    if(tablesInQuery.empty()) throw InvalidQueryException("No tables given.");
    //being here means one * column, possibly many tables
    //return (tablesInQuery, dbCatalog, tblAliases);
    std::vector<FetchSpec> fetches;
    std::vector<string> starTables;
    for(auto qname : qualColnames){
        auto pos = qname.find(".*");
        if(pos != string::npos) {
            auto tblnameOrAlias = qname.substr(0, pos);
            starTables.push_back(tblnameOrAlias);
        }
    }
    for(auto st : starTables) {
        auto aliasIter = tblAliases.find(st);
        auto tname = (aliasIter == tblAliases.end()) ? st : aliasIter->second;
        if(std::find(tablesInQuery.begin(), tablesInQuery.end(), tname) == tablesInQuery.end())
            throw InvalidQueryException("No table for "+st);
    }
    for (auto tbl : tablesInQuery)
    {
        //auto tblModel = tableCatalog.find(tbl)->second.getModel(); // guaranteed to hit a valid result if we are here, o/w the exception must have been thrown above
        auto colSpecs = dbCatalog.getFullSpecForTable(tbl);
        auto aliasIter = tblAliases.find(tbl);
        auto tAlias = (aliasIter == tblAliases.end()) ? tbl : aliasIter->first;
        auto cspec = colSpecs[0];
        FetchSpec fetch(tbl,cspec.getColumnName(), cspec.getColumnPosition(), cspec.getColType(), tAlias);
        //now push the remaining columns
        for(size_t i=1;i<colSpecs.size();i++){
            cspec =  colSpecs[i];
            fetch.addColumnToFetch(cspec.getColumnName(), cspec.getColumnPosition(), cspec.getColType());
        }
        fetches.push_back(fetch); 
    }
    return fetches;
}
bool starColumnAsked(const std::vector<std::string> &qualColnames){
    for(auto qname : qualColnames){
        if(qname == constants::STAR) return true;
        if(qname.find(".*") != string::npos) return true;
    }
    return false;
}

std::vector<FetchSpec> planFetches(const std::vector<std::string> &qualColnames, const std::vector<std::string> &tablesInQuery,
                                        const catalog::DBCatalog &dbCatalog,
                                        const map<string, string> &tblAliases)
{
    //handle presence of * in columns first
    if(starColumnAsked(qualColnames))
                return planAllColumnFetch(qualColnames, tablesInQuery, dbCatalog, tblAliases);
    std::vector<FetchSpec> fetches;
    for (auto qualColname : qualColnames)
    {
        std::string tblname = "", standaloneColName = "", tblAlias = "";
        auto dotPos = qualColname.find(".");
        if (dotPos == std::string::npos)
        { //no dot based qualified name used
            //try to assign the column to a table given in query
            for (auto tbl : tablesInQuery)
            {
                //auto tblModel = tableCatalog.find(tbl)->second.getModel(); // guaranteed to hit a valid result if we are here, o/w the exception must have been thrown above
                auto colSpecOpt = dbCatalog.getColumnSpecForTable(qualColname, tbl);
                if (colSpecOpt)
                {
                    tblname = tbl;
                    auto cspec = colSpecOpt.get();
                    addColumnToMatchingTableSpecWithName(fetches, cspec, tbl, tbl);
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
            auto tblnameOrAlias = qualColname.substr(0, dotPos);
            tblname = tblnameOrAlias;
            //check if its an alias
            auto iter = tblAliases.find(tblnameOrAlias);
            if (iter != tblAliases.end())
            { //indeed an alias
                tblname = iter->second;
                tblAlias = iter->first;
            }
            else if (!util::Collections::containerHasValue(tablesInQuery, tblname))
                throw InvalidQueryException("Invalid tablename: " + tblname); //tablename not present in tables requested

            standaloneColName = qualColname.substr(dotPos + 1);
            auto colSpecOpt = dbCatalog.getColumnSpecForTable(standaloneColName, tblname);
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
model::RelationSet executor::SelectQueryExecutor::getQueryResult()
{
   
    model::RelationSet rs(selectQuery.getNodeName());
    auto colNames = selectQuery.getColumnNames();
    auto tblNames = selectQuery.getTableNames();
    auto tblAliases = selectQuery.getTableAliases();
    const catalog::DBCatalog &dbCatalog = catalog::DBCatalog::instance();
    auto fetches = planFetches(colNames, tblNames, dbCatalog, tblAliases);
    //auto result =
    for (auto toFetch : fetches)
    {

        auto path = dbCatalog.getTableDataPath(toFetch.getTableName());
        csvops::CSVReader reader(path, toFetch);
        auto rows = reader.getDataFromFile();
        rs.appendColumnInfo(toFetch.computedColumnInfo());
        rs.appendData(rows);
    }
    return rs;
}
} // namespace executor
