
#pragma once

#include <iostream>
#include <exception>
#include "util/StringUtil.h"

#include "exception/InvalidQueryException.h"

class NoSuchEntryException : public InvalidQueryException
{
private:
  std::string entryName;
  //bool isColumn;

public:
  NoSuchEntryException(const std::string &name, bool isCol = false) : 
    InvalidQueryException(util::StringUtil::string_format("No %s found for the name: %s",
                                                          isCol ? "column" : "table",
                                                          name.c_str()))
  {}
};
