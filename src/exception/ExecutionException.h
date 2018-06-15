
#pragma once

#include <exception>
#include "util/StringUtil.h"

#include "InvalidQueryException.h"

class ExecutionException: public std::exception
{
    protected: 
    std::string msg;
  public: 
    ExecutionException(const std::string &reason = std::string()) {
        msg = "ExecutionException: "+reason;
    }
    virtual const char* what() const throw () override {
        return msg.c_str();
    }
};

