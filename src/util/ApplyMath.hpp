//
//  ApplyMath.hpp
//  sql
//
//  Created by Himanshu Chauhan on 6/13/18.
//

#pragma once

#include <string>

#include <cctype>
#include <map>
#include <string>
#include <sstream>
#include <vector>
#include <iostream>


using namespace std;
    class Parser {
        typedef int value_type;
        typedef std::vector<value_type> valuestack;
        typedef std::vector<char> opstack;
        typedef std::map<std::string,value_type> memory;
    public:
        memory  variables;
    private:
        void evaluateSingleOperator(char op,value_type &result,value_type operand) {
            switch(op) {
                case '+': result += operand; break;
                case '-': result -= operand; break;
                case '*': result *= operand; break;
                case '/': result /= operand; break;
                default: throw("invalid operand");
            }
        }
        void evaluateStacks(valuestack &values, opstack &ops) {
            while(ops.size() && values.size()>1) {
                char op = ops.back(); ops.pop_back();
                value_type operand = values.back(); values.pop_back();
                evaluateSingleOperator(op,values.back(),operand);
            }
        }
        bool higherPrecedenceOrLeftAssociative(char last, char current) {
            return (last == current)||(last == '*' || last == '/') ;
        }
        bool shouldEvaluate(char op,opstack const &ops) {
            return ops.size() > 0 && higherPrecedenceOrLeftAssociative(ops.back(),op);
        }
        std::string parseVariableName(std::istream &is) {
            std::string variable;
            char nextchar=0;
            while ((is >> nextchar) && isalpha(nextchar)) {
                variable += nextchar;
            }
            if (variable.size() == 0) throw std::string("internal parse error");
            is.unget();
            return variable;
        }
        int peekWithSkipWhiteSpace(std::istream &is) {
            int nextchar = EOF;
            while(isspace(nextchar = is.peek())) is.get();
            return nextchar;
        }
        value_type getOperand(std::istream &is) {
            int nextchar = peekWithSkipWhiteSpace(is);
            if (nextchar == EOF) throw std::string("syntax error operand expected");
            if (isdigit(nextchar)){
                value_type operand=0;
                if (!(is >> operand)) throw std::string("syntax error getting number") ;
                return operand;
            } else if ('(' == nextchar) {
                is.get();
                return parse(is);
            } else if (isalpha(nextchar)) {
                std::string variable= parseVariableName(is);
                if( parseAssignmentOperator(is)) {
                    variables[variable] = parse(is);
                } else {
                    if (!variables.count(variable)) throw std::string("undefined variable: ")+variable;
                }
                return variables[variable];
            }
            throw std::string("syntax error");
        }
        bool parseAssignmentOperator(std::istream &is) {
            int nextchar = peekWithSkipWhiteSpace(is);
            if ('=' != nextchar) {
                return false;
            }
            is.get();
            return true;
        }
    public:
        value_type parse(std::istream &is) {
            is >> std::skipws;
            valuestack values;
            opstack ops;
            values.push_back(getOperand(is));
            char op=')';
            while((is  >>op) && op != ')') {
                if (shouldEvaluate(op, ops)) {
                    evaluateStacks(values, ops);
                }
                values.push_back(getOperand(is));
                ops.push_back(op);
            }
            evaluateStacks(values,ops);
            return values.back();
        }
        value_type eval(std::string s) {
            std::istringstream is(s);
            return parse(is);
        }
    };
    int eval(std::string s) {
        return Parser().eval(s);
    }
    void shouldThrowEmptyExpression() {
        eval("");
    }
    void shouldThrowSyntaxError() {
        eval("()");
    }
    void shouldThrowUndefined() {
        eval("2 * undefinedVariable");
    }


int do_math(std::string expression, std::string x, int val){
    Parser p;
    p.eval(x+"="+std::to_string(val));
    return p.eval(expression);
}
