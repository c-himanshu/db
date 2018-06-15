#pragma once 
#include <string> 
using namespace std;
class GroupByColumn {
    public: 
    string tableName; 
    string columnName; 
    
    string str() const {
        if(tableName.empty())
            return columnName;
        
            return tableName+"."+columnName ;
    }
}; 