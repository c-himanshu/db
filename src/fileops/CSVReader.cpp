#include "CSVReader.h"

#include <set>
#include <vector>
#include <fstream>
#include <unordered_map>

#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string.hpp>
#include <boost/tokenizer.hpp>
#include <boost/optional/optional.hpp>

#include "../constants/Constants.h"
#include "exception/RuntimeException.h"
#include "model/DataRow.h"
#include "util/Comparisons.h"
#include "query/FetchSpec.h"

using namespace std;

bool matchesColumnValue(const std::string &token,
		const std::string &asked, const constants::COMPARE_OP &operation, 
		const data_types::DATA_TYPE &colDataType) {
			using namespace util;
	switch (colDataType) {
	case data_types::INT:
		return compare(std::stoi(token), operation, std::stoi(asked));
	case data_types::VARCHAR50:
		//first remove the ' from the start and end of asked string
		return compare(token, operation, (asked.substr(1, asked.size() - 2)));
	case data_types::DBL:
		return compare(std::stod(token), operation, std::stod(asked));
	case data_types::CHAR:
		//just check first chars
		return compare(token[0], operation, asked[0]);
	default:
		throw QueryRuntimeException("Unknown datatype for: " + asked);
	}
}

bool matchesAllClauses(const std::vector<std::string> &tokens,
		  query::FetchSpec &spec) { 
		//const std::vector<size_t> &wherePositions,
		//const std::vector<std::string> &whereMatchVals, 
		//const std::vector<constants::COMPARE_OP> &matchOps) {
	// we are assuming here that all clauses must be met, that is: no OR : TODO - fix for OR
	auto &positions = spec.getWherePositions();

	for (size_t index = 0; index < positions.size(); index++){
		//see if we are looking at the column required in the clause
		size_t colPos = positions[index];
		if (!matchesColumnValue(tokens[colPos], spec.getWhereValues()[index], 
					spec.getCompareOps()[index], spec.getWhereDataTypes()[index]))
			return false;
	}
	return true;
}
boost::optional<std::vector<std::string>> getEntriesForRow(std::string &line,
		 query::FetchSpec &spec) {
	std::string token;
	std::vector<std::string> tokens;
	boost::algorithm::split(tokens, line,
			boost::is_any_of(constants::DELIMITER));
	//first check clauses
	if (!matchesAllClauses(tokens, spec))
		return boost::optional<std::vector<std::string>> { };
	std::vector<std::string> entries;
    //add result cols
	for (auto colPos : spec.getColPositions()) {
		entries.push_back(tokens[colPos]);
	}
//    for (auto gb : spec.getGroupByCols()) {
//        entries.push_back(tokens[gb.getColumnPosition()]);
//    }
//    for (auto gb : spec.get()) {
//        entries.push_back(tokens[gb.getColumnPosition()]);
//    }
	return entries;
}

std::vector<model::DataRow> csvops::CSVReader::getDataFromFile() {
	// Open the File
	std::ifstream instream(fpath.c_str());

	// Check if object is valid
	if (!instream) {
		throw QueryRuntimeException(" Cannot open the file : " + fpath);
	}

	std::vector<model::DataRow> rows;
	std::string str;
	// Read the next line from File until it reaches the end.
	while (std::getline(instream, str)) {
		//remove carriage return
		if (!str.empty() && str[str.size() - 1] == '\r') {
			str.erase(str.size() - 1);
		}
		//collect entries
		auto entries = getEntriesForRow(str,fetchSpec);
		if (entries) {
			model::DataRow row(entries.get());
			rows.push_back(row);
		}
	}
	instream.close();
	return rows;
}
