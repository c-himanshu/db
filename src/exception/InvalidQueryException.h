
#pragma once

#include <iostream>
#include <exception>
#include "util/StringUtil.h"

class InvalidQueryException: public std::exception
{
    protected: 
    std::string msg;
  public: 
    InvalidQueryException(const std::string &reason = std::string()) {
        msg = "Error: invalid query. "+reason;
    }
    virtual const char* what() const throw () override {
        return msg.c_str();
    }
};
