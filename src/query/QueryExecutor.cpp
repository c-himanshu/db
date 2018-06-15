

#include "QueryExecutor.h"
#include "FetchSpec.h"
#include "metadata/DBCatalog.h"
#include "fileops/CSVReader.h"
#include "exception/NoSuchEntryException.h"
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/split.hpp>
#include "util/ApplyMath.hpp"

using namespace std;
using namespace model;
using namespace query;
using namespace util;

bool allColumns = false;

void replaceTableAliases(const vector<DataSource> &tables, vector<ResultColumn> &resultCols,
                         vector<WhereClause> &whereConditions,
                         vector<GroupByColumn> &groupByCols)
{
    for (const auto &tbl : tables)
    {
        auto tblName = tbl.name;
        assert(tblName.size());
        auto alias = tbl.alias;
        for (auto &rcol : resultCols)
        {
            if (alias.size() && rcol.tableName == alias)
            {
                rcol.tableName = tblName;
            }
        }
        for (auto &wc : whereConditions)
        {
            if (alias.size() && wc.getTableName() == alias)
            {
                wc.setTableName(tblName);
            }
        }
        for (auto &gb : groupByCols)
        {
            if (alias.size() && gb.tableName == alias)
            {
                gb.tableName = tblName;
            }
        }
    }
}

void replaceColumnAliases(const vector<ResultColumn> &resultCols,
                          vector<WhereClause> &whereConditions,
                          vector<GroupByColumn> &groupByCols)
{
    for (const auto &rcol : resultCols)
    {
        auto colname = rcol.columnName;
        assert(colname.size());
        auto alias = rcol.columnAlias;
        for (auto &wc : whereConditions)
        {
            if (alias.size() && wc.getColumnName() == alias)
            {
                wc.setColumnName(colname);
            }
        }
        for (auto &gb : groupByCols)
        {
            if (alias.size() && gb.columnName == alias)
            {
                gb.columnName = colname;
            }
        }
    }
}

bool addColumnToJoinFetchIfMatches(FetchSpec &fetch, const string &columnName, const string &colTblName,
                                   const shared_ptr<catalog::DBCatalog> dbCatalogPtr,
                                   bool addToGroupBy = false)
{
    auto tblName = fetch.getTableName();
    auto displayName = columnName;
    if(colTblName.size()) displayName = colTblName+"."+columnName;
    if (colTblName == tblName)
    { //we can only match a column with a given alias/name
        //to the matching alias/tablename
        //we have a alias/table, so we must find the column spec from here
        //otherwise the query is wrong
        auto colSpecOpt = dbCatalogPtr->getColumnSpecForTable(columnName, tblName);
        if (!colSpecOpt)
            throw NoSuchEntryException(tblName + "." + columnName, true);
        auto colSpec = colSpecOpt.get();
        
        fetch.addColumnToFetch(colSpec,displayName);
        
        return true;
    }
    
    return false;
}

bool addAllColumns(FetchSpec &fetch,
                   const shared_ptr<catalog::DBCatalog> dbCatalogPtr)
{
    allColumns = true;
    auto tblName = fetch.getTableName();
    auto colSpecOpt = dbCatalogPtr->getFullSpecForTable(tblName);
    if (colSpecOpt)
    {
        auto cs = colSpecOpt.get();
        for (auto c : cs)
        {
            fetch.addColumnToFetch(c,tblName+"."+c.getColumnName());
        }
        return true;
    }
    else
        throw NoSuchEntryException(tblName);
}
bool isRealAlias(string alias, bool isTable = true){
    if(isTable)
        return alias != constants::NO_TBL_ALIAS_GIVEN;
    else
        return alias != constants::NO_COL_ALIAS_GIVEN;
}
bool addColumnToFetchIfMatches(FetchSpec &fetch, const string &columnName, const string &colTblName,
                               const shared_ptr<catalog::DBCatalog> dbCatalogPtr,
                               bool addToGroupBy = false)
{
    auto tblName = fetch.getTableName();
    auto fetchTblAlias = fetch.getTableAlias();
    assert(tblName.size());
    auto displayName = columnName;
    if(colTblName.size()) displayName = colTblName+"."+columnName;
    //    auto colSpecOpt = dbCatalogPtr->getColumnSpecForTable(columnName, tblName);
    if ( (!isRealAlias(fetchTblAlias) && tblName == colTblName)
        ||
        (colTblName.empty() && !isRealAlias(fetchTblAlias))
        ||
        ( fetchTblAlias == colTblName )
        )
    {
        auto colSpecOpt = dbCatalogPtr->getColumnSpecForTable(columnName, tblName);
        if (!colSpecOpt)
            return false;
        auto colSpec = colSpecOpt.get();
        //        if (addToGroupBy)
        //        {
        //            fetch.addToGroupBy(colSpec);
        //        }
        //        else
        //        {
        fetch.addColumnToFetch(colSpec, displayName);
        //}
        return true;
    }
    return false;
}

