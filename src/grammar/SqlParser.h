
// Generated from Sql.g4 by ANTLR 4.7.1

#pragma once


#include "antlr4-runtime.h"




class  SqlParser : public antlr4::Parser {
public:
  enum {
    SCOL = 1, DOT = 2, OPEN_PAR = 3, CLOSE_PAR = 4, COMMA = 5, ASSIGN = 6, 
    STAR = 7, PLUS = 8, MINUS = 9, TILDE = 10, PIPE2 = 11, DIV = 12, MOD = 13, 
    LT2 = 14, GT2 = 15, AMP = 16, PIPE = 17, LT = 18, LT_EQ = 19, GT = 20, 
    GT_EQ = 21, EQ = 22, NOT_EQ1 = 23, NOT_EQ2 = 24, K_ABORT = 25, K_ACTION = 26, 
    K_ADD = 27, K_AFTER = 28, K_ALL = 29, K_ALTER = 30, K_ANALYZE = 31, 
    K_AND = 32, K_AS = 33, K_ASC = 34, K_ATTACH = 35, K_AUTOINCREMENT = 36, 
    K_BEFORE = 37, K_BEGIN = 38, K_BETWEEN = 39, K_BY = 40, K_CASCADE = 41, 
    K_CASE = 42, K_CAST = 43, K_CHECK = 44, K_COLLATE = 45, K_COLUMN = 46, 
    K_COMMIT = 47, K_CONFLICT = 48, K_CONSTRAINT = 49, K_CREATE = 50, K_CROSS = 51, 
    K_CURRENT_DATE = 52, K_CURRENT_TIME = 53, K_CURRENT_TIMESTAMP = 54, 
    K_DATABASE = 55, K_DEFAULT = 56, K_DEFERRABLE = 57, K_DEFERRED = 58, 
    K_DELETE = 59, K_DESC = 60, K_DETACH = 61, K_DISTINCT = 62, K_DROP = 63, 
    K_EACH = 64, K_ELSE = 65, K_END = 66, K_ESCAPE = 67, K_EXCEPT = 68, 
    K_EXCLUSIVE = 69, K_EXISTS = 70, K_EXPLAIN = 71, K_FAIL = 72, K_FOR = 73, 
    K_FOREIGN = 74, K_FROM = 75, K_FULL = 76, K_GLOB = 77, K_GROUP = 78, 
    K_HAVING = 79, K_IF = 80, K_IGNORE = 81, K_IMMEDIATE = 82, K_IN = 83, 
    K_INDEX = 84, K_INDEXED = 85, K_INITIALLY = 86, K_INNER = 87, K_INSERT = 88, 
    K_INSTEAD = 89, K_INTERSECT = 90, K_INTO = 91, K_IS = 92, K_ISNOT = 93, 
    K_ISNULL = 94, K_JOIN = 95, K_KEY = 96, K_LEFT = 97, K_LIKE = 98, K_LIMIT = 99, 
    K_MATCH = 100, K_NATURAL = 101, K_NO = 102, K_NOT = 103, K_NOTNULL = 104, 
    K_NULL = 105, K_OF = 106, K_OFFSET = 107, K_ON = 108, K_OR = 109, K_ORDER = 110, 
    K_OUTER = 111, K_PLAN = 112, K_PRAGMA = 113, K_PRIMARY = 114, K_QUERY = 115, 
    K_RAISE = 116, K_RECURSIVE = 117, K_REFERENCES = 118, K_REGEXP = 119, 
    K_REINDEX = 120, K_RELEASE = 121, K_RENAME = 122, K_REPLACE = 123, K_RESTRICT = 124, 
    K_RIGHT = 125, K_ROLLBACK = 126, K_ROW = 127, K_SAVEPOINT = 128, K_SELECT = 129, 
    K_SET = 130, K_TABLE = 131, K_TEMP = 132, K_TEMPORARY = 133, K_THEN = 134, 
    K_TO = 135, K_TRANSACTION = 136, K_TRIGGER = 137, K_UNION = 138, K_UNIQUE = 139, 
    K_UPDATE = 140, K_USING = 141, K_VACUUM = 142, K_VALUES = 143, K_VIEW = 144, 
    K_VIRTUAL = 145, K_WHEN = 146, K_WHERE = 147, K_WITH = 148, K_WITHOUT = 149, 
    IDENTIFIER = 150, NUMERIC_LITERAL = 151, BIND_PARAMETER = 152, STRING_LITERAL = 153, 
    BLOB_LITERAL = 154, SINGLE_LINE_COMMENT = 155, MULTILINE_COMMENT = 156, 
    SPACES = 157, UNEXPECTED_CHAR = 158
  };

