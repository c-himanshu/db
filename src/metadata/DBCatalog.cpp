#include "DBCatalog.h"

#include <string>
#include <vector>
#include <unordered_map>

#include "boost/optional/optional.hpp"
#include "constants/Constants.h"

using namespace std;
using namespace catalog;
shared_ptr<DBCatalog> ptr;
shared_ptr<DBCatalog> catalog::DBCatalog::instance(string name)
{
    if(ptr) return ptr;
    const auto pt = make_shared<DBCatalog>(name);
    ptr = pt;
    return ptr;
}

bool catalog::DBCatalog::hasTable(const std::string &tname) const
{
    return tableCatalog.hasTable(tname);
}
void catalog::DBCatalog::showTables() const
{
    tableCatalog.showTables();
}
void catalog::DBCatalog::describeAllTables() const
{
    tableCatalog.describeAllTables();
}

void catalog::DBCatalog::describeTables(const std::vector<std::string> &tblNames) const
{
    tableCatalog.describeTables(tblNames);
}

string catalog::DBCatalog::getTableDataPath(string tableName) const
{
    return tableCatalog.getTableDataPath(tableName);
}

void catalog::DBCatalog::addTableSpec(string tblName, const TableSpec &tspec)
{
    tableCatalog.addTableSpec(tblName, tspec);
}
void catalog::DBCatalog::addTableSpec(string tblName, const vector<ColumnSpec> &cinfo)
{
    TableSpec tspec(tblName, cinfo);
    tableCatalog.addTableSpec(tblName, tspec);
}
boost::optional<model::ColumnSpec> catalog::DBCatalog::getColumnSpecForTable(const std::string &colName, const std::string &tname) const
{
    return tableCatalog.getColumnSpecForTable(colName, tname);
}

boost::optional<vector<model::ColumnSpec>> catalog::DBCatalog::getFullSpecForTable(const std::string &tname) const
{
    return tableCatalog.getFullSpecForTable(tname);
}