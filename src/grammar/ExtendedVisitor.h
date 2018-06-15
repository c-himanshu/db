
// Generated from Sql.g4 by ANTLR 4.7.1

#pragma once

#include "antlr4-runtime.h"
#include "SqlBaseVisitor.h"

#include <iostream>
#include <vector>
#include <stack>
#include <memory>
#include <map>

#include <boost/optional/optional.hpp>

#include "log/Log.h"
#include "query/QueryNode.h"
#include "query/DescribeNode.h"
#include "query/SelectNode.h"
#include "model/RelationSet.h"
#include "exception/InvalidQueryException.h"
/**
 * This class provides an empty implementation of SqlBaseVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
using namespace std;
using namespace query;
class ExtendedVisitor : public SqlBaseVisitor
{
private:
  //int queryDepth = -1;
  //vector<shared_ptr<QueryNode>> nodes;
  std::vector<string> tableNames;
  std::vector<string> columnNames;
  shared_ptr<SelectNode> root;
  stack<shared_ptr<SelectNode>> nodeStack;
  stack<string> aliasStack;
  size_t nodeCount = 0;
  //string currContext;
  shared_ptr<WorkNode> describeNode;

  shared_ptr<SelectNode> currentSelectNode()
  {
    return nodeStack.top();
  }
  /*
  void setDescribeNode(const shared_ptr<WorkNode> &node)
  {
    describeNode = node;
  }

  void setSelectNode(const shared_ptr<SelectNode> &node)
  {
    currSelNode = node;
  }

  void debugCurrentNodeDepth()
  {
    //debug("currentNode points to depth " + to_string(queryDepth));
  } */
  shared_ptr<SelectNode> createNewSelectNode(string txt = "")
  {
    // if (subquery)
    // {
    //   debug("creating node in subquery");
    //   spacing += spacing + "  ";
    // }

    auto ptr = make_shared<SelectNode>(txt);
    if (!root)
    {
      debug("switching root");
      root = ptr;
    }
    //switch parent and currne ptrs
    // if(currSelNode){
    //   debug("switching parentNode on level down");
    //   parentNode = currSelNode;
    // }
    // currSelNode = ptr;
    // if(parentNode) {
    //   currSelNode->setParentNode(parentNode);
    // }
    return ptr;
  }

  shared_ptr<WorkNode> createNewDescribeNode()
  {
    //assert(queryDepth >= 0);
    //debug("creating new node at depth "+to_string(queryDepth));
    return make_shared<DescribeNode>();
  }
  bool isDescribe = false;

public:
  SqlParser::Select_coreContext *rootSelect;
  // virtual antlrcpp::Any visitDescribe_clause(SqlParser::Describe_clauseContext *ctx) override
  // {
  //   isDescribe = true;
  //   //debug("visiting describe clause");
  //   auto ptr = createNewDescribeNode();
  //   //setDescribeNode(ptr);
  //   describeNode = ptr;
  //   return visitChildren(ctx);
  // }
  shared_ptr<SelectNode> getSelectNode()
  {
    assert(root);
    return root;
  }
  // shared_ptr<WorkNode> getDescribeNode()
  // {
  //   assert(root->isDescribe());
  //   return describeNode;
  // }
  bool isDescribeQuery() const
  {
    return isDescribe;
  }
  void addCurrentSelectCoreAsChild()
  {
    if (nodeStack.empty())
      return;
    if (nodeStack.size() == 1)
    {
      // in the top most select core
      // just pop the node and return
      nodeStack.pop();
      return;
    }
    //nodeStack size must be 2 or more now
    //current selectCore which we are about to exit
    auto curr = nodeStack.top();
    nodeStack.pop();
    if (!aliasStack.empty())
    {
      auto alias = aliasStack.top();
      curr->setNodeName(alias);
      aliasStack.pop();
    }
    //make this the child of the new node at the top
    // of the stack
    auto parent = nodeStack.top();
    parent->addChild(curr);
  }
  virtual antlrcpp::Any visitResult_column(SqlParser::Result_columnContext *ctx) override
  {
    //debug("visiting rc " + ctx->getText());
    auto res = visitChildren(ctx);
    //debug("finished rc " + ctx->getText());
    currentSelectNode()->addColumnName(ctx->getText());
    // auto aliasContext = ctx->column_alias();
    // string qualName="";
    // if(!aliasContext){
    //   qualName = ctx->getText();
    // } 
    // else
    // {
    //   auto tblName = ctx->table_name();
    //   auto cname = ctx->expr()->getText();
    //   qualName = tblName->getText() + "." + cname;
    // }
    //   currentSelectNode()->addColumnName(qualName);
    
    // if (aliasContext)
    // {
    //   currentSelectNode()->addColumnAlias(aliasContext->getText(), qualName);
    // }
    return res;
  }

  virtual antlrcpp::Any visitTable_or_subquery(SqlParser::Table_or_subqueryContext *ctx) override
  {

    auto tname = ctx->table_name();
    auto talias = ctx->table_alias();

    auto join_clauseContext = ctx->join_clause();
    auto childSelCore = ctx->select_core();
    // debug("visiting tsq "+ctx->getText());
    if (tname)
    {
      auto tntext = tname->getText();
      currentSelectNode()->addTableName(tntext);
      if (talias)
      {
        currentSelectNode()->addTableAlias(talias->getText(), tntext);
      }
    }
    else if (childSelCore)
    { //its a subquery
      if (talias)
      {
        aliasStack.push(talias->getText());
        //currentSelectNode()->setNodeName(talias->getText());
      }
      else
      {
        //generate a name and set it
        ++nodeCount;
        auto name = "node_" + to_string(nodeCount);
        aliasStack.push(name);
        //currentSelectNode()->setNodeName(name);
      }
    }
    auto res = visitChildren(ctx);
    //debug("finished tsq " + ctx->getText());
    return res;
  }
  virtual antlrcpp::Any visitJoin_clause(SqlParser::Join_clauseContext *ctx) override
  {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprBinaryOp(SqlParser::ExprBinaryOpContext *ctx) override
  {
    //debug("visiting binary op " + ctx->getText());
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprCompareOp(SqlParser::ExprCompareOpContext *ctx) override
  {
    //debug("visiting comparison op " + ctx->getText());
    WhereClause wc(ctx->left->getText(), ctx->oper->getText(), ctx->right->getText());
    currentSelectNode()->insertNewWhereClause(wc);
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGroupByColName(SqlParser::GroupByColNameContext *ctx) override
  {
    currentSelectNode()->addGroupByCol(ctx->getText());
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSelect_core(SqlParser::Select_coreContext *ctx) override
  {
    //debug("starting selectCore: " + ctx->getText());
    auto ptr = createNewSelectNode(ctx->getText());
    nodeStack.push(ptr);
    /* result_column ( ',' result_column )*
   ( K_FROM ( table_or_subquery ( ',' table_or_subquery )* | join_clause ) )?
   ( where_clause )?
   ( group_clause )? */
    //debug("pushed a new node to stack for " + ctx->getText());
    auto res = visitChildren(ctx);
    addCurrentSelectCoreAsChild();
    //debug("removed the node from stack for " + ctx->getText());
    return res;
  }
};
