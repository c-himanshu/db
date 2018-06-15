#pragma once

#include <string>
#include <vector>

#include "../constants/Constants.h"


class ConditionColumn 
{
public:
    ConditionColumn (const std::string colname = std::string(), const std::string value = std::string(), constants::COMPARE_OP operation = constants::NEQ, int index = -1)
      : ColumnInTable("UNKNOWN_TABLE", colname, index), 
        op(operation), columnValString(value) {} ;

    inline std::string getColumnValString() const {
        return columnValString;
    }

    inline constants::COMPARE_OP getOp() const {
        return op;
    }

    inline void setOp(constants::COMPARE_OP oper) {
        op = oper;
    }

    void print(std::ostream& stream) const;

    std::string str() const;

    static std::string opString(const constants::COMPARE_OP & op);

private:
    constants::COMPARE_OP op;
    std::string columnValString;
};

std::ostream& operator<< (std::ostream& stream, const  ConditionColumn& cond);

inline bool operator> (const ConditionColumn &c1, const ConditionColumn &c2)
{
    return c1.getColumnName() > c2.getColumnName() ||
            c1.getColumnIndexInTable() > c1.getColumnIndexInTable() ||
            c1.getOp() > c2.getOp() ||
            c1.getColumnValString() > c2.getColumnValString();
}
 
 inline bool operator== (const ConditionColumn &c1, const ConditionColumn &c2)
{
    return c1.getColumnName() == c2.getColumnName() &&
            c1.getColumnIndexInTable() == c1.getColumnIndexInTable() &&
            c1.getOp() == c2.getOp() &&
            c1.getColumnValString() == c2.getColumnValString();
}
 

inline bool operator>= (const ConditionColumn &c1, const ConditionColumn &c2)
{
    return c1.getColumnName() >= c2.getColumnName() ||
            c1.getColumnIndexInTable() >= c1.getColumnIndexInTable() ||
            c1.getOp() >= c2.getOp() ||
            c1.getColumnValString() >= c2.getColumnValString();
}
 
inline bool operator< (const ConditionColumn &c1, const ConditionColumn &c2)
{
    return c1.getColumnName() < c2.getColumnName() ||
            c1.getColumnIndexInTable() < c1.getColumnIndexInTable() ||
            c1.getOp() < c2.getOp() ||
            c1.getColumnValString() < c2.getColumnValString();
}
 
inline bool operator<= (const ConditionColumn &c1, const ConditionColumn &c2)
{
    return c1.getColumnName() <= c2.getColumnName() ||
            c1.getColumnIndexInTable() <= c1.getColumnIndexInTable() ||
            c1.getOp() <= c2.getOp() ||
            c1.getColumnValString() <= c2.getColumnValString();
}

//typedef std::vector< std::shared_ptr<ColumnValuePair >> property_list_type;