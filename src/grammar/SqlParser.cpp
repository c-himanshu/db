
// Generated from Sql.g4 by ANTLR 4.7.1


#include "SqlListener.h"
#include "SqlVisitor.h"

#include "SqlParser.h"


using namespace antlrcpp;
using namespace antlr4;

SqlParser::SqlParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

SqlParser::~SqlParser() {
  delete _interpreter;
}

std::string SqlParser::getGrammarFileName() const {
  return "Sql.g4";
}

const std::vector<std::string>& SqlParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& SqlParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ParseContext ------------------------------------------------------------------

SqlParser::ParseContext::ParseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SqlParser::Select_coreContext *> SqlParser::ParseContext::select_core() {
  return getRuleContexts<SqlParser::Select_coreContext>();
}

SqlParser::Select_coreContext* SqlParser::ParseContext::select_core(size_t i) {
  return getRuleContext<SqlParser::Select_coreContext>(i);
}


size_t SqlParser::ParseContext::getRuleIndex() const {
  return SqlParser::RuleParse;
}

void SqlParser::ParseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterParse(this);
}

void SqlParser::ParseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitParse(this);
}


antlrcpp::Any SqlParser::ParseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlVisitor*>(visitor))
    return parserVisitor->visitParse(this);
  else
    return visitor->visitChildren(this);
}

SqlParser::ParseContext* SqlParser::parse() {
  ParseContext *_localctx = _tracker.createInstance<ParseContext>(_ctx, getState());
  enterRule(_localctx, 0, SqlParser::RuleParse);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(71); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(70);
      select_core();
      setState(73); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == SqlParser::K_SELECT

    || _la == SqlParser::K_VALUES);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

SqlParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SqlParser::Literal_valueContext* SqlParser::ExprContext::literal_value() {
  return getRuleContext<SqlParser::Literal_valueContext>(0);
}

tree::TerminalNode* SqlParser::ExprContext::BIND_PARAMETER() {
  return getToken(SqlParser::BIND_PARAMETER, 0);
}

SqlParser::Column_nameContext* SqlParser::ExprContext::column_name() {
  return getRuleContext<SqlParser::Column_nameContext>(0);
}

SqlParser::Table_nameContext* SqlParser::ExprContext::table_name() {
  return getRuleContext<SqlParser::Table_nameContext>(0);
}

SqlParser::Database_nameContext* SqlParser::ExprContext::database_name() {
  return getRuleContext<SqlParser::Database_nameContext>(0);
}

SqlParser::Function_nameContext* SqlParser::ExprContext::function_name() {
  return getRuleContext<SqlParser::Function_nameContext>(0);
}

std::vector<SqlParser::ExprContext *> SqlParser::ExprContext::expr() {
  return getRuleContexts<SqlParser::ExprContext>();
}

SqlParser::ExprContext* SqlParser::ExprContext::expr(size_t i) {
  return getRuleContext<SqlParser::ExprContext>(i);
}

tree::TerminalNode* SqlParser::ExprContext::K_DISTINCT() {
  return getToken(SqlParser::K_DISTINCT, 0);
}

tree::TerminalNode* SqlParser::ExprContext::K_IS() {
  return getToken(SqlParser::K_IS, 0);
}

tree::TerminalNode* SqlParser::ExprContext::K_ISNOT() {
  return getToken(SqlParser::K_ISNOT, 0);
}

tree::TerminalNode* SqlParser::ExprContext::K_IN() {
  return getToken(SqlParser::K_IN, 0);
}

tree::TerminalNode* SqlParser::ExprContext::K_LIKE() {
  return getToken(SqlParser::K_LIKE, 0);
}

tree::TerminalNode* SqlParser::ExprContext::K_AND() {
  return getToken(SqlParser::K_AND, 0);
}

tree::TerminalNode* SqlParser::ExprContext::K_OR() {
  return getToken(SqlParser::K_OR, 0);
}


size_t SqlParser::ExprContext::getRuleIndex() const {
  return SqlParser::RuleExpr;
}

void SqlParser::ExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr(this);
}

void SqlParser::ExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr(this);
}


antlrcpp::Any SqlParser::ExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlVisitor*>(visitor))
    return parserVisitor->visitExpr(this);
  else
    return visitor->visitChildren(this);
}


SqlParser::ExprContext* SqlParser::expr() {
   return expr(0);
}

SqlParser::ExprContext* SqlParser::expr(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  SqlParser::ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, parentState);
  SqlParser::ExprContext *previousContext = _localctx;
  size_t startState = 2;
  enterRecursionRule(_localctx, 2, SqlParser::RuleExpr, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(111);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 6, _ctx)) {
    case 1: {
      setState(76);
      literal_value();
      break;
    }

    case 2: {
      setState(77);
      match(SqlParser::BIND_PARAMETER);
      break;
    }

    case 3: {
      setState(86);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 2, _ctx)) {
      case 1: {
        setState(81);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 1, _ctx)) {
        case 1: {
          setState(78);
          database_name();
          setState(79);
          match(SqlParser::DOT);
          break;
        }

        }
        setState(83);
        table_name();
        setState(84);
        match(SqlParser::DOT);
        break;
      }

      }
      setState(88);
      column_name();
      break;
    }

    case 4: {
      setState(89);
      function_name();
      setState(90);
      match(SqlParser::OPEN_PAR);
      setState(103);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case SqlParser::OPEN_PAR:
        case SqlParser::K_ABORT:
        case SqlParser::K_ACTION:
        case SqlParser::K_ADD:
        case SqlParser::K_AFTER:
        case SqlParser::K_ALL:
        case SqlParser::K_ALTER:
        case SqlParser::K_ANALYZE:
        case SqlParser::K_AND:
        case SqlParser::K_AS:
        case SqlParser::K_ASC:
        case SqlParser::K_ATTACH:
        case SqlParser::K_AUTOINCREMENT:
        case SqlParser::K_BEFORE:
        case SqlParser::K_BEGIN:
        case SqlParser::K_BETWEEN:
        case SqlParser::K_BY:
        case SqlParser::K_CASCADE:
        case SqlParser::K_CASE:
        case SqlParser::K_CAST:
        case SqlParser::K_CHECK:
        case SqlParser::K_COLLATE:
        case SqlParser::K_COLUMN:
        case SqlParser::K_COMMIT:
        case SqlParser::K_CONFLICT:
        case SqlParser::K_CONSTRAINT:
        case SqlParser::K_CREATE:
        case SqlParser::K_CROSS:
        case SqlParser::K_CURRENT_DATE:
        case SqlParser::K_CURRENT_TIME:
        case SqlParser::K_CURRENT_TIMESTAMP:
        case SqlParser::K_DATABASE:
        case SqlParser::K_DEFAULT:
        case SqlParser::K_DEFERRABLE:
        case SqlParser::K_DEFERRED:
        case SqlParser::K_DELETE:
        case SqlParser::K_DESC:
        case SqlParser::K_DETACH:
        case SqlParser::K_DISTINCT:
        case SqlParser::K_DROP:
        case SqlParser::K_EACH:
        case SqlParser::K_ELSE:
        case SqlParser::K_END:
        case SqlParser::K_ESCAPE:
        case SqlParser::K_EXCEPT:
        case SqlParser::K_EXCLUSIVE:
        case SqlParser::K_EXISTS:
        case SqlParser::K_EXPLAIN:
        case SqlParser::K_FAIL:
        case SqlParser::K_FOR:
        case SqlParser::K_FOREIGN:
        case SqlParser::K_FROM:
        case SqlParser::K_FULL:
        case SqlParser::K_GLOB:
        case SqlParser::K_GROUP:
        case SqlParser::K_HAVING:
        case SqlParser::K_IF:
        case SqlParser::K_IGNORE:
        case SqlParser::K_IMMEDIATE:
        case SqlParser::K_IN:
        case SqlParser::K_INDEX:
        case SqlParser::K_INDEXED:
        case SqlParser::K_INITIALLY:
        case SqlParser::K_INNER:
        case SqlParser::K_INSERT:
        case SqlParser::K_INSTEAD:
        case SqlParser::K_INTERSECT:
        case SqlParser::K_INTO:
        case SqlParser::K_IS:
        case SqlParser::K_ISNOT:
        case SqlParser::K_ISNULL:
        case SqlParser::K_JOIN:
        case SqlParser::K_KEY:
        case SqlParser::K_LEFT:
        case SqlParser::K_LIKE:
        case SqlParser::K_LIMIT:
        case SqlParser::K_MATCH:
        case SqlParser::K_NATURAL:
        case SqlParser::K_NO:
        case SqlParser::K_NOT:
        case SqlParser::K_NOTNULL:
        case SqlParser::K_NULL:
        case SqlParser::K_OF:
        case SqlParser::K_OFFSET:
        case SqlParser::K_ON:
        case SqlParser::K_OR:
        case SqlParser::K_ORDER:
        case SqlParser::K_OUTER:
        case SqlParser::K_PLAN:
        case SqlParser::K_PRAGMA:
        case SqlParser::K_PRIMARY:
        case SqlParser::K_QUERY:
        case SqlParser::K_RAISE:
        case SqlParser::K_RECURSIVE:
        case SqlParser::K_REFERENCES:
        case SqlParser::K_REGEXP:
        case SqlParser::K_REINDEX:
        case SqlParser::K_RELEASE:
        case SqlParser::K_RENAME:
        case SqlParser::K_REPLACE:
        case SqlParser::K_RESTRICT:
        case SqlParser::K_RIGHT:
        case SqlParser::K_ROLLBACK:
        case SqlParser::K_ROW:
        case SqlParser::K_SAVEPOINT:
        case SqlParser::K_SELECT:
        case SqlParser::K_SET:
        case SqlParser::K_TABLE:
        case SqlParser::K_TEMP:
        case SqlParser::K_TEMPORARY:
        case SqlParser::K_THEN:
        case SqlParser::K_TO:
        case SqlParser::K_TRANSACTION:
        case SqlParser::K_TRIGGER:
        case SqlParser::K_UNION:
        case SqlParser::K_UNIQUE:
        case SqlParser::K_UPDATE:
        case SqlParser::K_USING:
        case SqlParser::K_VACUUM:
        case SqlParser::K_VALUES:
        case SqlParser::K_VIEW:
        case SqlParser::K_VIRTUAL:
        case SqlParser::K_WHEN:
        case SqlParser::K_WHERE:
        case SqlParser::K_WITH:
        case SqlParser::K_WITHOUT:
        case SqlParser::IDENTIFIER:
        case SqlParser::NUMERIC_LITERAL:
        case SqlParser::BIND_PARAMETER:
        case SqlParser::STRING_LITERAL:
        case SqlParser::BLOB_LITERAL: {
          setState(92);
          _errHandler->sync(this);

          switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 3, _ctx)) {
          case 1: {
            setState(91);
            match(SqlParser::K_DISTINCT);
            break;
          }

          }
          setState(94);
          expr(0);
          setState(99);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == SqlParser::COMMA) {
            setState(95);
            match(SqlParser::COMMA);
            setState(96);
            expr(0);
            setState(101);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          break;
        }

        case SqlParser::STAR: {
          setState(102);
          match(SqlParser::STAR);
          break;
        }

        case SqlParser::CLOSE_PAR: {
          break;
        }

      default:
        break;
      }
      setState(105);
      match(SqlParser::CLOSE_PAR);
      break;
    }

    case 5: {
      setState(107);
      match(SqlParser::OPEN_PAR);
      setState(108);
      expr(0);
      setState(109);
      match(SqlParser::CLOSE_PAR);
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(127);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(125);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 7, _ctx)) {
        case 1: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          _localctx->left = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(113);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(114);
          dynamic_cast<ExprContext *>(_localctx)->oper = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << SqlParser::STAR)
            | (1ULL << SqlParser::PLUS)
            | (1ULL << SqlParser::MINUS)
            | (1ULL << SqlParser::DIV)
            | (1ULL << SqlParser::MOD)
            | (1ULL << SqlParser::LT)
            | (1ULL << SqlParser::LT_EQ)
            | (1ULL << SqlParser::GT)
            | (1ULL << SqlParser::GT_EQ))) != 0))) {
            dynamic_cast<ExprContext *>(_localctx)->oper = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(115);
          dynamic_cast<ExprContext *>(_localctx)->right = expr(7);
          break;
        }

        case 2: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          _localctx->left = previousContext;
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(116);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(117);
          dynamic_cast<ExprContext *>(_localctx)->oper = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << SqlParser::ASSIGN)
            | (1ULL << SqlParser::EQ)
            | (1ULL << SqlParser::NOT_EQ1)
            | (1ULL << SqlParser::NOT_EQ2))) != 0) || ((((_la - 83) & ~ 0x3fULL) == 0) &&
            ((1ULL << (_la - 83)) & ((1ULL << (SqlParser::K_IN - 83))
            | (1ULL << (SqlParser::K_IS - 83))
            | (1ULL << (SqlParser::K_ISNOT - 83))
            | (1ULL << (SqlParser::K_LIKE - 83)))) != 0))) {
            dynamic_cast<ExprContext *>(_localctx)->oper = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(118);
          dynamic_cast<ExprContext *>(_localctx)->right = expr(6);
          break;
        }

        case 3: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(119);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(120);
          match(SqlParser::K_AND);
          setState(121);
          expr(5);
          break;
        }

        case 4: {
          _localctx = _tracker.createInstance<ExprContext>(parentContext, parentState);
          pushNewRecursionContext(_localctx, startState, RuleExpr);
          setState(122);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(123);
          match(SqlParser::K_OR);
          setState(124);
          expr(4);
          break;
        }

        } 
      }
      setState(129);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- ExprWhereContext ------------------------------------------------------------------

SqlParser::ExprWhereContext::ExprWhereContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}


size_t SqlParser::ExprWhereContext::getRuleIndex() const {
  return SqlParser::RuleExprWhere;
}

void SqlParser::ExprWhereContext::copyFrom(ExprWhereContext *ctx) {
  ParserRuleContext::copyFrom(ctx);
}

//----------------- ExprLiterContext ------------------------------------------------------------------

SqlParser::Literal_valueContext* SqlParser::ExprLiterContext::literal_value() {
  return getRuleContext<SqlParser::Literal_valueContext>(0);
}

SqlParser::ExprLiterContext::ExprLiterContext(ExprWhereContext *ctx) { copyFrom(ctx); }

void SqlParser::ExprLiterContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExprLiter(this);
}
void SqlParser::ExprLiterContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExprLiter(this);
}

antlrcpp::Any SqlParser::ExprLiterContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlVisitor*>(visitor))
    return parserVisitor->visitExprLiter(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprFuncContext ------------------------------------------------------------------

SqlParser::Function_nameContext* SqlParser::ExprFuncContext::function_name() {
  return getRuleContext<SqlParser::Function_nameContext>(0);
}

std::vector<SqlParser::ExprWhereContext *> SqlParser::ExprFuncContext::exprWhere() {
  return getRuleContexts<SqlParser::ExprWhereContext>();
}

SqlParser::ExprWhereContext* SqlParser::ExprFuncContext::exprWhere(size_t i) {
  return getRuleContext<SqlParser::ExprWhereContext>(i);
}

tree::TerminalNode* SqlParser::ExprFuncContext::K_DISTINCT() {
  return getToken(SqlParser::K_DISTINCT, 0);
}

SqlParser::ExprFuncContext::ExprFuncContext(ExprWhereContext *ctx) { copyFrom(ctx); }

void SqlParser::ExprFuncContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExprFunc(this);
}
void SqlParser::ExprFuncContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExprFunc(this);
}

antlrcpp::Any SqlParser::ExprFuncContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlVisitor*>(visitor))
    return parserVisitor->visitExprFunc(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprColContext ------------------------------------------------------------------

SqlParser::Column_nameContext* SqlParser::ExprColContext::column_name() {
  return getRuleContext<SqlParser::Column_nameContext>(0);
}

SqlParser::Table_nameContext* SqlParser::ExprColContext::table_name() {
  return getRuleContext<SqlParser::Table_nameContext>(0);
}

SqlParser::Database_nameContext* SqlParser::ExprColContext::database_name() {
  return getRuleContext<SqlParser::Database_nameContext>(0);
}

SqlParser::ExprColContext::ExprColContext(ExprWhereContext *ctx) { copyFrom(ctx); }

void SqlParser::ExprColContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExprCol(this);
}
void SqlParser::ExprColContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExprCol(this);
}

antlrcpp::Any SqlParser::ExprColContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlVisitor*>(visitor))
    return parserVisitor->visitExprCol(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprParenContext ------------------------------------------------------------------

SqlParser::ExprWhereContext* SqlParser::ExprParenContext::exprWhere() {
  return getRuleContext<SqlParser::ExprWhereContext>(0);
}

SqlParser::ExprParenContext::ExprParenContext(ExprWhereContext *ctx) { copyFrom(ctx); }

void SqlParser::ExprParenContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExprParen(this);
}
void SqlParser::ExprParenContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExprParen(this);
}

antlrcpp::Any SqlParser::ExprParenContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlVisitor*>(visitor))
    return parserVisitor->visitExprParen(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprOrContext ------------------------------------------------------------------

std::vector<SqlParser::ExprWhereContext *> SqlParser::ExprOrContext::exprWhere() {
  return getRuleContexts<SqlParser::ExprWhereContext>();
}

SqlParser::ExprWhereContext* SqlParser::ExprOrContext::exprWhere(size_t i) {
  return getRuleContext<SqlParser::ExprWhereContext>(i);
}

tree::TerminalNode* SqlParser::ExprOrContext::K_OR() {
  return getToken(SqlParser::K_OR, 0);
}

SqlParser::ExprOrContext::ExprOrContext(ExprWhereContext *ctx) { copyFrom(ctx); }

void SqlParser::ExprOrContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExprOr(this);
}
void SqlParser::ExprOrContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExprOr(this);
}

antlrcpp::Any SqlParser::ExprOrContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlVisitor*>(visitor))
    return parserVisitor->visitExprOr(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprBindContext ------------------------------------------------------------------

tree::TerminalNode* SqlParser::ExprBindContext::BIND_PARAMETER() {
  return getToken(SqlParser::BIND_PARAMETER, 0);
}

SqlParser::ExprBindContext::ExprBindContext(ExprWhereContext *ctx) { copyFrom(ctx); }

void SqlParser::ExprBindContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExprBind(this);
}
void SqlParser::ExprBindContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExprBind(this);
}

