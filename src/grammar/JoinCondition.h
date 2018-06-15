#pragma once 
#include <string> 
using namespace std;
class JoinCondition {
    public: 
        string joinOp; 
        string condition; 
        string leftTableName;
        string leftColumnName;
        string rightTableName;
        string rightColumnName;
        bool isLeftOuter = false;
        bool isRightOuter = false;
    
    bool isCrossJoin() const{
        return leftColumnName.empty() && rightColumnName.empty();
    }
    string str() const{
        if(isLeftOuter)
        return "LEFT OUTER "+leftTableName+"."+leftColumnName + " = " + rightTableName+"."+rightColumnName;
        if(isRightOuter)
            return "RIGHT OUTER "+leftTableName+"."+leftColumnName + " = " + rightTableName+"."+rightColumnName;
        
            return leftTableName+"."+leftColumnName + " = " + rightTableName+"."+rightColumnName;
    }
};
