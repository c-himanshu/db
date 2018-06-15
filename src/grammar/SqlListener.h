
// Generated from Sql.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "SqlParser.h"


/**
 * This interface defines an abstract listener for a parse tree produced by SqlParser.
 */
class  SqlListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterParse(SqlParser::ParseContext *ctx) = 0;
  virtual void exitParse(SqlParser::ParseContext *ctx) = 0;

  virtual void enterExpr(SqlParser::ExprContext *ctx) = 0;
  virtual void exitExpr(SqlParser::ExprContext *ctx) = 0;

  virtual void enterExprLiter(SqlParser::ExprLiterContext *ctx) = 0;
  virtual void exitExprLiter(SqlParser::ExprLiterContext *ctx) = 0;

  virtual void enterExprFunc(SqlParser::ExprFuncContext *ctx) = 0;
  virtual void exitExprFunc(SqlParser::ExprFuncContext *ctx) = 0;

  virtual void enterExprCol(SqlParser::ExprColContext *ctx) = 0;
  virtual void exitExprCol(SqlParser::ExprColContext *ctx) = 0;

  virtual void enterExprParen(SqlParser::ExprParenContext *ctx) = 0;
  virtual void exitExprParen(SqlParser::ExprParenContext *ctx) = 0;

  virtual void enterExprOr(SqlParser::ExprOrContext *ctx) = 0;
  virtual void exitExprOr(SqlParser::ExprOrContext *ctx) = 0;

  virtual void enterExprBind(SqlParser::ExprBindContext *ctx) = 0;
  virtual void exitExprBind(SqlParser::ExprBindContext *ctx) = 0;

  virtual void enterExprCompareOp(SqlParser::ExprCompareOpContext *ctx) = 0;
  virtual void exitExprCompareOp(SqlParser::ExprCompareOpContext *ctx) = 0;

  virtual void enterExprBinaryMathOp(SqlParser::ExprBinaryMathOpContext *ctx) = 0;
  virtual void exitExprBinaryMathOp(SqlParser::ExprBinaryMathOpContext *ctx) = 0;

  virtual void enterExprAnd(SqlParser::ExprAndContext *ctx) = 0;
  virtual void exitExprAnd(SqlParser::ExprAndContext *ctx) = 0;

  virtual void enterResult_column(SqlParser::Result_columnContext *ctx) = 0;
  virtual void exitResult_column(SqlParser::Result_columnContext *ctx) = 0;

  virtual void enterTable_or_subquery(SqlParser::Table_or_subqueryContext *ctx) = 0;
  virtual void exitTable_or_subquery(SqlParser::Table_or_subqueryContext *ctx) = 0;

  virtual void enterJoin_clause(SqlParser::Join_clauseContext *ctx) = 0;
  virtual void exitJoin_clause(SqlParser::Join_clauseContext *ctx) = 0;

  virtual void enterJoin_operator(SqlParser::Join_operatorContext *ctx) = 0;
  virtual void exitJoin_operator(SqlParser::Join_operatorContext *ctx) = 0;

  virtual void enterJoin_constraint(SqlParser::Join_constraintContext *ctx) = 0;
  virtual void exitJoin_constraint(SqlParser::Join_constraintContext *ctx) = 0;

  virtual void enterSelect_core(SqlParser::Select_coreContext *ctx) = 0;
  virtual void exitSelect_core(SqlParser::Select_coreContext *ctx) = 0;

  virtual void enterWhere_clause(SqlParser::Where_clauseContext *ctx) = 0;
  virtual void exitWhere_clause(SqlParser::Where_clauseContext *ctx) = 0;

  virtual void enterGroup_by_clause(SqlParser::Group_by_clauseContext *ctx) = 0;
  virtual void exitGroup_by_clause(SqlParser::Group_by_clauseContext *ctx) = 0;

  virtual void enterSigned_number(SqlParser::Signed_numberContext *ctx) = 0;
  virtual void exitSigned_number(SqlParser::Signed_numberContext *ctx) = 0;

  virtual void enterLiteral_value(SqlParser::Literal_valueContext *ctx) = 0;
  virtual void exitLiteral_value(SqlParser::Literal_valueContext *ctx) = 0;

  virtual void enterUnary_operator(SqlParser::Unary_operatorContext *ctx) = 0;
  virtual void exitUnary_operator(SqlParser::Unary_operatorContext *ctx) = 0;

  virtual void enterError_message(SqlParser::Error_messageContext *ctx) = 0;
  virtual void exitError_message(SqlParser::Error_messageContext *ctx) = 0;

  virtual void enterColumn_alias(SqlParser::Column_aliasContext *ctx) = 0;
  virtual void exitColumn_alias(SqlParser::Column_aliasContext *ctx) = 0;

  virtual void enterKeyword(SqlParser::KeywordContext *ctx) = 0;
  virtual void exitKeyword(SqlParser::KeywordContext *ctx) = 0;

  virtual void enterName(SqlParser::NameContext *ctx) = 0;
  virtual void exitName(SqlParser::NameContext *ctx) = 0;

  virtual void enterFunction_name(SqlParser::Function_nameContext *ctx) = 0;
  virtual void exitFunction_name(SqlParser::Function_nameContext *ctx) = 0;

  virtual void enterDatabase_name(SqlParser::Database_nameContext *ctx) = 0;
  virtual void exitDatabase_name(SqlParser::Database_nameContext *ctx) = 0;

  virtual void enterTable_name(SqlParser::Table_nameContext *ctx) = 0;
  virtual void exitTable_name(SqlParser::Table_nameContext *ctx) = 0;

  virtual void enterTable_or_index_name(SqlParser::Table_or_index_nameContext *ctx) = 0;
  virtual void exitTable_or_index_name(SqlParser::Table_or_index_nameContext *ctx) = 0;

  virtual void enterNew_table_name(SqlParser::New_table_nameContext *ctx) = 0;
  virtual void exitNew_table_name(SqlParser::New_table_nameContext *ctx) = 0;

  virtual void enterColumn_name(SqlParser::Column_nameContext *ctx) = 0;
  virtual void exitColumn_name(SqlParser::Column_nameContext *ctx) = 0;

  virtual void enterCollation_name(SqlParser::Collation_nameContext *ctx) = 0;
  virtual void exitCollation_name(SqlParser::Collation_nameContext *ctx) = 0;

  virtual void enterForeign_table(SqlParser::Foreign_tableContext *ctx) = 0;
  virtual void exitForeign_table(SqlParser::Foreign_tableContext *ctx) = 0;

  virtual void enterIndex_name(SqlParser::Index_nameContext *ctx) = 0;
  virtual void exitIndex_name(SqlParser::Index_nameContext *ctx) = 0;

  virtual void enterTrigger_name(SqlParser::Trigger_nameContext *ctx) = 0;
  virtual void exitTrigger_name(SqlParser::Trigger_nameContext *ctx) = 0;

  virtual void enterView_name(SqlParser::View_nameContext *ctx) = 0;
  virtual void exitView_name(SqlParser::View_nameContext *ctx) = 0;

  virtual void enterModule_name(SqlParser::Module_nameContext *ctx) = 0;
  virtual void exitModule_name(SqlParser::Module_nameContext *ctx) = 0;

  virtual void enterPragma_name(SqlParser::Pragma_nameContext *ctx) = 0;
  virtual void exitPragma_name(SqlParser::Pragma_nameContext *ctx) = 0;

  virtual void enterSavepoint_name(SqlParser::Savepoint_nameContext *ctx) = 0;
  virtual void exitSavepoint_name(SqlParser::Savepoint_nameContext *ctx) = 0;

  virtual void enterTable_alias(SqlParser::Table_aliasContext *ctx) = 0;
  virtual void exitTable_alias(SqlParser::Table_aliasContext *ctx) = 0;

  virtual void enterTransaction_name(SqlParser::Transaction_nameContext *ctx) = 0;
  virtual void exitTransaction_name(SqlParser::Transaction_nameContext *ctx) = 0;

  virtual void enterAny_name(SqlParser::Any_nameContext *ctx) = 0;
  virtual void exitAny_name(SqlParser::Any_nameContext *ctx) = 0;


};