antlrcpp::Any SqlParser::ExprBindContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlVisitor*>(visitor))
    return parserVisitor->visitExprBind(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprCompareOpContext ------------------------------------------------------------------

std::vector<SqlParser::ExprWhereContext *> SqlParser::ExprCompareOpContext::exprWhere() {
  return getRuleContexts<SqlParser::ExprWhereContext>();
}

SqlParser::ExprWhereContext* SqlParser::ExprCompareOpContext::exprWhere(size_t i) {
  return getRuleContext<SqlParser::ExprWhereContext>(i);
}

tree::TerminalNode* SqlParser::ExprCompareOpContext::K_IS() {
  return getToken(SqlParser::K_IS, 0);
}

tree::TerminalNode* SqlParser::ExprCompareOpContext::K_ISNOT() {
  return getToken(SqlParser::K_ISNOT, 0);
}

tree::TerminalNode* SqlParser::ExprCompareOpContext::K_IN() {
  return getToken(SqlParser::K_IN, 0);
}

tree::TerminalNode* SqlParser::ExprCompareOpContext::K_LIKE() {
  return getToken(SqlParser::K_LIKE, 0);
}

SqlParser::ExprCompareOpContext::ExprCompareOpContext(ExprWhereContext *ctx) { copyFrom(ctx); }

void SqlParser::ExprCompareOpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExprCompareOp(this);
}
void SqlParser::ExprCompareOpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExprCompareOp(this);
}

antlrcpp::Any SqlParser::ExprCompareOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlVisitor*>(visitor))
    return parserVisitor->visitExprCompareOp(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprBinaryMathOpContext ------------------------------------------------------------------

std::vector<SqlParser::ExprWhereContext *> SqlParser::ExprBinaryMathOpContext::exprWhere() {
  return getRuleContexts<SqlParser::ExprWhereContext>();
}

SqlParser::ExprWhereContext* SqlParser::ExprBinaryMathOpContext::exprWhere(size_t i) {
  return getRuleContext<SqlParser::ExprWhereContext>(i);
}

SqlParser::ExprBinaryMathOpContext::ExprBinaryMathOpContext(ExprWhereContext *ctx) { copyFrom(ctx); }

void SqlParser::ExprBinaryMathOpContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExprBinaryMathOp(this);
}
void SqlParser::ExprBinaryMathOpContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExprBinaryMathOp(this);
}

antlrcpp::Any SqlParser::ExprBinaryMathOpContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlVisitor*>(visitor))
    return parserVisitor->visitExprBinaryMathOp(this);
  else
    return visitor->visitChildren(this);
}
//----------------- ExprAndContext ------------------------------------------------------------------

std::vector<SqlParser::ExprWhereContext *> SqlParser::ExprAndContext::exprWhere() {
  return getRuleContexts<SqlParser::ExprWhereContext>();
}

SqlParser::ExprWhereContext* SqlParser::ExprAndContext::exprWhere(size_t i) {
  return getRuleContext<SqlParser::ExprWhereContext>(i);
}

tree::TerminalNode* SqlParser::ExprAndContext::K_AND() {
  return getToken(SqlParser::K_AND, 0);
}

SqlParser::ExprAndContext::ExprAndContext(ExprWhereContext *ctx) { copyFrom(ctx); }

void SqlParser::ExprAndContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExprAnd(this);
}
void SqlParser::ExprAndContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExprAnd(this);
}

antlrcpp::Any SqlParser::ExprAndContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlVisitor*>(visitor))
    return parserVisitor->visitExprAnd(this);
  else
    return visitor->visitChildren(this);
}

SqlParser::ExprWhereContext* SqlParser::exprWhere() {
   return exprWhere(0);
}

SqlParser::ExprWhereContext* SqlParser::exprWhere(int precedence) {
  ParserRuleContext *parentContext = _ctx;
  size_t parentState = getState();
  SqlParser::ExprWhereContext *_localctx = _tracker.createInstance<ExprWhereContext>(_ctx, parentState);
  SqlParser::ExprWhereContext *previousContext = _localctx;
  size_t startState = 4;
  enterRecursionRule(_localctx, 4, SqlParser::RuleExprWhere, precedence);

    size_t _la = 0;

  auto onExit = finally([=] {
    unrollRecursionContexts(parentContext);
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(166);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 14, _ctx)) {
    case 1: {
      _localctx = _tracker.createInstance<ExprLiterContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;

      setState(131);
      literal_value();
      break;
    }

    case 2: {
      _localctx = _tracker.createInstance<ExprBindContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(132);
      match(SqlParser::BIND_PARAMETER);
      break;
    }

    case 3: {
      _localctx = _tracker.createInstance<ExprColContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(141);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx)) {
      case 1: {
        setState(136);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 9, _ctx)) {
        case 1: {
          setState(133);
          database_name();
          setState(134);
          match(SqlParser::DOT);
          break;
        }

        }
        setState(138);
        table_name();
        setState(139);
        match(SqlParser::DOT);
        break;
      }

      }
      setState(143);
      column_name();
      break;
    }

    case 4: {
      _localctx = _tracker.createInstance<ExprFuncContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(144);
      function_name();
      setState(145);
      match(SqlParser::OPEN_PAR);
      setState(158);
      _errHandler->sync(this);
      switch (_input->LA(1)) {
        case SqlParser::OPEN_PAR:
        case SqlParser::K_ABORT:
        case SqlParser::K_ACTION:
        case SqlParser::K_ADD:
        case SqlParser::K_AFTER:
        case SqlParser::K_ALL:
        case SqlParser::K_ALTER:
        case SqlParser::K_ANALYZE:
        case SqlParser::K_AND:
        case SqlParser::K_AS:
        case SqlParser::K_ASC:
        case SqlParser::K_ATTACH:
        case SqlParser::K_AUTOINCREMENT:
        case SqlParser::K_BEFORE:
        case SqlParser::K_BEGIN:
        case SqlParser::K_BETWEEN:
        case SqlParser::K_BY:
        case SqlParser::K_CASCADE:
        case SqlParser::K_CASE:
        case SqlParser::K_CAST:
        case SqlParser::K_CHECK:
        case SqlParser::K_COLLATE:
        case SqlParser::K_COLUMN:
        case SqlParser::K_COMMIT:
        case SqlParser::K_CONFLICT:
        case SqlParser::K_CONSTRAINT:
        case SqlParser::K_CREATE:
        case SqlParser::K_CROSS:
        case SqlParser::K_CURRENT_DATE:
        case SqlParser::K_CURRENT_TIME:
        case SqlParser::K_CURRENT_TIMESTAMP:
        case SqlParser::K_DATABASE:
        case SqlParser::K_DEFAULT:
        case SqlParser::K_DEFERRABLE:
        case SqlParser::K_DEFERRED:
        case SqlParser::K_DELETE:
        case SqlParser::K_DESC:
        case SqlParser::K_DETACH:
        case SqlParser::K_DISTINCT:
        case SqlParser::K_DROP:
        case SqlParser::K_EACH:
        case SqlParser::K_ELSE:
        case SqlParser::K_END:
        case SqlParser::K_ESCAPE:
        case SqlParser::K_EXCEPT:
        case SqlParser::K_EXCLUSIVE:
        case SqlParser::K_EXISTS:
        case SqlParser::K_EXPLAIN:
        case SqlParser::K_FAIL:
        case SqlParser::K_FOR:
        case SqlParser::K_FOREIGN:
        case SqlParser::K_FROM:
        case SqlParser::K_FULL:
        case SqlParser::K_GLOB:
        case SqlParser::K_GROUP:
        case SqlParser::K_HAVING:
        case SqlParser::K_IF:
        case SqlParser::K_IGNORE:
        case SqlParser::K_IMMEDIATE:
        case SqlParser::K_IN:
        case SqlParser::K_INDEX:
        case SqlParser::K_INDEXED:
        case SqlParser::K_INITIALLY:
        case SqlParser::K_INNER:
        case SqlParser::K_INSERT:
        case SqlParser::K_INSTEAD:
        case SqlParser::K_INTERSECT:
        case SqlParser::K_INTO:
        case SqlParser::K_IS:
        case SqlParser::K_ISNOT:
        case SqlParser::K_ISNULL:
        case SqlParser::K_JOIN:
        case SqlParser::K_KEY:
        case SqlParser::K_LEFT:
        case SqlParser::K_LIKE:
        case SqlParser::K_LIMIT:
        case SqlParser::K_MATCH:
        case SqlParser::K_NATURAL:
        case SqlParser::K_NO:
        case SqlParser::K_NOT:
        case SqlParser::K_NOTNULL:
        case SqlParser::K_NULL:
        case SqlParser::K_OF:
        case SqlParser::K_OFFSET:
        case SqlParser::K_ON:
        case SqlParser::K_OR:
        case SqlParser::K_ORDER:
        case SqlParser::K_OUTER:
        case SqlParser::K_PLAN:
        case SqlParser::K_PRAGMA:
        case SqlParser::K_PRIMARY:
        case SqlParser::K_QUERY:
        case SqlParser::K_RAISE:
        case SqlParser::K_RECURSIVE:
        case SqlParser::K_REFERENCES:
        case SqlParser::K_REGEXP:
        case SqlParser::K_REINDEX:
        case SqlParser::K_RELEASE:
        case SqlParser::K_RENAME:
        case SqlParser::K_REPLACE:
        case SqlParser::K_RESTRICT:
        case SqlParser::K_RIGHT:
        case SqlParser::K_ROLLBACK:
        case SqlParser::K_ROW:
        case SqlParser::K_SAVEPOINT:
        case SqlParser::K_SELECT:
        case SqlParser::K_SET:
        case SqlParser::K_TABLE:
        case SqlParser::K_TEMP:
        case SqlParser::K_TEMPORARY:
        case SqlParser::K_THEN:
        case SqlParser::K_TO:
        case SqlParser::K_TRANSACTION:
        case SqlParser::K_TRIGGER:
        case SqlParser::K_UNION:
        case SqlParser::K_UNIQUE:
        case SqlParser::K_UPDATE:
        case SqlParser::K_USING:
        case SqlParser::K_VACUUM:
        case SqlParser::K_VALUES:
        case SqlParser::K_VIEW:
        case SqlParser::K_VIRTUAL:
        case SqlParser::K_WHEN:
        case SqlParser::K_WHERE:
        case SqlParser::K_WITH:
        case SqlParser::K_WITHOUT:
        case SqlParser::IDENTIFIER:
        case SqlParser::NUMERIC_LITERAL:
        case SqlParser::BIND_PARAMETER:
        case SqlParser::STRING_LITERAL:
        case SqlParser::BLOB_LITERAL: {
          setState(147);
          _errHandler->sync(this);

          switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 11, _ctx)) {
          case 1: {
            setState(146);
            match(SqlParser::K_DISTINCT);
            break;
          }

          }
          setState(149);
          exprWhere(0);
          setState(154);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == SqlParser::COMMA) {
            setState(150);
            match(SqlParser::COMMA);
            setState(151);
            exprWhere(0);
            setState(156);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          break;
        }

        case SqlParser::STAR: {
          setState(157);
          match(SqlParser::STAR);
          break;
        }

        case SqlParser::CLOSE_PAR: {
          break;
        }

      default:
        break;
      }
      setState(160);
      match(SqlParser::CLOSE_PAR);
      break;
    }

    case 5: {
      _localctx = _tracker.createInstance<ExprParenContext>(_localctx);
      _ctx = _localctx;
      previousContext = _localctx;
      setState(162);
      match(SqlParser::OPEN_PAR);
      setState(163);
      exprWhere(0);
      setState(164);
      match(SqlParser::CLOSE_PAR);
      break;
    }

    }
    _ctx->stop = _input->LT(-1);
    setState(182);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        if (!_parseListeners.empty())
          triggerExitRuleEvent();
        previousContext = _localctx;
        setState(180);
        _errHandler->sync(this);
        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 15, _ctx)) {
        case 1: {
          auto newContext = _tracker.createInstance<ExprBinaryMathOpContext>(_tracker.createInstance<ExprWhereContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExprWhere);
          setState(168);

          if (!(precpred(_ctx, 6))) throw FailedPredicateException(this, "precpred(_ctx, 6)");
          setState(169);
          dynamic_cast<ExprBinaryMathOpContext *>(_localctx)->oper = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << SqlParser::STAR)
            | (1ULL << SqlParser::PLUS)
            | (1ULL << SqlParser::MINUS)
            | (1ULL << SqlParser::DIV)
            | (1ULL << SqlParser::MOD))) != 0))) {
            dynamic_cast<ExprBinaryMathOpContext *>(_localctx)->oper = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(170);
          dynamic_cast<ExprBinaryMathOpContext *>(_localctx)->right = exprWhere(7);
          break;
        }

        case 2: {
          auto newContext = _tracker.createInstance<ExprCompareOpContext>(_tracker.createInstance<ExprWhereContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExprWhere);
          setState(171);

          if (!(precpred(_ctx, 5))) throw FailedPredicateException(this, "precpred(_ctx, 5)");
          setState(172);
          dynamic_cast<ExprCompareOpContext *>(_localctx)->oper = _input->LT(1);
          _la = _input->LA(1);
          if (!((((_la & ~ 0x3fULL) == 0) &&
            ((1ULL << _la) & ((1ULL << SqlParser::ASSIGN)
            | (1ULL << SqlParser::LT)
            | (1ULL << SqlParser::LT_EQ)
            | (1ULL << SqlParser::GT)
            | (1ULL << SqlParser::GT_EQ)
            | (1ULL << SqlParser::EQ)
            | (1ULL << SqlParser::NOT_EQ1)
            | (1ULL << SqlParser::NOT_EQ2))) != 0) || ((((_la - 83) & ~ 0x3fULL) == 0) &&
            ((1ULL << (_la - 83)) & ((1ULL << (SqlParser::K_IN - 83))
            | (1ULL << (SqlParser::K_IS - 83))
            | (1ULL << (SqlParser::K_ISNOT - 83))
            | (1ULL << (SqlParser::K_LIKE - 83)))) != 0))) {
            dynamic_cast<ExprCompareOpContext *>(_localctx)->oper = _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          setState(173);
          dynamic_cast<ExprCompareOpContext *>(_localctx)->right = exprWhere(6);
          break;
        }

        case 3: {
          auto newContext = _tracker.createInstance<ExprAndContext>(_tracker.createInstance<ExprWhereContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExprWhere);
          setState(174);

          if (!(precpred(_ctx, 4))) throw FailedPredicateException(this, "precpred(_ctx, 4)");
          setState(175);
          dynamic_cast<ExprAndContext *>(_localctx)->oper = match(SqlParser::K_AND);
          setState(176);
          dynamic_cast<ExprAndContext *>(_localctx)->right = exprWhere(5);
          break;
        }

        case 4: {
          auto newContext = _tracker.createInstance<ExprOrContext>(_tracker.createInstance<ExprWhereContext>(parentContext, parentState));
          _localctx = newContext;
          newContext->left = previousContext;
          pushNewRecursionContext(newContext, startState, RuleExprWhere);
          setState(177);

          if (!(precpred(_ctx, 3))) throw FailedPredicateException(this, "precpred(_ctx, 3)");
          setState(178);
          dynamic_cast<ExprOrContext *>(_localctx)->oper = match(SqlParser::K_OR);
          setState(179);
          dynamic_cast<ExprOrContext *>(_localctx)->right = exprWhere(4);
          break;
        }

        } 
      }
      setState(184);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 16, _ctx);
    }
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }
  return _localctx;
}

//----------------- Result_columnContext ------------------------------------------------------------------

SqlParser::Result_columnContext::Result_columnContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SqlParser::Table_nameContext* SqlParser::Result_columnContext::table_name() {
  return getRuleContext<SqlParser::Table_nameContext>(0);
}

SqlParser::ExprContext* SqlParser::Result_columnContext::expr() {
  return getRuleContext<SqlParser::ExprContext>(0);
}

SqlParser::Column_aliasContext* SqlParser::Result_columnContext::column_alias() {
  return getRuleContext<SqlParser::Column_aliasContext>(0);
}

tree::TerminalNode* SqlParser::Result_columnContext::K_AS() {
  return getToken(SqlParser::K_AS, 0);
}


size_t SqlParser::Result_columnContext::getRuleIndex() const {
  return SqlParser::RuleResult_column;
}

void SqlParser::Result_columnContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterResult_column(this);
}

void SqlParser::Result_columnContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitResult_column(this);
}


antlrcpp::Any SqlParser::Result_columnContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlVisitor*>(visitor))
    return parserVisitor->visitResult_column(this);
  else
    return visitor->visitChildren(this);
}

SqlParser::Result_columnContext* SqlParser::result_column() {
  Result_columnContext *_localctx = _tracker.createInstance<Result_columnContext>(_ctx, getState());
  enterRule(_localctx, 6, SqlParser::RuleResult_column);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(197);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 19, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(185);
      match(SqlParser::STAR);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(186);
      table_name();
      setState(187);
      match(SqlParser::DOT);
      setState(188);
      match(SqlParser::STAR);
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(190);
      expr(0);
      setState(195);
      _errHandler->sync(this);

      _la = _input->LA(1);
      if (_la == SqlParser::K_AS || _la == SqlParser::IDENTIFIER

      || _la == SqlParser::STRING_LITERAL) {
        setState(192);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == SqlParser::K_AS) {
          setState(191);
          match(SqlParser::K_AS);
        }
        setState(194);
        column_alias();
      }
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Table_or_subqueryContext ------------------------------------------------------------------

SqlParser::Table_or_subqueryContext::Table_or_subqueryContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SqlParser::Table_nameContext* SqlParser::Table_or_subqueryContext::table_name() {
  return getRuleContext<SqlParser::Table_nameContext>(0);
}

SqlParser::Database_nameContext* SqlParser::Table_or_subqueryContext::database_name() {
  return getRuleContext<SqlParser::Database_nameContext>(0);
}

SqlParser::Table_aliasContext* SqlParser::Table_or_subqueryContext::table_alias() {
  return getRuleContext<SqlParser::Table_aliasContext>(0);
}

tree::TerminalNode* SqlParser::Table_or_subqueryContext::K_AS() {
  return getToken(SqlParser::K_AS, 0);
}

std::vector<SqlParser::Table_or_subqueryContext *> SqlParser::Table_or_subqueryContext::table_or_subquery() {
  return getRuleContexts<SqlParser::Table_or_subqueryContext>();
}

SqlParser::Table_or_subqueryContext* SqlParser::Table_or_subqueryContext::table_or_subquery(size_t i) {
  return getRuleContext<SqlParser::Table_or_subqueryContext>(i);
}

SqlParser::Join_clauseContext* SqlParser::Table_or_subqueryContext::join_clause() {
  return getRuleContext<SqlParser::Join_clauseContext>(0);
}

SqlParser::Select_coreContext* SqlParser::Table_or_subqueryContext::select_core() {
  return getRuleContext<SqlParser::Select_coreContext>(0);
}


size_t SqlParser::Table_or_subqueryContext::getRuleIndex() const {
  return SqlParser::RuleTable_or_subquery;
}

void SqlParser::Table_or_subqueryContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTable_or_subquery(this);
}

void SqlParser::Table_or_subqueryContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTable_or_subquery(this);
}


antlrcpp::Any SqlParser::Table_or_subqueryContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlVisitor*>(visitor))
    return parserVisitor->visitTable_or_subquery(this);
  else
    return visitor->visitChildren(this);
}

