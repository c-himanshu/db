/*
 * RelationalTable.h
 *
 *  Created on: May 18, 2018
 *      Author: hchauhan
 */

#pragma once

#include <vector>

#include "RelationSet.h"
namespace model
{
    using namespace std;

class RelationalTable : public RelationSet
{
  protected:
    string dataFilePath;

  public:
    RelationalTable(const string &name) : RelationSet(name, true /* isTable */) {}
    RelationalTable(const string &name, const string &dataFile) : RelationSet(name, true /* isTable */), dataFilePath(dataFile) {}
    void setDataFilePath(const string &fpath)
    {
        dataFilePath = fpath;
    }
    const string &getDataFilePath() const
    {
        return dataFilePath;
    }
};
} // namespace model
