//
//  FetchSpec.cpp
//  sql
//
//  Created by Himanshu Chauhan on 6/8/18.
//
#include "FetchSpec.h"
#include <stdio.h>


bool operator== (const query::FetchSpec &first, const query::FetchSpec &second){
    return first.getTableName() == second.getTableName() &&
    first.getTableAlias() == second.getTableAlias();
}

