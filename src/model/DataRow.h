#pragma once

#include <string>
#include <vector>
#include <iostream>

namespace model {
    class DataRow {
    private:
        std::vector<std::string> data;
        int sortIndex = 0;
    public:
        DataRow() {}
        DataRow(const std::vector<std::string> & data) : data(data) {}
        virtual void print(
                           std::ostream& stream, const std::vector<size_t> &widths, const std::vector<size_t> positionsToPrint = std::vector<size_t>()) const;
        void setSortIndex(int ind) {
            sortIndex = ind;
        }
        const std::string &operator[] (int i) const {
            return data[i];
        }
        void copyDataFromAnotherRow(const DataRow &other){
            for(size_t i = 0; i<other.data.size(); i++){
                data.push_back(other[i]);
            }
        }
        void appendNulls(size_t count);
        void appendColumnData(const DataRow &right);
        void push_back(std::string entry){
            data.push_back(entry);
        }
        void setValue(size_t i, std::string v) {
            data[i] = v;
        }
        int getSortIndex() const{
            return sortIndex;
        }
        int size() const {
            return data.size();
        }
        const std::vector<std::string> &getEntries() const {
            return data;
        }
    };
    
    inline bool operator< (const DataRow &r1, const DataRow &r2){
        return r1[r1.getSortIndex()] < r2[r2.getSortIndex()];
    }
    std::ostream& operator<< (std::ostream& stream, const  model::DataRow& row);
}
