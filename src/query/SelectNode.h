#pragma once
#include <vector>
#include <map>
#include <memory>

#include "log/Log.h"
#include "model/ResultSet.h"
#include "metadata/DBCatalog.h"
#include "query/WhereClause.h"

using namespace std;

namespace query
{
class SelectNode
{
  protected:
    bool fetchAll = false;
    std::vector<string> tableNames;
    bool whereInited = true;
    std::vector<string> columnNames;
    string nodeName;
    std::map<string, string> tableAliases;
    std::map<string, string> collumnAliases;
    std::vector<SelectNode> children;
    model::RelationSet result;
    vector<model::RelationSet> feed;
    string queryText;
    shared_ptr<SelectNode> parentNode;
    vector<WhereClause> whereClauses;
    vector<string> groupByNames;
  public:
    SelectNode(string qText = "", bool subquery = false) : queryText(qText) {}

    void fetchAllCols()
    {
        fetchAll = true;
    }

    virtual void setNodeName(const string &name)
    {
        debug("setting nodename to "+name);
        nodeName = name;
    }

    virtual const string getNodeName()
    {
        return nodeName;
    }
    virtual void setTableNames(const std::vector<std::string> &tNames)
    {
        tableNames = tNames;
    }
    WhereClause &latestWhereClause() {
        size_t count = whereClauses.size(); 
        assert(count);
        return whereClauses[count - 1];
    }
    virtual const std::vector<std::string> &getTableNames() 
    {
        return tableNames;
    }

    virtual const std::vector<std::string> &getColumnNames() 
    {
        return columnNames;
    }

    virtual void addTableName(const std::string &name)
    {
        auto currcout = tableNames.size();
        tableNames.push_back(name);
        assert(tableNames.size() == currcout + 1);
        debug("added " + name + " to tables of node");
    }

    virtual void addColumnName(const std::string &name)
    {
        columnNames.push_back(name);
    }

    void addFetcher(model::RelationSet &rs)
    {
        feed.push_back(rs);
    }

    void setParentNode(shared_ptr<SelectNode> parent)
    {
        assert(parent);
        parentNode = parent;
    }

    shared_ptr<SelectNode> getParentNode()
    {
        return parentNode;
    }

    const std::map<string, string> &getTableAliases() const
    {
        return tableAliases;
    }
    virtual void setTableAliases(const std::map<string, string> &aliases)
    {
        tableAliases = aliases;
    }
    const string &getQueryText()
    {
        return queryText;
    }
    void printQueryText()
    {

        // if(children.empty()) {
        //     //debug("trying tablenames ");
        //     catalog::DBCatalog::instance()->describeTables(getTableNames());
        //     // catalog::DBCatalog::instance()->showTables();
        // }
        for (auto &sub : children)
        {
            sub.printQueryText();
        }
        cout << "tables in node " << getNodeName() << " (query: " << queryText << ") # ";
        for (auto &t : tableNames)
            cout << t << ", ";
        cout << std::endl;
    }

    bool hasSubqueries()
    {
        return !children.empty();
    }

    vector<SelectNode> &getSubqueries()
    {
        return children;
    }

        void printTablesAndColumns()
    {
        debug("");
        debug(nodeName+" # tables and columns");
        for(auto pair : tableAliases){
            debug(pair.first + " = "+pair.second);
        }
        for (auto t : tableNames)
            debug(t);
        for (auto t : collumnAliases)
            debug("columnAlias: "+t.first + ":"+t.second);
        for (auto t : columnNames)
            debug("column: "+t);
        
        for (auto t : whereClauses)
            debug(getNodeName()+" -> where: "+t.getTableName()+"."+t.getColumnName());
        for (auto t : groupByNames)
            debug("groupby: "+t);
        debug("---------");
    }

    void insertNewWhereClause(WhereClause &where){
        // debug("inserting where clause with oeprator "+where.getOp());
        whereClauses.push_back(where);
    }

    void addGroupByCol(string gbCol){
        groupByNames.push_back(gbCol);
    }

    void markWhereStarted() {
        whereInited = true;
    }
    bool initedWhere(){
        return whereInited;
    }

    void printTables()
    {
        debug("");
        debug(nodeName+" # tables");
        for(auto pair : tableAliases){
            debug(pair.first + " = "+pair.second);
        }
        for (auto t : tableNames)
            debug(t);
        debug("");
    }

    virtual void addChild(shared_ptr<SelectNode> childPtr)
    {
        // debug(getNodeName()+": adding subquery with name "+childPtr->getNodeName()+ "as my child" );
        children.push_back(*childPtr);
        // debug("updated children size: "+to_string(children.size()));
    }

    const shared_ptr<model::RelationSet> getQueryResult();

    virtual vector<model::ColumnSpec> presentColumnSpec()
    {
        return result.getColumnInfo();
    }

    virtual void addTableAlias(string alias, string tableName)
    {
        assert(!alias.empty() && !tableName.empty());
        //debug("adding table alias "+alias+" for tablename " +tableName);
        auto current = tableAliases.find(alias);
        if (current != tableAliases.end() && current->second != tableName)
        {
            throw InvalidQueryException("Table alias " + alias + " already assigned to table name: " + current->second);
        }
        tableAliases[alias] = tableName;
    }
    virtual void addColumnAlias(string alias, string colName)
    {
        assert(!alias.empty() && !colName.empty());
        //debug("adding table alias "+alias+" for tablename " +tableName);
        auto current = collumnAliases.find(alias);
        if (current != collumnAliases.end() && current->second != colName)
        {
            throw InvalidQueryException("Column alias " + alias + " already assigned to table name: " + current->second);
        }
        collumnAliases[alias] = colName;
    }
};
} // namespace query