/*
 *
 *  Created on: May 18, 2018
 *      Author: hchauhan
 */

#pragma once 

#include <string>
#include <vector>
#include <iostream>
#include <iomanip>

#include "ColumnSpec.h"
#include "boost/optional/optional.hpp"

namespace model {
using namespace std;
using namespace model;
class TableSpec {
private:
	std::string tableName;
	vector<ColumnSpec> columnSpecs;
	string dataFilePath;
public:
	TableSpec(string tname, vector<ColumnSpec> colInfo = vector<ColumnSpec>(), string dataPath = constants::NO_DATA_PATH): 
	tableName(tname), columnSpecs(colInfo), dataFilePath(dataPath) {}

	const vector<ColumnSpec>& getColumnSpecs() const {
		return columnSpecs;
	}

	boost::optional<model::ColumnSpec> getColumnSpec(const std::string & colName) const {
		for(auto cs : columnSpecs) {
			if(cs.getColumnName() == colName) return cs;
		}
		return boost::optional<model::ColumnSpec>{};
    }

	void setDataFilePath(string dPath) {
		dataFilePath = dPath;
	}

	

	string getDataFilePath() const {
		return dataFilePath;
	}

	size_t getColumnCount() const { return columnSpecs.size(); }

	void setColumnSpecs(const vector<ColumnSpec>& columnInfo) {
		this->columnSpecs = columnInfo;
	}

	void print(std::ostream &stream) const {
		stream << "TABLE " << tableName << std::endl;
                stream << "------------------------------"<< std::endl;
                for(auto c : columnSpecs) {
					stream << std::setw(16) << std::left << c.getColumnName();
					stream << std::setw(16) << std::left << c.getColumnTypeString() << std::endl;
				}
                stream << "------------------------------"<< std::endl;
	}
};
}




