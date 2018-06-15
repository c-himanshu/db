/*
 * RelationSet.h
 *
 *  Created on: May 18, 2018
 *      Author: hchauhan
 */

#pragma once

#include <string>
#include <vector>
#include <sstream>
#include <iomanip>
#include <boost/optional/optional.hpp>

#include "model/ColumnSpec.h"
#include "model/DataRow.h"
#include "constants/Constants.h"
#include "util/Comparisons.h"
#include "util/Collections.h"
#include "query/FetchSpec.h"
#include "grammar/ResultColumn.h"
#include "exception/ExecutionException.h"
namespace model
{
using namespace std;
class RelationSet
{
  private:
    string name;
    vector<model::ColumnSpec> columnInfo;
    vector<model::DataRow> data;
    vector<size_t> positionsToPrint;
    protected: 
        bool isTable = false;

  public:
    RelationSet(string rname = "_NO_NAME_", bool table = false) : name(rname), isTable(table) {}
    // RelationSet(string rname, vector<model::ColumnSpec> colInfo =
    // vector<model::ColumnSpec>()): name(rname), columnInfo(colInfo) {}
    size_t getColumnCount() const
    {
        return columnInfo.size();
    }

    string getRelationName() const { return name; }
    
        void setColPositionsToPrint(vector<size_t> &colPositionsToPrint){
        positionsToPrint = colPositionsToPrint;
    }

    bool isDBTable() {
        return isTable;
    }
    void setName(string name)
    {
        this->name = name;
    }
    void setColumnInfo(const vector<model::ColumnSpec> &colInfo)
    {
        columnInfo = colInfo;
    }

    vector<string> getColumnNames() const
    {
        vector<string> colnames;
        for(const auto &cs : columnInfo){
            colnames.push_back(cs.getColumnName());
        }
        return colnames; 
    }
  
    vector<string> getQualifiedColumnNames() const
    {
        vector<string> colnames;
        for(const auto &cs : columnInfo){
            colnames.push_back(cs.getColumnName());
        }
        return colnames;
    }
    vector<model::ColumnSpec> &getColumnInfo()
    {
        return columnInfo;
    }
    
    vector<model::ColumnSpec> getColumnInfoCopy()
    {
        return columnInfo;
    }
    
    vector<model::DataRow> getData()
    {
        return data;
    }

    const model::DataRow getFirstMatchingRow(size_t colPos, std::string colVal){
        
        for(auto d : data){
            if(d[colPos] == colVal) return d;
        }
        return model::DataRow();
    }
    vector<model::DataRow> &getDataAsReference()
    {
        return data;
    }

    model::DataRow &lastRowReference()
    {
        assert(data.size());
        return data[data.size() - 1];
    }
    
    void createFromRelationSet(model::RelationSet &relation)
    {
        this->setColumnInfo(relation.getColumnInfo());
        this->data = relation.getData();
    }

bool matchesColumnValue(const std::string &token,
		const std::string &asked, const constants::COMPARE_OP &operation, 
		const data_types::DATA_TYPE &colDataType) {
			using namespace util;
	switch (colDataType) {
	case data_types::INT:
		return compare(std::stoi(token), operation, std::stoi(asked));
	case data_types::VARCHAR50:
		//first remove the ' from the start and end of asked string
		return compare(token, operation, (asked.substr(1, asked.size() - 2)));
	case data_types::DBL:
		return compare(std::stod(token), operation, std::stod(asked));
	case data_types::CHAR:
		//just check first chars
		return compare(token[0], operation, asked[0]);
	default:
		throw QueryRuntimeException("Unknown datatype for: " + asked);
	}
}

bool matchesAllClauses(const DataRow &row,
		   query::FetchSpec &spec) { 
		//const std::vector<size_t> &wherePositions,
		//const std::vector<std::string> &whereMatchVals, 
		//const std::vector<constants::COMPARE_OP> &matchOps) {
	// we are assuming here that all clauses must be met, that is: no OR : TODO - fix for OR
	auto &positions = spec.getWherePositions();

	for (size_t index = 0; index < positions.size(); index++){
		//see if we are looking at the column required in the clause
		size_t colPos = positions[index];
		if (!matchesColumnValue(row[colPos], spec.getWhereValues()[index], 
					spec.getCompareOps()[index], spec.getWhereDataTypes()[index]))
			return false;
	}
	return true;
}

