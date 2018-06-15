#pragma once

#include <vector>

#include "DataRow.h"
#include "RelationSet.h"

namespace model {
class ResultSet : public model::RelationSet {
  private:
    std::vector<model::DataRow> rows;

  public:
    ResultSet(const std::string &name = "_UNNAMED_RS") : RelationSet(name) {}

    inline size_t size() const
    {
        return rows.size();
    }

    inline bool empty() const
    {
        return rows.empty();
    }

    const std::vector<model::DataRow> &getRows() const
    {
        return rows;
    }
};
}