//only use for result set from subqueries -- DO NOT USE for anything else
//assumes that tablename is the name of result set node
bool addColumnToFetchIfFounInColumnInfo(FetchSpec &fetch, const string &columnName, const string &colTblName, const vector<ColumnSpec> &columnInfo, bool addToGroupBy = false)
{
    if(columnName == "*"){
        for (auto c : columnInfo)
        {
            fetch.addColumnToFetch(c);
        }
        return true;
    }
    auto tblName = fetch.getTableName();
    assert(tblName.size() && columnName.size());
    if (colTblName.size() && colTblName != tblName)
        return false;
    auto displayName = columnName;
    if(colTblName.size()) displayName = colTblName+"."+columnName;
    if (colTblName.size() && colTblName == tblName)
    {
        //must be fetched from this node then
        //go over node's column info and find a matching column
        //if we dont find one, throw exception
        for (auto &cs : columnInfo)
        {
            if (cs.getColumnName() == columnName)
            {
                model::ColumnSpec csp = cs;
                //                if (addToGroupBy)
                //                {
                //                    fetch.addToGroupBy(csp);
                //                }
                //                else
                //                {
                fetch.addColumnToFetch(csp, displayName);
                //                }
                return true;
            }
        }
        throw NoSuchEntryException(colTblName + "." + columnName, true);
    }
    //colTblName must be empty here
    assert(colTblName.empty());
    for (auto &cs : columnInfo)
    {
        if (cs.getColumnName() == columnName)
        {
            model::ColumnSpec csp = cs;
//            if (addToGroupBy)
//            {
//                fetch.addToGroupBy(csp);
//            }
//            else
//            {
                fetch.addColumnToFetch(csp, displayName);
            //}
            return true;
        }
    }
    return false;
}

//only use for result set from subqueries -- DO NOT USE for anything else
//assumes that tablename is the name of result set node
bool addWhereToFetchIfFounInColumnInfo(FetchSpec &fetch, WhereClause &where,
                                       const vector<ColumnSpec> &columnInfo)
{
    auto tblName = fetch.getTableName();
    auto columnName = where.getColumnName();
    assert(tblName.size() && columnName.size());
    auto colTblName = where.getTableName();
    if (colTblName.size() && colTblName != tblName)
        return false;
    if (colTblName.size() && colTblName == tblName)
    {
        //must be fetched from this node then
        //go over node's column info and find a matching column
        //if we dont find one, throw exception
        for (auto &cs : columnInfo)
        {
            if (cs.getColumnName() == columnName)
            {
                model::ColumnSpec cspec = cs;
                fetch.addToWheres(cspec.getColumnPosition(), where.getValue(),
                                  where.getOp(), cspec.getColType());
                return true;
            }
        }
        throw NoSuchEntryException(colTblName + "." + columnName, true);
    }
    //colTblName must be empty here
    assert(colTblName.empty());
    for (auto &cs : columnInfo)
    {
        if (cs.getColumnName() == columnName)
        {
            model::ColumnSpec cspec = cs;
            fetch.addToWheres(cspec.getColumnPosition(), where.getValue(),
                              where.getOp(), cspec.getColType());
            return true;
        }
    }
    return false;
}

bool addWhereToFetchIfMatches(FetchSpec &fetch, const WhereClause &where,
                              const shared_ptr<catalog::DBCatalog> dbCatalogPtr)
{
    auto tblName = fetch.getTableName();
    assert(tblName.size());
    auto alias = fetch.getTableAlias();
    auto colSpecOpt = dbCatalogPtr->getColumnSpecForTable(where.getColumnName(), tblName);
    if (where.getTableName() == tblName || colSpecOpt)
    {
        auto cspec = colSpecOpt.get();
        fetch.addToWheres(cspec.getColumnPosition(), where.getValue(),
                          where.getOp(), cspec.getColType());
        return true;
    }
    return false;
}

