#pragma once 

#include <string> 
#include "constants/Constants.h"
using namespace std;
class FunctionOnColumn {
    public: 
    string fullFunctionString;
    string functionName;
    string tableName; 
    string columnName;
    size_t positionInResult;
    data_types::DATA_TYPE colDataType;
};