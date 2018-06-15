#pragma once; 

#include <vector>
#include <string>

class SingleTableSelectNode 
{
    private: 
        string tableName;
        vector<size_t> columnPositions;
        vector<string> whereClauses;
    SingleTableSelectNode(string tname);
};