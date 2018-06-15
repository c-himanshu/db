
#pragma once

#include <iostream>
#include <exception>
#include "util/StringUtil.h"

#include "InvalidQueryException.h"

class NoParamsException: public InvalidQueryException
{

  public: 
    NoParamsException(bool noColumn = false): InvalidQueryException(
      util::StringUtil::string_format("Error: No %s was requested in the query",
                                              noColumn ? "table" : "column")) {}
};
