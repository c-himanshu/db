
// Generated from Sql.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"
#include "SqlParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by SqlParser.
 */
class  SqlVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by SqlParser.
   */
    virtual antlrcpp::Any visitParse(SqlParser::ParseContext *context) = 0;

    virtual antlrcpp::Any visitExpr(SqlParser::ExprContext *context) = 0;

    virtual antlrcpp::Any visitExprLiter(SqlParser::ExprLiterContext *context) = 0;

    virtual antlrcpp::Any visitExprFunc(SqlParser::ExprFuncContext *context) = 0;

    virtual antlrcpp::Any visitExprCol(SqlParser::ExprColContext *context) = 0;

    virtual antlrcpp::Any visitExprParen(SqlParser::ExprParenContext *context) = 0;

    virtual antlrcpp::Any visitExprOr(SqlParser::ExprOrContext *context) = 0;

    virtual antlrcpp::Any visitExprBind(SqlParser::ExprBindContext *context) = 0;

    virtual antlrcpp::Any visitExprCompareOp(SqlParser::ExprCompareOpContext *context) = 0;

    virtual antlrcpp::Any visitExprBinaryMathOp(SqlParser::ExprBinaryMathOpContext *context) = 0;

    virtual antlrcpp::Any visitExprAnd(SqlParser::ExprAndContext *context) = 0;

    virtual antlrcpp::Any visitResult_column(SqlParser::Result_columnContext *context) = 0;

    virtual antlrcpp::Any visitTable_or_subquery(SqlParser::Table_or_subqueryContext *context) = 0;

    virtual antlrcpp::Any visitJoin_clause(SqlParser::Join_clauseContext *context) = 0;

    virtual antlrcpp::Any visitJoin_operator(SqlParser::Join_operatorContext *context) = 0;

    virtual antlrcpp::Any visitJoin_constraint(SqlParser::Join_constraintContext *context) = 0;

    virtual antlrcpp::Any visitSelect_core(SqlParser::Select_coreContext *context) = 0;

    virtual antlrcpp::Any visitWhere_clause(SqlParser::Where_clauseContext *context) = 0;

    virtual antlrcpp::Any visitGroup_by_clause(SqlParser::Group_by_clauseContext *context) = 0;

    virtual antlrcpp::Any visitSigned_number(SqlParser::Signed_numberContext *context) = 0;

    virtual antlrcpp::Any visitLiteral_value(SqlParser::Literal_valueContext *context) = 0;

    virtual antlrcpp::Any visitUnary_operator(SqlParser::Unary_operatorContext *context) = 0;

    virtual antlrcpp::Any visitError_message(SqlParser::Error_messageContext *context) = 0;

    virtual antlrcpp::Any visitColumn_alias(SqlParser::Column_aliasContext *context) = 0;

    virtual antlrcpp::Any visitKeyword(SqlParser::KeywordContext *context) = 0;

    virtual antlrcpp::Any visitName(SqlParser::NameContext *context) = 0;

    virtual antlrcpp::Any visitFunction_name(SqlParser::Function_nameContext *context) = 0;

    virtual antlrcpp::Any visitDatabase_name(SqlParser::Database_nameContext *context) = 0;

    virtual antlrcpp::Any visitTable_name(SqlParser::Table_nameContext *context) = 0;

    virtual antlrcpp::Any visitTable_or_index_name(SqlParser::Table_or_index_nameContext *context) = 0;

    virtual antlrcpp::Any visitNew_table_name(SqlParser::New_table_nameContext *context) = 0;

    virtual antlrcpp::Any visitColumn_name(SqlParser::Column_nameContext *context) = 0;

    virtual antlrcpp::Any visitCollation_name(SqlParser::Collation_nameContext *context) = 0;

    virtual antlrcpp::Any visitForeign_table(SqlParser::Foreign_tableContext *context) = 0;

    virtual antlrcpp::Any visitIndex_name(SqlParser::Index_nameContext *context) = 0;

    virtual antlrcpp::Any visitTrigger_name(SqlParser::Trigger_nameContext *context) = 0;

    virtual antlrcpp::Any visitView_name(SqlParser::View_nameContext *context) = 0;

    virtual antlrcpp::Any visitModule_name(SqlParser::Module_nameContext *context) = 0;

    virtual antlrcpp::Any visitPragma_name(SqlParser::Pragma_nameContext *context) = 0;

    virtual antlrcpp::Any visitSavepoint_name(SqlParser::Savepoint_nameContext *context) = 0;

    virtual antlrcpp::Any visitTable_alias(SqlParser::Table_aliasContext *context) = 0;

    virtual antlrcpp::Any visitTransaction_name(SqlParser::Transaction_nameContext *context) = 0;

    virtual antlrcpp::Any visitAny_name(SqlParser::Any_nameContext *context) = 0;


};

