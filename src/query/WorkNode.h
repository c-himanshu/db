#pragma once

#include <string>
#include <memory>

#include "log/Log.h"

#include "model/RelationSet.h"
#include "model/ColumnSpec.h"

namespace query
{
using namespace std;
class WorkNode
{
  protected:
    std::vector<string> tableNames;
    std::vector<string> columnNames;
    bool isSelect = false;
    bool isSubquery = false;
    bool subqueryResolved = false;
    string nodeName;
    
  public:
    WorkNode(bool select = true, bool subquery = false) : isSelect(select), isSubquery(subquery), subqueryResolved(!subquery) {}
    virtual void setNodeName(const string &name) 
    {
        nodeName = name;
    }
    virtual bool isSelectNode() const
    {
        return isSelect;
    }
    virtual const string getNodeName()
    {
        return nodeName;
    }
    virtual void setTableNames(const std::vector<std::string> &tNames)
    {
        tableNames = tNames;
    }

    virtual vector<model::ColumnSpec> presentColumnSpec()
    {
        return vector<model::ColumnSpec>();
    }

    virtual const std::vector<std::string> &getTableNames() const
    {
        return tableNames;
    }

    virtual const std::vector<std::string> &getColumnNames() const
    {
        return columnNames;
    }

    virtual void addTableName(const std::string &name)
    {
        auto currcout = tableNames.size();
        tableNames.push_back(name);
        assert(tableNames.size() == currcout + 1);
        debug("added "+name +" to tables of node");
    }

    virtual void setTableAliases(const std::map<string, string> &aliases) {}

    virtual void addColumnName(const std::string &name)
    {
        columnNames.push_back(name);
    }

    virtual bool isDescribe()
    {
        return !isSelect;
    }

    virtual shared_ptr<model::RelationSet> resolve()
    {
        return make_shared<model::RelationSet>("_FIX_THIS");
    }

    virtual void addTableAlias(string, string) {}

    virtual bool isSubQuery() { return isSubquery; }
};
} // namespace query