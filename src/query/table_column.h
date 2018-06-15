#pragma once

#include <string>
#include <iostream>
#include <set>
#include <map>
#include <vector>

#include "../constants/Constants.h"

using namespace std;

class ColumnInTable
{
public:
    ColumnInTable (const std::string &tablename, const std::string &colname, int indexInTable = -1, data_types::DATA_TYPE colDataType = data_types::INT)
      : tableName(tablename), columnName(colname), colIndexInTable(indexInTable), columnDataType(colDataType) {} ;

    inline std::string getTableName() const {
        return tableName;
    }

    inline std::string getQualifiedName() const {
        return tableName + "." + columnName;
    }

    inline std::string getColumnName() const {
        return columnName;
    }

    inline int getColumnIndexInTable() const {
        return colIndexInTable;
    }

    inline void setColDataType(data_types::DATA_TYPE type) {
        columnDataType = type;
    }

    inline data_types::DATA_TYPE getColDataType() const {
        return columnDataType;
    }

    inline void setTableName(std::string tname){ 
        tableName = tname;
    }

    inline void setColumnName(std::string cname){ 
        columnName = cname;
    }
    inline void setIndexInTable(int ind) {
        colIndexInTable = ind;
    }
    bool shouldPrint() {
            return doPrint;
    }
    
    void donotPrint(){
        doPrint = false;
    }

    void print(std::ostream& stream) const;

    void setAggregationCode(constants::AGGREGATE_FN aggCode) {
        aggregationCode = aggCode;
    }
    std::string str() const;

private:
    std::string tableName;
    std::string columnName;
    constants::AGGREGATE_FN aggregationCode = constants::NO_FUN;
    int colIndexInTable;
    data_types::DATA_TYPE columnDataType;
    bool doPrint = true;
};
inline bool operator> (const ColumnInTable &c1, const ColumnInTable &c2)
{
    return c1.getTableName() > c2.getTableName() || 
            c1.getColumnName() > c2.getColumnName() || 
            c1.getColumnIndexInTable() > c2.getColumnIndexInTable() || 
            c1.getColDataType() > c2.getColDataType() ;
}
 
 inline bool operator== (const ColumnInTable &c1, const ColumnInTable &c2)
{
     return c1.getTableName() == c2.getTableName() &&
            c1.getColumnName() == c2.getColumnName() && 
            c1.getColumnIndexInTable() == c2.getColumnIndexInTable() &&
            c1.getColDataType() == c2.getColDataType() ;
}
 

inline bool operator>= (const ColumnInTable &c1, const ColumnInTable &c2)
{
        return c1.getTableName() >= c2.getTableName() || 
            c1.getColumnName() >= c2.getColumnName() || 
            c1.getColumnIndexInTable() >= c2.getColumnIndexInTable() || 
            c1.getColDataType() >= c2.getColDataType() ;
}
 
inline bool operator< (const ColumnInTable &c1, const ColumnInTable &c2)
{
       return c1.getTableName() < c2.getTableName() || 
            c1.getColumnName() < c2.getColumnName() || 
            c1.getColumnIndexInTable() < c2.getColumnIndexInTable() || 
            c1.getColDataType() < c2.getColDataType() ;
}
 
inline bool operator<= (const ColumnInTable &c1, const ColumnInTable &c2)
{
        return c1.getTableName() <= c2.getTableName() || 
            c1.getColumnName() <= c2.getColumnName() || 
            c1.getColumnIndexInTable() <= c2.getColumnIndexInTable() || 
            c1.getColDataType() <= c2.getColDataType() ;
}