#pragma once

#include "grammar/LogicalQueryNode.h";
#include "model/RelationalTable.h"

using namespace std;
using namespace model;
class PhysicalQueryNode
{
    static size_t nodeCount;

  private:
    string nodeName;
    RelationSet myResults;
    vector<RelationalTable> tables;
    vector<FetchSpec> allFetches;
    vector<PhysicalQueryNode> children;

  public:
    PhysicalQueryNode() {}

    PhysicalQueryNode(const LogicalQueryNode &logicalQuery)
    {
        constructSelfFromLogicalQuery(logicalQuery);
    }
    void addChild(PhysicalQueryNode &node)
    {
        this->children.push_back(node);
    }

    void populateTables(const vector<DataSource> &dsources)
    {
        for (const auto &ltbl : dsources)
        {
            RelationalTable tbl(ltbl.name);
            tables.push_back(tbl);
        }
    }

    boost::optional<string> getRealTableNameForColumn(const ResultColumn &resCol, const vector<DataSource> &dsources)
    {
        auto givenTableName = resCol.tableName;
        for (const auto &t : dsources)
        {
            if (t.name == givenTableName || t.alias == givenTableName)
                return t.name;
        }
        return boost::optional<string>{};
    }
    void populateResultColumns(const vector<ResultColumn> &resCols, const vector<DataSource> &dsources)
    {
        for (const auto &rc : resCols)
        {
            auto tname = getRealTableNameForColumn(rc, dsources);
        }
    }

    void constructSelfFromLogicalQuery(const LogicalQueryNode &lnode)
    {
        nodeName = lnode.name;
        if (nodeName.empty())
        {
            ++nodeCount;
            nodeName = "_pq_unnamed_node_" + to_string(nodeCount);
        }

        //go over each result column
    }
}