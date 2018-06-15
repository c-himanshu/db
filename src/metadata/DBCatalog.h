#pragma once

#include <string>
#include <vector>
#include <set>
#include <iostream>
#include <memory>

#include <boost/optional/optional.hpp>

#include "constants/Constants.h"
#include "metadata/TableCatalog.h"
#include "metadata/CatalogBuilder.h"

namespace catalog
{
using namespace std;

class CatalogBuilder;
class DBCatalog
{
    friend class catalog::CatalogBuilder;

  private:
    bool instanceCreated = false;
    std::string dbName;
    catalog::TableCatalog tableCatalog;
    void setTableCatalog(const catalog::TableCatalog tCatalog) {
        tableCatalog = tCatalog;
    }

    void setDBName(const string &name ) {
        dbName = name;
    }

  public:
    DBCatalog(string name): dbName(name) {}
    static shared_ptr<DBCatalog> instance(string name = constants::NO_DB_NAME);
    
    bool hasTable(const std::string &tname) const;

    void showTables() const;

    void describeAllTables() const;

    void describeTables(const std::vector<std::string> &tblNames) const;

    string getTableDataPath(string tableName) const;

    void addTableSpec(string tblName, const TableSpec &tspec);

    void addTableSpec(string tblName, const vector<ColumnSpec> &cinfo);

    boost::optional<model::ColumnSpec> getColumnSpecForTable(const std::string &colName, const std::string &tname) const;

    boost::optional<vector<model::ColumnSpec>> getFullSpecForTable(const std::string &tname) const;
};
} // namespace catalog