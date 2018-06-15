#pragma once

#include "grammar/ResultColumn.h"
#include "grammar/TableInQuery.h"
#include "grammar/GroupByColumn.h"
#include "query/WhereClause.h"
#include "grammar/JoinCondition.h"

#include "grammar/FunctionOnColumn.h"

#include <vector>
#include <sstream>
using namespace std;

class LogicalQueryNode
{
public:
  bool inResultCol;
  bool inFromTable;
  bool inSubQuery;
  bool inJoinClause;
  bool inJoinOperator;
  bool inJoinConstraint;
  bool inWhere;
  bool inAndWhere; 
  bool inOrWhere; 
  bool inGroupBy;
bool inColMathExpr; 
    bool nextTableIsRightTable;
    bool starGiven = false;
  string name;
  vector<DataSource> datasources;
vector<DataSource> joinTables;
  vector<ResultColumn> resultColumns;
  //vector<JoinColumn> joinColumns;
  vector<WhereClause> whereConditionsAnd;
  vector<WhereClause> whereConditionsOr;
  vector<GroupByColumn> groupByColumns;
  vector<LogicalQueryNode> children;
  vector<FunctionOnColumn> functionsOnColumns;
  vector<JoinCondition> joins;
    size_t currentJoinNum;
    vector<ResultColumn> colsFromChildren;
    vector<WhereClause> whereOnChildren;
    vector<GroupByColumn> groupByOnChildren;
    
    vector<DataSource> getDataSources() const{
        return datasources;
    }
  void addChild(LogicalQueryNode &node)
  {
    this->children.push_back(node);
  }

  size_t whereCount() {
    return whereConditionsAnd.size() + whereConditionsOr.size();
  }
  string str() const
  {

    stringstream ss;
    ss << "--- node: " << name << " # ";
    if (datasources.size())
    {
      ss << "datasources: ";
      for (const auto &t : this->datasources)
      {
        ss << t.str() << " ";
      }
      ss << std::endl;
    }
    if (resultColumns.size())
    {
      ss << "columns: ";
      for (const auto &t : this->resultColumns)
      {
        ss << t.str() << " ";
      }
      ss << "--------------" << std::endl;
    }
    if (whereConditionsAnd.size())
    {
      ss << "where: ";
      for (const auto &t : this->whereConditionsAnd)
      {
        ss << t.str() << " ";
      }
      ss << "--------------" << std::endl;
    }

    if (groupByColumns.size())
    {
      ss << "groupBy: ";
      for (const auto &t : this->groupByColumns)
      {
        ss << t.str() << " ";
      }
      ss << "--------------" << std::endl;
    }
    return ss.str();
  }
};