void populateFetchSpec(FetchSpec &fetch, vector<ResultColumn> &resultcols,
                       vector<WhereClause> &wheres, vector<GroupByColumn> &groups,
                       vector<JoinCondition> &joins)
{
    const auto dbCatalogPtr = catalog::DBCatalog::instance();
    size_t pos = 0;
    for (auto i = resultcols.begin(); i != resultcols.end();)
    {
        if ("*" == i->columnName)
        {
            addAllColumns(fetch, dbCatalogPtr);
            resultcols.erase(i);
            break;
        }
        auto added = addColumnToFetchIfMatches(fetch, i->columnName, i->tableName, dbCatalogPtr);
        if (added)
        {
            fetch.resultColumnPositions.push_back(pos);
            resultcols.erase(i);
        }
        else
        {
            ++i;
        }
        pos++;
    }
    for (auto i = wheres.begin(); i != wheres.end();)
    {
        auto added = addWhereToFetchIfMatches(fetch, *i, dbCatalogPtr);
        if (added)
        {
            wheres.erase(i);
        }
        else
        {
            ++i;
        }
    }
    for (auto i = groups.begin(); i != groups.end();)
    {
        auto added = addColumnToFetchIfMatches(fetch, i->columnName, i->tableName, dbCatalogPtr, true /*groupby*/);
        if (added)
        {
            groups.erase(i);
        }
        else
        {
            ++i;
        }
    }
    for (auto & j : joins)
    {
        addColumnToFetchIfMatches(fetch, j.leftColumnName, j.leftTableName, dbCatalogPtr);
        addColumnToFetchIfMatches(fetch, j.rightColumnName, j.rightTableName, dbCatalogPtr);
    }
}

void populateFetchSpecFromResultSetInfo(FetchSpec &fetch, vector<ResultColumn> &resultcols,
                                        vector<WhereClause> &wheres, vector<GroupByColumn> &groups,
                                        const vector<ColumnSpec> &columnInfo)
{
    for (auto i = resultcols.begin(); i != resultcols.end();)
    {
        auto added = addColumnToFetchIfFounInColumnInfo(fetch, i->columnName, i->tableName, columnInfo);
        if (added)
        {
            resultcols.erase(i);
        }
        else
        {
            ++i;
        }
    }
    for (auto i = wheres.begin(); i != wheres.end();)
    {
        auto added = addWhereToFetchIfFounInColumnInfo(fetch, *i, columnInfo);
        if (added)
        {
            wheres.erase(i);
        }
        else
        {
            ++i;
        }
    }
    for (auto i = groups.begin(); i != groups.end();)
    {
        auto added = addColumnToFetchIfFounInColumnInfo(fetch, i->columnName, i->tableName, columnInfo, true /*groupby*/);
        if (added)
        {
            groups.erase(i);
        }
        else
        {
            ++i;
        }
    }
}

vector<DataRow> getDataFromTable(FetchSpec &toFetch, const shared_ptr<catalog::DBCatalog> dbCatalogPtr)
{
    auto path = dbCatalogPtr->getTableDataPath(toFetch.getTableName());
    debug("fetching data from " + path);
    csvops::CSVReader reader(path, toFetch);
    return reader.getDataFromFile();
}

boost::optional<JoinCondition> isJoinTable(const vector<JoinCondition> &joins, string tblName)
{
    for (const auto &j : joins)
    {
        if (util::StringUtil::string_contains(j.condition, (tblName + ".")))
            return j;
    }
    return boost::optional<JoinCondition>{};
}

void dedupTables(vector<DataSource> &tables){
    set<string> tblAliasCombinedSet;
    for (auto i = tables.begin(); i != tables.end();)
    {
        auto combo = i->name+"@"+i->alias;
        if(tblAliasCombinedSet.find(combo) != tblAliasCombinedSet.end()){
            tables.erase(i);
        }
        else {
            tblAliasCombinedSet.insert(combo);
            ++i;
        }
    }
}
void validateTables(const vector<DataSource> &tbls, const shared_ptr<catalog::DBCatalog> dbCatalogPtr){
    for(const auto &t: tbls){
        if(! dbCatalogPtr->hasTable(t.name))
            throw NoSuchEntryException(t.name);
    }
}

