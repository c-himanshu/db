#pragma once

#include <string>
#include <vector>
#include <set>

#include "constants/Constants.h"

namespace query
{
    using namespace std;
class QueryNode
{
  private:
    vector<string> columns;
    vector<string> tables;
    //set<ConditionColumn> whereClauses;
    vector<string> groupBys;
    vector<string> wheres;
    vector<string> functions;
    size_t depth;
    vector<QueryNode> children;
    
  public:
    QueryNode(size_t d) : depth(d) {}
    void addColumn(string colName) { 
        columns.push_back(colName);
    }

    void addTable(string tname){
        tables.push_back(tname);
    }
    bool empty() { 
        return tables.empty();
    }
    void print() const {
        string space = "";
        for(size_t i = 0; i < depth;i++){
            space += " ";
        }
        std::cout << endl;
        
        std::cout << space << "Query" << depth << std::endl;
        if(!columns.empty()) std::cout << "Cols: ";
        for(auto t : columns){
            std::cout << space << " " << t;
        }
        if(!columns.empty()) cout << std::endl;
        if(!tables.empty()) cout << "Tables: ";
        for(auto t : tables){
            std::cout << space << " " << t ;
        }
        if(!tables.empty()) cout << endl;
    }
};
} // namespace query