SqlParser::Table_or_subqueryContext* SqlParser::table_or_subquery() {
  Table_or_subqueryContext *_localctx = _tracker.createInstance<Table_or_subqueryContext>(_ctx, getState());
  enterRule(_localctx, 8, SqlParser::RuleTable_or_subquery);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(239);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 29, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(202);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 20, _ctx)) {
      case 1: {
        setState(199);
        database_name();
        setState(200);
        match(SqlParser::DOT);
        break;
      }

      }
      setState(204);
      table_name();
      setState(209);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx)) {
      case 1: {
        setState(206);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx)) {
        case 1: {
          setState(205);
          match(SqlParser::K_AS);
          break;
        }

        }
        setState(208);
        table_alias();
        break;
      }

      }
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(211);
      match(SqlParser::OPEN_PAR);
      setState(221);
      _errHandler->sync(this);
      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx)) {
      case 1: {
        setState(212);
        table_or_subquery();
        setState(217);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == SqlParser::COMMA) {
          setState(213);
          match(SqlParser::COMMA);
          setState(214);
          table_or_subquery();
          setState(219);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        break;
      }

      case 2: {
        setState(220);
        join_clause();
        break;
      }

      }
      setState(223);
      match(SqlParser::CLOSE_PAR);
      setState(228);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx)) {
      case 1: {
        setState(225);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx)) {
        case 1: {
          setState(224);
          match(SqlParser::K_AS);
          break;
        }

        }
        setState(227);
        table_alias();
        break;
      }

      }
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(230);
      match(SqlParser::OPEN_PAR);
      setState(231);
      select_core();
      setState(232);
      match(SqlParser::CLOSE_PAR);
      setState(237);
      _errHandler->sync(this);

      switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx)) {
      case 1: {
        setState(234);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx)) {
        case 1: {
          setState(233);
          match(SqlParser::K_AS);
          break;
        }

        }
        setState(236);
        table_alias();
        break;
      }

      }
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Join_clauseContext ------------------------------------------------------------------

SqlParser::Join_clauseContext::Join_clauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<SqlParser::Table_or_subqueryContext *> SqlParser::Join_clauseContext::table_or_subquery() {
  return getRuleContexts<SqlParser::Table_or_subqueryContext>();
}

SqlParser::Table_or_subqueryContext* SqlParser::Join_clauseContext::table_or_subquery(size_t i) {
  return getRuleContext<SqlParser::Table_or_subqueryContext>(i);
}

std::vector<SqlParser::Join_operatorContext *> SqlParser::Join_clauseContext::join_operator() {
  return getRuleContexts<SqlParser::Join_operatorContext>();
}

SqlParser::Join_operatorContext* SqlParser::Join_clauseContext::join_operator(size_t i) {
  return getRuleContext<SqlParser::Join_operatorContext>(i);
}

std::vector<SqlParser::Join_constraintContext *> SqlParser::Join_clauseContext::join_constraint() {
  return getRuleContexts<SqlParser::Join_constraintContext>();
}

SqlParser::Join_constraintContext* SqlParser::Join_clauseContext::join_constraint(size_t i) {
  return getRuleContext<SqlParser::Join_constraintContext>(i);
}


size_t SqlParser::Join_clauseContext::getRuleIndex() const {
  return SqlParser::RuleJoin_clause;
}

void SqlParser::Join_clauseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterJoin_clause(this);
}

void SqlParser::Join_clauseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitJoin_clause(this);
}


antlrcpp::Any SqlParser::Join_clauseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlVisitor*>(visitor))
    return parserVisitor->visitJoin_clause(this);
  else
    return visitor->visitChildren(this);
}

SqlParser::Join_clauseContext* SqlParser::join_clause() {
  Join_clauseContext *_localctx = _tracker.createInstance<Join_clauseContext>(_ctx, getState());
  enterRule(_localctx, 10, SqlParser::RuleJoin_clause);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(241);
    table_or_subquery();
    setState(248);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SqlParser::COMMA

    || _la == SqlParser::K_CROSS || ((((_la - 87) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 87)) & ((1ULL << (SqlParser::K_INNER - 87))
      | (1ULL << (SqlParser::K_JOIN - 87))
      | (1ULL << (SqlParser::K_LEFT - 87)))) != 0)) {
      setState(242);
      join_operator();
      setState(243);
      table_or_subquery();
      setState(244);
      join_constraint();
      setState(250);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Join_operatorContext ------------------------------------------------------------------

SqlParser::Join_operatorContext::Join_operatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SqlParser::Join_operatorContext::K_JOIN() {
  return getToken(SqlParser::K_JOIN, 0);
}

tree::TerminalNode* SqlParser::Join_operatorContext::K_LEFT() {
  return getToken(SqlParser::K_LEFT, 0);
}

tree::TerminalNode* SqlParser::Join_operatorContext::K_INNER() {
  return getToken(SqlParser::K_INNER, 0);
}

tree::TerminalNode* SqlParser::Join_operatorContext::K_CROSS() {
  return getToken(SqlParser::K_CROSS, 0);
}

tree::TerminalNode* SqlParser::Join_operatorContext::K_OUTER() {
  return getToken(SqlParser::K_OUTER, 0);
}


size_t SqlParser::Join_operatorContext::getRuleIndex() const {
  return SqlParser::RuleJoin_operator;
}

void SqlParser::Join_operatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterJoin_operator(this);
}

void SqlParser::Join_operatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitJoin_operator(this);
}


antlrcpp::Any SqlParser::Join_operatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlVisitor*>(visitor))
    return parserVisitor->visitJoin_operator(this);
  else
    return visitor->visitChildren(this);
}

SqlParser::Join_operatorContext* SqlParser::join_operator() {
  Join_operatorContext *_localctx = _tracker.createInstance<Join_operatorContext>(_ctx, getState());
  enterRule(_localctx, 12, SqlParser::RuleJoin_operator);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(261);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SqlParser::COMMA: {
        enterOuterAlt(_localctx, 1);
        setState(251);
        match(SqlParser::COMMA);
        break;
      }

      case SqlParser::K_CROSS:
      case SqlParser::K_INNER:
      case SqlParser::K_JOIN:
      case SqlParser::K_LEFT: {
        enterOuterAlt(_localctx, 2);
        setState(258);
        _errHandler->sync(this);
        switch (_input->LA(1)) {
          case SqlParser::K_LEFT: {
            setState(252);
            match(SqlParser::K_LEFT);
            setState(254);
            _errHandler->sync(this);

            _la = _input->LA(1);
            if (_la == SqlParser::K_OUTER) {
              setState(253);
              match(SqlParser::K_OUTER);
            }
            break;
          }

          case SqlParser::K_INNER: {
            setState(256);
            match(SqlParser::K_INNER);
            break;
          }

          case SqlParser::K_CROSS: {
            setState(257);
            match(SqlParser::K_CROSS);
            break;
          }

          case SqlParser::K_JOIN: {
            break;
          }

        default:
          break;
        }
        setState(260);
        match(SqlParser::K_JOIN);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Join_constraintContext ------------------------------------------------------------------

SqlParser::Join_constraintContext::Join_constraintContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SqlParser::Join_constraintContext::K_ON() {
  return getToken(SqlParser::K_ON, 0);
}

SqlParser::ExprContext* SqlParser::Join_constraintContext::expr() {
  return getRuleContext<SqlParser::ExprContext>(0);
}

tree::TerminalNode* SqlParser::Join_constraintContext::K_USING() {
  return getToken(SqlParser::K_USING, 0);
}

std::vector<SqlParser::Column_nameContext *> SqlParser::Join_constraintContext::column_name() {
  return getRuleContexts<SqlParser::Column_nameContext>();
}

SqlParser::Column_nameContext* SqlParser::Join_constraintContext::column_name(size_t i) {
  return getRuleContext<SqlParser::Column_nameContext>(i);
}


size_t SqlParser::Join_constraintContext::getRuleIndex() const {
  return SqlParser::RuleJoin_constraint;
}

void SqlParser::Join_constraintContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterJoin_constraint(this);
}

void SqlParser::Join_constraintContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitJoin_constraint(this);
}


antlrcpp::Any SqlParser::Join_constraintContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlVisitor*>(visitor))
    return parserVisitor->visitJoin_constraint(this);
  else
    return visitor->visitChildren(this);
}

SqlParser::Join_constraintContext* SqlParser::join_constraint() {
  Join_constraintContext *_localctx = _tracker.createInstance<Join_constraintContext>(_ctx, getState());
  enterRule(_localctx, 14, SqlParser::RuleJoin_constraint);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(277);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SqlParser::K_ON: {
        setState(263);
        match(SqlParser::K_ON);
        setState(264);
        expr(0);
        break;
      }

      case SqlParser::K_USING: {
        setState(265);
        match(SqlParser::K_USING);
        setState(266);
        match(SqlParser::OPEN_PAR);
        setState(267);
        column_name();
        setState(272);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == SqlParser::COMMA) {
          setState(268);
          match(SqlParser::COMMA);
          setState(269);
          column_name();
          setState(274);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(275);
        match(SqlParser::CLOSE_PAR);
        break;
      }

      case SqlParser::EOF:
      case SqlParser::CLOSE_PAR:
      case SqlParser::COMMA:
      case SqlParser::K_CROSS:
      case SqlParser::K_GROUP:
      case SqlParser::K_INNER:
      case SqlParser::K_JOIN:
      case SqlParser::K_LEFT:
      case SqlParser::K_SELECT:
      case SqlParser::K_VALUES:
      case SqlParser::K_WHERE: {
        break;
      }

    default:
      break;
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Select_coreContext ------------------------------------------------------------------

SqlParser::Select_coreContext::Select_coreContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SqlParser::Select_coreContext::K_SELECT() {
  return getToken(SqlParser::K_SELECT, 0);
}

std::vector<SqlParser::Result_columnContext *> SqlParser::Select_coreContext::result_column() {
  return getRuleContexts<SqlParser::Result_columnContext>();
}

SqlParser::Result_columnContext* SqlParser::Select_coreContext::result_column(size_t i) {
  return getRuleContext<SqlParser::Result_columnContext>(i);
}

tree::TerminalNode* SqlParser::Select_coreContext::K_FROM() {
  return getToken(SqlParser::K_FROM, 0);
}

SqlParser::Where_clauseContext* SqlParser::Select_coreContext::where_clause() {
  return getRuleContext<SqlParser::Where_clauseContext>(0);
}

SqlParser::Group_by_clauseContext* SqlParser::Select_coreContext::group_by_clause() {
  return getRuleContext<SqlParser::Group_by_clauseContext>(0);
}

tree::TerminalNode* SqlParser::Select_coreContext::K_DISTINCT() {
  return getToken(SqlParser::K_DISTINCT, 0);
}

tree::TerminalNode* SqlParser::Select_coreContext::K_ALL() {
  return getToken(SqlParser::K_ALL, 0);
}

std::vector<SqlParser::Table_or_subqueryContext *> SqlParser::Select_coreContext::table_or_subquery() {
  return getRuleContexts<SqlParser::Table_or_subqueryContext>();
}

SqlParser::Table_or_subqueryContext* SqlParser::Select_coreContext::table_or_subquery(size_t i) {
  return getRuleContext<SqlParser::Table_or_subqueryContext>(i);
}

SqlParser::Join_clauseContext* SqlParser::Select_coreContext::join_clause() {
  return getRuleContext<SqlParser::Join_clauseContext>(0);
}

tree::TerminalNode* SqlParser::Select_coreContext::K_VALUES() {
  return getToken(SqlParser::K_VALUES, 0);
}

std::vector<SqlParser::ExprContext *> SqlParser::Select_coreContext::expr() {
  return getRuleContexts<SqlParser::ExprContext>();
}

SqlParser::ExprContext* SqlParser::Select_coreContext::expr(size_t i) {
  return getRuleContext<SqlParser::ExprContext>(i);
}

tree::TerminalNode* SqlParser::Select_coreContext::SCOL() {
  return getToken(SqlParser::SCOL, 0);
}


size_t SqlParser::Select_coreContext::getRuleIndex() const {
  return SqlParser::RuleSelect_core;
}

void SqlParser::Select_coreContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSelect_core(this);
}

void SqlParser::Select_coreContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSelect_core(this);
}


antlrcpp::Any SqlParser::Select_coreContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlVisitor*>(visitor))
    return parserVisitor->visitSelect_core(this);
  else
    return visitor->visitChildren(this);
}

SqlParser::Select_coreContext* SqlParser::select_core() {
  Select_coreContext *_localctx = _tracker.createInstance<Select_coreContext>(_ctx, getState());
  enterRule(_localctx, 16, SqlParser::RuleSelect_core);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(341);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SqlParser::K_SELECT: {
        enterOuterAlt(_localctx, 1);
        setState(279);
        match(SqlParser::K_SELECT);
        setState(281);
        _errHandler->sync(this);

        switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 36, _ctx)) {
        case 1: {
          setState(280);
          _la = _input->LA(1);
          if (!(_la == SqlParser::K_ALL

          || _la == SqlParser::K_DISTINCT)) {
          _errHandler->recoverInline(this);
          }
          else {
            _errHandler->reportMatch(this);
            consume();
          }
          break;
        }

        }
        setState(283);
        result_column();
        setState(288);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == SqlParser::COMMA) {
          setState(284);
          match(SqlParser::COMMA);
          setState(285);
          result_column();
          setState(290);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(303);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == SqlParser::K_FROM) {
          setState(291);
          match(SqlParser::K_FROM);
          setState(301);
          _errHandler->sync(this);
          switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 39, _ctx)) {
          case 1: {
            setState(292);
            table_or_subquery();
            setState(297);
            _errHandler->sync(this);
            _la = _input->LA(1);
            while (_la == SqlParser::COMMA) {
              setState(293);
              match(SqlParser::COMMA);
              setState(294);
              table_or_subquery();
              setState(299);
              _errHandler->sync(this);
              _la = _input->LA(1);
            }
            break;
          }

          case 2: {
            setState(300);
            join_clause();
            break;
          }

          }
        }
        setState(306);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == SqlParser::K_WHERE) {
          setState(305);
          where_clause();
        }
        setState(309);
        _errHandler->sync(this);

        _la = _input->LA(1);
        if (_la == SqlParser::K_GROUP) {
          setState(308);
          group_by_clause();
        }
        break;
      }

      case SqlParser::K_VALUES: {
        enterOuterAlt(_localctx, 2);
        setState(311);
        match(SqlParser::K_VALUES);
        setState(312);
        match(SqlParser::OPEN_PAR);
        setState(313);
        expr(0);
        setState(318);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == SqlParser::COMMA) {
          setState(314);
          match(SqlParser::COMMA);
          setState(315);
          expr(0);
          setState(320);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(321);
        match(SqlParser::CLOSE_PAR);
        setState(336);
        _errHandler->sync(this);
        _la = _input->LA(1);
        while (_la == SqlParser::COMMA) {
          setState(322);
          match(SqlParser::COMMA);
          setState(323);
          match(SqlParser::OPEN_PAR);
          setState(324);
          expr(0);
          setState(329);
          _errHandler->sync(this);
          _la = _input->LA(1);
          while (_la == SqlParser::COMMA) {
            setState(325);
            match(SqlParser::COMMA);
            setState(326);
            expr(0);
            setState(331);
            _errHandler->sync(this);
            _la = _input->LA(1);
          }
          setState(332);
          match(SqlParser::CLOSE_PAR);
          setState(338);
          _errHandler->sync(this);
          _la = _input->LA(1);
        }
        setState(339);
        match(SqlParser::SCOL);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Where_clauseContext ------------------------------------------------------------------

SqlParser::Where_clauseContext::Where_clauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SqlParser::Where_clauseContext::K_WHERE() {
  return getToken(SqlParser::K_WHERE, 0);
}

SqlParser::ExprContext* SqlParser::Where_clauseContext::expr() {
  return getRuleContext<SqlParser::ExprContext>(0);
}


size_t SqlParser::Where_clauseContext::getRuleIndex() const {
  return SqlParser::RuleWhere_clause;
}

void SqlParser::Where_clauseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWhere_clause(this);
}

void SqlParser::Where_clauseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWhere_clause(this);
}


antlrcpp::Any SqlParser::Where_clauseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlVisitor*>(visitor))
    return parserVisitor->visitWhere_clause(this);
  else
    return visitor->visitChildren(this);
}

SqlParser::Where_clauseContext* SqlParser::where_clause() {
  Where_clauseContext *_localctx = _tracker.createInstance<Where_clauseContext>(_ctx, getState());
  enterRule(_localctx, 18, SqlParser::RuleWhere_clause);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(343);
    match(SqlParser::K_WHERE);
    setState(344);
    expr(0);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Group_by_clauseContext ------------------------------------------------------------------

SqlParser::Group_by_clauseContext::Group_by_clauseContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SqlParser::Group_by_clauseContext::K_GROUP() {
  return getToken(SqlParser::K_GROUP, 0);
}

tree::TerminalNode* SqlParser::Group_by_clauseContext::K_BY() {
  return getToken(SqlParser::K_BY, 0);
}

std::vector<SqlParser::ExprContext *> SqlParser::Group_by_clauseContext::expr() {
  return getRuleContexts<SqlParser::ExprContext>();
}

SqlParser::ExprContext* SqlParser::Group_by_clauseContext::expr(size_t i) {
  return getRuleContext<SqlParser::ExprContext>(i);
}


size_t SqlParser::Group_by_clauseContext::getRuleIndex() const {
  return SqlParser::RuleGroup_by_clause;
}

void SqlParser::Group_by_clauseContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterGroup_by_clause(this);
}

void SqlParser::Group_by_clauseContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitGroup_by_clause(this);
}


antlrcpp::Any SqlParser::Group_by_clauseContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlVisitor*>(visitor))
    return parserVisitor->visitGroup_by_clause(this);
  else
    return visitor->visitChildren(this);
}

SqlParser::Group_by_clauseContext* SqlParser::group_by_clause() {
  Group_by_clauseContext *_localctx = _tracker.createInstance<Group_by_clauseContext>(_ctx, getState());
  enterRule(_localctx, 20, SqlParser::RuleGroup_by_clause);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(346);
    match(SqlParser::K_GROUP);
    setState(347);
    match(SqlParser::K_BY);
    setState(348);
    expr(0);
    setState(353);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == SqlParser::COMMA) {
      setState(349);
      match(SqlParser::COMMA);
      setState(350);
      expr(0);
      setState(355);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Signed_numberContext ------------------------------------------------------------------

SqlParser::Signed_numberContext::Signed_numberContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SqlParser::Signed_numberContext::NUMERIC_LITERAL() {
  return getToken(SqlParser::NUMERIC_LITERAL, 0);
}


size_t SqlParser::Signed_numberContext::getRuleIndex() const {
  return SqlParser::RuleSigned_number;
}

void SqlParser::Signed_numberContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSigned_number(this);
}

void SqlParser::Signed_numberContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSigned_number(this);
}


antlrcpp::Any SqlParser::Signed_numberContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlVisitor*>(visitor))
    return parserVisitor->visitSigned_number(this);
  else
    return visitor->visitChildren(this);
}

