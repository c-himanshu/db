
// Generated from Sql.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "SqlVisitor.h"


/**
 * This class provides an empty implementation of SqlVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  SqlBaseVisitor : public SqlVisitor {
public:

  virtual antlrcpp::Any visitParse(SqlParser::ParseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpr(SqlParser::ExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprLiter(SqlParser::ExprLiterContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprFunc(SqlParser::ExprFuncContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprCol(SqlParser::ExprColContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprParen(SqlParser::ExprParenContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprOr(SqlParser::ExprOrContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprBind(SqlParser::ExprBindContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprCompareOp(SqlParser::ExprCompareOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprBinaryMathOp(SqlParser::ExprBinaryMathOpContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExprAnd(SqlParser::ExprAndContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitResult_column(SqlParser::Result_columnContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTable_or_subquery(SqlParser::Table_or_subqueryContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitJoin_clause(SqlParser::Join_clauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitJoin_operator(SqlParser::Join_operatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitJoin_constraint(SqlParser::Join_constraintContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSelect_core(SqlParser::Select_coreContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWhere_clause(SqlParser::Where_clauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitGroup_by_clause(SqlParser::Group_by_clauseContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSigned_number(SqlParser::Signed_numberContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitLiteral_value(SqlParser::Literal_valueContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitUnary_operator(SqlParser::Unary_operatorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitError_message(SqlParser::Error_messageContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitColumn_alias(SqlParser::Column_aliasContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitKeyword(SqlParser::KeywordContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitName(SqlParser::NameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunction_name(SqlParser::Function_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDatabase_name(SqlParser::Database_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTable_name(SqlParser::Table_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTable_or_index_name(SqlParser::Table_or_index_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitNew_table_name(SqlParser::New_table_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitColumn_name(SqlParser::Column_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCollation_name(SqlParser::Collation_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitForeign_table(SqlParser::Foreign_tableContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIndex_name(SqlParser::Index_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTrigger_name(SqlParser::Trigger_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitView_name(SqlParser::View_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitModule_name(SqlParser::Module_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitPragma_name(SqlParser::Pragma_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSavepoint_name(SqlParser::Savepoint_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTable_alias(SqlParser::Table_aliasContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTransaction_name(SqlParser::Transaction_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAny_name(SqlParser::Any_nameContext *ctx) override {
    return visitChildren(ctx);
  }


};

