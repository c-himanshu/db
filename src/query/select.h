#pragma once

#include <string>
#include <iostream>
#include <set>
#include <map>
#include <vector>

#include "query/column_condition.h"


using namespace std;

class SelectQuery 
{
    private: 
        set<string> tableNames; 
        vector<ColumnInTable> columns; 
        set <ConditionColumn> conditions;
        vector<ColumnInTable> groupByCols;
        vector<ColumnInTable> columnsToAggregate;
        vector<string> aggFunctionsToApply;
        bool hasAggregations = false;
    public:
        SelectQuery(const set<string> &tables, const vector<ColumnInTable> &cols, const set<ConditionColumn> &whereClauses, const vector<ColumnInTable> &groupBys, 
        bool aggregateQuery = false) : 
        tableNames(tables), columns(cols), conditions(whereClauses), groupByCols(groupBys), 
        hasAggregations(aggregateQuery) {}
        inline  set<string> getTableNames() const { return tableNames; }
        inline  vector<ColumnInTable> getColumns() const {return columns; }
        inline  set <ConditionColumn> getConditions() const { return conditions; }
        inline  vector<ColumnInTable> getGroupByCols() const { return groupByCols; }
        inline bool hasGroupBy() const {
            return groupByCols.size() > 0;
        }
        inline bool hasWhereClauses() const {
            return conditions.size() > 0;
        }
        inline bool isMultiTable() const {
            return tableNames.size() > 0;
        }
        void setAggFunctionColumns(vector<ColumnInTable> colsToAgg){
            columnsToAggregate = colsToAgg;
        }
        void setAggFunctionNames(vector<string> aggFnNames) {
            aggFunctionsToApply = aggFnNames;
        }
        vector<ColumnInTable> getAggFunctionColumns(){
            return columnsToAggregate ;
        }
        vector<string> getAggFunctionNames() {
            return aggFunctionsToApply ;
        }
};

std::ostream& operator<< (std::ostream& stream, const  SelectQuery& SelectQuery);

std::ostream& operator<< (std::ostream& stream, const  ColumnInTable& columnInfo);