SqlParser::Signed_numberContext* SqlParser::signed_number() {
  Signed_numberContext *_localctx = _tracker.createInstance<Signed_numberContext>(_ctx, getState());
  enterRule(_localctx, 22, SqlParser::RuleSigned_number);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(357);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == SqlParser::PLUS

    || _la == SqlParser::MINUS) {
      setState(356);
      _la = _input->LA(1);
      if (!(_la == SqlParser::PLUS

      || _la == SqlParser::MINUS)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
    }
    setState(359);
    match(SqlParser::NUMERIC_LITERAL);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Literal_valueContext ------------------------------------------------------------------

SqlParser::Literal_valueContext::Literal_valueContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SqlParser::Literal_valueContext::NUMERIC_LITERAL() {
  return getToken(SqlParser::NUMERIC_LITERAL, 0);
}

tree::TerminalNode* SqlParser::Literal_valueContext::STRING_LITERAL() {
  return getToken(SqlParser::STRING_LITERAL, 0);
}

tree::TerminalNode* SqlParser::Literal_valueContext::BLOB_LITERAL() {
  return getToken(SqlParser::BLOB_LITERAL, 0);
}

tree::TerminalNode* SqlParser::Literal_valueContext::K_NULL() {
  return getToken(SqlParser::K_NULL, 0);
}

tree::TerminalNode* SqlParser::Literal_valueContext::K_CURRENT_TIME() {
  return getToken(SqlParser::K_CURRENT_TIME, 0);
}

tree::TerminalNode* SqlParser::Literal_valueContext::K_CURRENT_DATE() {
  return getToken(SqlParser::K_CURRENT_DATE, 0);
}

tree::TerminalNode* SqlParser::Literal_valueContext::K_CURRENT_TIMESTAMP() {
  return getToken(SqlParser::K_CURRENT_TIMESTAMP, 0);
}


size_t SqlParser::Literal_valueContext::getRuleIndex() const {
  return SqlParser::RuleLiteral_value;
}

void SqlParser::Literal_valueContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterLiteral_value(this);
}

void SqlParser::Literal_valueContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitLiteral_value(this);
}


antlrcpp::Any SqlParser::Literal_valueContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlVisitor*>(visitor))
    return parserVisitor->visitLiteral_value(this);
  else
    return visitor->visitChildren(this);
}

SqlParser::Literal_valueContext* SqlParser::literal_value() {
  Literal_valueContext *_localctx = _tracker.createInstance<Literal_valueContext>(_ctx, getState());
  enterRule(_localctx, 24, SqlParser::RuleLiteral_value);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(361);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SqlParser::K_CURRENT_DATE)
      | (1ULL << SqlParser::K_CURRENT_TIME)
      | (1ULL << SqlParser::K_CURRENT_TIMESTAMP))) != 0) || ((((_la - 105) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 105)) & ((1ULL << (SqlParser::K_NULL - 105))
      | (1ULL << (SqlParser::NUMERIC_LITERAL - 105))
      | (1ULL << (SqlParser::STRING_LITERAL - 105))
      | (1ULL << (SqlParser::BLOB_LITERAL - 105)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Unary_operatorContext ------------------------------------------------------------------

SqlParser::Unary_operatorContext::Unary_operatorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SqlParser::Unary_operatorContext::K_NOT() {
  return getToken(SqlParser::K_NOT, 0);
}


size_t SqlParser::Unary_operatorContext::getRuleIndex() const {
  return SqlParser::RuleUnary_operator;
}

void SqlParser::Unary_operatorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterUnary_operator(this);
}

void SqlParser::Unary_operatorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitUnary_operator(this);
}


antlrcpp::Any SqlParser::Unary_operatorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlVisitor*>(visitor))
    return parserVisitor->visitUnary_operator(this);
  else
    return visitor->visitChildren(this);
}

SqlParser::Unary_operatorContext* SqlParser::unary_operator() {
  Unary_operatorContext *_localctx = _tracker.createInstance<Unary_operatorContext>(_ctx, getState());
  enterRule(_localctx, 26, SqlParser::RuleUnary_operator);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(363);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << SqlParser::PLUS)
      | (1ULL << SqlParser::MINUS)
      | (1ULL << SqlParser::TILDE))) != 0) || _la == SqlParser::K_NOT)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Error_messageContext ------------------------------------------------------------------

SqlParser::Error_messageContext::Error_messageContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SqlParser::Error_messageContext::STRING_LITERAL() {
  return getToken(SqlParser::STRING_LITERAL, 0);
}


size_t SqlParser::Error_messageContext::getRuleIndex() const {
  return SqlParser::RuleError_message;
}

void SqlParser::Error_messageContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterError_message(this);
}

void SqlParser::Error_messageContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitError_message(this);
}


antlrcpp::Any SqlParser::Error_messageContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlVisitor*>(visitor))
    return parserVisitor->visitError_message(this);
  else
    return visitor->visitChildren(this);
}

SqlParser::Error_messageContext* SqlParser::error_message() {
  Error_messageContext *_localctx = _tracker.createInstance<Error_messageContext>(_ctx, getState());
  enterRule(_localctx, 28, SqlParser::RuleError_message);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(365);
    match(SqlParser::STRING_LITERAL);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Column_aliasContext ------------------------------------------------------------------

SqlParser::Column_aliasContext::Column_aliasContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SqlParser::Column_aliasContext::IDENTIFIER() {
  return getToken(SqlParser::IDENTIFIER, 0);
}

tree::TerminalNode* SqlParser::Column_aliasContext::STRING_LITERAL() {
  return getToken(SqlParser::STRING_LITERAL, 0);
}


size_t SqlParser::Column_aliasContext::getRuleIndex() const {
  return SqlParser::RuleColumn_alias;
}

void SqlParser::Column_aliasContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterColumn_alias(this);
}

void SqlParser::Column_aliasContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitColumn_alias(this);
}


antlrcpp::Any SqlParser::Column_aliasContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlVisitor*>(visitor))
    return parserVisitor->visitColumn_alias(this);
  else
    return visitor->visitChildren(this);
}