vector<FetchSpec> planFetchesForQuery(LogicalQueryNode &query){
    vector<FetchSpec> fetches;
    vector<ResultColumn> rcols = query.resultColumns;
    vector<WhereClause> wheres = query.whereConditionsAnd;
    vector<GroupByColumn> groups = query.groupByColumns;
    vector<JoinCondition> joins = query.joins;
    
    for (const auto &tbl : query.getDataSources())
    {
        assert(tbl.name.size());
        FetchSpec tblFetch(tbl.name);
        if(tbl.alias != constants::NO_TBL_ALIAS_GIVEN){
            tblFetch.setTableAlias(tbl.alias);
        }
        populateFetchSpec(tblFetch, rcols, wheres, groups, joins);
        if (tblFetch.columnCount())
        {
            fetches.push_back(tblFetch);
        }
    }
    
    //addUnmatchedResultColsToChildren of query
    for(auto rc : rcols){
        query.colsFromChildren.push_back(rc);
    }
    for(auto wc : wheres){
        query.whereOnChildren.push_back(wc);
    }
    for(auto gb : groups){
        query.groupByOnChildren.push_back(gb);
    }
    
    return fetches;
}

std::pair<int, int> positionsOfRelationsToJoin(const vector<RelationSet> &fetchResults,
                                               const JoinCondition &join){
    auto lTable = join.leftTableName;
    auto rTable = join.rightTableName;
    auto lcol = join.leftColumnName;
    auto rcol = join.rightColumnName;
    
    int first = -1, second = -1;
    int pos = 0;
    for(auto &fr : fetchResults){
        auto colnames = fr.getColumnNames();
        if(fr.getRelationName() == lTable){
            for(auto cname : colnames){
                auto tcpair = StringUtil::extractTableColumnNames(cname);
                if( (tcpair.first == lTable || tcpair.first.empty())
                   && tcpair.second == lcol){
                    first = pos;
                    break;
                }
            }
        }
        else if(fr.getRelationName() == rTable ) {
            for(auto cname : colnames){
                auto tcpair = StringUtil::extractTableColumnNames(cname);
                if( (tcpair.first == rTable || tcpair.first.empty())
                   && tcpair.second == rcol){
                    second = pos;
                    break;
                }
            }
        }
        ++pos;
    }
    return make_pair(first, second);
}

void  storeUniqueValues(set<string> &store, const RelationSet &rs, size_t pos){
    for(size_t i = 0; i < rs.size(); i++){
        store.insert(rs.getRowColumnValue(i, pos));
    }
}

/*stores the result in the left reference */
void doJoin(RelationSet &left, RelationSet &right, const JoinCondition &join,
            RelationSet &collect){
    size_t leftColPos = 0;
    size_t rightColPos = 0;
    auto colnames = left.getColumnNames();
    for(size_t i = 0; i < colnames.size(); i++){
        if(StringUtil::extractTableColumnNames(colnames[i]).second == join.leftColumnName) {
            leftColPos = i;
            break;
        }
    }
    
    colnames = right.getColumnNames();
    for(size_t i = 0; i < colnames.size(); i++){
        if(StringUtil::extractTableColumnNames(colnames[i]).second == join.rightColumnName) {
            rightColPos = i;
            break;
        }
    }
    collect.appendColumnInfo(left.getColumnInfo());
    collect.appendColumnInfo(right.getColumnInfo());
    //set<string> acceptValues;
    if(join.isLeftOuter){
        //storeUniqueValues(acceptValues, right, rightColPos);
        auto rightWidth = right.getColumnCount();
        for(auto &lrow : left.getDataAsReference()){
            DataRow drow = lrow;
            auto val = lrow[leftColPos];
            auto matchRow = right.getFirstMatchingRow(rightColPos,val);
            if(matchRow.size()){
                //            if(Collections::containerHasValue(acceptValues, val)){
                drow.appendColumnData(matchRow);
            }
            else{
                drow.appendNulls(rightWidth);
            }
            collect.appendSingleRow(drow);
        }
        return;
    }
    else if(join.isRightOuter){
        //        storeUniqueValues(acceptValues, left, leftColPos);
        //        auto leftWidth = left.getColumnCount();
        //        for(auto &rrow : right.getDataAsReference()){
        //            auto val = rrow[rightColPos];
        //            auto lrow = left.getFirstMatchingRow(leftColPos,val);
        //            if(lrow.size()){
        //                lrow.appendColumnData(right.);
        //            }
        //            else{
        //                lrow.appendNulls(rightWidth);
        //            }
        //        }
    } else {
        //inner join
        left.appendColumnInfo(right.getColumnInfo());
        auto ldata = left.getDataAsReference();
        for(auto lrowIter = ldata.begin(); lrowIter != ldata.end(); ++lrowIter){
            auto val = (*lrowIter)[leftColPos];
            auto matchRow = right.getFirstMatchingRow(rightColPos,val);
            if(matchRow.size()){
                DataRow drow = *lrowIter;
                drow.appendColumnData(matchRow);
                collect.appendSingleRow(drow);
            }
            //            }else { // no match; remove
            //                ldata.erase(lrowIter);
            //            }
        }
    }
}

