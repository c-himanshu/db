#pragma once 
#include <string> 
using namespace std;
class ResultColumn {
    public: 
    string tableName; 
    string columnName; 
    string columnAlias;
    string mathOperation; 
    string str() const {
        if(tableName.empty() && columnAlias.empty())
            return columnName;
        if(!tableName.empty() && !columnAlias.empty())
            return tableName+"."+columnName +" ("+columnAlias+")";
        if(!tableName.empty())
            return tableName+"."+columnName ;
        if(!columnAlias.empty())
            return columnName +" ("+columnAlias+")";

        return "_NO_COLUMN_NAME";
    }
}; 
