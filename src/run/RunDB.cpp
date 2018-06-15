

#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <sstream>
#include <iomanip>
#include <algorithm>

#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/split.hpp>

#include "exception/InvalidQueryException.h"
#include "exception/RuntimeException.h"
#include "metadata/CatalogBuilder.h"
#include "grammar/SqlParser.h"
#include "parser/QueryParser.h"
#include "run/SelectQueryExecutor.h"
#include "query/SelectNode.h"
#include "log/Log.h"
#include "query/QueryExecutor.h"

//#include "fileops/readcsv.h"

const std::string prompt("> ");
const std::string exitString("exit");
const std::string colon(";");

void printTab()
{
    std::cout << "    ->";
}

void printPrompt()
{
    std::cout << prompt;
}

void printData(const LogicalQueryNode &logicalQueryNode){
    debug("----------------------");
    debug("result cols: ");
    for(const auto &rc : logicalQueryNode.resultColumns){
        std::cout << rc.str() << std::endl;
    }
    debug("----------------------");
    debug("where cols: ");
    for(const auto &rc : logicalQueryNode.whereConditionsAnd){
        std::cout << rc.str() << std::endl;
    }
    debug("----------------------");
    debug("join cols: ");
    for(const auto &rc : logicalQueryNode.joins){
        std::cout << rc.str() << std::endl;
    }
    debug("----------------------");
    debug("group by cols: ");
    for(const auto &rc : logicalQueryNode.groupByColumns){
        std::cout << rc.str() << std::endl;
    }
    debug("----------------------");
    debug("tables: ");
    for(auto rc : logicalQueryNode.getDataSources()){
        std::cout << rc.str() << std::endl;
    }
}
void validateAndRunQuery(string queryStr)
{
    try
    {
        parser::QueryParser qp(queryStr);
        const auto logicalQueryNode = qp.parseQuery();
//        for(const auto c : logicalQueryNode->children){
//            printData(c);
//        }
//        printData(*logicalQueryNode);
        QueryExecutor executor(*logicalQueryNode);
        auto rs = executor.getResult();
        rs->print();
    }
    catch (InvalidQueryException ex)
    {
        std::cout << ex.what() << std::endl;
    }
}
bool isShowTables(std::string qstring)
{
    boost::trim(qstring);
    boost::to_lower(qstring);
    boost::erase_all(qstring, " ");
    return "showtables;" == qstring;
}

bool isDescribeTable(std::string qstring)
{
    boost::trim(qstring);
    boost::to_lower(qstring);
    return boost::starts_with(qstring, "describe ");
}

void describeTables(shared_ptr<catalog::DBCatalog> catalog, std::string qstring)
{
    boost::trim(qstring);
    boost::to_lower(qstring);
    //remove semi colon if present
    if (qstring.back() == ';')
    {
        boost::erase_last(qstring, ";");
    }
    boost::erase_first(qstring, "describe ");
    boost::erase_all(qstring, " ");
    std::vector<std::string> tblNames;
    boost::algorithm::split(tblNames, qstring,
                            boost::is_any_of(constants::DELIMITER));
    catalog->describeTables(tblNames);
}

int main()
{
    using namespace catalog;
    CatalogBuilder catalogBuilder("sales", "/Users/hchauhan/code/dbexercise/data/sales/");
    //this is a pair: first entry is the map of tablename -> TableModel
    //second entry is the reverse catalog that maps: columnName -> tableNames
    catalogBuilder.buildCatalog();
    //get the instance of the catalog
    auto dbCatalog = DBCatalog::instance();
    //dbCatalog->showTables();
    //dbCatalog->describeAllTables();

    //util::StringUtil::print_container(tableData.getTableNames(), "dbtables: ");
    printPrompt();
    std::stringstream input;
    for (std::string line; std::getline(std::cin, line) && exitString != line;)
    {
        input << line;
        if (exitString == boost::to_lower_copy(line))
        { //exit typed
            return 0;
        }
        if (boost::contains(line, colon))
        { // got a semi colon, process full query
            std::string qstring = input.str();
            if (isShowTables(qstring))
            { //show tables and return
                dbCatalog->showTables();
            }
            else if (isDescribeTable(qstring))
            {
                describeTables(dbCatalog, qstring);
            }
            else
            {
                validateAndRunQuery(qstring);
            }
            input.str(std::string()); // clear the stream for next query
            input.clear();
            printPrompt();
        }
        else
        { //in same query as above line, print tab for readability
            printTab();
        }
    }
    return 0;
}
