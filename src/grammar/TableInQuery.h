#pragma once 
#include <string> 

#include "grammar/DataSource.h"

using namespace std;
class TableInQuery : public DataSource{
    public:
    bool isJoinTable = false;
    TableInQuery(string tname = "_no_tbl_name"): DataSource(tname) {}
    virtual string str() const override {
        if(alias != constants::NO_TBL_ALIAS_GIVEN)
            return name +" as " + alias;
        return name;
    }
};