  enum {
    RuleParse = 0, RuleExpr = 1, RuleExprWhere = 2, RuleResult_column = 3, 
    RuleTable_or_subquery = 4, RuleJoin_clause = 5, RuleJoin_operator = 6, 
    RuleJoin_constraint = 7, RuleSelect_core = 8, RuleWhere_clause = 9, 
    RuleGroup_by_clause = 10, RuleSigned_number = 11, RuleLiteral_value = 12, 
    RuleUnary_operator = 13, RuleError_message = 14, RuleColumn_alias = 15, 
    RuleKeyword = 16, RuleName = 17, RuleFunction_name = 18, RuleDatabase_name = 19, 
    RuleTable_name = 20, RuleTable_or_index_name = 21, RuleNew_table_name = 22, 
    RuleColumn_name = 23, RuleCollation_name = 24, RuleForeign_table = 25, 
    RuleIndex_name = 26, RuleTrigger_name = 27, RuleView_name = 28, RuleModule_name = 29, 
    RulePragma_name = 30, RuleSavepoint_name = 31, RuleTable_alias = 32, 
    RuleTransaction_name = 33, RuleAny_name = 34
  };

  SqlParser(antlr4::TokenStream *input);
  ~SqlParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class ParseContext;
  class ExprContext;
  class ExprWhereContext;
  class Result_columnContext;
  class Table_or_subqueryContext;
  class Join_clauseContext;
  class Join_operatorContext;
  class Join_constraintContext;
  class Select_coreContext;
  class Where_clauseContext;
  class Group_by_clauseContext;
  class Signed_numberContext;
  class Literal_valueContext;
  class Unary_operatorContext;
  class Error_messageContext;
  class Column_aliasContext;
  class KeywordContext;
  class NameContext;
  class Function_nameContext;
  class Database_nameContext;
  class Table_nameContext;
  class Table_or_index_nameContext;
  class New_table_nameContext;
  class Column_nameContext;
  class Collation_nameContext;
  class Foreign_tableContext;
  class Index_nameContext;
  class Trigger_nameContext;
  class View_nameContext;
  class Module_nameContext;
  class Pragma_nameContext;
  class Savepoint_nameContext;
  class Table_aliasContext;
  class Transaction_nameContext;
  class Any_nameContext; 

