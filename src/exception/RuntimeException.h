
#pragma once

#include <iostream>
#include <exception>

class QueryRuntimeException: public std::exception
{
    protected: 
    std::string msg;
  public: 
    QueryRuntimeException(const std::string &reason = std::string()) {
        msg = "Error: "+reason;
    }
    virtual const char* what() const throw () override {
        return msg.c_str();
    }
};
