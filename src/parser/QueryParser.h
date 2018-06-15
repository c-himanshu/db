#pragma once

#include <iostream>

#include "antlr4-runtime.h"
#include <boost/algorithm/string.hpp>
#include <boost/optional/optional.hpp>

#include "grammar/SqlParser.h"
#include "grammar/SqlLexer.h"
#include "grammar/SqlVisitor.h"
#include "grammar/SqlBaseVisitor.h"

#include <set>
#include <string>
#include <unordered_map>

#include <memory>

using namespace std;
using namespace antlr4;
#include "grammar/LogicalQueryNode.h"
namespace parser
{
    class QueryParser {
        private: 
        string qString;
        public: 
            QueryParser(const std::string &query): qString(query) {}
            const shared_ptr<LogicalQueryNode> parseQuery();
    };
}