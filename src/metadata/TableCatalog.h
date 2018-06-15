#pragma once

#include <string>
#include <map>
#include <iostream>

#include <boost/optional/optional.hpp>

#include "constants/Constants.h"
#include "model/TableSpec.h"
#include "exception/NoSuchEntryException.h"

namespace catalog
{
using namespace std;
using namespace model;

class TableCatalog
{
  private:
    string dbName;
    map<string, TableSpec> tableSpecMap;

  public:
    TableCatalog(string dbName = "_UKNOWN_DBNAME_") : dbName(dbName) {}
    bool empty() const {
        return tableSpecMap.empty();
    }
    bool hasTable(const std::string &tname) const
    {
        return tableSpecMap.find(tname) != tableSpecMap.end();
    }

    void showTables() const
    {
        std::cout << "Tables in database " << dbName << std::endl;
        std::cout << "------------------------------" << std::endl;
        size_t count = 1;
        for (auto t : tableSpecMap){
            std::cout << count << ". " << t.first << std::endl;
            count++;
            
        }
        std::cout << "------------------------------" << std::endl;
    }

    boost::optional<model::ColumnSpec> getColumnSpecForTable(const std::string &colName, const std::string &tname) const
    {
        auto tableSpec = getTableSpec(tname);
        if(tableSpec) return tableSpec.get().getColumnSpec(colName);

        return boost::optional<model::ColumnSpec>{};
    }

    const boost::optional<vector<model::ColumnSpec>> getFullSpecForTable(string tableName) const
    {
        auto tsOpt = getTableSpec(tableName);
        if(tsOpt)
            return tsOpt.get().getColumnSpecs();

            return boost::optional<vector<model::ColumnSpec>>{};
    }

    void addTableSpec(const string &tname, const TableSpec &spec)
    {
        tableSpecMap.emplace(tname, spec);
    }

    string getTableDataPath(string tableName) const
    {
        auto tSpec = getTableSpec(tableName);
        if(tSpec) 
            return tSpec.get().getDataFilePath();
        
        return constants::NO_TBL_NAME;
    }

    // void addTableDescription(const string &tname, const string &desc) {
    //     tableDescripts[tname] = desc;
    // }

    const boost::optional<TableSpec> getTableSpec(const string &tname) const
    {
        if (!hasTable(tname))
        {
            //throw NoSuchEntryException(tname, false);
            return boost::optional<TableSpec>{};
        }
        return tableSpecMap.find(tname)->second;
    }

    void describeAllTables() const
    {
        for (auto tp : tableSpecMap)
        {
            tp.second.print(std::cout);
        }
    }

    void describeTables(const std::vector<std::string> &tblNames) const
    {
        for (auto t : tblNames)
        {
            if (!hasTable(t))
            {
                throw NoSuchEntryException(t, false);
            }
            tableSpecMap.find(t)->second.print(std::cout);
        }
    }
};
} // namespace catalog
