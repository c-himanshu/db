#include "column_condition.h"

#include <string>
#include <vector>
#include <iostream>

#include "../constants/Constants.h"

void ConditionColumn::print(std::ostream &stream) const
{
    stream << str() << std::endl;
}

std::string ConditionColumn::opString(const constants::COMPARE_OP &op)
{
    switch (op)
    {
    case constants::EQ:
        return "=";
    case constants::NEQ:
        return "!=";
    case constants::GE:
        return ">=";
    case constants::GT:
        return ">";
    case constants::LE:
        return "<=";
    case constants::LT:
        return "<";
    default:
        return "UNSUPPORTED_OP";
    }
}
std::string ConditionColumn::str() const
{
    return getQualifiedName() + "(" + std::to_string(getColumnIndexInTable()) + ")" + opString(getOp()) + getColumnValString();
}

std::ostream &operator<<(std::ostream &stream, const ConditionColumn &cond)
{
    cond.print(stream);
    return stream;
}