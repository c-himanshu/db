
#include "CatalogBuilder.h"

#include <fstream>
#include <iomanip>
#include <unordered_map>
#include <set>

#include <boost/filesystem.hpp>
#include <boost/algorithm/string.hpp>

#include "exception/InvalidDataTypeException.h"
#include "exception/NoSuchEntryException.h"
#include "exception/NoParamsException.h"
#include "util/Collections.h"
#include "constants/Constants.h"
#include "util/StringUtil.h"
#include "model/TableSpec.h"
#include "model/ColumnSpec.h"
#include "metadata/TableCatalog.h"
#include "metadata/DBCatalog.h"

const std::string file_type = ".csv";
const std::string default_tables_dir = "tables/";
namespace fs = ::boost::filesystem;
using namespace std;

// namespace catalog
// {
// void describeTables(std::set<std::string> tables)
// {
//     if (tables.empty())
//     {
//         throw NoParamsException(true /*no tables*/);
//     }
//     //convert table names to lower case
//     for (auto name : tables)
//     {
//         boost::to_lower(name);
//     }
//     //check if table is valid
//     auto descriptions = getTableDescriptions();
//     for (auto tableName : tables)
//     {
//         if (descriptions.find(tableName) == descriptions.end())
//             throw NoSuchEntryException(tableName);
//         //describe table
//         std::cout << "TABLE " << tableName << std::endl;
//         std::cout << "----------------------------" << std::endl;
//         std::cout << descriptions[tableName];
//         std::cout << "----------------------------" << std::endl;
//     }
// }
// } // namespace catalog
// return the filenames of all files that have the specified extension
// in the specified directory and all subdirectories
void get_all_files(const fs::path &root, const std::string &ext, std::vector<fs::path> &ret)
{
    if (!fs::exists(root) || !fs::is_directory(root))
        return;

    fs::recursive_directory_iterator it(root);
    fs::recursive_directory_iterator endit;

    while (it != endit)
    {
        if (fs::is_regular_file(*it) && it->path().extension() == ext)
            ret.push_back(it->path());
        ++it;
    }
}

data_types::DATA_TYPE getDataTypeEnum(const std::string &colTypeStr)
{
    using namespace constants;
    using namespace data_types;
    if (colTypeStr == "int")
        return data_types::INT;
    if (colTypeStr == "char")
        return CHAR;
    if (colTypeStr == "varchar50")
        return VARCHAR50;
    if (colTypeStr == "dbl")
        return DBL;

    throw InvalidDataTypeException(colTypeStr);
}

//model::TableModel getTableModel(const std::string &colInfoPath, const std::string &tableName)
model::TableSpec getTableSpec(const std::string &colInfoPath, const std::string &tableName = std::string())
{
    using namespace catalog;
    using namespace model;
    std::ifstream colInfoFile(colInfoPath);
    std::string colName, colType;
    vector<ColumnSpec> tableColumns;
    int position = 0;
    std::stringstream tblDesc;
    while (colInfoFile >> colName >> colType)
    {
        //remove carriage return
        if (!colType.empty() && colType[colType.size() - 1] == '\r')
        {
            colType.erase(colType.size() - 1);
        }
        boost::to_lower(colName);
        boost::to_lower(colType);
        auto dtype = getDataTypeEnum(colType);
        //tblDesc << std::setw(15) << std::left << colName << std::setw(15) << std::left << colType << '\n';
        tableColumns.push_back(
            ColumnSpec(colName, position, dtype));
        position++;
    }

    return TableSpec(tableName, tableColumns);
}

// int dbinfo::MetaDataCollector::collectTableInfo()
// {
//     std::vector<fs::path> filePaths;
//     std::cout << dbDirPath << std::endl;
//     get_all_files(dbDirPath + default_tables_dir, file_type, filePaths);

//     for (auto fpath : filePaths)
//     { // all the csv files would be the tdata.csv files
//         auto tablePath = fpath.parent_path();
//         auto tname = tablePath.stem().string();
//         auto model = getTableModel(tablePath.string() + "/columns.info", tname);
//         model.setDataFilePath(tablePath.string() + "/tdata.csv");
//         model::DBTableInfo tblInfo(tname, model);
//         dbinfo::tableCatalog.emplace(boost::to_lower_copy(tname), tblInfo);
//     }
//     return 0;
// }

// const std::set<std::string> &dbinfo::TableData::getTableNames()
// {
//     return tableNames;
// }

// void dbinfo::TableData::setTableNames(std::set<std::string> names)
// {
//     tableNames = names;
// }

// const boost::optional<data_types::DATA_TYPE> dbinfo::getColumnDataTypeForTable(const std::string &tblName, const std::string &colName)
// {
//     auto catalog = dbinfo::getTableCatalog(); //this is a map
//     auto modPair = catalog.find(tblName);
//     if (modPair == catalog.end())
//     {
//         throw NoSuchEntryException(tblName);
//     }
//     //found the table, get its DBTableInfo
//     auto model = modPair->second.getModel();
//     return model.getColumnType(colName); //return the type as boost optional
// }
namespace catalog
{
void CatalogBuilder::buildCatalog() 
{
    std::vector<fs::path> filePaths;
    get_all_files(dbDirPath + default_tables_dir, file_type, filePaths);
    vector<model::TableSpec> tableSpecs;
    catalog::TableCatalog tableCatalog(dbName);
    for (auto fpath : filePaths)
    { // all the csv files would be the tdata.csv files
        auto tablePath = fpath.parent_path();
        auto tname = tablePath.stem().string();
        auto tableSpec = getTableSpec(tablePath.string() + "/columns.info", tname);
        tableSpec.setDataFilePath(tablePath.string() + "/tdata.csv");
        tableCatalog.addTableSpec(tname, tableSpec);
    }
    auto dbcatalog = catalog::DBCatalog::instance();
    dbcatalog->setDBName(dbName);
    dbcatalog->setTableCatalog(tableCatalog);
}
} // namespace catalog