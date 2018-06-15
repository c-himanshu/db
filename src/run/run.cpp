#include "run.h"

#include <iostream>
#include <string>
#include <map>
#include <unordered_map>
#include <sstream>
#include <iomanip>
#include <algorithm>

#include <boost/algorithm/string.hpp>
#include <boost/optional/optional.hpp>


#include "parser/query_parser.h"
#include "exception/NoSuchEntryException.h"
#include "exception/TableNotInQueryException.h"
#include "metadata/CatalogBuilder.h"
//#include "fileops/readcsv.h"
#include "query/column_condition.h"
#include "query/select.h"

const std::string prompt("> ");
const std::string exitString("exit");
const std::string colon(";");

void printTab()
{
    std::cout << '\t';
}

void printPrompt()
{
    std::cout << prompt;
}

void groupResults(ResultSet &rs, const vector<ColumnInTable> &colsToFetch, 
vector<ColumnInTable> groupByCols)
{
    //calculate the relative position of group by columns 
    // in the width of each row
    auto totalWidth = colsToFetch.size(); 
    vector<std::pair<size_t, data_types::DATA_TYPE>> groupByPositionAndType;
    for(auto gc : groupByCols) {
        auto iter = find(colsToFetch.begin(), colsToFetch.end(), gc);
        //we are guaranteed that the element must be found 
        //because we insert all group by cols in cols to fetch 
        // when we build the query
        auto index = std::distance(colsToFetch.begin(), iter);
        groupByPositionAndType.push_back(std::make_pair(index,gc.getColDataType()));
    }
    rs.groupResults(groupByPositionAndType);
}

size_t printResultRows(const ResultSet &rs)
{
    if(rs.empty()) return 0;
    //first print the headers
    auto cols = rs.getColumnInfo();
    std::stringstream header;
    header << "| ";
    for(auto c : cols){
        header << c.getQualifiedName() << "     |";
    }
    header << std::endl;
    auto headerStr = header.str();
    for(int i=0;i<headerStr.size();i++) { std::cout << '-';} //print header top divider
    std::cout<<std::endl;
    std::cout << headerStr; //print header names
    for(int i=0;i<headerStr.size();i++) { std::cout << '-';} //print header bot divider
    std::cout<<std::endl;
    //now print rows
    size_t count = 0;
    for (auto r : rs.getRows())
    {
        // for(auto c : r.)
        // std::cout << "tjos of bizarre";
        std::cout << r << std::endl;
        count++;
        if (count == constants::MAX_ROWS_TO_PRINT)
            break;
        //std::cout << "--------- " << std::endl;
    }
    //for(int i=0;i<headerStr.size();i++) { std::cout << '-';} //print table bot line
    std::cout<<std::endl;
    return count;
}
vector<ColumnInTable> colsToFetchForTable(const string &tableName,
const vector<ColumnInTable> & colsToFetch) {
    vector<ColumnInTable> result;
    for(auto c : colsToFetch) {
        if(tableName == c.getTableName()) {
            result.push_back(c);
        }
    }
    return result;
}

set<ConditionColumn> conditionsForTable(const string &tableName,
const set<ConditionColumn> &conditions) {
    set<ConditionColumn> result;
    for(auto c : conditions) {
        if(tableName == c.getTableName()) {
            result.insert(c);
        }
    }
    return result;
}

void execSelectQuery(const SelectQuery &query)
{
    using namespace std;
    auto tableCatalog = dbinfo::getTableCatalog();
    size_t rowCount = 0;
    size_t printedCount = 0;
    auto colsToFetch = query.getColumns();
    auto hasGroupBy = query.hasGroupBy();
    auto queryConditions = query.getConditions();
    for (auto tableName : query.getTableNames())
    {
        csvops::CSVReader reader(tableCatalog.find(tableName)->second.getModel().getDataFilePath());
        auto tblColstoFetch = colsToFetchForTable(tableName, colsToFetch);
        auto tblConditions = conditionsForTable(tableName, queryConditions);
        ResultSet rs = reader.readColsFromFile(tblColstoFetch, tblConditions);
        if (!rs.empty())
        {
            //now perform grouping if needed
            if (hasGroupBy)
            {
                groupResults(rs, colsToFetch, query.getGroupByCols());
            }
            //perform aggregations

            printedCount = printResultRows(rs);
            rowCount = rs.size();
        }
    }
    std::cout << rowCount << " rows in set.";
    if (rowCount && (printedCount < rowCount))
    {
        std::cout << " Printed " << constants::MAX_ROWS_TO_PRINT << " rows.";
    }
    std::cout << std::endl;
}
void validateAndRunQuery(const std::string &query)
{
    try
    {
        boost::optional<SelectQuery> sq = sqlparser::parseQuery(query);
        if (sq)
        {
            auto selectQuery = sq.get();
            //std::cout << selectQuery << std::endl;
            //now we have a query to run, lets execute it
            execSelectQuery(selectQuery);
        }
    }
    catch (InvalidQueryException ex)
    {
        std::cout << ex.what() << std::endl;
    }
    printPrompt();
}

int main()
{
    using namespace dbinfo;
    MetaDataCollector meta("/Users/hchauhan/code/dbexercise/data/salesdb/", "sales");
    //this is a pair: first entry is the map of tablename -> TableModel
    //second entry is the reverse catalog that maps: columnName -> tableNames
    int worked = meta.collectTableInfo();
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
            input.str(std::string()); // clear the stream for next query
            input.clear();
            validateAndRunQuery(qstring);
        }
        else
        { //in same query as above line, print tab for readability
            printTab();
        }
    }
    return 0;
}
