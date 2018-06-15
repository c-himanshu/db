#include "select.h"

#include <iostream>

void ColumnInTable::print(std::ostream &stream) const
{
    stream << getQualifiedName() << "[" << getColumnIndexInTable() << "]";
}
std::ostream &operator<<(std::ostream &stream, const ColumnInTable &col)
{
    col.print(stream);
    return stream;
}

std::ostream &operator<<(std::ostream &stream, const SelectQuery &sq)
{
    stream << "SELECT_QUERY| tables: {";
    for (auto t : sq.getTableNames())
    {
        stream << t << " ";
    }
    stream << " } ";

    stream << "columns: {";
    for (auto t : sq.getColumns())
    {
        stream << t << " ";
    }
    stream << " } ";

    stream << "wheres: {";
    for (auto t : sq.getConditions())
    {
        stream << t << " ";
    }
    stream << " } ";

    stream << "groups: {";
    for (auto t : sq.getGroupByCols())
    {
        stream << t << " ";
    }
    stream << " } ";
    return stream;
}