void collectJoins(RelationSet &collect, vector<RelationSet> &fetchResults,
                  const vector<JoinCondition> &joins){
    for(const auto &join : joins){
        if(join.isCrossJoin()){
            //handle cross join by just appending data
            //remove the first two relations
            auto leftRelation = fetchResults[0];
            auto rightRelation = fetchResults[1];
            collect.appendColumnInfo(leftRelation.getColumnInfo());
            collect.appendData(leftRelation.getDataAsReference());
            collect.appendColumnInfo(rightRelation.getColumnInfo());
            collect.appendData(rightRelation.getDataAsReference());
            fetchResults.erase(fetchResults.begin());
            fetchResults.erase(fetchResults.begin());
        }
        auto posPair = positionsOfRelationsToJoin(fetchResults, join);
        //handle inner or outer join
        auto leftRelation = fetchResults[posPair.first];
        auto rightRelation = fetchResults[posPair.second];
        
        doJoin(leftRelation, rightRelation, join, collect);
        //        collect.appendColumnInfo(leftRelation.getColumnInfo());
        //        collect.appendData(leftRelation.getDataAsReference());
    }
}
shared_ptr<model::RelationSet> QueryExecutor::getLocalTableResults()
{
    //find column spect for whichever result columns
    // we can satisfy from our tables
    auto tables = this->queryNode.getDataSources();
    //dedup the tables (ensuring that same table name with diff aliases is not removed)
    dedupTables(tables);
    const auto dbCatalogPtr = catalog::DBCatalog::instance();
    validateTables(tables, dbCatalogPtr);
    debug("in local get result");
    vector<FetchSpec> fetches = planFetchesForQuery(this->queryNode);
    model::RelationSet localResults;
    vector<RelationSet> fetchResults;
    for(auto &fetch : fetches){
        auto data = getDataFromTable(fetch, dbCatalogPtr);
        auto colinfo = fetch.computedColumnInfo();
        RelationSet rs;
        rs.appendColumnInfo(colinfo);
        rs.appendData(data);
        rs.setName(fetch.getTableName());
        fetchResults.push_back(rs);
    }
    if(this->queryNode.joins.size()){
        collectJoins(localResults, fetchResults, this->queryNode.joins);
    }
    else { // no joins, append my results to localResults
        for(auto &fr : fetchResults){
            localResults.appendColumnInfo(fr.getColumnInfo());
            localResults.appendData(fr.getDataAsReference());
        }
    }
    localResults.setName(queryNode.name);
    return make_shared<model::RelationSet>(localResults);
}

