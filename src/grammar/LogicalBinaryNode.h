#pragma once 
#include <string>

using namespace std;
class LogicalBinaryNode {
    public: 
    string operation; 
    string columnName; 
    string tableName;
    string value; 
    shared_ptr<LogicalBinaryNode> left;
    shared_ptr<LogicalBinaryNode> right; 
};