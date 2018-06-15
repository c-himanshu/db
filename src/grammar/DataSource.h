#pragma once 
#include <string>
#include "constants/Constants.h"
using namespace std;
class DataSource {
    public: 
    DataSource(string dname = constants::NO_TBL_NAME, string dalias = constants::NO_TBL_ALIAS_GIVEN) : name(dname), alias(dalias) { }
    string queryString; 
    string name;
    string alias; 

    virtual string str() const {
        if(alias.size() && name.size())
            return name +" as " + alias;
        if( (name == constants::NO_TBL_NAME || name.empty()) && queryString.size())
            return queryString + (alias.empty() ? "" : ("as "+ alias)); 
        return name;
    }
};