shared_ptr<model::RelationSet>
collectResultsFromChildren(vector<shared_ptr<model::RelationSet>> &subResults,
                           vector<ResultColumn> &colsFromChildren,
                           vector<WhereClause> &whereOnChildren,
                           vector<GroupByColumn> &groupByOnChildren)
{
    // debug("in collectResultsFromChildren");
    RelationSet result;
    for (auto &source : subResults)
    {
        FetchSpec tblFetch(source->getRelationName());
        auto colInfo = source->getColumnInfoCopy();
        populateFetchSpecFromResultSetInfo(tblFetch, colsFromChildren, whereOnChildren, groupByOnChildren, colInfo);
        if (tblFetch.columnCount())
        {
            //execute query for table
            auto rs = source->getData(tblFetch);
            result.appendColumnInfo(tblFetch.computedColumnInfo());
            result.appendData(rs->getData());
        }
    }
    return make_shared<model::RelationSet>(result);
}
std::pair<string, string> extractFuncNameAndColumn(FunctionOnColumn &funCol)
{
    auto fname = funCol.functionName;
    auto fstr = funCol.fullFunctionString;
    std::vector<std::string> splits;
    boost::erase_last(fstr, ")");
    boost::algorithm::split(splits, fstr,
                            boost::is_any_of("("));
    //check for table name
    auto tcPair = util::StringUtil::extractTableColumnNames(splits[1]);
    return make_pair(fname, tcPair.second);
}
shared_ptr<model::RelationSet> performGroupAggregation(model::RelationSet &relation, const std::map<size_t, string> &columnPositionAggregateMap,
                                                       vector<model::ColumnSpec> &aggResultCols,
                                                       const vector<model::ColumnSpec> &groupByCols)
{
    auto aggResult = make_shared<model::RelationSet>(relation.getRelationName());
    aggResult->overwriteColumnInfo(aggResultCols);
    std::map<size_t, size_t> counts;
    std::map<size_t, double> sums;
    
    if (relation.size() == 0)
        return aggResult;
    auto &dataRef = relation.getDataAsReference();
    auto firstRow = dataRef.front();
    string key = "";
    for (const auto &gb : groupByCols)
    {
        key += (firstRow[gb.getColumnPosition()] + "|");
    }
    DataRow row;
    row.copyDataFromAnotherRow(firstRow);
    for (auto &pair : columnPositionAggregateMap)
    {
        auto fname = pair.second;
        auto colIndex = pair.first;
        auto v = firstRow[colIndex];
        if (util::StringUtil::valueIsEmptyOrNull(v) || util::StringUtil::valueIsZero(v))
            continue;
        if (fname == "count")
        {
            row.setValue(colIndex, "1");
        }
        else if (fname == "sum")
        {
            row.setValue(colIndex, to_string(stod(v)));
        }
    }
    aggResult->appendSingleRow(row);
    string prevKey = key;
    size_t rowIndexToUpdate = 0;
    for (size_t index = 1; index < dataRef.size(); index++)
    {
        auto &drow = dataRef[index];
        string computedKey = "";
        for (const auto &gb : groupByCols)
        {
            computedKey += (drow[gb.getColumnPosition()] + "|");
        }
        if (computedKey != prevKey)
        { //we need to add new row
            DataRow row;
            row.copyDataFromAnotherRow(drow);
            aggResult->appendSingleRow(row);
            rowIndexToUpdate++;
            for (auto &pair : columnPositionAggregateMap)
            {
                auto fname = pair.second;
                auto colIndex = pair.first;
                auto v = drow[colIndex];
                if (util::StringUtil::valueIsEmptyOrNull(v) || util::StringUtil::valueIsZero(v))
                    continue;
                if (fname == "count")
                {
                    aggResult->updateRowColumnValue(rowIndexToUpdate, colIndex, "1");
                }
                if (fname == "sum")
                {
                    aggResult->updateRowColumnValue(rowIndexToUpdate, colIndex, v);
                }
            }
            prevKey = computedKey;
            continue;
        }
        for (auto &pair : columnPositionAggregateMap)
        {
            auto fname = pair.second;
            auto colIndex = pair.first;
            auto v = drow[colIndex];
            if (util::StringUtil::valueIsEmptyOrNull(v) || util::StringUtil::valueIsZero(v))
                continue;
            
                if (fname == "count")
                {
                    auto prevCount = aggResult->getRowColumnValue(rowIndexToUpdate, colIndex);
                    auto newCount = stoi(prevCount) + 1;
                    aggResult->updateRowColumnValue(rowIndexToUpdate, colIndex, to_string(newCount));
                }
                if (fname == "sum")
                {
                    auto prevSum = aggResult->getRowColumnValue(rowIndexToUpdate, colIndex);
                    auto newSum = stod(prevSum) + stod(v);
                    aggResult->updateRowColumnValue(rowIndexToUpdate, colIndex, to_string(newSum));
                }
        }
    }
    return aggResult;
}
shared_ptr<model::RelationSet> performCountStar(model::RelationSet &relation){
    auto aggResult = make_shared<model::RelationSet>(relation.getRelationName());
    vector<ColumnSpec> cinfo;
    cinfo.push_back(ColumnSpec("count(*)",0,data_types::INT));
    aggResult->appendColumnInfo(cinfo);
    DataRow row;
    row.push_back(to_string(relation.size()));
    aggResult->appendSingleRow(row);
    return aggResult;
}