    shared_ptr<model::RelationSet> getData(query::FetchSpec &fetchSpec) {
       if(data.empty()){
           throw InvalidQueryException("No data to fetch in relation "+name);
       }
        model::RelationSet result; 
        vector<model::DataRow> rowsToAdd; 
        for(const auto &row : data){
            if(matchesAllClauses(row, fetchSpec)){
                std::vector<std::string> projectedData;
                for(auto pos : fetchSpec.getColPositions()) {
                    projectedData.push_back(row[pos]);
                }
                rowsToAdd.push_back(projectedData);
            }
        }
        result.appendColumnInfo(fetchSpec.computedColumnInfo());
        result.appendData(rowsToAdd);
        return make_shared<RelationSet>(result);
    }

    void generateColumnInfoFromNames(const std::vector<string> &names)
    {
        if (!columnInfo.empty())
            throw ExecutionException("Cannot replace existing columns in RelationSet");
        size_t pos = 0;
        for (auto cn : names)
        {
            columnInfo.push_back(ColumnSpec(cn, pos)); //we are not setting the correct data type here yet
            pos++;
        }
    }

    void appendColumnInfoFromNames(const std::vector<string> &names)
    {
        size_t pos = 0;
        for (auto cn : names)
        {
            columnInfo.push_back(ColumnSpec(cn, pos)); //we are not setting the correct data type here yet
            pos++;
        }
    }

    void appendColumnInfo(const vector<model::ColumnSpec> &colInfo)
    {
        if(colInfo.empty()) return;
        size_t pos = columnInfo.size();
        for (auto ci : colInfo)
        {
            //set correct position in local context
            ci.setColumnPosition(pos);
            columnInfo.push_back(ci);
            pos++;
        }
    }

    void overwriteColumnInfo(const vector<model::ColumnSpec> &colInfo)
    {
        if(colInfo.empty()) return;
        this->columnInfo = colInfo;
    }

    void appendSingleRow(const model::DataRow &drow)
    {
        if(!drow.size()) return;
        assert(this->getColumnCount() == drow.size());
        data.push_back(drow);
    }

    void updateColumnValue(const model::ColumnSpec &colSpec, std::string value){
        for(auto &row : data){
            row.setValue(colSpec.getColumnPosition(), value);
        }
    }

    void updateColumnValue(size_t pos, std::string value){
        for(auto &row : data){
            row.setValue(pos, value);
        }
    }

    void updateLastRowColumnValue(size_t pos, std::string value){
        assert(data.size());
        data[data.size() - 1].setValue(pos, value);
    }

    void updateRowColumnValue(size_t rowIndex, size_t pos, std::string value){
        assert(data.size());
        data[rowIndex].setValue(pos, value);
    }

    std::string getRowColumnValue(size_t rowIndex, size_t pos) const {
        assert(data.size());
        return data[rowIndex][pos];
    }
    void joinWithRelationSet(model::RelationSet &other, std::string joinConstraint){
        auto otherName = other.name;
        //if(joinConstraint)
    }
    void appendData(const vector<model::DataRow> &dRows, bool cross = true)
    {
        if (dRows.empty())
            return;
        
        //assert(getColumnCount() == (dRows[0].size() + currWidth));
        if (data.empty())
        { //no pre-existing data, append the rows that were given to us
            data = dRows;
            return;
        }
        if(cross){
        //being here means we already have some data of our own, then do cross product
        vector<model::DataRow> newData; //we create these many rows myRowCount * otherRowCount
        for (auto &myrow : data)
        {
            for (auto &otherRow : dRows)
            {
                vector<string> newRow;
                for (auto entry : myrow.getEntries())
                {
                    newRow.push_back(entry);
                }
                for (auto otherEntry : otherRow.getEntries())
                {
                    newRow.push_back(otherEntry);
                }
                newData.push_back(model::DataRow(newRow));
            }
        }
            data = newData;
            return;
        }
        //we want to do a side by side glueing of data:
        assert(data.size() == dRows.size());
        size_t index = 0;
            for (auto &otherRow : dRows)
            {
                for (auto otherEntry : otherRow.getEntries())
                {
                    data[index].push_back(otherEntry);
                }
            }
    }
    
