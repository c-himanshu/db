#pragma once

#include "grammar/LogicalQueryNode.h"
#include "model/RelationSet.h"
#include "model/ColumnSpec.h"

class QueryExecutor
{
  private:
    LogicalQueryNode queryNode;
    vector<model::ColumnSpec> groupBys; 
  public:
    QueryExecutor(const LogicalQueryNode qNode) : queryNode(qNode) {}
    shared_ptr<model::RelationSet> getResult();
    shared_ptr<model::RelationSet> getLocalTableResults();
    shared_ptr<model::RelationSet> getLocalTableResults(vector<ResultColumn> &colsFromChildren,
                                                        vector<WhereClause> &whereOnChildren,
                                                        vector<GroupByColumn> &groupByOnChildren);
};
