#pragma once

#include <string>
#include "constants/Constants.h"
#include "util/StringUtil.h"

namespace model
{
class ColumnSpec
{
  private:
    std::string columnName;
    size_t columnPosition;
    data_types::DATA_TYPE colType;
    std::string tableName = constants::NO_TBL_NAME;
  public:
    ColumnSpec(std::string columnName = "_NO_COL_NAME",
        size_t columnPosition = 0, data_types::DATA_TYPE colType = data_types::INT) : columnName(columnName),
        columnPosition(columnPosition),
                                 colType(colType)
                                  {}

    const std::string &getColumnName() const
    {
        return columnName;
    }
    
    void setTableName(std::string name){ tableName = name; }
    
    std::string getTableName() { return tableName; }

    void setColumnName(std::string colname) 
    {
        columnName = colname;
    }
    void print(std::ostream& stream) const;
    const std::string getColumnTypeString() const
    {
        return util::StringUtil::dataTypeAsString(colType);
    }

    const data_types::DATA_TYPE &getColType() const
    {
        return colType;
    }

    void setColType(data_types::DATA_TYPE cType) 
    {
         colType = cType;
    }

    size_t getColumnPosition() const
    {
        return columnPosition;
    }

    void setColumnPosition(size_t pos) 
    {
         columnPosition = pos;
    }
};
} // namespace model

std::ostream& operator<< (std::ostream& stream, const  model::ColumnSpec& cs);

