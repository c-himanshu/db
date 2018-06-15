
// Generated from Sql.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "SqlListener.h"


/**
 * This class provides an empty implementation of SqlListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  SqlBaseListener : public SqlListener {
public:

  virtual void enterParse(SqlParser::ParseContext * /*ctx*/) override { }
  virtual void exitParse(SqlParser::ParseContext * /*ctx*/) override { }

  virtual void enterExpr(SqlParser::ExprContext * /*ctx*/) override { }
  virtual void exitExpr(SqlParser::ExprContext * /*ctx*/) override { }

  virtual void enterExprLiter(SqlParser::ExprLiterContext * /*ctx*/) override { }
  virtual void exitExprLiter(SqlParser::ExprLiterContext * /*ctx*/) override { }

  virtual void enterExprFunc(SqlParser::ExprFuncContext * /*ctx*/) override { }
  virtual void exitExprFunc(SqlParser::ExprFuncContext * /*ctx*/) override { }

  virtual void enterExprCol(SqlParser::ExprColContext * /*ctx*/) override { }
  virtual void exitExprCol(SqlParser::ExprColContext * /*ctx*/) override { }

  virtual void enterExprParen(SqlParser::ExprParenContext * /*ctx*/) override { }
  virtual void exitExprParen(SqlParser::ExprParenContext * /*ctx*/) override { }

  virtual void enterExprOr(SqlParser::ExprOrContext * /*ctx*/) override { }
  virtual void exitExprOr(SqlParser::ExprOrContext * /*ctx*/) override { }

  virtual void enterExprBind(SqlParser::ExprBindContext * /*ctx*/) override { }
  virtual void exitExprBind(SqlParser::ExprBindContext * /*ctx*/) override { }

  virtual void enterExprCompareOp(SqlParser::ExprCompareOpContext * /*ctx*/) override { }
  virtual void exitExprCompareOp(SqlParser::ExprCompareOpContext * /*ctx*/) override { }

  virtual void enterExprBinaryMathOp(SqlParser::ExprBinaryMathOpContext * /*ctx*/) override { }
  virtual void exitExprBinaryMathOp(SqlParser::ExprBinaryMathOpContext * /*ctx*/) override { }

  virtual void enterExprAnd(SqlParser::ExprAndContext * /*ctx*/) override { }
  virtual void exitExprAnd(SqlParser::ExprAndContext * /*ctx*/) override { }

  virtual void enterResult_column(SqlParser::Result_columnContext * /*ctx*/) override { }
  virtual void exitResult_column(SqlParser::Result_columnContext * /*ctx*/) override { }

  virtual void enterTable_or_subquery(SqlParser::Table_or_subqueryContext * /*ctx*/) override { }
  virtual void exitTable_or_subquery(SqlParser::Table_or_subqueryContext * /*ctx*/) override { }

  virtual void enterJoin_clause(SqlParser::Join_clauseContext * /*ctx*/) override { }
  virtual void exitJoin_clause(SqlParser::Join_clauseContext * /*ctx*/) override { }

  virtual void enterJoin_operator(SqlParser::Join_operatorContext * /*ctx*/) override { }
  virtual void exitJoin_operator(SqlParser::Join_operatorContext * /*ctx*/) override { }

  virtual void enterJoin_constraint(SqlParser::Join_constraintContext * /*ctx*/) override { }
  virtual void exitJoin_constraint(SqlParser::Join_constraintContext * /*ctx*/) override { }

  virtual void enterSelect_core(SqlParser::Select_coreContext * /*ctx*/) override { }
  virtual void exitSelect_core(SqlParser::Select_coreContext * /*ctx*/) override { }

  virtual void enterWhere_clause(SqlParser::Where_clauseContext * /*ctx*/) override { }
  virtual void exitWhere_clause(SqlParser::Where_clauseContext * /*ctx*/) override { }

  virtual void enterGroup_by_clause(SqlParser::Group_by_clauseContext * /*ctx*/) override { }
  virtual void exitGroup_by_clause(SqlParser::Group_by_clauseContext * /*ctx*/) override { }

  virtual void enterSigned_number(SqlParser::Signed_numberContext * /*ctx*/) override { }
  virtual void exitSigned_number(SqlParser::Signed_numberContext * /*ctx*/) override { }

  virtual void enterLiteral_value(SqlParser::Literal_valueContext * /*ctx*/) override { }
  virtual void exitLiteral_value(SqlParser::Literal_valueContext * /*ctx*/) override { }

  virtual void enterUnary_operator(SqlParser::Unary_operatorContext * /*ctx*/) override { }
  virtual void exitUnary_operator(SqlParser::Unary_operatorContext * /*ctx*/) override { }

  virtual void enterError_message(SqlParser::Error_messageContext * /*ctx*/) override { }
  virtual void exitError_message(SqlParser::Error_messageContext * /*ctx*/) override { }

  virtual void enterColumn_alias(SqlParser::Column_aliasContext * /*ctx*/) override { }
  virtual void exitColumn_alias(SqlParser::Column_aliasContext * /*ctx*/) override { }

  virtual void enterKeyword(SqlParser::KeywordContext * /*ctx*/) override { }
  virtual void exitKeyword(SqlParser::KeywordContext * /*ctx*/) override { }

  virtual void enterName(SqlParser::NameContext * /*ctx*/) override { }
  virtual void exitName(SqlParser::NameContext * /*ctx*/) override { }

  virtual void enterFunction_name(SqlParser::Function_nameContext * /*ctx*/) override { }
  virtual void exitFunction_name(SqlParser::Function_nameContext * /*ctx*/) override { }

  virtual void enterDatabase_name(SqlParser::Database_nameContext * /*ctx*/) override { }
  virtual void exitDatabase_name(SqlParser::Database_nameContext * /*ctx*/) override { }

  virtual void enterTable_name(SqlParser::Table_nameContext * /*ctx*/) override { }
  virtual void exitTable_name(SqlParser::Table_nameContext * /*ctx*/) override { }

  virtual void enterTable_or_index_name(SqlParser::Table_or_index_nameContext * /*ctx*/) override { }
  virtual void exitTable_or_index_name(SqlParser::Table_or_index_nameContext * /*ctx*/) override { }

  virtual void enterNew_table_name(SqlParser::New_table_nameContext * /*ctx*/) override { }
  virtual void exitNew_table_name(SqlParser::New_table_nameContext * /*ctx*/) override { }

  virtual void enterColumn_name(SqlParser::Column_nameContext * /*ctx*/) override { }
  virtual void exitColumn_name(SqlParser::Column_nameContext * /*ctx*/) override { }

  virtual void enterCollation_name(SqlParser::Collation_nameContext * /*ctx*/) override { }
  virtual void exitCollation_name(SqlParser::Collation_nameContext * /*ctx*/) override { }

  virtual void enterForeign_table(SqlParser::Foreign_tableContext * /*ctx*/) override { }
  virtual void exitForeign_table(SqlParser::Foreign_tableContext * /*ctx*/) override { }

  virtual void enterIndex_name(SqlParser::Index_nameContext * /*ctx*/) override { }
  virtual void exitIndex_name(SqlParser::Index_nameContext * /*ctx*/) override { }

  virtual void enterTrigger_name(SqlParser::Trigger_nameContext * /*ctx*/) override { }
  virtual void exitTrigger_name(SqlParser::Trigger_nameContext * /*ctx*/) override { }

  virtual void enterView_name(SqlParser::View_nameContext * /*ctx*/) override { }
  virtual void exitView_name(SqlParser::View_nameContext * /*ctx*/) override { }

  virtual void enterModule_name(SqlParser::Module_nameContext * /*ctx*/) override { }
  virtual void exitModule_name(SqlParser::Module_nameContext * /*ctx*/) override { }

  virtual void enterPragma_name(SqlParser::Pragma_nameContext * /*ctx*/) override { }
  virtual void exitPragma_name(SqlParser::Pragma_nameContext * /*ctx*/) override { }

  virtual void enterSavepoint_name(SqlParser::Savepoint_nameContext * /*ctx*/) override { }
  virtual void exitSavepoint_name(SqlParser::Savepoint_nameContext * /*ctx*/) override { }

  virtual void enterTable_alias(SqlParser::Table_aliasContext * /*ctx*/) override { }
  virtual void exitTable_alias(SqlParser::Table_aliasContext * /*ctx*/) override { }

  virtual void enterTransaction_name(SqlParser::Transaction_nameContext * /*ctx*/) override { }
  virtual void exitTransaction_name(SqlParser::Transaction_nameContext * /*ctx*/) override { }

  virtual void enterAny_name(SqlParser::Any_nameContext * /*ctx*/) override { }
  virtual void exitAny_name(SqlParser::Any_nameContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

