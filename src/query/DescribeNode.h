#pragma once

#include "grammar/SqlParser.h"
#include "metadata/DBCatalog.h"
#include "WorkNode.h"

#include <vector>
#include <string>

namespace query
{
class DescribeNode : public WorkNode
{
    public: 
        DescribeNode() : WorkNode(false){}
        vector<model::ColumnSpec> presentColumnSpec() override {
            return vector<model::ColumnSpec>();
        }
        virtual void addTableAlias(string, string) override{}
        virtual void setTableAliases(const std::map<string, string> &aliases) override{}
};
} // namespace query