    size_t size() const 
    {
        return data.size();
    }
    boost::optional<data_types::DATA_TYPE> getColumnType(const std::string &colName) const;
    boost::optional<size_t> getColumnPosition(const std::string &colName) const;
    void printSeparatorRow(size_t width)
    {
        if (width < 2)
            width = 2; //ensure no underflow for size_t subtraction
        std::cout << "+";
        for (int i = 0; i < width - 2; i++)
        {
            std::cout << '-';
        }
        std::cout << "+" << std::endl;
    }
    void print()
    {
        if (data.empty())
        {
            std::cout << "0 rows in set." << std::endl;
            return;
        }
        auto datasize = data.size();
        //first print the headers
        auto cols = getColumnInfo();
        std::stringstream header;
        //find max widths for each column
        vector<size_t> colWidths(cols.size());
        auto limit = constants::MAX_ROWS_TO_PRINT < datasize ? constants::MAX_ROWS_TO_PRINT : datasize;
        for (size_t dataIndex = 0; dataIndex < limit; dataIndex++)
        {
            auto rowEntries = data[dataIndex].getEntries();
            for (size_t i = 0; i < rowEntries.size(); i++)
            {
                //if(positionsToPrint.size() && util::Collections::containerHasValue(positionsToPrint, i)){
                if (colWidths[i] < rowEntries[i].size())
                {
                    colWidths[i] = rowEntries[i].size();
                    // std::cout << "set width to " << colWidths[i] << " due to " << rowEntries[i] << rowEntries[i].size() << std::endl;
                }
                //}
            }
        }
        //now go over column names to check the widths
        for (size_t i = 0; i < colWidths.size(); i++)
        {
            //if(positionsToPrint.size() && util::Collections::containerHasValue(positionsToPrint, i)){
            if (colWidths[i] < cols[i].getColumnName().size())
            {
                colWidths[i] = cols[i].getColumnName().size();
                // std::cout << "set width to " << colWidths[i] << " due to " << cols[i].getColumnName() << cols[i].getColumnName().size() << std::endl;
            }
        }
        size_t i = 0;
        header << "|";
        for (; i < cols.size() - 1; i++)
        {
            if(positionsToPrint.empty() || util::Collections::containerHasValue(positionsToPrint, i)){
                header << std::setw(colWidths[i]) << std::left << cols[i].getColumnName() << " | ";
            }
        }
        //now add the last one
        if(positionsToPrint.empty() || util::Collections::containerHasValue(positionsToPrint, i)){
            header << std::setw(colWidths[i]) << std::left << cols[i].getColumnName() << " |";
        }
        auto headerStr = header.str();

        printSeparatorRow(headerStr.size());
        std::cout << headerStr << std::endl; //print header names
        printSeparatorRow(headerStr.size());

        //now print rows
        i = 0;
        for (; i < limit; i++)
        {
                data[i].print(std::cout, colWidths, positionsToPrint);
        }
        printSeparatorRow(headerStr.size());
        std::cout << datasize << " rows in set.";
        if (limit < datasize)
        {
            std::cout << " Printed top " << limit << " rows.";
        }
        //for(int i=0;i<headerStr.size();i++) { std::cout << '-';} //print table bot line
        std::cout << std::endl;
        //first print header
    }
    
    void removeWhereColValueDifferent(size_t colPos, const std::set<std::string> &acceptVals){
        for (auto i = data.begin(); i != data.end();)
    {
        // auto added = addWhereToFetchIfFounInColumnInfo(fetch, *i, columnInfo);
        auto &drow = *i;
        if(util::Collections::containerHasValue(acceptVals, drow[colPos])){
            ++i;
        }
        else
        {
            data.erase(i);
        }
    }
    }
    void groupData(const vector<model::ColumnSpec> &groupByColumns) 
    {
        if(groupByColumns.empty()) return;
        //std::cout<< "width of rows: " << rows[0].size() << std::endl;
        stable_sort(data.begin(), data.end(), [groupByColumns](const auto &left, const auto &right) {
            for (auto &colSpec : groupByColumns)
            {
                //std::cout<< "sorting by: " << v << std::endl;
                auto v = colSpec.getColumnPosition();
                auto dtype = colSpec.getColType();
                auto leftVal = left[v];
                auto rightVal = right[v];
                if (dtype == data_types::INT)
                {
                    int lhs = std::stoi(leftVal), rhs = std::stoi(rightVal);
                    if(lhs > rhs) return false;
                    if(lhs < rhs) return true;
                }
                else if (dtype == data_types::DBL)
                {
                    double lhs = std::stod(leftVal), rhs = std::stod(rightVal);
                    if(lhs > rhs) return false;
                    if(lhs < rhs) return true;
                }
                //if we are here then its neither int or double
                if (left[v] < right[v])
                    return true;
                if (left[v] > right[v])
                    return false;
            }
            return false;
        });
        //}
    } 
};
} // namespace model
