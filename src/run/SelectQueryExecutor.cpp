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

model::RelationSet executor::SelectQueryExecutor::getQueryResult()
{
    //first resolve the dependencies of this query
    //now we are in a select and need to check if
    // there are subqueries of this select that need to be resolved first
    auto ctx = rootSelectCore;
    auto result_columns = ctx->result_column();
    auto where_clauses = ctx->where_clause();
    auto groups = ctx->group_clause();
    auto table_or_subqueries = ctx->table_or_subquery();
    auto joins = ctx->join_clause();
    auto expressions = ctx->expr();
    catalog::TableCatalog subqueryTableCatalog;
    RelationSet rs;
    for (auto &tsq : table_or_subqueries)
    {
        auto tsqAlias = tsq->table_alias();
        //check if its a subquery or a plain table
        auto subQ = tsq->select_core();
        if (subQ)
        { //its a subquery
            executor::SelectQueryExecutor subExec(subQ);
            auto subRS = subExec.getQueryResult();
            if (tsqAlias)
            {
                subRS.setName(tsqAlias->getText());
            }
            else
            {
                subRS.setName(tsq->table_name()->getText());
            }
            //append this result
            rs.appendColumnInfo(subRS.getColumnInfo());
            rs.appendData(subRS.getData());
        }
        else
        {
            //its a table name with possible where conditions and joins etc
            auto tname = tsq->table_name();
        }
        // auto relationPtr = c.getQueryResult();
        // catalog::TableSpec tspec(relationPtr->getRelationName() , relationPtr->getColumnInfo());
        // subqueryTableCatalog.addTableSpec(relationPtr->getRelationName(), tspec);
    }
    // auto fetches = planFetches(colNames, tblNames, subqueryTableCatalog, tblAliases);
    // //auto result =
    // auto rs = make_shared<model::RelationSet>(getNodeName());
    // for (auto toFetch : fetches)
    // {

    //     // auto path = dbCatalog.getTableDataPath(toFetch.getTableName());
    //     // csvops::CSVReader reader(path, toFetch);
    //     // auto rows = reader.getDataFromFile();
    //     // rs.appendColumnInfo(toFetch.computedColumnInfo());
    //     // rs.appendData(rows);
    // }
    return rs;
}