  class  ParseContext : public antlr4::ParserRuleContext {
  public:
    ParseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Select_coreContext *> select_core();
    Select_coreContext* select_core(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ParseContext* parse();

  class  ExprContext : public antlr4::ParserRuleContext {
  public:
    SqlParser::ExprContext *left = nullptr;;
    antlr4::Token *oper = nullptr;;
    SqlParser::ExprContext *right = nullptr;;
    ExprContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Literal_valueContext *literal_value();
    antlr4::tree::TerminalNode *BIND_PARAMETER();
    Column_nameContext *column_name();
    Table_nameContext *table_name();
    Database_nameContext *database_name();
    Function_nameContext *function_name();
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    antlr4::tree::TerminalNode *K_DISTINCT();
    antlr4::tree::TerminalNode *K_IS();
    antlr4::tree::TerminalNode *K_ISNOT();
    antlr4::tree::TerminalNode *K_IN();
    antlr4::tree::TerminalNode *K_LIKE();
    antlr4::tree::TerminalNode *K_AND();
    antlr4::tree::TerminalNode *K_OR();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExprContext* expr();
  ExprContext* expr(int precedence);
  class  ExprWhereContext : public antlr4::ParserRuleContext {
  public:
    ExprWhereContext(antlr4::ParserRuleContext *parent, size_t invokingState);
   
    ExprWhereContext() : antlr4::ParserRuleContext() { }
    void copyFrom(ExprWhereContext *context);
    using antlr4::ParserRuleContext::copyFrom;

    virtual size_t getRuleIndex() const override;

   
  };

  class  ExprLiterContext : public ExprWhereContext {
  public:
    ExprLiterContext(ExprWhereContext *ctx);

    Literal_valueContext *literal_value();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ExprFuncContext : public ExprWhereContext {
  public:
    ExprFuncContext(ExprWhereContext *ctx);

    Function_nameContext *function_name();
    std::vector<ExprWhereContext *> exprWhere();
    ExprWhereContext* exprWhere(size_t i);
    antlr4::tree::TerminalNode *K_DISTINCT();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ExprColContext : public ExprWhereContext {
  public:
    ExprColContext(ExprWhereContext *ctx);

    Column_nameContext *column_name();
    Table_nameContext *table_name();
    Database_nameContext *database_name();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ExprParenContext : public ExprWhereContext {
  public:
    ExprParenContext(ExprWhereContext *ctx);

    ExprWhereContext *exprWhere();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ExprOrContext : public ExprWhereContext {
  public:
    ExprOrContext(ExprWhereContext *ctx);

    SqlParser::ExprWhereContext *left = nullptr;
    antlr4::Token *oper = nullptr;
    SqlParser::ExprWhereContext *right = nullptr;
    std::vector<ExprWhereContext *> exprWhere();
    ExprWhereContext* exprWhere(size_t i);
    antlr4::tree::TerminalNode *K_OR();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ExprBindContext : public ExprWhereContext {
  public:
    ExprBindContext(ExprWhereContext *ctx);

    antlr4::tree::TerminalNode *BIND_PARAMETER();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ExprCompareOpContext : public ExprWhereContext {
  public:
    ExprCompareOpContext(ExprWhereContext *ctx);

    SqlParser::ExprWhereContext *left = nullptr;
    antlr4::Token *oper = nullptr;
    SqlParser::ExprWhereContext *right = nullptr;
    std::vector<ExprWhereContext *> exprWhere();
    ExprWhereContext* exprWhere(size_t i);
    antlr4::tree::TerminalNode *K_IS();
    antlr4::tree::TerminalNode *K_ISNOT();
    antlr4::tree::TerminalNode *K_IN();
    antlr4::tree::TerminalNode *K_LIKE();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ExprBinaryMathOpContext : public ExprWhereContext {
  public:
    ExprBinaryMathOpContext(ExprWhereContext *ctx);

    SqlParser::ExprWhereContext *left = nullptr;
    antlr4::Token *oper = nullptr;
    SqlParser::ExprWhereContext *right = nullptr;
    std::vector<ExprWhereContext *> exprWhere();
    ExprWhereContext* exprWhere(size_t i);
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  class  ExprAndContext : public ExprWhereContext {
  public:
    ExprAndContext(ExprWhereContext *ctx);

    SqlParser::ExprWhereContext *left = nullptr;
    antlr4::Token *oper = nullptr;
    SqlParser::ExprWhereContext *right = nullptr;
    std::vector<ExprWhereContext *> exprWhere();
    ExprWhereContext* exprWhere(size_t i);
    antlr4::tree::TerminalNode *K_AND();
    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
  };

  ExprWhereContext* exprWhere();
  ExprWhereContext* exprWhere(int precedence);
  class  Result_columnContext : public antlr4::ParserRuleContext {
  public:
    Result_columnContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Table_nameContext *table_name();
    ExprContext *expr();
    Column_aliasContext *column_alias();
    antlr4::tree::TerminalNode *K_AS();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Result_columnContext* result_column();

  class  Table_or_subqueryContext : public antlr4::ParserRuleContext {
  public:
    Table_or_subqueryContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Table_nameContext *table_name();
    Database_nameContext *database_name();
    Table_aliasContext *table_alias();
    antlr4::tree::TerminalNode *K_AS();
    std::vector<Table_or_subqueryContext *> table_or_subquery();
    Table_or_subqueryContext* table_or_subquery(size_t i);
    Join_clauseContext *join_clause();
    Select_coreContext *select_core();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Table_or_subqueryContext* table_or_subquery();

  class  Join_clauseContext : public antlr4::ParserRuleContext {
  public:
    Join_clauseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Table_or_subqueryContext *> table_or_subquery();
    Table_or_subqueryContext* table_or_subquery(size_t i);
    std::vector<Join_operatorContext *> join_operator();
    Join_operatorContext* join_operator(size_t i);
    std::vector<Join_constraintContext *> join_constraint();
    Join_constraintContext* join_constraint(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Join_clauseContext* join_clause();

  class  Join_operatorContext : public antlr4::ParserRuleContext {
  public:
    Join_operatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *K_JOIN();
    antlr4::tree::TerminalNode *K_LEFT();
    antlr4::tree::TerminalNode *K_INNER();
    antlr4::tree::TerminalNode *K_CROSS();
    antlr4::tree::TerminalNode *K_OUTER();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Join_operatorContext* join_operator();

  class  Join_constraintContext : public antlr4::ParserRuleContext {
  public:
    Join_constraintContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *K_ON();
    ExprContext *expr();
    antlr4::tree::TerminalNode *K_USING();
    std::vector<Column_nameContext *> column_name();
    Column_nameContext* column_name(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Join_constraintContext* join_constraint();

  class  Select_coreContext : public antlr4::ParserRuleContext {
  public:
    Select_coreContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *K_SELECT();
    std::vector<Result_columnContext *> result_column();
    Result_columnContext* result_column(size_t i);
    antlr4::tree::TerminalNode *K_FROM();
    Where_clauseContext *where_clause();
    Group_by_clauseContext *group_by_clause();
    antlr4::tree::TerminalNode *K_DISTINCT();
    antlr4::tree::TerminalNode *K_ALL();
    std::vector<Table_or_subqueryContext *> table_or_subquery();
    Table_or_subqueryContext* table_or_subquery(size_t i);
    Join_clauseContext *join_clause();
    antlr4::tree::TerminalNode *K_VALUES();
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);
    antlr4::tree::TerminalNode *SCOL();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Select_coreContext* select_core();

  class  Where_clauseContext : public antlr4::ParserRuleContext {
  public:
    Where_clauseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *K_WHERE();
    ExprContext *expr();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Where_clauseContext* where_clause();

  class  Group_by_clauseContext : public antlr4::ParserRuleContext {
  public:
    Group_by_clauseContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *K_GROUP();
    antlr4::tree::TerminalNode *K_BY();
    std::vector<ExprContext *> expr();
    ExprContext* expr(size_t i);

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Group_by_clauseContext* group_by_clause();

  class  Signed_numberContext : public antlr4::ParserRuleContext {
  public:
    Signed_numberContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NUMERIC_LITERAL();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Signed_numberContext* signed_number();

  class  Literal_valueContext : public antlr4::ParserRuleContext {
  public:
    Literal_valueContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *NUMERIC_LITERAL();
    antlr4::tree::TerminalNode *STRING_LITERAL();
    antlr4::tree::TerminalNode *BLOB_LITERAL();
    antlr4::tree::TerminalNode *K_NULL();
    antlr4::tree::TerminalNode *K_CURRENT_TIME();
    antlr4::tree::TerminalNode *K_CURRENT_DATE();
    antlr4::tree::TerminalNode *K_CURRENT_TIMESTAMP();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Literal_valueContext* literal_value();

  class  Unary_operatorContext : public antlr4::ParserRuleContext {
  public:
    Unary_operatorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *K_NOT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Unary_operatorContext* unary_operator();

  class  Error_messageContext : public antlr4::ParserRuleContext {
  public:
    Error_messageContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *STRING_LITERAL();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Error_messageContext* error_message();

  class  Column_aliasContext : public antlr4::ParserRuleContext {
  public:
    Column_aliasContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();
    antlr4::tree::TerminalNode *STRING_LITERAL();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Column_aliasContext* column_alias();

  class  KeywordContext : public antlr4::ParserRuleContext {
  public:
    KeywordContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *K_ABORT();
    antlr4::tree::TerminalNode *K_ACTION();
    antlr4::tree::TerminalNode *K_ADD();
    antlr4::tree::TerminalNode *K_AFTER();
    antlr4::tree::TerminalNode *K_ALL();
    antlr4::tree::TerminalNode *K_ALTER();
    antlr4::tree::TerminalNode *K_ANALYZE();
    antlr4::tree::TerminalNode *K_AND();
    antlr4::tree::TerminalNode *K_AS();
    antlr4::tree::TerminalNode *K_ASC();
    antlr4::tree::TerminalNode *K_ATTACH();
    antlr4::tree::TerminalNode *K_AUTOINCREMENT();
    antlr4::tree::TerminalNode *K_BEFORE();
    antlr4::tree::TerminalNode *K_BEGIN();
    antlr4::tree::TerminalNode *K_BETWEEN();
    antlr4::tree::TerminalNode *K_BY();
    antlr4::tree::TerminalNode *K_CASCADE();
    antlr4::tree::TerminalNode *K_CASE();
    antlr4::tree::TerminalNode *K_CAST();
    antlr4::tree::TerminalNode *K_CHECK();
    antlr4::tree::TerminalNode *K_COLLATE();
    antlr4::tree::TerminalNode *K_COLUMN();
    antlr4::tree::TerminalNode *K_COMMIT();
    antlr4::tree::TerminalNode *K_CONFLICT();
    antlr4::tree::TerminalNode *K_CONSTRAINT();
    antlr4::tree::TerminalNode *K_CREATE();
    antlr4::tree::TerminalNode *K_CROSS();
    antlr4::tree::TerminalNode *K_CURRENT_DATE();
    antlr4::tree::TerminalNode *K_CURRENT_TIME();
    antlr4::tree::TerminalNode *K_CURRENT_TIMESTAMP();
    antlr4::tree::TerminalNode *K_DATABASE();
    antlr4::tree::TerminalNode *K_DEFAULT();
    antlr4::tree::TerminalNode *K_DEFERRABLE();
    antlr4::tree::TerminalNode *K_DEFERRED();
    antlr4::tree::TerminalNode *K_DELETE();
    antlr4::tree::TerminalNode *K_DESC();
    antlr4::tree::TerminalNode *K_DETACH();
    antlr4::tree::TerminalNode *K_DISTINCT();
    antlr4::tree::TerminalNode *K_DROP();
    antlr4::tree::TerminalNode *K_EACH();
    antlr4::tree::TerminalNode *K_ELSE();
    antlr4::tree::TerminalNode *K_END();
    antlr4::tree::TerminalNode *K_ESCAPE();
    antlr4::tree::TerminalNode *K_EXCEPT();
    antlr4::tree::TerminalNode *K_EXCLUSIVE();
    antlr4::tree::TerminalNode *K_EXISTS();
    antlr4::tree::TerminalNode *K_EXPLAIN();
    antlr4::tree::TerminalNode *K_FAIL();
    antlr4::tree::TerminalNode *K_FOR();
    antlr4::tree::TerminalNode *K_FOREIGN();
    antlr4::tree::TerminalNode *K_FROM();
    antlr4::tree::TerminalNode *K_FULL();
    antlr4::tree::TerminalNode *K_GLOB();
    antlr4::tree::TerminalNode *K_GROUP();
    antlr4::tree::TerminalNode *K_HAVING();
    antlr4::tree::TerminalNode *K_IF();
    antlr4::tree::TerminalNode *K_IGNORE();
    antlr4::tree::TerminalNode *K_IMMEDIATE();
    antlr4::tree::TerminalNode *K_IN();
    antlr4::tree::TerminalNode *K_INDEX();
    antlr4::tree::TerminalNode *K_INDEXED();
    antlr4::tree::TerminalNode *K_INITIALLY();
    antlr4::tree::TerminalNode *K_INNER();
    antlr4::tree::TerminalNode *K_INSERT();
    antlr4::tree::TerminalNode *K_INSTEAD();
    antlr4::tree::TerminalNode *K_INTERSECT();
    antlr4::tree::TerminalNode *K_INTO();
    antlr4::tree::TerminalNode *K_IS();
    antlr4::tree::TerminalNode *K_ISNOT();
    antlr4::tree::TerminalNode *K_ISNULL();
    antlr4::tree::TerminalNode *K_JOIN();
    antlr4::tree::TerminalNode *K_KEY();
    antlr4::tree::TerminalNode *K_LEFT();
    antlr4::tree::TerminalNode *K_LIKE();
    antlr4::tree::TerminalNode *K_LIMIT();
    antlr4::tree::TerminalNode *K_MATCH();
    antlr4::tree::TerminalNode *K_NATURAL();
    antlr4::tree::TerminalNode *K_NO();
    antlr4::tree::TerminalNode *K_NOT();
    antlr4::tree::TerminalNode *K_NOTNULL();
    antlr4::tree::TerminalNode *K_NULL();
    antlr4::tree::TerminalNode *K_OF();
    antlr4::tree::TerminalNode *K_OFFSET();
    antlr4::tree::TerminalNode *K_ON();
    antlr4::tree::TerminalNode *K_OR();
    antlr4::tree::TerminalNode *K_ORDER();
    antlr4::tree::TerminalNode *K_OUTER();
    antlr4::tree::TerminalNode *K_PLAN();
    antlr4::tree::TerminalNode *K_PRAGMA();
    antlr4::tree::TerminalNode *K_PRIMARY();
    antlr4::tree::TerminalNode *K_QUERY();
    antlr4::tree::TerminalNode *K_RAISE();
    antlr4::tree::TerminalNode *K_RECURSIVE();
    antlr4::tree::TerminalNode *K_REFERENCES();
    antlr4::tree::TerminalNode *K_REGEXP();
    antlr4::tree::TerminalNode *K_REINDEX();
    antlr4::tree::TerminalNode *K_RELEASE();
    antlr4::tree::TerminalNode *K_RENAME();
    antlr4::tree::TerminalNode *K_REPLACE();
    antlr4::tree::TerminalNode *K_RESTRICT();
    antlr4::tree::TerminalNode *K_RIGHT();
    antlr4::tree::TerminalNode *K_ROLLBACK();
    antlr4::tree::TerminalNode *K_ROW();
    antlr4::tree::TerminalNode *K_SAVEPOINT();
    antlr4::tree::TerminalNode *K_SELECT();
    antlr4::tree::TerminalNode *K_SET();
    antlr4::tree::TerminalNode *K_TABLE();
    antlr4::tree::TerminalNode *K_TEMP();
    antlr4::tree::TerminalNode *K_TEMPORARY();
    antlr4::tree::TerminalNode *K_THEN();
    antlr4::tree::TerminalNode *K_TO();
    antlr4::tree::TerminalNode *K_TRANSACTION();
    antlr4::tree::TerminalNode *K_TRIGGER();
    antlr4::tree::TerminalNode *K_UNION();
    antlr4::tree::TerminalNode *K_UNIQUE();
    antlr4::tree::TerminalNode *K_UPDATE();
    antlr4::tree::TerminalNode *K_USING();
    antlr4::tree::TerminalNode *K_VACUUM();
    antlr4::tree::TerminalNode *K_VALUES();
    antlr4::tree::TerminalNode *K_VIEW();
    antlr4::tree::TerminalNode *K_VIRTUAL();
    antlr4::tree::TerminalNode *K_WHEN();
    antlr4::tree::TerminalNode *K_WHERE();
    antlr4::tree::TerminalNode *K_WITH();
    antlr4::tree::TerminalNode *K_WITHOUT();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  KeywordContext* keyword();

  class  NameContext : public antlr4::ParserRuleContext {
  public:
    NameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Any_nameContext *any_name();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  NameContext* name();

  class  Function_nameContext : public antlr4::ParserRuleContext {
  public:
    Function_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Any_nameContext *any_name();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Function_nameContext* function_name();

  class  Database_nameContext : public antlr4::ParserRuleContext {
  public:
    Database_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Any_nameContext *any_name();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Database_nameContext* database_name();

  class  Table_nameContext : public antlr4::ParserRuleContext {
  public:
    Table_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Any_nameContext *any_name();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Table_nameContext* table_name();

  class  Table_or_index_nameContext : public antlr4::ParserRuleContext {
  public:
    Table_or_index_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Any_nameContext *any_name();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Table_or_index_nameContext* table_or_index_name();

  class  New_table_nameContext : public antlr4::ParserRuleContext {
  public:
    New_table_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Any_nameContext *any_name();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  New_table_nameContext* new_table_name();

  class  Column_nameContext : public antlr4::ParserRuleContext {
  public:
    Column_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Any_nameContext *any_name();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Column_nameContext* column_name();

  class  Collation_nameContext : public antlr4::ParserRuleContext {
  public:
    Collation_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Any_nameContext *any_name();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Collation_nameContext* collation_name();

  class  Foreign_tableContext : public antlr4::ParserRuleContext {
  public:
    Foreign_tableContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Any_nameContext *any_name();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Foreign_tableContext* foreign_table();

  class  Index_nameContext : public antlr4::ParserRuleContext {
  public:
    Index_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Any_nameContext *any_name();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Index_nameContext* index_name();

  class  Trigger_nameContext : public antlr4::ParserRuleContext {
  public:
    Trigger_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Any_nameContext *any_name();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Trigger_nameContext* trigger_name();

  class  View_nameContext : public antlr4::ParserRuleContext {
  public:
    View_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Any_nameContext *any_name();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  View_nameContext* view_name();

  class  Module_nameContext : public antlr4::ParserRuleContext {
  public:
    Module_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Any_nameContext *any_name();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Module_nameContext* module_name();

  class  Pragma_nameContext : public antlr4::ParserRuleContext {
  public:
    Pragma_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Any_nameContext *any_name();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Pragma_nameContext* pragma_name();

  class  Savepoint_nameContext : public antlr4::ParserRuleContext {
  public:
    Savepoint_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Any_nameContext *any_name();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Savepoint_nameContext* savepoint_name();

  class  Table_aliasContext : public antlr4::ParserRuleContext {
  public:
    Table_aliasContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Any_nameContext *any_name();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Table_aliasContext* table_alias();

  class  Transaction_nameContext : public antlr4::ParserRuleContext {
  public:
    Transaction_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Any_nameContext *any_name();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Transaction_nameContext* transaction_name();

  class  Any_nameContext : public antlr4::ParserRuleContext {
  public:
    Any_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();
    KeywordContext *keyword();
    antlr4::tree::TerminalNode *STRING_LITERAL();
    Any_nameContext *any_name();

    virtual void enterRule(antlr4::tree::ParseTreeListener *listener) override;
    virtual void exitRule(antlr4::tree::ParseTreeListener *listener) override;

    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Any_nameContext* any_name();


  virtual bool sempred(antlr4::RuleContext *_localctx, size_t ruleIndex, size_t predicateIndex) override;
  bool exprSempred(ExprContext *_localctx, size_t predicateIndex);
  bool exprWhereSempred(ExprWhereContext *_localctx, size_t predicateIndex);

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

