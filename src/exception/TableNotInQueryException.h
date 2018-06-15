
#pragma once

#include <iostream>
#include <exception>
#include "util/StringUtil.h"

#include "InvalidQueryException.h"

class TableNotInQueryException: public InvalidQueryException
{
  public: 
    TableNotInQueryException(const std::string& tableName) : InvalidQueryException(
       util::StringUtil::string_format("Table: %s was not given in the query.",tableName.c_str())){}
};