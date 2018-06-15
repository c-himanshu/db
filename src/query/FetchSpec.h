#pragma once

#include <string>
#include <iostream>
#include <vector>
#include "constants/Constants.h"
#include "util/StringUtil.h"

#include "log/Log.h"
#include "model/ColumnSpec.h"

namespace query
{
    using namespace std;
    class FetchSpec
    {
        string name;
        vector<string> colNames;
        vector<std::string> displayNames;
        vector<size_t> colPos;
        vector<model::ColumnSpec> groupByCols;
        vector<data_types::DATA_TYPE> dataTypes;
        vector<data_types::DATA_TYPE> whereTypes;
        vector<size_t> wherePositions;
        vector<std::string> whereValues;
        vector<constants::COMPARE_OP> compareOps;
        string tblAlias;
        
    public:
        vector<size_t> resultColumnPositions;
        bool isJoinFetch = false;
        FetchSpec(const string &tname = constants::NO_TBL_NAME, const string colName = constants::NO_COLNAME, size_t pos = 0, data_types::DATA_TYPE dtype = data_types::VARCHAR50,
                  const string &alias = constants::NO_TBL_ALIAS_GIVEN) : name(tname)
        {
            tblAlias = alias;
        }
        const vector<model::ColumnSpec> &getGroupByCols() {
            return groupByCols;
        }
        void setTableAlias(string alias)
        {
            tblAlias = alias;
        }
        size_t columnCount() const
        {
            return colNames.size();
        }
        const vector<string> &getColumnNames()
        {
            return colNames;
        }
        
        const vector<string> getDisplayNames(){
            return displayNames;
        }
        
        const string getTableAlias() const { return tblAlias; }
        const string &getTableName() const { return name; }
        const vector<size_t> &getColPositions() const { return colPos; }
        const vector<data_types::DATA_TYPE> &getDataTypes() const { return dataTypes; }
        const vector<data_types::DATA_TYPE> &getWhereDataTypes() const { return whereTypes; }
        vector<std::string> &getWhereValues()
        {
            return whereValues;
        }
        vector<size_t> &getWherePositions()
        {
            // std::cout << "returning where positions of size " << wherePositions.size() << std::endl;
            return wherePositions;
        }
        void addToWheres(size_t pos, string value, string compareOpStr, data_types::DATA_TYPE type)
        {
            // std::cout << "adding to where positions of size " << wherePositions.size() << std::endl;
            wherePositions.push_back(pos);
            whereValues.push_back(value);
            compareOps.push_back(util::StringUtil::operationFromString(compareOpStr));
            whereTypes.push_back(type);
            // std::cout << "after adding to where positions, new size " << wherePositions.size() << std::endl;
        }
        vector<constants::COMPARE_OP> &getCompareOps()
        {
            return compareOps;
        }
        
        void addToGroupBy(model::ColumnSpec &col){
            for(const auto &gb : groupByCols){
                if(gb.getColumnPosition() == col.getColumnPosition()) return;
            }
            for(auto cp : colPos){
                if(cp == col.getColumnPosition()) return;
            }
//            for(auto wp : wherePositinos){
//                if(gb.getColumnPosition() == wp) return;
//            }
            groupByCols.push_back(col);
        }
        
        vector<model::ColumnSpec> computedColumnInfo()
        {
            vector<model::ColumnSpec> result;
            for (size_t index = 0; index < colNames.size(); index++)
            {
                //result.push_back(model::ColumnSpec(name+"."+colNames[index], index, dataTypes[index]));
                result.push_back(model::ColumnSpec(colNames[index], index, dataTypes[index]));
            }
            return result;
        }
        
        void addColumnToFetch(const model::ColumnSpec &colSpec, string displayName = constants::NO_DISPLAY_NAME)
        {
            for(auto p : colPos){
                if(p == colSpec.getColumnPosition()) return;
            }
            colNames.push_back(colSpec.getColumnName());
            colPos.push_back(colSpec.getColumnPosition());
            dataTypes.push_back(colSpec.getColType());
            if(displayName != constants::NO_DISPLAY_NAME){
                displayNames.push_back(displayName);
            }
        }
        
        void addColumnToFetch(string colName, size_t pos = 0, data_types::DATA_TYPE dtype = data_types::VARCHAR50)
        {
            for(auto p : colPos){
                if(p == pos) return;
            }
            colNames.push_back(colName);
            colPos.push_back(pos);
            dataTypes.push_back(dtype);
        }
        
//        void addFetchCondition(size_t colPos, constants::COMPARE_OP operation, string matchVal)
//        {
//
//            compareOps.push_back(operation);
//            whereValues.push_back(matchVal);
//        }
        
        void print(std::ostream &stream) const
        {
            stream << "FetchSpec: {";
            stream << "alias=" << tblAlias << " table=" << name << " cols: {";
            size_t ind = 0;
            for (auto cp : colPos)
            {
                stream << cp << "[" << util::StringUtil::dataTypeAsString(dataTypes[ind]) << "] ";
                ind++;
            }
            stream << "}";
        }
    };
} // namespace query

bool operator== (const query::FetchSpec &first, const query::FetchSpec &second);


