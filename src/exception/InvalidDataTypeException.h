
#pragma once

#include <iostream>
#include <exception>
#include "util/StringUtil.h"

#include "InvalidQueryException.h"

class InvalidDataTypeException: public InvalidQueryException
{
  public: 
    InvalidDataTypeException(const std::string& dtypeName) :  InvalidQueryException(
      util::StringUtil::string_format("Datatype: %s is invalid.",dtypeName.c_str())){}
};