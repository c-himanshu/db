#pragma once

#include "model/RelationSet.h"
#include "model/ResultSet.h"
#include "model/RelationalTable.h"
#include "model/ColumnSpec.h"
#include "model/TableSpec.h"

#include "grammar/SqlParser.h"
#include "metadata/DBCatalog.h"

namespace executor
{
using namespace std;
using namespace model;
using namespace query;
class SelectQueryExecutor
{
  private:
    SqlParser::Select_coreContext *rootSelectCore;

  public:
    SelectQueryExecutor(SqlParser::Select_coreContext *q) : rootSelectCore(q) {}
    //SelectQueryExecutor(const SelectNode &sq) : selectQuery(sq) {}
    RelationSet getQueryResult();
};
} // namespace executor