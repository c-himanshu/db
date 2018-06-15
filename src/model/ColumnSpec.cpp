#include "ColumnSpec.h"

#include <string>
#include <vector>
#include <iomanip>


    void model::ColumnSpec::print(std::ostream& stream) const {
        stream << "ColumnSpec: {";
        stream << getColumnName() << " ";
        stream << getColumnPosition() << " ";
        stream << getColumnTypeString() << " ";
        stream << "}";
    }

    std::ostream& operator<< (std::ostream& stream, const  model::ColumnSpec& row) {
        row.print(stream); 
        return stream;
    }