#pragma once

#include <set>
#include <unordered_map>
#include <boost/optional/optional.hpp>
#include "model/DataRow.h"
#include "query/FetchSpec.h"


 using namespace std;
namespace csvops
{
class CSVReader
{

  private:
    std::string fpath;
    query::FetchSpec fetchSpec;
  public:
    CSVReader(const std::string &path, query::FetchSpec &fspec) : fpath(path), fetchSpec(fspec) {}
    std::vector<model::DataRow> getDataFromFile();

    //const boost::optional<std::vector<double>> getSumsFromFile(const std::set<int> &colIndices, const std::set<ConditionColumn> &whereClauses, bool computeAverage = false) const;
    //const size_t getCountFromFile(const std::set<ConditionColumn> &whereClauses) const;
    //const size_t getCountDistinctFromFile(const std::set<int> &colIndices, const std::set<ConditionColumn> &whereClauses) const;
};
} // namespace csvops