shared_ptr<model::RelationSet> performPlainAggregation(model::RelationSet &relation, std::map<size_t, string> &columnPositionAggregateMap,
                                                       vector<model::ColumnSpec> &aggResultCols)
{
    auto aggResult = make_shared<model::RelationSet>(relation.getRelationName());
    aggResult->overwriteColumnInfo(aggResultCols);
    if (relation.size() == 0)
        return aggResult;
    // relation.overwriteColumnInfo(aggResultCols);
    long count = 0;
    double sum = 0;
    std::map<size_t, size_t> counts;
    std::map<size_t, double> sums;
    for (auto &drow : relation.getDataAsReference())
    {
        for (auto &pair : columnPositionAggregateMap)
        {
            auto fname = pair.second;
            auto colIndex = pair.first;
            auto v = drow[colIndex];
            if (util::StringUtil::valueIsEmptyOrNull(v) || util::StringUtil::valueIsZero(v))
                continue;
            if (fname == "count")
            {
                ++count;
                counts[colIndex] = count;
            }
            else if (fname == "sum")
            {
                sum += stod(v);
                sums[colIndex] = sum;
            }
        }
    }
    //now check if all columns to be returned in the result are aggregate functions
    bool allAggregate = true;
    for (auto &col : aggResultCols)
    {
        auto colname = col.getColumnName();
        if (!(boost::starts_with(colname, "count(") ||
              boost::starts_with(colname, "sum(")))
        {
            allAggregate = false;
            break;
        }
    }
    if (!allAggregate)
    {
        //relation.overwriteColumnInfo(aggResultCols);
        for (auto &pair : columnPositionAggregateMap)
        {
            if (pair.second == "count")
            {
                relation.updateColumnValue(pair.first, to_string(counts[pair.first]));
            }
            if (pair.second == "sum")
            {
                relation.updateColumnValue(pair.first, to_string(sums[pair.first]));
            }
        }
        // use the passed relation ref as the final result
        aggResult->appendData(relation.getData());
        return aggResult;
    }
    //being here means they are all aggregate functions
    //we need to return a single row
    vector<string> aggValues;
    for (auto &pair : columnPositionAggregateMap)
    {
        if (pair.second == "count")
        {
            aggValues.push_back(to_string(counts[pair.first]));
        }
        if (pair.second == "sum")
        {
            aggValues.push_back(to_string(sums[pair.first]));
        }
    }
    DataRow row(aggValues);
    aggResult->appendSingleRow(row);
    return aggResult;
}

shared_ptr<model::RelationSet> applyAggregateFunctions(model::RelationSet &relation,
                                                       const vector<model::ColumnSpec> &groupByColumns, vector<FunctionOnColumn> &aggFunctions)
{
    //iterate over each row of grouped data
    vector<model::ColumnSpec> aggResultCols;
    const auto colInfo = relation.getColumnInfo();
    //go over columns of relation and find the header replacement in terms of aggregate function
    map<size_t, string> columnPositionAggregateMap;
    
    for (const auto &cs : colInfo)
    {
        auto colname = StringUtil::extractTableColumnNames(cs.getColumnName()).second;
        model::ColumnSpec cspec(colname, cs.getColumnPosition(),
                                cs.getColType());
        for (auto &fnOnCol : aggFunctions)
        {
            auto pair = extractFuncNameAndColumn(fnOnCol);
            fnOnCol.columnName = pair.second;
            if (colname == fnOnCol.columnName)
            {
                cspec.setColumnName(fnOnCol.fullFunctionString);
                columnPositionAggregateMap[cs.getColumnPosition()] = fnOnCol.functionName;
            }
        }
        aggResultCols.push_back(cspec);
    }
    if (relation.size() == 0)
    {
        return make_shared<model::RelationSet>();
    }
    if (groupByColumns.empty())
    {
        return performPlainAggregation(relation, columnPositionAggregateMap, aggResultCols);
    }
    return performGroupAggregation(relation, columnPositionAggregateMap, aggResultCols, groupByColumns);
}
void applyMathExpr(const ResultColumn &rcol, shared_ptr<RelationSet> relation, const vector<ColumnSpec> &resultColInfo){
    size_t pos = 0;
    for (size_t i = 0; i < resultColInfo.size(); i++)
    {
        const auto &rci = resultColInfo[i];
        auto rescol = StringUtil::extractTableColumnNames(rci.getColumnName()).second;
        if (rescol == rcol.columnName)
        {
            pos = i;
            break;
        }
    }
    for(auto &d : relation->getDataAsReference()){
        auto v = d[pos];
        auto computed = do_math(rcol.mathOperation, rcol.columnName, stoi(v));
        d.setValue(pos, std::to_string(computed));
    }
}

