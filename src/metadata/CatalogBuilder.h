#pragma once

#include <string>

#include "constants/Constants.h"

namespace catalog
{
class CatalogBuilder
{
  private:
    std::string dbName;
    std::string dbDirPath;

  public:
    CatalogBuilder(const std::string &dbName, const std::string &dbDirPath) : 
      dbName(dbName), dbDirPath(dbDirPath) {}

    void buildCatalog();
};

//  const std::unordered_map<std::string, std::vector<std::string> > & getColTableMap();
//  const std::unordered_map<std::string, model::DBTableInfo> & getTableCatalog();

//  const boost::optional<data_types::DATA_TYPE> getColumnDataTypeForTable(const std::string &tblName, const std::string &colName);
}