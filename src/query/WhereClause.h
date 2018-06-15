#pragma once

#include <string>
#include <vector>

#include "constants/Constants.h"

using namespace std;
class WhereClause
{
  private:
    string columnName;
    string op;
    string value;
    string tableName;

  public:
    WhereClause(string colName = constants::NO_COLNAME, string op = constants::NO_OP,
                string value = constants::NO_VALUE) : columnName(colName), op(op), value(value) {}

    string getColumnName() const
    {
        return columnName;
    }
    string getOp() const
    {
        return op;
    }
    string getValue() const
    {
        return value;
    }
    string getTableName() const
    {
        return tableName;
    }
    void setTableName(string tname)
    {
        tableName = tname;
    }
    void setColumnName(string name)
    {
        columnName = name;
    }
    void setOp(string oper)
    {
        op = oper;
    }
    void setValue(string val)
    {
        value = val;
    }

    string str() const {
        string answer("");
        if(!tableName.empty()) answer += (tableName+".");
        answer += columnName;
        answer += op; 
        answer += value;

        return answer;
    }
};