SqlParser::Column_aliasContext* SqlParser::column_alias() {
  Column_aliasContext *_localctx = _tracker.createInstance<Column_aliasContext>(_ctx, getState());
  enterRule(_localctx, 30, SqlParser::RuleColumn_alias);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(367);
    _la = _input->LA(1);
    if (!(_la == SqlParser::IDENTIFIER

    || _la == SqlParser::STRING_LITERAL)) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- KeywordContext ------------------------------------------------------------------

SqlParser::KeywordContext::KeywordContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SqlParser::KeywordContext::K_ABORT() {
  return getToken(SqlParser::K_ABORT, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_ACTION() {
  return getToken(SqlParser::K_ACTION, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_ADD() {
  return getToken(SqlParser::K_ADD, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_AFTER() {
  return getToken(SqlParser::K_AFTER, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_ALL() {
  return getToken(SqlParser::K_ALL, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_ALTER() {
  return getToken(SqlParser::K_ALTER, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_ANALYZE() {
  return getToken(SqlParser::K_ANALYZE, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_AND() {
  return getToken(SqlParser::K_AND, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_AS() {
  return getToken(SqlParser::K_AS, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_ASC() {
  return getToken(SqlParser::K_ASC, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_ATTACH() {
  return getToken(SqlParser::K_ATTACH, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_AUTOINCREMENT() {
  return getToken(SqlParser::K_AUTOINCREMENT, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_BEFORE() {
  return getToken(SqlParser::K_BEFORE, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_BEGIN() {
  return getToken(SqlParser::K_BEGIN, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_BETWEEN() {
  return getToken(SqlParser::K_BETWEEN, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_BY() {
  return getToken(SqlParser::K_BY, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_CASCADE() {
  return getToken(SqlParser::K_CASCADE, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_CASE() {
  return getToken(SqlParser::K_CASE, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_CAST() {
  return getToken(SqlParser::K_CAST, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_CHECK() {
  return getToken(SqlParser::K_CHECK, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_COLLATE() {
  return getToken(SqlParser::K_COLLATE, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_COLUMN() {
  return getToken(SqlParser::K_COLUMN, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_COMMIT() {
  return getToken(SqlParser::K_COMMIT, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_CONFLICT() {
  return getToken(SqlParser::K_CONFLICT, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_CONSTRAINT() {
  return getToken(SqlParser::K_CONSTRAINT, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_CREATE() {
  return getToken(SqlParser::K_CREATE, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_CROSS() {
  return getToken(SqlParser::K_CROSS, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_CURRENT_DATE() {
  return getToken(SqlParser::K_CURRENT_DATE, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_CURRENT_TIME() {
  return getToken(SqlParser::K_CURRENT_TIME, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_CURRENT_TIMESTAMP() {
  return getToken(SqlParser::K_CURRENT_TIMESTAMP, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_DATABASE() {
  return getToken(SqlParser::K_DATABASE, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_DEFAULT() {
  return getToken(SqlParser::K_DEFAULT, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_DEFERRABLE() {
  return getToken(SqlParser::K_DEFERRABLE, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_DEFERRED() {
  return getToken(SqlParser::K_DEFERRED, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_DELETE() {
  return getToken(SqlParser::K_DELETE, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_DESC() {
  return getToken(SqlParser::K_DESC, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_DETACH() {
  return getToken(SqlParser::K_DETACH, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_DISTINCT() {
  return getToken(SqlParser::K_DISTINCT, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_DROP() {
  return getToken(SqlParser::K_DROP, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_EACH() {
  return getToken(SqlParser::K_EACH, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_ELSE() {
  return getToken(SqlParser::K_ELSE, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_END() {
  return getToken(SqlParser::K_END, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_ESCAPE() {
  return getToken(SqlParser::K_ESCAPE, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_EXCEPT() {
  return getToken(SqlParser::K_EXCEPT, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_EXCLUSIVE() {
  return getToken(SqlParser::K_EXCLUSIVE, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_EXISTS() {
  return getToken(SqlParser::K_EXISTS, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_EXPLAIN() {
  return getToken(SqlParser::K_EXPLAIN, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_FAIL() {
  return getToken(SqlParser::K_FAIL, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_FOR() {
  return getToken(SqlParser::K_FOR, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_FOREIGN() {
  return getToken(SqlParser::K_FOREIGN, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_FROM() {
  return getToken(SqlParser::K_FROM, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_FULL() {
  return getToken(SqlParser::K_FULL, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_GLOB() {
  return getToken(SqlParser::K_GLOB, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_GROUP() {
  return getToken(SqlParser::K_GROUP, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_HAVING() {
  return getToken(SqlParser::K_HAVING, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_IF() {
  return getToken(SqlParser::K_IF, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_IGNORE() {
  return getToken(SqlParser::K_IGNORE, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_IMMEDIATE() {
  return getToken(SqlParser::K_IMMEDIATE, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_IN() {
  return getToken(SqlParser::K_IN, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_INDEX() {
  return getToken(SqlParser::K_INDEX, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_INDEXED() {
  return getToken(SqlParser::K_INDEXED, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_INITIALLY() {
  return getToken(SqlParser::K_INITIALLY, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_INNER() {
  return getToken(SqlParser::K_INNER, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_INSERT() {
  return getToken(SqlParser::K_INSERT, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_INSTEAD() {
  return getToken(SqlParser::K_INSTEAD, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_INTERSECT() {
  return getToken(SqlParser::K_INTERSECT, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_INTO() {
  return getToken(SqlParser::K_INTO, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_IS() {
  return getToken(SqlParser::K_IS, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_ISNOT() {
  return getToken(SqlParser::K_ISNOT, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_ISNULL() {
  return getToken(SqlParser::K_ISNULL, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_JOIN() {
  return getToken(SqlParser::K_JOIN, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_KEY() {
  return getToken(SqlParser::K_KEY, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_LEFT() {
  return getToken(SqlParser::K_LEFT, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_LIKE() {
  return getToken(SqlParser::K_LIKE, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_LIMIT() {
  return getToken(SqlParser::K_LIMIT, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_MATCH() {
  return getToken(SqlParser::K_MATCH, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_NATURAL() {
  return getToken(SqlParser::K_NATURAL, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_NO() {
  return getToken(SqlParser::K_NO, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_NOT() {
  return getToken(SqlParser::K_NOT, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_NOTNULL() {
  return getToken(SqlParser::K_NOTNULL, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_NULL() {
  return getToken(SqlParser::K_NULL, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_OF() {
  return getToken(SqlParser::K_OF, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_OFFSET() {
  return getToken(SqlParser::K_OFFSET, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_ON() {
  return getToken(SqlParser::K_ON, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_OR() {
  return getToken(SqlParser::K_OR, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_ORDER() {
  return getToken(SqlParser::K_ORDER, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_OUTER() {
  return getToken(SqlParser::K_OUTER, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_PLAN() {
  return getToken(SqlParser::K_PLAN, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_PRAGMA() {
  return getToken(SqlParser::K_PRAGMA, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_PRIMARY() {
  return getToken(SqlParser::K_PRIMARY, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_QUERY() {
  return getToken(SqlParser::K_QUERY, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_RAISE() {
  return getToken(SqlParser::K_RAISE, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_RECURSIVE() {
  return getToken(SqlParser::K_RECURSIVE, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_REFERENCES() {
  return getToken(SqlParser::K_REFERENCES, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_REGEXP() {
  return getToken(SqlParser::K_REGEXP, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_REINDEX() {
  return getToken(SqlParser::K_REINDEX, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_RELEASE() {
  return getToken(SqlParser::K_RELEASE, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_RENAME() {
  return getToken(SqlParser::K_RENAME, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_REPLACE() {
  return getToken(SqlParser::K_REPLACE, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_RESTRICT() {
  return getToken(SqlParser::K_RESTRICT, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_RIGHT() {
  return getToken(SqlParser::K_RIGHT, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_ROLLBACK() {
  return getToken(SqlParser::K_ROLLBACK, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_ROW() {
  return getToken(SqlParser::K_ROW, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_SAVEPOINT() {
  return getToken(SqlParser::K_SAVEPOINT, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_SELECT() {
  return getToken(SqlParser::K_SELECT, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_SET() {
  return getToken(SqlParser::K_SET, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_TABLE() {
  return getToken(SqlParser::K_TABLE, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_TEMP() {
  return getToken(SqlParser::K_TEMP, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_TEMPORARY() {
  return getToken(SqlParser::K_TEMPORARY, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_THEN() {
  return getToken(SqlParser::K_THEN, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_TO() {
  return getToken(SqlParser::K_TO, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_TRANSACTION() {
  return getToken(SqlParser::K_TRANSACTION, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_TRIGGER() {
  return getToken(SqlParser::K_TRIGGER, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_UNION() {
  return getToken(SqlParser::K_UNION, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_UNIQUE() {
  return getToken(SqlParser::K_UNIQUE, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_UPDATE() {
  return getToken(SqlParser::K_UPDATE, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_USING() {
  return getToken(SqlParser::K_USING, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_VACUUM() {
  return getToken(SqlParser::K_VACUUM, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_VALUES() {
  return getToken(SqlParser::K_VALUES, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_VIEW() {
  return getToken(SqlParser::K_VIEW, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_VIRTUAL() {
  return getToken(SqlParser::K_VIRTUAL, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_WHEN() {
  return getToken(SqlParser::K_WHEN, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_WHERE() {
  return getToken(SqlParser::K_WHERE, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_WITH() {
  return getToken(SqlParser::K_WITH, 0);
}

tree::TerminalNode* SqlParser::KeywordContext::K_WITHOUT() {
  return getToken(SqlParser::K_WITHOUT, 0);
}


size_t SqlParser::KeywordContext::getRuleIndex() const {
  return SqlParser::RuleKeyword;
}

void SqlParser::KeywordContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterKeyword(this);
}

void SqlParser::KeywordContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitKeyword(this);
}


antlrcpp::Any SqlParser::KeywordContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlVisitor*>(visitor))
    return parserVisitor->visitKeyword(this);
  else
    return visitor->visitChildren(this);
}

SqlParser::KeywordContext* SqlParser::keyword() {
  KeywordContext *_localctx = _tracker.createInstance<KeywordContext>(_ctx, getState());
  enterRule(_localctx, 32, SqlParser::RuleKeyword);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(369);
    _la = _input->LA(1);
    if (!(((((_la - 25) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 25)) & ((1ULL << (SqlParser::K_ABORT - 25))
      | (1ULL << (SqlParser::K_ACTION - 25))
      | (1ULL << (SqlParser::K_ADD - 25))
      | (1ULL << (SqlParser::K_AFTER - 25))
      | (1ULL << (SqlParser::K_ALL - 25))
      | (1ULL << (SqlParser::K_ALTER - 25))
      | (1ULL << (SqlParser::K_ANALYZE - 25))
      | (1ULL << (SqlParser::K_AND - 25))
      | (1ULL << (SqlParser::K_AS - 25))
      | (1ULL << (SqlParser::K_ASC - 25))
      | (1ULL << (SqlParser::K_ATTACH - 25))
      | (1ULL << (SqlParser::K_AUTOINCREMENT - 25))
      | (1ULL << (SqlParser::K_BEFORE - 25))
      | (1ULL << (SqlParser::K_BEGIN - 25))
      | (1ULL << (SqlParser::K_BETWEEN - 25))
      | (1ULL << (SqlParser::K_BY - 25))
      | (1ULL << (SqlParser::K_CASCADE - 25))
      | (1ULL << (SqlParser::K_CASE - 25))
      | (1ULL << (SqlParser::K_CAST - 25))
      | (1ULL << (SqlParser::K_CHECK - 25))
      | (1ULL << (SqlParser::K_COLLATE - 25))
      | (1ULL << (SqlParser::K_COLUMN - 25))
      | (1ULL << (SqlParser::K_COMMIT - 25))
      | (1ULL << (SqlParser::K_CONFLICT - 25))
      | (1ULL << (SqlParser::K_CONSTRAINT - 25))
      | (1ULL << (SqlParser::K_CREATE - 25))
      | (1ULL << (SqlParser::K_CROSS - 25))
      | (1ULL << (SqlParser::K_CURRENT_DATE - 25))
      | (1ULL << (SqlParser::K_CURRENT_TIME - 25))
      | (1ULL << (SqlParser::K_CURRENT_TIMESTAMP - 25))
      | (1ULL << (SqlParser::K_DATABASE - 25))
      | (1ULL << (SqlParser::K_DEFAULT - 25))
      | (1ULL << (SqlParser::K_DEFERRABLE - 25))
      | (1ULL << (SqlParser::K_DEFERRED - 25))
      | (1ULL << (SqlParser::K_DELETE - 25))
      | (1ULL << (SqlParser::K_DESC - 25))
      | (1ULL << (SqlParser::K_DETACH - 25))
      | (1ULL << (SqlParser::K_DISTINCT - 25))
      | (1ULL << (SqlParser::K_DROP - 25))
      | (1ULL << (SqlParser::K_EACH - 25))
      | (1ULL << (SqlParser::K_ELSE - 25))
      | (1ULL << (SqlParser::K_END - 25))
      | (1ULL << (SqlParser::K_ESCAPE - 25))
      | (1ULL << (SqlParser::K_EXCEPT - 25))
      | (1ULL << (SqlParser::K_EXCLUSIVE - 25))
      | (1ULL << (SqlParser::K_EXISTS - 25))
      | (1ULL << (SqlParser::K_EXPLAIN - 25))
      | (1ULL << (SqlParser::K_FAIL - 25))
      | (1ULL << (SqlParser::K_FOR - 25))
      | (1ULL << (SqlParser::K_FOREIGN - 25))
      | (1ULL << (SqlParser::K_FROM - 25))
      | (1ULL << (SqlParser::K_FULL - 25))
      | (1ULL << (SqlParser::K_GLOB - 25))
      | (1ULL << (SqlParser::K_GROUP - 25))
      | (1ULL << (SqlParser::K_HAVING - 25))
      | (1ULL << (SqlParser::K_IF - 25))
      | (1ULL << (SqlParser::K_IGNORE - 25))
      | (1ULL << (SqlParser::K_IMMEDIATE - 25))
      | (1ULL << (SqlParser::K_IN - 25))
      | (1ULL << (SqlParser::K_INDEX - 25))
      | (1ULL << (SqlParser::K_INDEXED - 25))
      | (1ULL << (SqlParser::K_INITIALLY - 25))
      | (1ULL << (SqlParser::K_INNER - 25))
      | (1ULL << (SqlParser::K_INSERT - 25)))) != 0) || ((((_la - 89) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 89)) & ((1ULL << (SqlParser::K_INSTEAD - 89))
      | (1ULL << (SqlParser::K_INTERSECT - 89))
      | (1ULL << (SqlParser::K_INTO - 89))
      | (1ULL << (SqlParser::K_IS - 89))
      | (1ULL << (SqlParser::K_ISNOT - 89))
      | (1ULL << (SqlParser::K_ISNULL - 89))
      | (1ULL << (SqlParser::K_JOIN - 89))
      | (1ULL << (SqlParser::K_KEY - 89))
      | (1ULL << (SqlParser::K_LEFT - 89))
      | (1ULL << (SqlParser::K_LIKE - 89))
      | (1ULL << (SqlParser::K_LIMIT - 89))
      | (1ULL << (SqlParser::K_MATCH - 89))
      | (1ULL << (SqlParser::K_NATURAL - 89))
      | (1ULL << (SqlParser::K_NO - 89))
      | (1ULL << (SqlParser::K_NOT - 89))
      | (1ULL << (SqlParser::K_NOTNULL - 89))
      | (1ULL << (SqlParser::K_NULL - 89))
      | (1ULL << (SqlParser::K_OF - 89))
      | (1ULL << (SqlParser::K_OFFSET - 89))
      | (1ULL << (SqlParser::K_ON - 89))
      | (1ULL << (SqlParser::K_OR - 89))
      | (1ULL << (SqlParser::K_ORDER - 89))
      | (1ULL << (SqlParser::K_OUTER - 89))
      | (1ULL << (SqlParser::K_PLAN - 89))
      | (1ULL << (SqlParser::K_PRAGMA - 89))
      | (1ULL << (SqlParser::K_PRIMARY - 89))
      | (1ULL << (SqlParser::K_QUERY - 89))
      | (1ULL << (SqlParser::K_RAISE - 89))
      | (1ULL << (SqlParser::K_RECURSIVE - 89))
      | (1ULL << (SqlParser::K_REFERENCES - 89))
      | (1ULL << (SqlParser::K_REGEXP - 89))
      | (1ULL << (SqlParser::K_REINDEX - 89))
      | (1ULL << (SqlParser::K_RELEASE - 89))
      | (1ULL << (SqlParser::K_RENAME - 89))
      | (1ULL << (SqlParser::K_REPLACE - 89))
      | (1ULL << (SqlParser::K_RESTRICT - 89))
      | (1ULL << (SqlParser::K_RIGHT - 89))
      | (1ULL << (SqlParser::K_ROLLBACK - 89))
      | (1ULL << (SqlParser::K_ROW - 89))
      | (1ULL << (SqlParser::K_SAVEPOINT - 89))
      | (1ULL << (SqlParser::K_SELECT - 89))
      | (1ULL << (SqlParser::K_SET - 89))
      | (1ULL << (SqlParser::K_TABLE - 89))
      | (1ULL << (SqlParser::K_TEMP - 89))
      | (1ULL << (SqlParser::K_TEMPORARY - 89))
      | (1ULL << (SqlParser::K_THEN - 89))
      | (1ULL << (SqlParser::K_TO - 89))
      | (1ULL << (SqlParser::K_TRANSACTION - 89))
      | (1ULL << (SqlParser::K_TRIGGER - 89))
      | (1ULL << (SqlParser::K_UNION - 89))
      | (1ULL << (SqlParser::K_UNIQUE - 89))
      | (1ULL << (SqlParser::K_UPDATE - 89))
      | (1ULL << (SqlParser::K_USING - 89))
      | (1ULL << (SqlParser::K_VACUUM - 89))
      | (1ULL << (SqlParser::K_VALUES - 89))
      | (1ULL << (SqlParser::K_VIEW - 89))
      | (1ULL << (SqlParser::K_VIRTUAL - 89))
      | (1ULL << (SqlParser::K_WHEN - 89))
      | (1ULL << (SqlParser::K_WHERE - 89))
      | (1ULL << (SqlParser::K_WITH - 89))
      | (1ULL << (SqlParser::K_WITHOUT - 89)))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NameContext ------------------------------------------------------------------

SqlParser::NameContext::NameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SqlParser::Any_nameContext* SqlParser::NameContext::any_name() {
  return getRuleContext<SqlParser::Any_nameContext>(0);
}


size_t SqlParser::NameContext::getRuleIndex() const {
  return SqlParser::RuleName;
}

void SqlParser::NameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterName(this);
}

void SqlParser::NameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitName(this);
}


antlrcpp::Any SqlParser::NameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlVisitor*>(visitor))
    return parserVisitor->visitName(this);
  else
    return visitor->visitChildren(this);
}

SqlParser::NameContext* SqlParser::name() {
  NameContext *_localctx = _tracker.createInstance<NameContext>(_ctx, getState());
  enterRule(_localctx, 34, SqlParser::RuleName);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(371);
    any_name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Function_nameContext ------------------------------------------------------------------

SqlParser::Function_nameContext::Function_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SqlParser::Any_nameContext* SqlParser::Function_nameContext::any_name() {
  return getRuleContext<SqlParser::Any_nameContext>(0);
}


size_t SqlParser::Function_nameContext::getRuleIndex() const {
  return SqlParser::RuleFunction_name;
}

void SqlParser::Function_nameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFunction_name(this);
}

void SqlParser::Function_nameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFunction_name(this);
}


antlrcpp::Any SqlParser::Function_nameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlVisitor*>(visitor))
    return parserVisitor->visitFunction_name(this);
  else
    return visitor->visitChildren(this);
}

SqlParser::Function_nameContext* SqlParser::function_name() {
  Function_nameContext *_localctx = _tracker.createInstance<Function_nameContext>(_ctx, getState());
  enterRule(_localctx, 36, SqlParser::RuleFunction_name);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(373);
    any_name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Database_nameContext ------------------------------------------------------------------

SqlParser::Database_nameContext::Database_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SqlParser::Any_nameContext* SqlParser::Database_nameContext::any_name() {
  return getRuleContext<SqlParser::Any_nameContext>(0);
}


size_t SqlParser::Database_nameContext::getRuleIndex() const {
  return SqlParser::RuleDatabase_name;
}

void SqlParser::Database_nameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterDatabase_name(this);
}

void SqlParser::Database_nameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitDatabase_name(this);
}


antlrcpp::Any SqlParser::Database_nameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlVisitor*>(visitor))
    return parserVisitor->visitDatabase_name(this);
  else
    return visitor->visitChildren(this);
}

SqlParser::Database_nameContext* SqlParser::database_name() {
  Database_nameContext *_localctx = _tracker.createInstance<Database_nameContext>(_ctx, getState());
  enterRule(_localctx, 38, SqlParser::RuleDatabase_name);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(375);
    any_name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Table_nameContext ------------------------------------------------------------------

SqlParser::Table_nameContext::Table_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SqlParser::Any_nameContext* SqlParser::Table_nameContext::any_name() {
  return getRuleContext<SqlParser::Any_nameContext>(0);
}


size_t SqlParser::Table_nameContext::getRuleIndex() const {
  return SqlParser::RuleTable_name;
}

void SqlParser::Table_nameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTable_name(this);
}

void SqlParser::Table_nameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTable_name(this);
}


antlrcpp::Any SqlParser::Table_nameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlVisitor*>(visitor))
    return parserVisitor->visitTable_name(this);
  else
    return visitor->visitChildren(this);
}

SqlParser::Table_nameContext* SqlParser::table_name() {
  Table_nameContext *_localctx = _tracker.createInstance<Table_nameContext>(_ctx, getState());
  enterRule(_localctx, 40, SqlParser::RuleTable_name);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(377);
    any_name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Table_or_index_nameContext ------------------------------------------------------------------

SqlParser::Table_or_index_nameContext::Table_or_index_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SqlParser::Any_nameContext* SqlParser::Table_or_index_nameContext::any_name() {
  return getRuleContext<SqlParser::Any_nameContext>(0);
}


size_t SqlParser::Table_or_index_nameContext::getRuleIndex() const {
  return SqlParser::RuleTable_or_index_name;
}

void SqlParser::Table_or_index_nameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTable_or_index_name(this);
}

void SqlParser::Table_or_index_nameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTable_or_index_name(this);
}


antlrcpp::Any SqlParser::Table_or_index_nameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlVisitor*>(visitor))
    return parserVisitor->visitTable_or_index_name(this);
  else
    return visitor->visitChildren(this);
}

SqlParser::Table_or_index_nameContext* SqlParser::table_or_index_name() {
  Table_or_index_nameContext *_localctx = _tracker.createInstance<Table_or_index_nameContext>(_ctx, getState());
  enterRule(_localctx, 42, SqlParser::RuleTable_or_index_name);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(379);
    any_name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- New_table_nameContext ------------------------------------------------------------------

SqlParser::New_table_nameContext::New_table_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SqlParser::Any_nameContext* SqlParser::New_table_nameContext::any_name() {
  return getRuleContext<SqlParser::Any_nameContext>(0);
}


size_t SqlParser::New_table_nameContext::getRuleIndex() const {
  return SqlParser::RuleNew_table_name;
}

void SqlParser::New_table_nameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNew_table_name(this);
}

void SqlParser::New_table_nameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNew_table_name(this);
}


antlrcpp::Any SqlParser::New_table_nameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlVisitor*>(visitor))
    return parserVisitor->visitNew_table_name(this);
  else
    return visitor->visitChildren(this);
}

SqlParser::New_table_nameContext* SqlParser::new_table_name() {
  New_table_nameContext *_localctx = _tracker.createInstance<New_table_nameContext>(_ctx, getState());
  enterRule(_localctx, 44, SqlParser::RuleNew_table_name);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(381);
    any_name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Column_nameContext ------------------------------------------------------------------

SqlParser::Column_nameContext::Column_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SqlParser::Any_nameContext* SqlParser::Column_nameContext::any_name() {
  return getRuleContext<SqlParser::Any_nameContext>(0);
}


size_t SqlParser::Column_nameContext::getRuleIndex() const {
  return SqlParser::RuleColumn_name;
}

void SqlParser::Column_nameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterColumn_name(this);
}

void SqlParser::Column_nameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitColumn_name(this);
}


antlrcpp::Any SqlParser::Column_nameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlVisitor*>(visitor))
    return parserVisitor->visitColumn_name(this);
  else
    return visitor->visitChildren(this);
}

SqlParser::Column_nameContext* SqlParser::column_name() {
  Column_nameContext *_localctx = _tracker.createInstance<Column_nameContext>(_ctx, getState());
  enterRule(_localctx, 46, SqlParser::RuleColumn_name);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(383);
    any_name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Collation_nameContext ------------------------------------------------------------------

SqlParser::Collation_nameContext::Collation_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SqlParser::Any_nameContext* SqlParser::Collation_nameContext::any_name() {
  return getRuleContext<SqlParser::Any_nameContext>(0);
}


size_t SqlParser::Collation_nameContext::getRuleIndex() const {
  return SqlParser::RuleCollation_name;
}

void SqlParser::Collation_nameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCollation_name(this);
}

void SqlParser::Collation_nameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCollation_name(this);
}


antlrcpp::Any SqlParser::Collation_nameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlVisitor*>(visitor))
    return parserVisitor->visitCollation_name(this);
  else
    return visitor->visitChildren(this);
}

SqlParser::Collation_nameContext* SqlParser::collation_name() {
  Collation_nameContext *_localctx = _tracker.createInstance<Collation_nameContext>(_ctx, getState());
  enterRule(_localctx, 48, SqlParser::RuleCollation_name);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(385);
    any_name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Foreign_tableContext ------------------------------------------------------------------

SqlParser::Foreign_tableContext::Foreign_tableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SqlParser::Any_nameContext* SqlParser::Foreign_tableContext::any_name() {
  return getRuleContext<SqlParser::Any_nameContext>(0);
}


size_t SqlParser::Foreign_tableContext::getRuleIndex() const {
  return SqlParser::RuleForeign_table;
}

void SqlParser::Foreign_tableContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterForeign_table(this);
}

void SqlParser::Foreign_tableContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitForeign_table(this);
}


antlrcpp::Any SqlParser::Foreign_tableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlVisitor*>(visitor))
    return parserVisitor->visitForeign_table(this);
  else
    return visitor->visitChildren(this);
}

SqlParser::Foreign_tableContext* SqlParser::foreign_table() {
  Foreign_tableContext *_localctx = _tracker.createInstance<Foreign_tableContext>(_ctx, getState());
  enterRule(_localctx, 50, SqlParser::RuleForeign_table);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(387);
    any_name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Index_nameContext ------------------------------------------------------------------

SqlParser::Index_nameContext::Index_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SqlParser::Any_nameContext* SqlParser::Index_nameContext::any_name() {
  return getRuleContext<SqlParser::Any_nameContext>(0);
}


size_t SqlParser::Index_nameContext::getRuleIndex() const {
  return SqlParser::RuleIndex_name;
}

void SqlParser::Index_nameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIndex_name(this);
}

void SqlParser::Index_nameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIndex_name(this);
}


antlrcpp::Any SqlParser::Index_nameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlVisitor*>(visitor))
    return parserVisitor->visitIndex_name(this);
  else
    return visitor->visitChildren(this);
}

SqlParser::Index_nameContext* SqlParser::index_name() {
  Index_nameContext *_localctx = _tracker.createInstance<Index_nameContext>(_ctx, getState());
  enterRule(_localctx, 52, SqlParser::RuleIndex_name);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(389);
    any_name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Trigger_nameContext ------------------------------------------------------------------

SqlParser::Trigger_nameContext::Trigger_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SqlParser::Any_nameContext* SqlParser::Trigger_nameContext::any_name() {
  return getRuleContext<SqlParser::Any_nameContext>(0);
}


size_t SqlParser::Trigger_nameContext::getRuleIndex() const {
  return SqlParser::RuleTrigger_name;
}

void SqlParser::Trigger_nameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTrigger_name(this);
}

void SqlParser::Trigger_nameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTrigger_name(this);
}


antlrcpp::Any SqlParser::Trigger_nameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlVisitor*>(visitor))
    return parserVisitor->visitTrigger_name(this);
  else
    return visitor->visitChildren(this);
}

SqlParser::Trigger_nameContext* SqlParser::trigger_name() {
  Trigger_nameContext *_localctx = _tracker.createInstance<Trigger_nameContext>(_ctx, getState());
  enterRule(_localctx, 54, SqlParser::RuleTrigger_name);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(391);
    any_name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- View_nameContext ------------------------------------------------------------------

SqlParser::View_nameContext::View_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SqlParser::Any_nameContext* SqlParser::View_nameContext::any_name() {
  return getRuleContext<SqlParser::Any_nameContext>(0);
}


size_t SqlParser::View_nameContext::getRuleIndex() const {
  return SqlParser::RuleView_name;
}

void SqlParser::View_nameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterView_name(this);
}

void SqlParser::View_nameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitView_name(this);
}


antlrcpp::Any SqlParser::View_nameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlVisitor*>(visitor))
    return parserVisitor->visitView_name(this);
  else
    return visitor->visitChildren(this);
}

SqlParser::View_nameContext* SqlParser::view_name() {
  View_nameContext *_localctx = _tracker.createInstance<View_nameContext>(_ctx, getState());
  enterRule(_localctx, 56, SqlParser::RuleView_name);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(393);
    any_name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Module_nameContext ------------------------------------------------------------------

SqlParser::Module_nameContext::Module_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SqlParser::Any_nameContext* SqlParser::Module_nameContext::any_name() {
  return getRuleContext<SqlParser::Any_nameContext>(0);
}


size_t SqlParser::Module_nameContext::getRuleIndex() const {
  return SqlParser::RuleModule_name;
}

void SqlParser::Module_nameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterModule_name(this);
}

void SqlParser::Module_nameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitModule_name(this);
}


antlrcpp::Any SqlParser::Module_nameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlVisitor*>(visitor))
    return parserVisitor->visitModule_name(this);
  else
    return visitor->visitChildren(this);
}

SqlParser::Module_nameContext* SqlParser::module_name() {
  Module_nameContext *_localctx = _tracker.createInstance<Module_nameContext>(_ctx, getState());
  enterRule(_localctx, 58, SqlParser::RuleModule_name);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(395);
    any_name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Pragma_nameContext ------------------------------------------------------------------

SqlParser::Pragma_nameContext::Pragma_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SqlParser::Any_nameContext* SqlParser::Pragma_nameContext::any_name() {
  return getRuleContext<SqlParser::Any_nameContext>(0);
}


size_t SqlParser::Pragma_nameContext::getRuleIndex() const {
  return SqlParser::RulePragma_name;
}

void SqlParser::Pragma_nameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterPragma_name(this);
}

void SqlParser::Pragma_nameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitPragma_name(this);
}


antlrcpp::Any SqlParser::Pragma_nameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlVisitor*>(visitor))
    return parserVisitor->visitPragma_name(this);
  else
    return visitor->visitChildren(this);
}

SqlParser::Pragma_nameContext* SqlParser::pragma_name() {
  Pragma_nameContext *_localctx = _tracker.createInstance<Pragma_nameContext>(_ctx, getState());
  enterRule(_localctx, 60, SqlParser::RulePragma_name);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(397);
    any_name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Savepoint_nameContext ------------------------------------------------------------------

SqlParser::Savepoint_nameContext::Savepoint_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SqlParser::Any_nameContext* SqlParser::Savepoint_nameContext::any_name() {
  return getRuleContext<SqlParser::Any_nameContext>(0);
}


size_t SqlParser::Savepoint_nameContext::getRuleIndex() const {
  return SqlParser::RuleSavepoint_name;
}

void SqlParser::Savepoint_nameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterSavepoint_name(this);
}

void SqlParser::Savepoint_nameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitSavepoint_name(this);
}


antlrcpp::Any SqlParser::Savepoint_nameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlVisitor*>(visitor))
    return parserVisitor->visitSavepoint_name(this);
  else
    return visitor->visitChildren(this);
}

SqlParser::Savepoint_nameContext* SqlParser::savepoint_name() {
  Savepoint_nameContext *_localctx = _tracker.createInstance<Savepoint_nameContext>(_ctx, getState());
  enterRule(_localctx, 62, SqlParser::RuleSavepoint_name);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(399);
    any_name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Table_aliasContext ------------------------------------------------------------------

SqlParser::Table_aliasContext::Table_aliasContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SqlParser::Any_nameContext* SqlParser::Table_aliasContext::any_name() {
  return getRuleContext<SqlParser::Any_nameContext>(0);
}


size_t SqlParser::Table_aliasContext::getRuleIndex() const {
  return SqlParser::RuleTable_alias;
}

void SqlParser::Table_aliasContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTable_alias(this);
}

void SqlParser::Table_aliasContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTable_alias(this);
}


antlrcpp::Any SqlParser::Table_aliasContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlVisitor*>(visitor))
    return parserVisitor->visitTable_alias(this);
  else
    return visitor->visitChildren(this);
}

SqlParser::Table_aliasContext* SqlParser::table_alias() {
  Table_aliasContext *_localctx = _tracker.createInstance<Table_aliasContext>(_ctx, getState());
  enterRule(_localctx, 64, SqlParser::RuleTable_alias);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(401);
    any_name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Transaction_nameContext ------------------------------------------------------------------

SqlParser::Transaction_nameContext::Transaction_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

SqlParser::Any_nameContext* SqlParser::Transaction_nameContext::any_name() {
  return getRuleContext<SqlParser::Any_nameContext>(0);
}


size_t SqlParser::Transaction_nameContext::getRuleIndex() const {
  return SqlParser::RuleTransaction_name;
}

void SqlParser::Transaction_nameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTransaction_name(this);
}

void SqlParser::Transaction_nameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTransaction_name(this);
}


antlrcpp::Any SqlParser::Transaction_nameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlVisitor*>(visitor))
    return parserVisitor->visitTransaction_name(this);
  else
    return visitor->visitChildren(this);
}

SqlParser::Transaction_nameContext* SqlParser::transaction_name() {
  Transaction_nameContext *_localctx = _tracker.createInstance<Transaction_nameContext>(_ctx, getState());
  enterRule(_localctx, 66, SqlParser::RuleTransaction_name);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(403);
    any_name();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Any_nameContext ------------------------------------------------------------------

SqlParser::Any_nameContext::Any_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* SqlParser::Any_nameContext::IDENTIFIER() {
  return getToken(SqlParser::IDENTIFIER, 0);
}

SqlParser::KeywordContext* SqlParser::Any_nameContext::keyword() {
  return getRuleContext<SqlParser::KeywordContext>(0);
}

tree::TerminalNode* SqlParser::Any_nameContext::STRING_LITERAL() {
  return getToken(SqlParser::STRING_LITERAL, 0);
}

SqlParser::Any_nameContext* SqlParser::Any_nameContext::any_name() {
  return getRuleContext<SqlParser::Any_nameContext>(0);
}


size_t SqlParser::Any_nameContext::getRuleIndex() const {
  return SqlParser::RuleAny_name;
}

void SqlParser::Any_nameContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterAny_name(this);
}

void SqlParser::Any_nameContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<SqlListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitAny_name(this);
}


antlrcpp::Any SqlParser::Any_nameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<SqlVisitor*>(visitor))
    return parserVisitor->visitAny_name(this);
  else
    return visitor->visitChildren(this);
}

SqlParser::Any_nameContext* SqlParser::any_name() {
  Any_nameContext *_localctx = _tracker.createInstance<Any_nameContext>(_ctx, getState());
  enterRule(_localctx, 68, SqlParser::RuleAny_name);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(412);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case SqlParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(405);
        match(SqlParser::IDENTIFIER);
        break;
      }

      case SqlParser::K_ABORT:
      case SqlParser::K_ACTION:
      case SqlParser::K_ADD:
      case SqlParser::K_AFTER:
      case SqlParser::K_ALL:
      case SqlParser::K_ALTER:
      case SqlParser::K_ANALYZE:
      case SqlParser::K_AND:
      case SqlParser::K_AS:
      case SqlParser::K_ASC:
      case SqlParser::K_ATTACH:
      case SqlParser::K_AUTOINCREMENT:
      case SqlParser::K_BEFORE:
      case SqlParser::K_BEGIN:
      case SqlParser::K_BETWEEN:
      case SqlParser::K_BY:
      case SqlParser::K_CASCADE:
      case SqlParser::K_CASE:
      case SqlParser::K_CAST:
      case SqlParser::K_CHECK:
      case SqlParser::K_COLLATE:
      case SqlParser::K_COLUMN:
      case SqlParser::K_COMMIT:
      case SqlParser::K_CONFLICT:
      case SqlParser::K_CONSTRAINT:
      case SqlParser::K_CREATE:
      case SqlParser::K_CROSS:
      case SqlParser::K_CURRENT_DATE:
      case SqlParser::K_CURRENT_TIME:
      case SqlParser::K_CURRENT_TIMESTAMP:
      case SqlParser::K_DATABASE:
      case SqlParser::K_DEFAULT:
      case SqlParser::K_DEFERRABLE:
      case SqlParser::K_DEFERRED:
      case SqlParser::K_DELETE:
      case SqlParser::K_DESC:
      case SqlParser::K_DETACH:
      case SqlParser::K_DISTINCT:
      case SqlParser::K_DROP:
      case SqlParser::K_EACH:
      case SqlParser::K_ELSE:
      case SqlParser::K_END:
      case SqlParser::K_ESCAPE:
      case SqlParser::K_EXCEPT:
      case SqlParser::K_EXCLUSIVE:
      case SqlParser::K_EXISTS:
      case SqlParser::K_EXPLAIN:
      case SqlParser::K_FAIL:
      case SqlParser::K_FOR:
      case SqlParser::K_FOREIGN:
      case SqlParser::K_FROM:
      case SqlParser::K_FULL:
      case SqlParser::K_GLOB:
      case SqlParser::K_GROUP:
      case SqlParser::K_HAVING:
      case SqlParser::K_IF:
      case SqlParser::K_IGNORE:
      case SqlParser::K_IMMEDIATE:
      case SqlParser::K_IN:
      case SqlParser::K_INDEX:
      case SqlParser::K_INDEXED:
      case SqlParser::K_INITIALLY:
      case SqlParser::K_INNER:
      case SqlParser::K_INSERT:
      case SqlParser::K_INSTEAD:
      case SqlParser::K_INTERSECT:
      case SqlParser::K_INTO:
      case SqlParser::K_IS:
      case SqlParser::K_ISNOT:
      case SqlParser::K_ISNULL:
      case SqlParser::K_JOIN:
      case SqlParser::K_KEY:
      case SqlParser::K_LEFT:
      case SqlParser::K_LIKE:
      case SqlParser::K_LIMIT:
      case SqlParser::K_MATCH:
      case SqlParser::K_NATURAL:
      case SqlParser::K_NO:
      case SqlParser::K_NOT:
      case SqlParser::K_NOTNULL:
      case SqlParser::K_NULL:
      case SqlParser::K_OF:
      case SqlParser::K_OFFSET:
      case SqlParser::K_ON:
      case SqlParser::K_OR:
      case SqlParser::K_ORDER:
      case SqlParser::K_OUTER:
      case SqlParser::K_PLAN:
      case SqlParser::K_PRAGMA:
      case SqlParser::K_PRIMARY:
      case SqlParser::K_QUERY:
      case SqlParser::K_RAISE:
      case SqlParser::K_RECURSIVE:
      case SqlParser::K_REFERENCES:
      case SqlParser::K_REGEXP:
      case SqlParser::K_REINDEX:
      case SqlParser::K_RELEASE:
      case SqlParser::K_RENAME:
      case SqlParser::K_REPLACE:
      case SqlParser::K_RESTRICT:
      case SqlParser::K_RIGHT:
      case SqlParser::K_ROLLBACK:
      case SqlParser::K_ROW:
      case SqlParser::K_SAVEPOINT:
      case SqlParser::K_SELECT:
      case SqlParser::K_SET:
      case SqlParser::K_TABLE:
      case SqlParser::K_TEMP:
      case SqlParser::K_TEMPORARY:
      case SqlParser::K_THEN:
      case SqlParser::K_TO:
      case SqlParser::K_TRANSACTION:
      case SqlParser::K_TRIGGER:
      case SqlParser::K_UNION:
      case SqlParser::K_UNIQUE:
      case SqlParser::K_UPDATE:
      case SqlParser::K_USING:
      case SqlParser::K_VACUUM:
      case SqlParser::K_VALUES:
      case SqlParser::K_VIEW:
      case SqlParser::K_VIRTUAL:
      case SqlParser::K_WHEN:
      case SqlParser::K_WHERE:
      case SqlParser::K_WITH:
      case SqlParser::K_WITHOUT: {
        enterOuterAlt(_localctx, 2);
        setState(406);
        keyword();
        break;
      }

      case SqlParser::STRING_LITERAL: {
        enterOuterAlt(_localctx, 3);
        setState(407);
        match(SqlParser::STRING_LITERAL);
        break;
      }

      case SqlParser::OPEN_PAR: {
        enterOuterAlt(_localctx, 4);
        setState(408);
        match(SqlParser::OPEN_PAR);
        setState(409);
        any_name();
        setState(410);
        match(SqlParser::CLOSE_PAR);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

bool SqlParser::sempred(RuleContext *context, size_t ruleIndex, size_t predicateIndex) {
  switch (ruleIndex) {
    case 1: return exprSempred(dynamic_cast<ExprContext *>(context), predicateIndex);
    case 2: return exprWhereSempred(dynamic_cast<ExprWhereContext *>(context), predicateIndex);

  default:
    break;
  }
  return true;
}

bool SqlParser::exprSempred(ExprContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 0: return precpred(_ctx, 6);
    case 1: return precpred(_ctx, 5);
    case 2: return precpred(_ctx, 4);
    case 3: return precpred(_ctx, 3);

  default:
    break;
  }
  return true;
}

bool SqlParser::exprWhereSempred(ExprWhereContext *_localctx, size_t predicateIndex) {
  switch (predicateIndex) {
    case 4: return precpred(_ctx, 6);
    case 5: return precpred(_ctx, 5);
    case 6: return precpred(_ctx, 4);
    case 7: return precpred(_ctx, 3);

  default:
    break;
  }
  return true;
}

// Static vars and initialization.
std::vector<dfa::DFA> SqlParser::_decisionToDFA;
atn::PredictionContextCache SqlParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN SqlParser::_atn;
std::vector<uint16_t> SqlParser::_serializedATN;

std::vector<std::string> SqlParser::_ruleNames = {
  "parse", "expr", "exprWhere", "result_column", "table_or_subquery", "join_clause", 
  "join_operator", "join_constraint", "select_core", "where_clause", "group_by_clause", 
  "signed_number", "literal_value", "unary_operator", "error_message", "column_alias", 
  "keyword", "name", "function_name", "database_name", "table_name", "table_or_index_name", 
  "new_table_name", "column_name", "collation_name", "foreign_table", "index_name", 
  "trigger_name", "view_name", "module_name", "pragma_name", "savepoint_name", 
  "table_alias", "transaction_name", "any_name"
};

std::vector<std::string> SqlParser::_literalNames = {
  "", "';'", "'.'", "'('", "')'", "','", "'='", "'*'", "'+'", "'-'", "'~'", 
  "'||'", "'/'", "'%'", "'<<'", "'>>'", "'&'", "'|'", "'<'", "'<='", "'>'", 
  "'>='", "'=='", "'!='", "'<>'"
};

std::vector<std::string> SqlParser::_symbolicNames = {
  "", "SCOL", "DOT", "OPEN_PAR", "CLOSE_PAR", "COMMA", "ASSIGN", "STAR", 
  "PLUS", "MINUS", "TILDE", "PIPE2", "DIV", "MOD", "LT2", "GT2", "AMP", 
  "PIPE", "LT", "LT_EQ", "GT", "GT_EQ", "EQ", "NOT_EQ1", "NOT_EQ2", "K_ABORT", 
  "K_ACTION", "K_ADD", "K_AFTER", "K_ALL", "K_ALTER", "K_ANALYZE", "K_AND", 
  "K_AS", "K_ASC", "K_ATTACH", "K_AUTOINCREMENT", "K_BEFORE", "K_BEGIN", 
  "K_BETWEEN", "K_BY", "K_CASCADE", "K_CASE", "K_CAST", "K_CHECK", "K_COLLATE", 
  "K_COLUMN", "K_COMMIT", "K_CONFLICT", "K_CONSTRAINT", "K_CREATE", "K_CROSS", 
  "K_CURRENT_DATE", "K_CURRENT_TIME", "K_CURRENT_TIMESTAMP", "K_DATABASE", 
  "K_DEFAULT", "K_DEFERRABLE", "K_DEFERRED", "K_DELETE", "K_DESC", "K_DETACH", 
  "K_DISTINCT", "K_DROP", "K_EACH", "K_ELSE", "K_END", "K_ESCAPE", "K_EXCEPT", 
  "K_EXCLUSIVE", "K_EXISTS", "K_EXPLAIN", "K_FAIL", "K_FOR", "K_FOREIGN", 
  "K_FROM", "K_FULL", "K_GLOB", "K_GROUP", "K_HAVING", "K_IF", "K_IGNORE", 
  "K_IMMEDIATE", "K_IN", "K_INDEX", "K_INDEXED", "K_INITIALLY", "K_INNER", 
  "K_INSERT", "K_INSTEAD", "K_INTERSECT", "K_INTO", "K_IS", "K_ISNOT", "K_ISNULL", 
  "K_JOIN", "K_KEY", "K_LEFT", "K_LIKE", "K_LIMIT", "K_MATCH", "K_NATURAL", 
  "K_NO", "K_NOT", "K_NOTNULL", "K_NULL", "K_OF", "K_OFFSET", "K_ON", "K_OR", 
  "K_ORDER", "K_OUTER", "K_PLAN", "K_PRAGMA", "K_PRIMARY", "K_QUERY", "K_RAISE", 
  "K_RECURSIVE", "K_REFERENCES", "K_REGEXP", "K_REINDEX", "K_RELEASE", "K_RENAME", 
  "K_REPLACE", "K_RESTRICT", "K_RIGHT", "K_ROLLBACK", "K_ROW", "K_SAVEPOINT", 
  "K_SELECT", "K_SET", "K_TABLE", "K_TEMP", "K_TEMPORARY", "K_THEN", "K_TO", 
  "K_TRANSACTION", "K_TRIGGER", "K_UNION", "K_UNIQUE", "K_UPDATE", "K_USING", 
  "K_VACUUM", "K_VALUES", "K_VIEW", "K_VIRTUAL", "K_WHEN", "K_WHERE", "K_WITH", 
  "K_WITHOUT", "IDENTIFIER", "NUMERIC_LITERAL", "BIND_PARAMETER", "STRING_LITERAL", 
  "BLOB_LITERAL", "SINGLE_LINE_COMMENT", "MULTILINE_COMMENT", "SPACES", 
  "UNEXPECTED_CHAR"
};

dfa::Vocabulary SqlParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> SqlParser::_tokenNames;

SqlParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0xa0, 0x1a1, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 
    0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 
    0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4, 
    0x1f, 0x9, 0x1f, 0x4, 0x20, 0x9, 0x20, 0x4, 0x21, 0x9, 0x21, 0x4, 0x22, 
    0x9, 0x22, 0x4, 0x23, 0x9, 0x23, 0x4, 0x24, 0x9, 0x24, 0x3, 0x2, 0x6, 
    0x2, 0x4a, 0xa, 0x2, 0xd, 0x2, 0xe, 0x2, 0x4b, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x54, 0xa, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x5, 0x3, 0x59, 0xa, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x5, 0x3, 0x5f, 0xa, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x7, 0x3, 0x64, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x67, 0xb, 0x3, 0x3, 0x3, 
    0x5, 0x3, 0x6a, 0xa, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x5, 0x3, 0x72, 0xa, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x7, 0x3, 0x80, 0xa, 0x3, 0xc, 0x3, 0xe, 0x3, 0x83, 
    0xb, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x5, 0x4, 0x8b, 0xa, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x90, 
    0xa, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x96, 0xa, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x7, 0x4, 0x9b, 0xa, 0x4, 0xc, 0x4, 
    0xe, 0x4, 0x9e, 0xb, 0x4, 0x3, 0x4, 0x5, 0x4, 0xa1, 0xa, 0x4, 0x3, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0xa9, 0xa, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x7, 0x4, 0xb7, 
    0xa, 0x4, 0xc, 0x4, 0xe, 0x4, 0xba, 0xb, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 
    0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x5, 0x5, 0xc3, 0xa, 0x5, 
    0x3, 0x5, 0x5, 0x5, 0xc6, 0xa, 0x5, 0x5, 0x5, 0xc8, 0xa, 0x5, 0x3, 0x6, 
    0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0xcd, 0xa, 0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 
    0x6, 0xd1, 0xa, 0x6, 0x3, 0x6, 0x5, 0x6, 0xd4, 0xa, 0x6, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x3, 0x6, 0x7, 0x6, 0xda, 0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 
    0xdd, 0xb, 0x6, 0x3, 0x6, 0x5, 0x6, 0xe0, 0xa, 0x6, 0x3, 0x6, 0x3, 0x6, 
    0x5, 0x6, 0xe4, 0xa, 0x6, 0x3, 0x6, 0x5, 0x6, 0xe7, 0xa, 0x6, 0x3, 0x6, 
    0x3, 0x6, 0x3, 0x6, 0x3, 0x6, 0x5, 0x6, 0xed, 0xa, 0x6, 0x3, 0x6, 0x5, 
    0x6, 0xf0, 0xa, 0x6, 0x5, 0x6, 0xf2, 0xa, 0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 
    0x7, 0x3, 0x7, 0x3, 0x7, 0x7, 0x7, 0xf9, 0xa, 0x7, 0xc, 0x7, 0xe, 0x7, 
    0xfc, 0xb, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x101, 0xa, 
    0x8, 0x3, 0x8, 0x3, 0x8, 0x5, 0x8, 0x105, 0xa, 0x8, 0x3, 0x8, 0x5, 0x8, 
    0x108, 0xa, 0x8, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 
    0x9, 0x3, 0x9, 0x7, 0x9, 0x111, 0xa, 0x9, 0xc, 0x9, 0xe, 0x9, 0x114, 
    0xb, 0x9, 0x3, 0x9, 0x3, 0x9, 0x5, 0x9, 0x118, 0xa, 0x9, 0x3, 0xa, 0x3, 
    0xa, 0x5, 0xa, 0x11c, 0xa, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x7, 0xa, 
    0x121, 0xa, 0xa, 0xc, 0xa, 0xe, 0xa, 0x124, 0xb, 0xa, 0x3, 0xa, 0x3, 
    0xa, 0x3, 0xa, 0x3, 0xa, 0x7, 0xa, 0x12a, 0xa, 0xa, 0xc, 0xa, 0xe, 0xa, 
    0x12d, 0xb, 0xa, 0x3, 0xa, 0x5, 0xa, 0x130, 0xa, 0xa, 0x5, 0xa, 0x132, 
    0xa, 0xa, 0x3, 0xa, 0x5, 0xa, 0x135, 0xa, 0xa, 0x3, 0xa, 0x5, 0xa, 0x138, 
    0xa, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x7, 0xa, 
    0x13f, 0xa, 0xa, 0xc, 0xa, 0xe, 0xa, 0x142, 0xb, 0xa, 0x3, 0xa, 0x3, 
    0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x7, 0xa, 0x14a, 0xa, 0xa, 
    0xc, 0xa, 0xe, 0xa, 0x14d, 0xb, 0xa, 0x3, 0xa, 0x3, 0xa, 0x7, 0xa, 0x151, 
    0xa, 0xa, 0xc, 0xa, 0xe, 0xa, 0x154, 0xb, 0xa, 0x3, 0xa, 0x3, 0xa, 0x5, 
    0xa, 0x158, 0xa, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 
    0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x7, 0xc, 0x162, 0xa, 0xc, 0xc, 0xc, 0xe, 
    0xc, 0x165, 0xb, 0xc, 0x3, 0xd, 0x5, 0xd, 0x168, 0xa, 0xd, 0x3, 0xd, 
    0x3, 0xd, 0x3, 0xe, 0x3, 0xe, 0x3, 0xf, 0x3, 0xf, 0x3, 0x10, 0x3, 0x10, 
    0x3, 0x11, 0x3, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x13, 0x3, 0x13, 0x3, 
    0x14, 0x3, 0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 0x16, 0x3, 0x16, 0x3, 0x17, 
    0x3, 0x17, 0x3, 0x18, 0x3, 0x18, 0x3, 0x19, 0x3, 0x19, 0x3, 0x1a, 0x3, 
    0x1a, 0x3, 0x1b, 0x3, 0x1b, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1d, 0x3, 0x1d, 
    0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1f, 0x3, 0x1f, 0x3, 0x20, 0x3, 0x20, 0x3, 
    0x21, 0x3, 0x21, 0x3, 0x22, 0x3, 0x22, 0x3, 0x23, 0x3, 0x23, 0x3, 0x24, 
    0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x3, 0x24, 0x5, 
    0x24, 0x19f, 0xa, 0x24, 0x3, 0x24, 0x2, 0x4, 0x4, 0x6, 0x25, 0x2, 0x4, 
    0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 0x1e, 
    0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 0x36, 
    0x38, 0x3a, 0x3c, 0x3e, 0x40, 0x42, 0x44, 0x46, 0x2, 0xc, 0x5, 0x2, 
    0x9, 0xb, 0xe, 0xf, 0x14, 0x17, 0x7, 0x2, 0x8, 0x8, 0x18, 0x1a, 0x55, 
    0x55, 0x5e, 0x5f, 0x64, 0x64, 0x4, 0x2, 0x9, 0xb, 0xe, 0xf, 0x7, 0x2, 
    0x8, 0x8, 0x14, 0x1a, 0x55, 0x55, 0x5e, 0x5f, 0x64, 0x64, 0x4, 0x2, 
    0x1f, 0x1f, 0x40, 0x40, 0x3, 0x2, 0xa, 0xb, 0x6, 0x2, 0x36, 0x38, 0x6b, 
    0x6b, 0x99, 0x99, 0x9b, 0x9c, 0x4, 0x2, 0xa, 0xc, 0x69, 0x69, 0x4, 0x2, 
    0x98, 0x98, 0x9b, 0x9b, 0x3, 0x2, 0x1b, 0x97, 0x2, 0x1c2, 0x2, 0x49, 
    0x3, 0x2, 0x2, 0x2, 0x4, 0x71, 0x3, 0x2, 0x2, 0x2, 0x6, 0xa8, 0x3, 0x2, 
    0x2, 0x2, 0x8, 0xc7, 0x3, 0x2, 0x2, 0x2, 0xa, 0xf1, 0x3, 0x2, 0x2, 0x2, 
    0xc, 0xf3, 0x3, 0x2, 0x2, 0x2, 0xe, 0x107, 0x3, 0x2, 0x2, 0x2, 0x10, 
    0x117, 0x3, 0x2, 0x2, 0x2, 0x12, 0x157, 0x3, 0x2, 0x2, 0x2, 0x14, 0x159, 
    0x3, 0x2, 0x2, 0x2, 0x16, 0x15c, 0x3, 0x2, 0x2, 0x2, 0x18, 0x167, 0x3, 
    0x2, 0x2, 0x2, 0x1a, 0x16b, 0x3, 0x2, 0x2, 0x2, 0x1c, 0x16d, 0x3, 0x2, 
    0x2, 0x2, 0x1e, 0x16f, 0x3, 0x2, 0x2, 0x2, 0x20, 0x171, 0x3, 0x2, 0x2, 
    0x2, 0x22, 0x173, 0x3, 0x2, 0x2, 0x2, 0x24, 0x175, 0x3, 0x2, 0x2, 0x2, 
    0x26, 0x177, 0x3, 0x2, 0x2, 0x2, 0x28, 0x179, 0x3, 0x2, 0x2, 0x2, 0x2a, 
    0x17b, 0x3, 0x2, 0x2, 0x2, 0x2c, 0x17d, 0x3, 0x2, 0x2, 0x2, 0x2e, 0x17f, 
    0x3, 0x2, 0x2, 0x2, 0x30, 0x181, 0x3, 0x2, 0x2, 0x2, 0x32, 0x183, 0x3, 
    0x2, 0x2, 0x2, 0x34, 0x185, 0x3, 0x2, 0x2, 0x2, 0x36, 0x187, 0x3, 0x2, 
    0x2, 0x2, 0x38, 0x189, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x18b, 0x3, 0x2, 0x2, 
    0x2, 0x3c, 0x18d, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x18f, 0x3, 0x2, 0x2, 0x2, 
    0x40, 0x191, 0x3, 0x2, 0x2, 0x2, 0x42, 0x193, 0x3, 0x2, 0x2, 0x2, 0x44, 
    0x195, 0x3, 0x2, 0x2, 0x2, 0x46, 0x19e, 0x3, 0x2, 0x2, 0x2, 0x48, 0x4a, 
    0x5, 0x12, 0xa, 0x2, 0x49, 0x48, 0x3, 0x2, 0x2, 0x2, 0x4a, 0x4b, 0x3, 
    0x2, 0x2, 0x2, 0x4b, 0x49, 0x3, 0x2, 0x2, 0x2, 0x4b, 0x4c, 0x3, 0x2, 
    0x2, 0x2, 0x4c, 0x3, 0x3, 0x2, 0x2, 0x2, 0x4d, 0x4e, 0x8, 0x3, 0x1, 
    0x2, 0x4e, 0x72, 0x5, 0x1a, 0xe, 0x2, 0x4f, 0x72, 0x7, 0x9a, 0x2, 0x2, 
    0x50, 0x51, 0x5, 0x28, 0x15, 0x2, 0x51, 0x52, 0x7, 0x4, 0x2, 0x2, 0x52, 
    0x54, 0x3, 0x2, 0x2, 0x2, 0x53, 0x50, 0x3, 0x2, 0x2, 0x2, 0x53, 0x54, 
    0x3, 0x2, 0x2, 0x2, 0x54, 0x55, 0x3, 0x2, 0x2, 0x2, 0x55, 0x56, 0x5, 
    0x2a, 0x16, 0x2, 0x56, 0x57, 0x7, 0x4, 0x2, 0x2, 0x57, 0x59, 0x3, 0x2, 
    0x2, 0x2, 0x58, 0x53, 0x3, 0x2, 0x2, 0x2, 0x58, 0x59, 0x3, 0x2, 0x2, 
    0x2, 0x59, 0x5a, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x72, 0x5, 0x30, 0x19, 0x2, 
    0x5b, 0x5c, 0x5, 0x26, 0x14, 0x2, 0x5c, 0x69, 0x7, 0x5, 0x2, 0x2, 0x5d, 
    0x5f, 0x7, 0x40, 0x2, 0x2, 0x5e, 0x5d, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x5f, 
    0x3, 0x2, 0x2, 0x2, 0x5f, 0x60, 0x3, 0x2, 0x2, 0x2, 0x60, 0x65, 0x5, 
    0x4, 0x3, 0x2, 0x61, 0x62, 0x7, 0x7, 0x2, 0x2, 0x62, 0x64, 0x5, 0x4, 
    0x3, 0x2, 0x63, 0x61, 0x3, 0x2, 0x2, 0x2, 0x64, 0x67, 0x3, 0x2, 0x2, 
    0x2, 0x65, 0x63, 0x3, 0x2, 0x2, 0x2, 0x65, 0x66, 0x3, 0x2, 0x2, 0x2, 
    0x66, 0x6a, 0x3, 0x2, 0x2, 0x2, 0x67, 0x65, 0x3, 0x2, 0x2, 0x2, 0x68, 
    0x6a, 0x7, 0x9, 0x2, 0x2, 0x69, 0x5e, 0x3, 0x2, 0x2, 0x2, 0x69, 0x68, 
    0x3, 0x2, 0x2, 0x2, 0x69, 0x6a, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x6b, 0x3, 
    0x2, 0x2, 0x2, 0x6b, 0x6c, 0x7, 0x6, 0x2, 0x2, 0x6c, 0x72, 0x3, 0x2, 
    0x2, 0x2, 0x6d, 0x6e, 0x7, 0x5, 0x2, 0x2, 0x6e, 0x6f, 0x5, 0x4, 0x3, 
    0x2, 0x6f, 0x70, 0x7, 0x6, 0x2, 0x2, 0x70, 0x72, 0x3, 0x2, 0x2, 0x2, 
    0x71, 0x4d, 0x3, 0x2, 0x2, 0x2, 0x71, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x71, 
    0x58, 0x3, 0x2, 0x2, 0x2, 0x71, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x71, 0x6d, 
    0x3, 0x2, 0x2, 0x2, 0x72, 0x81, 0x3, 0x2, 0x2, 0x2, 0x73, 0x74, 0xc, 
    0x8, 0x2, 0x2, 0x74, 0x75, 0x9, 0x2, 0x2, 0x2, 0x75, 0x80, 0x5, 0x4, 
    0x3, 0x9, 0x76, 0x77, 0xc, 0x7, 0x2, 0x2, 0x77, 0x78, 0x9, 0x3, 0x2, 
    0x2, 0x78, 0x80, 0x5, 0x4, 0x3, 0x8, 0x79, 0x7a, 0xc, 0x6, 0x2, 0x2, 
    0x7a, 0x7b, 0x7, 0x22, 0x2, 0x2, 0x7b, 0x80, 0x5, 0x4, 0x3, 0x7, 0x7c, 
    0x7d, 0xc, 0x5, 0x2, 0x2, 0x7d, 0x7e, 0x7, 0x6f, 0x2, 0x2, 0x7e, 0x80, 
    0x5, 0x4, 0x3, 0x6, 0x7f, 0x73, 0x3, 0x2, 0x2, 0x2, 0x7f, 0x76, 0x3, 
    0x2, 0x2, 0x2, 0x7f, 0x79, 0x3, 0x2, 0x2, 0x2, 0x7f, 0x7c, 0x3, 0x2, 
    0x2, 0x2, 0x80, 0x83, 0x3, 0x2, 0x2, 0x2, 0x81, 0x7f, 0x3, 0x2, 0x2, 
    0x2, 0x81, 0x82, 0x3, 0x2, 0x2, 0x2, 0x82, 0x5, 0x3, 0x2, 0x2, 0x2, 
    0x83, 0x81, 0x3, 0x2, 0x2, 0x2, 0x84, 0x85, 0x8, 0x4, 0x1, 0x2, 0x85, 
    0xa9, 0x5, 0x1a, 0xe, 0x2, 0x86, 0xa9, 0x7, 0x9a, 0x2, 0x2, 0x87, 0x88, 
    0x5, 0x28, 0x15, 0x2, 0x88, 0x89, 0x7, 0x4, 0x2, 0x2, 0x89, 0x8b, 0x3, 
    0x2, 0x2, 0x2, 0x8a, 0x87, 0x3, 0x2, 0x2, 0x2, 0x8a, 0x8b, 0x3, 0x2, 
    0x2, 0x2, 0x8b, 0x8c, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x8d, 0x5, 0x2a, 0x16, 
    0x2, 0x8d, 0x8e, 0x7, 0x4, 0x2, 0x2, 0x8e, 0x90, 0x3, 0x2, 0x2, 0x2, 
    0x8f, 0x8a, 0x3, 0x2, 0x2, 0x2, 0x8f, 0x90, 0x3, 0x2, 0x2, 0x2, 0x90, 
    0x91, 0x3, 0x2, 0x2, 0x2, 0x91, 0xa9, 0x5, 0x30, 0x19, 0x2, 0x92, 0x93, 
    0x5, 0x26, 0x14, 0x2, 0x93, 0xa0, 0x7, 0x5, 0x2, 0x2, 0x94, 0x96, 0x7, 
    0x40, 0x2, 0x2, 0x95, 0x94, 0x3, 0x2, 0x2, 0x2, 0x95, 0x96, 0x3, 0x2, 
    0x2, 0x2, 0x96, 0x97, 0x3, 0x2, 0x2, 0x2, 0x97, 0x9c, 0x5, 0x6, 0x4, 
    0x2, 0x98, 0x99, 0x7, 0x7, 0x2, 0x2, 0x99, 0x9b, 0x5, 0x6, 0x4, 0x2, 
    0x9a, 0x98, 0x3, 0x2, 0x2, 0x2, 0x9b, 0x9e, 0x3, 0x2, 0x2, 0x2, 0x9c, 
    0x9a, 0x3, 0x2, 0x2, 0x2, 0x9c, 0x9d, 0x3, 0x2, 0x2, 0x2, 0x9d, 0xa1, 
    0x3, 0x2, 0x2, 0x2, 0x9e, 0x9c, 0x3, 0x2, 0x2, 0x2, 0x9f, 0xa1, 0x7, 
    0x9, 0x2, 0x2, 0xa0, 0x95, 0x3, 0x2, 0x2, 0x2, 0xa0, 0x9f, 0x3, 0x2, 
    0x2, 0x2, 0xa0, 0xa1, 0x3, 0x2, 0x2, 0x2, 0xa1, 0xa2, 0x3, 0x2, 0x2, 
    0x2, 0xa2, 0xa3, 0x7, 0x6, 0x2, 0x2, 0xa3, 0xa9, 0x3, 0x2, 0x2, 0x2, 
    0xa4, 0xa5, 0x7, 0x5, 0x2, 0x2, 0xa5, 0xa6, 0x5, 0x6, 0x4, 0x2, 0xa6, 
    0xa7, 0x7, 0x6, 0x2, 0x2, 0xa7, 0xa9, 0x3, 0x2, 0x2, 0x2, 0xa8, 0x84, 
    0x3, 0x2, 0x2, 0x2, 0xa8, 0x86, 0x3, 0x2, 0x2, 0x2, 0xa8, 0x8f, 0x3, 
    0x2, 0x2, 0x2, 0xa8, 0x92, 0x3, 0x2, 0x2, 0x2, 0xa8, 0xa4, 0x3, 0x2, 
    0x2, 0x2, 0xa9, 0xb8, 0x3, 0x2, 0x2, 0x2, 0xaa, 0xab, 0xc, 0x8, 0x2, 
    0x2, 0xab, 0xac, 0x9, 0x4, 0x2, 0x2, 0xac, 0xb7, 0x5, 0x6, 0x4, 0x9, 
    0xad, 0xae, 0xc, 0x7, 0x2, 0x2, 0xae, 0xaf, 0x9, 0x5, 0x2, 0x2, 0xaf, 
    0xb7, 0x5, 0x6, 0x4, 0x8, 0xb0, 0xb1, 0xc, 0x6, 0x2, 0x2, 0xb1, 0xb2, 
    0x7, 0x22, 0x2, 0x2, 0xb2, 0xb7, 0x5, 0x6, 0x4, 0x7, 0xb3, 0xb4, 0xc, 
    0x5, 0x2, 0x2, 0xb4, 0xb5, 0x7, 0x6f, 0x2, 0x2, 0xb5, 0xb7, 0x5, 0x6, 
    0x4, 0x6, 0xb6, 0xaa, 0x3, 0x2, 0x2, 0x2, 0xb6, 0xad, 0x3, 0x2, 0x2, 
    0x2, 0xb6, 0xb0, 0x3, 0x2, 0x2, 0x2, 0xb6, 0xb3, 0x3, 0x2, 0x2, 0x2, 
    0xb7, 0xba, 0x3, 0x2, 0x2, 0x2, 0xb8, 0xb6, 0x3, 0x2, 0x2, 0x2, 0xb8, 
    0xb9, 0x3, 0x2, 0x2, 0x2, 0xb9, 0x7, 0x3, 0x2, 0x2, 0x2, 0xba, 0xb8, 
    0x3, 0x2, 0x2, 0x2, 0xbb, 0xc8, 0x7, 0x9, 0x2, 0x2, 0xbc, 0xbd, 0x5, 
    0x2a, 0x16, 0x2, 0xbd, 0xbe, 0x7, 0x4, 0x2, 0x2, 0xbe, 0xbf, 0x7, 0x9, 
    0x2, 0x2, 0xbf, 0xc8, 0x3, 0x2, 0x2, 0x2, 0xc0, 0xc5, 0x5, 0x4, 0x3, 
    0x2, 0xc1, 0xc3, 0x7, 0x23, 0x2, 0x2, 0xc2, 0xc1, 0x3, 0x2, 0x2, 0x2, 
    0xc2, 0xc3, 0x3, 0x2, 0x2, 0x2, 0xc3, 0xc4, 0x3, 0x2, 0x2, 0x2, 0xc4, 
    0xc6, 0x5, 0x20, 0x11, 0x2, 0xc5, 0xc2, 0x3, 0x2, 0x2, 0x2, 0xc5, 0xc6, 
    0x3, 0x2, 0x2, 0x2, 0xc6, 0xc8, 0x3, 0x2, 0x2, 0x2, 0xc7, 0xbb, 0x3, 
    0x2, 0x2, 0x2, 0xc7, 0xbc, 0x3, 0x2, 0x2, 0x2, 0xc7, 0xc0, 0x3, 0x2, 
    0x2, 0x2, 0xc8, 0x9, 0x3, 0x2, 0x2, 0x2, 0xc9, 0xca, 0x5, 0x28, 0x15, 
    0x2, 0xca, 0xcb, 0x7, 0x4, 0x2, 0x2, 0xcb, 0xcd, 0x3, 0x2, 0x2, 0x2, 
    0xcc, 0xc9, 0x3, 0x2, 0x2, 0x2, 0xcc, 0xcd, 0x3, 0x2, 0x2, 0x2, 0xcd, 
    0xce, 0x3, 0x2, 0x2, 0x2, 0xce, 0xd3, 0x5, 0x2a, 0x16, 0x2, 0xcf, 0xd1, 
    0x7, 0x23, 0x2, 0x2, 0xd0, 0xcf, 0x3, 0x2, 0x2, 0x2, 0xd0, 0xd1, 0x3, 
    0x2, 0x2, 0x2, 0xd1, 0xd2, 0x3, 0x2, 0x2, 0x2, 0xd2, 0xd4, 0x5, 0x42, 
    0x22, 0x2, 0xd3, 0xd0, 0x3, 0x2, 0x2, 0x2, 0xd3, 0xd4, 0x3, 0x2, 0x2, 
    0x2, 0xd4, 0xf2, 0x3, 0x2, 0x2, 0x2, 0xd5, 0xdf, 0x7, 0x5, 0x2, 0x2, 
    0xd6, 0xdb, 0x5, 0xa, 0x6, 0x2, 0xd7, 0xd8, 0x7, 0x7, 0x2, 0x2, 0xd8, 
    0xda, 0x5, 0xa, 0x6, 0x2, 0xd9, 0xd7, 0x3, 0x2, 0x2, 0x2, 0xda, 0xdd, 
    0x3, 0x2, 0x2, 0x2, 0xdb, 0xd9, 0x3, 0x2, 0x2, 0x2, 0xdb, 0xdc, 0x3, 
    0x2, 0x2, 0x2, 0xdc, 0xe0, 0x3, 0x2, 0x2, 0x2, 0xdd, 0xdb, 0x3, 0x2, 
    0x2, 0x2, 0xde, 0xe0, 0x5, 0xc, 0x7, 0x2, 0xdf, 0xd6, 0x3, 0x2, 0x2, 
    0x2, 0xdf, 0xde, 0x3, 0x2, 0x2, 0x2, 0xe0, 0xe1, 0x3, 0x2, 0x2, 0x2, 
    0xe1, 0xe6, 0x7, 0x6, 0x2, 0x2, 0xe2, 0xe4, 0x7, 0x23, 0x2, 0x2, 0xe3, 
    0xe2, 0x3, 0x2, 0x2, 0x2, 0xe3, 0xe4, 0x3, 0x2, 0x2, 0x2, 0xe4, 0xe5, 
    0x3, 0x2, 0x2, 0x2, 0xe5, 0xe7, 0x5, 0x42, 0x22, 0x2, 0xe6, 0xe3, 0x3, 
    0x2, 0x2, 0x2, 0xe6, 0xe7, 0x3, 0x2, 0x2, 0x2, 0xe7, 0xf2, 0x3, 0x2, 
    0x2, 0x2, 0xe8, 0xe9, 0x7, 0x5, 0x2, 0x2, 0xe9, 0xea, 0x5, 0x12, 0xa, 
    0x2, 0xea, 0xef, 0x7, 0x6, 0x2, 0x2, 0xeb, 0xed, 0x7, 0x23, 0x2, 0x2, 
    0xec, 0xeb, 0x3, 0x2, 0x2, 0x2, 0xec, 0xed, 0x3, 0x2, 0x2, 0x2, 0xed, 
    0xee, 0x3, 0x2, 0x2, 0x2, 0xee, 0xf0, 0x5, 0x42, 0x22, 0x2, 0xef, 0xec, 
    0x3, 0x2, 0x2, 0x2, 0xef, 0xf0, 0x3, 0x2, 0x2, 0x2, 0xf0, 0xf2, 0x3, 
    0x2, 0x2, 0x2, 0xf1, 0xcc, 0x3, 0x2, 0x2, 0x2, 0xf1, 0xd5, 0x3, 0x2, 
    0x2, 0x2, 0xf1, 0xe8, 0x3, 0x2, 0x2, 0x2, 0xf2, 0xb, 0x3, 0x2, 0x2, 
    0x2, 0xf3, 0xfa, 0x5, 0xa, 0x6, 0x2, 0xf4, 0xf5, 0x5, 0xe, 0x8, 0x2, 
    0xf5, 0xf6, 0x5, 0xa, 0x6, 0x2, 0xf6, 0xf7, 0x5, 0x10, 0x9, 0x2, 0xf7, 
    0xf9, 0x3, 0x2, 0x2, 0x2, 0xf8, 0xf4, 0x3, 0x2, 0x2, 0x2, 0xf9, 0xfc, 
    0x3, 0x2, 0x2, 0x2, 0xfa, 0xf8, 0x3, 0x2, 0x2, 0x2, 0xfa, 0xfb, 0x3, 
    0x2, 0x2, 0x2, 0xfb, 0xd, 0x3, 0x2, 0x2, 0x2, 0xfc, 0xfa, 0x3, 0x2, 
    0x2, 0x2, 0xfd, 0x108, 0x7, 0x7, 0x2, 0x2, 0xfe, 0x100, 0x7, 0x63, 0x2, 
    0x2, 0xff, 0x101, 0x7, 0x71, 0x2, 0x2, 0x100, 0xff, 0x3, 0x2, 0x2, 0x2, 
    0x100, 0x101, 0x3, 0x2, 0x2, 0x2, 0x101, 0x105, 0x3, 0x2, 0x2, 0x2, 
    0x102, 0x105, 0x7, 0x59, 0x2, 0x2, 0x103, 0x105, 0x7, 0x35, 0x2, 0x2, 
    0x104, 0xfe, 0x3, 0x2, 0x2, 0x2, 0x104, 0x102, 0x3, 0x2, 0x2, 0x2, 0x104, 
    0x103, 0x3, 0x2, 0x2, 0x2, 0x104, 0x105, 0x3, 0x2, 0x2, 0x2, 0x105, 
    0x106, 0x3, 0x2, 0x2, 0x2, 0x106, 0x108, 0x7, 0x61, 0x2, 0x2, 0x107, 
    0xfd, 0x3, 0x2, 0x2, 0x2, 0x107, 0x104, 0x3, 0x2, 0x2, 0x2, 0x108, 0xf, 
    0x3, 0x2, 0x2, 0x2, 0x109, 0x10a, 0x7, 0x6e, 0x2, 0x2, 0x10a, 0x118, 
    0x5, 0x4, 0x3, 0x2, 0x10b, 0x10c, 0x7, 0x8f, 0x2, 0x2, 0x10c, 0x10d, 
    0x7, 0x5, 0x2, 0x2, 0x10d, 0x112, 0x5, 0x30, 0x19, 0x2, 0x10e, 0x10f, 
    0x7, 0x7, 0x2, 0x2, 0x10f, 0x111, 0x5, 0x30, 0x19, 0x2, 0x110, 0x10e, 
    0x3, 0x2, 0x2, 0x2, 0x111, 0x114, 0x3, 0x2, 0x2, 0x2, 0x112, 0x110, 
    0x3, 0x2, 0x2, 0x2, 0x112, 0x113, 0x3, 0x2, 0x2, 0x2, 0x113, 0x115, 
    0x3, 0x2, 0x2, 0x2, 0x114, 0x112, 0x3, 0x2, 0x2, 0x2, 0x115, 0x116, 
    0x7, 0x6, 0x2, 0x2, 0x116, 0x118, 0x3, 0x2, 0x2, 0x2, 0x117, 0x109, 
    0x3, 0x2, 0x2, 0x2, 0x117, 0x10b, 0x3, 0x2, 0x2, 0x2, 0x117, 0x118, 
    0x3, 0x2, 0x2, 0x2, 0x118, 0x11, 0x3, 0x2, 0x2, 0x2, 0x119, 0x11b, 0x7, 
    0x83, 0x2, 0x2, 0x11a, 0x11c, 0x9, 0x6, 0x2, 0x2, 0x11b, 0x11a, 0x3, 
    0x2, 0x2, 0x2, 0x11b, 0x11c, 0x3, 0x2, 0x2, 0x2, 0x11c, 0x11d, 0x3, 
    0x2, 0x2, 0x2, 0x11d, 0x122, 0x5, 0x8, 0x5, 0x2, 0x11e, 0x11f, 0x7, 
    0x7, 0x2, 0x2, 0x11f, 0x121, 0x5, 0x8, 0x5, 0x2, 0x120, 0x11e, 0x3, 
    0x2, 0x2, 0x2, 0x121, 0x124, 0x3, 0x2, 0x2, 0x2, 0x122, 0x120, 0x3, 
    0x2, 0x2, 0x2, 0x122, 0x123, 0x3, 0x2, 0x2, 0x2, 0x123, 0x131, 0x3, 
    0x2, 0x2, 0x2, 0x124, 0x122, 0x3, 0x2, 0x2, 0x2, 0x125, 0x12f, 0x7, 
    0x4d, 0x2, 0x2, 0x126, 0x12b, 0x5, 0xa, 0x6, 0x2, 0x127, 0x128, 0x7, 
    0x7, 0x2, 0x2, 0x128, 0x12a, 0x5, 0xa, 0x6, 0x2, 0x129, 0x127, 0x3, 
    0x2, 0x2, 0x2, 0x12a, 0x12d, 0x3, 0x2, 0x2, 0x2, 0x12b, 0x129, 0x3, 
    0x2, 0x2, 0x2, 0x12b, 0x12c, 0x3, 0x2, 0x2, 0x2, 0x12c, 0x130, 0x3, 
    0x2, 0x2, 0x2, 0x12d, 0x12b, 0x3, 0x2, 0x2, 0x2, 0x12e, 0x130, 0x5, 
    0xc, 0x7, 0x2, 0x12f, 0x126, 0x3, 0x2, 0x2, 0x2, 0x12f, 0x12e, 0x3, 
    0x2, 0x2, 0x2, 0x130, 0x132, 0x3, 0x2, 0x2, 0x2, 0x131, 0x125, 0x3, 
    0x2, 0x2, 0x2, 0x131, 0x132, 0x3, 0x2, 0x2, 0x2, 0x132, 0x134, 0x3, 
    0x2, 0x2, 0x2, 0x133, 0x135, 0x5, 0x14, 0xb, 0x2, 0x134, 0x133, 0x3, 
    0x2, 0x2, 0x2, 0x134, 0x135, 0x3, 0x2, 0x2, 0x2, 0x135, 0x137, 0x3, 
    0x2, 0x2, 0x2, 0x136, 0x138, 0x5, 0x16, 0xc, 0x2, 0x137, 0x136, 0x3, 
    0x2, 0x2, 0x2, 0x137, 0x138, 0x3, 0x2, 0x2, 0x2, 0x138, 0x158, 0x3, 
    0x2, 0x2, 0x2, 0x139, 0x13a, 0x7, 0x91, 0x2, 0x2, 0x13a, 0x13b, 0x7, 
    0x5, 0x2, 0x2, 0x13b, 0x140, 0x5, 0x4, 0x3, 0x2, 0x13c, 0x13d, 0x7, 
    0x7, 0x2, 0x2, 0x13d, 0x13f, 0x5, 0x4, 0x3, 0x2, 0x13e, 0x13c, 0x3, 
    0x2, 0x2, 0x2, 0x13f, 0x142, 0x3, 0x2, 0x2, 0x2, 0x140, 0x13e, 0x3, 
    0x2, 0x2, 0x2, 0x140, 0x141, 0x3, 0x2, 0x2, 0x2, 0x141, 0x143, 0x3, 
    0x2, 0x2, 0x2, 0x142, 0x140, 0x3, 0x2, 0x2, 0x2, 0x143, 0x152, 0x7, 
    0x6, 0x2, 0x2, 0x144, 0x145, 0x7, 0x7, 0x2, 0x2, 0x145, 0x146, 0x7, 
    0x5, 0x2, 0x2, 0x146, 0x14b, 0x5, 0x4, 0x3, 0x2, 0x147, 0x148, 0x7, 
    0x7, 0x2, 0x2, 0x148, 0x14a, 0x5, 0x4, 0x3, 0x2, 0x149, 0x147, 0x3, 
    0x2, 0x2, 0x2, 0x14a, 0x14d, 0x3, 0x2, 0x2, 0x2, 0x14b, 0x149, 0x3, 
    0x2, 0x2, 0x2, 0x14b, 0x14c, 0x3, 0x2, 0x2, 0x2, 0x14c, 0x14e, 0x3, 
    0x2, 0x2, 0x2, 0x14d, 0x14b, 0x3, 0x2, 0x2, 0x2, 0x14e, 0x14f, 0x7, 
    0x6, 0x2, 0x2, 0x14f, 0x151, 0x3, 0x2, 0x2, 0x2, 0x150, 0x144, 0x3, 
    0x2, 0x2, 0x2, 0x151, 0x154, 0x3, 0x2, 0x2, 0x2, 0x152, 0x150, 0x3, 
    0x2, 0x2, 0x2, 0x152, 0x153, 0x3, 0x2, 0x2, 0x2, 0x153, 0x155, 0x3, 
    0x2, 0x2, 0x2, 0x154, 0x152, 0x3, 0x2, 0x2, 0x2, 0x155, 0x156, 0x7, 
    0x3, 0x2, 0x2, 0x156, 0x158, 0x3, 0x2, 0x2, 0x2, 0x157, 0x119, 0x3, 
    0x2, 0x2, 0x2, 0x157, 0x139, 0x3, 0x2, 0x2, 0x2, 0x158, 0x13, 0x3, 0x2, 
    0x2, 0x2, 0x159, 0x15a, 0x7, 0x95, 0x2, 0x2, 0x15a, 0x15b, 0x5, 0x4, 
    0x3, 0x2, 0x15b, 0x15, 0x3, 0x2, 0x2, 0x2, 0x15c, 0x15d, 0x7, 0x50, 
    0x2, 0x2, 0x15d, 0x15e, 0x7, 0x2a, 0x2, 0x2, 0x15e, 0x163, 0x5, 0x4, 
    0x3, 0x2, 0x15f, 0x160, 0x7, 0x7, 0x2, 0x2, 0x160, 0x162, 0x5, 0x4, 
    0x3, 0x2, 0x161, 0x15f, 0x3, 0x2, 0x2, 0x2, 0x162, 0x165, 0x3, 0x2, 
    0x2, 0x2, 0x163, 0x161, 0x3, 0x2, 0x2, 0x2, 0x163, 0x164, 0x3, 0x2, 
    0x2, 0x2, 0x164, 0x17, 0x3, 0x2, 0x2, 0x2, 0x165, 0x163, 0x3, 0x2, 0x2, 
    0x2, 0x166, 0x168, 0x9, 0x7, 0x2, 0x2, 0x167, 0x166, 0x3, 0x2, 0x2, 
    0x2, 0x167, 0x168, 0x3, 0x2, 0x2, 0x2, 0x168, 0x169, 0x3, 0x2, 0x2, 
    0x2, 0x169, 0x16a, 0x7, 0x99, 0x2, 0x2, 0x16a, 0x19, 0x3, 0x2, 0x2, 
    0x2, 0x16b, 0x16c, 0x9, 0x8, 0x2, 0x2, 0x16c, 0x1b, 0x3, 0x2, 0x2, 0x2, 
    0x16d, 0x16e, 0x9, 0x9, 0x2, 0x2, 0x16e, 0x1d, 0x3, 0x2, 0x2, 0x2, 0x16f, 
    0x170, 0x7, 0x9b, 0x2, 0x2, 0x170, 0x1f, 0x3, 0x2, 0x2, 0x2, 0x171, 
    0x172, 0x9, 0xa, 0x2, 0x2, 0x172, 0x21, 0x3, 0x2, 0x2, 0x2, 0x173, 0x174, 
    0x9, 0xb, 0x2, 0x2, 0x174, 0x23, 0x3, 0x2, 0x2, 0x2, 0x175, 0x176, 0x5, 
    0x46, 0x24, 0x2, 0x176, 0x25, 0x3, 0x2, 0x2, 0x2, 0x177, 0x178, 0x5, 
    0x46, 0x24, 0x2, 0x178, 0x27, 0x3, 0x2, 0x2, 0x2, 0x179, 0x17a, 0x5, 
    0x46, 0x24, 0x2, 0x17a, 0x29, 0x3, 0x2, 0x2, 0x2, 0x17b, 0x17c, 0x5, 
    0x46, 0x24, 0x2, 0x17c, 0x2b, 0x3, 0x2, 0x2, 0x2, 0x17d, 0x17e, 0x5, 
    0x46, 0x24, 0x2, 0x17e, 0x2d, 0x3, 0x2, 0x2, 0x2, 0x17f, 0x180, 0x5, 
    0x46, 0x24, 0x2, 0x180, 0x2f, 0x3, 0x2, 0x2, 0x2, 0x181, 0x182, 0x5, 
    0x46, 0x24, 0x2, 0x182, 0x31, 0x3, 0x2, 0x2, 0x2, 0x183, 0x184, 0x5, 
    0x46, 0x24, 0x2, 0x184, 0x33, 0x3, 0x2, 0x2, 0x2, 0x185, 0x186, 0x5, 
    0x46, 0x24, 0x2, 0x186, 0x35, 0x3, 0x2, 0x2, 0x2, 0x187, 0x188, 0x5, 
    0x46, 0x24, 0x2, 0x188, 0x37, 0x3, 0x2, 0x2, 0x2, 0x189, 0x18a, 0x5, 
    0x46, 0x24, 0x2, 0x18a, 0x39, 0x3, 0x2, 0x2, 0x2, 0x18b, 0x18c, 0x5, 
    0x46, 0x24, 0x2, 0x18c, 0x3b, 0x3, 0x2, 0x2, 0x2, 0x18d, 0x18e, 0x5, 
    0x46, 0x24, 0x2, 0x18e, 0x3d, 0x3, 0x2, 0x2, 0x2, 0x18f, 0x190, 0x5, 
    0x46, 0x24, 0x2, 0x190, 0x3f, 0x3, 0x2, 0x2, 0x2, 0x191, 0x192, 0x5, 
    0x46, 0x24, 0x2, 0x192, 0x41, 0x3, 0x2, 0x2, 0x2, 0x193, 0x194, 0x5, 
    0x46, 0x24, 0x2, 0x194, 0x43, 0x3, 0x2, 0x2, 0x2, 0x195, 0x196, 0x5, 
    0x46, 0x24, 0x2, 0x196, 0x45, 0x3, 0x2, 0x2, 0x2, 0x197, 0x19f, 0x7, 
    0x98, 0x2, 0x2, 0x198, 0x19f, 0x5, 0x22, 0x12, 0x2, 0x199, 0x19f, 0x7, 
    0x9b, 0x2, 0x2, 0x19a, 0x19b, 0x7, 0x5, 0x2, 0x2, 0x19b, 0x19c, 0x5, 
    0x46, 0x24, 0x2, 0x19c, 0x19d, 0x7, 0x6, 0x2, 0x2, 0x19d, 0x19f, 0x3, 
    0x2, 0x2, 0x2, 0x19e, 0x197, 0x3, 0x2, 0x2, 0x2, 0x19e, 0x198, 0x3, 
    0x2, 0x2, 0x2, 0x19e, 0x199, 0x3, 0x2, 0x2, 0x2, 0x19e, 0x19a, 0x3, 
    0x2, 0x2, 0x2, 0x19f, 0x47, 0x3, 0x2, 0x2, 0x2, 0x34, 0x4b, 0x53, 0x58, 
    0x5e, 0x65, 0x69, 0x71, 0x7f, 0x81, 0x8a, 0x8f, 0x95, 0x9c, 0xa0, 0xa8, 
    0xb6, 0xb8, 0xc2, 0xc5, 0xc7, 0xcc, 0xd0, 0xd3, 0xdb, 0xdf, 0xe3, 0xe6, 
    0xec, 0xef, 0xf1, 0xfa, 0x100, 0x104, 0x107, 0x112, 0x117, 0x11b, 0x122, 
    0x12b, 0x12f, 0x131, 0x134, 0x137, 0x140, 0x14b, 0x152, 0x157, 0x163, 
    0x167, 0x19e, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

SqlParser::Initializer SqlParser::_init;
