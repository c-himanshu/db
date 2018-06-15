#include "DataRow.h"
#include "util/Collections.h"
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>
#include <cassert>

namespace model {
    void DataRow::print(std::ostream& stream, const std::vector<size_t> &widths, const std::vector<size_t> positionsToPrint) const {
        if(data.empty()) return;
        assert(!widths.empty());
        size_t i=0;
        stream << "|";
        for(;i<data.size() - 1;i++) {
            if(positionsToPrint.empty() || util::Collections::containerHasValue(positionsToPrint, i)){
                stream << std::setw(widths[i]) << std::left << data[i] << " | ";
            }
        }
        if(positionsToPrint.empty() || util::Collections::containerHasValue(positionsToPrint, i)){
            stream << std::setw(widths[i]) << std::left << data[i] << " |" ;
        }
        stream << std::endl;
    }
    
    void DataRow::appendColumnData(const DataRow &right){
        for(auto & d : right.getEntries()){
            data.push_back(d);
        }
    }
    
    void DataRow::appendNulls(size_t count){
        for(size_t i=0;i<count;i++) {
             data.push_back("NULL");
        }
    }
    
    std::ostream& operator<< (std::ostream& stream, const model::DataRow& row) {
        std::vector<size_t> colWidths (row.size());
        for(size_t i=0;i<colWidths.size();i++) {
            colWidths[i] = 16;
        }
        row.print(stream, colWidths); 
        return stream;
    }
}