shared_ptr<model::RelationSet> QueryExecutor::getResult()
{
    //start at the root, resolve all its children first
    //debug("in getResults " + queryNode.str());
    auto result = make_shared<RelationSet>(queryNode.name);
    vector<shared_ptr<model::RelationSet>> subResults;
    for (const auto &child : this->queryNode.children)
    {
        QueryExecutor childExec(child);
        auto childResult = childExec.getResult();
        subResults.push_back(childResult);
    }
    //get whatevver data we can from the tables that are in
    // our node
    auto myLocalResultsPtr = getLocalTableResults();
    //then get the filter/project results from subqueries
    if(this->queryNode.children.size()){
        if (myLocalResultsPtr && myLocalResultsPtr->size())
        {
            result->appendColumnInfo(myLocalResultsPtr->getColumnInfo());
            result->appendData(myLocalResultsPtr->getData());
        }
        auto resultFromChildren = collectResultsFromChildren(subResults, queryNode.colsFromChildren, queryNode.whereOnChildren, queryNode.groupByOnChildren);
        if (resultFromChildren->size())
        {
            result->appendColumnInfo(resultFromChildren->getColumnInfo());
            result->appendData(resultFromChildren->getData());
        }
    } else {
        result = myLocalResultsPtr;
    }
    //fix group by column positions
    vector<ColumnSpec> resultColInfo = result->getColumnInfo();
    vector<ColumnSpec> colsToGroupBy;
    for (const auto &gb : queryNode.groupByColumns)
    {
        bool found = false;
        for (const auto &rci : resultColInfo)
        {
            auto rescol = StringUtil::extractTableColumnNames(rci.getColumnName()).second;
            if (rescol == gb.columnName)
            {
                found = true;
                colsToGroupBy.push_back(ColumnSpec(gb.columnName, rci.getColumnPosition(),
                                                   rci.getColType()));
            }
        }
        if (!found)
        {
            throw InvalidQueryException("Invalid column name " + gb.columnName + " in group by.");
        }
    }
    //do group by if needed
    result->groupData(colsToGroupBy);
    if(allColumns && queryNode.functionsOnColumns.size() &&
       queryNode.functionsOnColumns.begin()->fullFunctionString == "count(*)"){
        return performCountStar(*result);
    }
    for(const auto & rs: this->queryNode.resultColumns){
        if(rs.mathOperation.size()){
            applyMathExpr(rs, result, resultColInfo);
        }
    }
    vector<size_t> colPositionsToPrint;
    if(allColumns && queryNode.functionsOnColumns.empty()){
        for (size_t i = 0; i < resultColInfo.size(); i++)
        {
            colPositionsToPrint.push_back(i);
        }
    }
    else{
        for(const auto & rs: this->queryNode.resultColumns){
            for (size_t i = 0; i < resultColInfo.size(); i++)
            {
                const auto &rci = resultColInfo[i];
                auto rescol = StringUtil::extractTableColumnNames(rci.getColumnName()).second;
                if (rescol == rs.columnName)
                {
                    colPositionsToPrint.push_back(i);
                    break;
                }
            }
        }
    }
    //hide columns not asked in results
    result->setColPositionsToPrint(colPositionsToPrint);
    //removeRedundantColumns(
    if (queryNode.functionsOnColumns.empty())
        return result;
    //now apply aggregate functions on result columns if any
    return applyAggregateFunctions(*result, colsToGroupBy, queryNode.functionsOnColumns);
    //return make_shared<model::RelationSet>(result);
}
