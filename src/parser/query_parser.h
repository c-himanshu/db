#pragma once

#include <iostream>

#include "antlr4-runtime.h"
#include <boost/algorithm/string.hpp>
#include <boost/optional/optional.hpp>

#include "grammar/SqlParser.h"
#include "grammar/SqlLexer.h"
#include "grammar/SqlVisitor.h"
#include "grammar/SqlBaseVisitor.h"
#include "query/column_condition.h"
#include "query/select.h"

#include <set>
#include <string>
#include <unordered_map>

using namespace std;
using namespace antlr4;

namespace sqlparser
{
boost::optional<SelectQuery> parseQuery(const std::string &query);
}