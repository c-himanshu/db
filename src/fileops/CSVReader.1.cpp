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


bool matchesColumnValue(const std::string &token,
		const ConditionColumn &clause) {
			using namespace util;
	auto operation = clause.getOp();
	auto asked = clause.getColumnValString();
	switch (clause.getColDataType()) {
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
		throw RuntimeException("Unknown datatype for: " + asked);
	}
}

bool matchesAllClauses(const std::vector<std::string> &tokens,
		const std::set<ConditionColumn> &whereClauses) {
	// we are assuming here that all clauses must be met, that is: no OR : TODO - fix for O
	for (auto clause : whereClauses) {
		//see if we are looking at the column required in the clause
		int index = clause.getColumnIndexInTable();
		if (!matchesColumnValue(tokens[index], clause))
			return false;
	}
	return true;
}
bool rowMatchesAllClauses(const std::string &row,
		const std::set<ConditionColumn> &whereClauses) {
	std::vector<std::string> tokens;
	boost::algorithm::split(tokens, row,
			boost::is_any_of(constants::DELIMITER));
	return matchesAllClauses(tokens, whereClauses);
}

const boost::optional<std::vector<double>> getDoublesFromLine(std::string &line,
		const std::set<int> &colIndices,
		const std::set<ConditionColumn> &whereClauses) {
	std::string token;
	std::vector<std::string> tokens;
	boost::algorithm::split(tokens, line,
			boost::is_any_of(constants::DELIMITER));
	//first check clauses
	if (!matchesAllClauses(tokens, whereClauses))
		return boost::optional<std::vector<double>> { };
	std::vector<double> entries;
	for (int ind : colIndices) {
		entries.push_back(std::stod(tokens[ind]));
	}
	return entries;
}

namespace csvops {

boost::optional<std::vector<std::string>> getEntriesForRow(std::string &line,
		const std::vector<ColumnInTable> &colsToFetch,
		const std::set<ConditionColumn> &whereClauses) {
	std::string token;
	std::vector<std::string> tokens;
	boost::algorithm::split(tokens, line,
			boost::is_any_of(constants::DELIMITER));
	//first check clauses
	if (!matchesAllClauses(tokens, whereClauses))
		return boost::optional<std::vector<std::string>> { };
	std::vector<std::string> entries;
	for (auto col : colsToFetch) {
		//auto entry = ;
		entries.push_back(tokens[col.getColumnIndexInTable()]);
	}
	return entries;
}

const size_t CSVReader::getCountFromFile(
		const std::set<ConditionColumn> &whereClauses) const {
	// Open the File
	std::ifstream instream(fpath.c_str());
	// Check if object is valid
	if (!instream) {
		throw RuntimeException(" Cannot open the data file : " + fpath);
	}

	size_t count = 0;
	std::string str;
	// Read the next line from File untill it reaches the end.
	while (std::getline(instream, str)) {
		if (rowMatchesAllClauses(str, whereClauses)) {
			count++;
		}
	}
	instream.close();
	return count;
}

const boost::optional<std::vector<double>> CSVReader::getSumsFromFile(
		const std::set<int> & colIndices,
		const std::set<ConditionColumn> &whereClauses,
		bool computeAverage) const {
	if (colIndices.empty())
		return boost::optional<std::vector<double>> { };
	// Open the File
	std::ifstream instream(fpath.c_str());

	// Check if object is valid
	if (!instream) {
		throw RuntimeException(" Cannot open the data file : " + fpath);
	}

	std::string str; //string to read the line
	std::vector<double> sums(colIndices.size()); //vector to hold the sums
	// Read the next line from File untill it reaches the end.
	while (std::getline(instream, str)) {
		auto valueOpt = getDoublesFromLine(str, colIndices, whereClauses);
		if (valueOpt) {
			auto values = valueOpt.get();
			for (size_t index = 0; index < values.size(); index++) { //add values in correct order
				sums[index] += values[index];
			}
		}
	}
	instream.close();
	if (computeAverage) { //we need to return the averages instead of sums
		size_t denom = sums.size();
		for (size_t index = 0; index < sums.size(); index++) { //add values in correct order
			sums[index] /= denom;
		}
	}
	return sums;
}
const size_t CSVReader::getCountDistinctFromFile(
		const std::set<int> & colIndices,
		const std::set<ConditionColumn> &whereClauses) const {
	// Open the File
	std::ifstream instream(fpath.c_str());

	// Check if object is valid
	if (!instream) {
		throw RuntimeException(" Cannot open the data file : " + fpath);
	}

	size_t count = 0;
	std::string str;
	// Read the next line from File untill it reaches the end.
	while (std::getline(instream, str)) {
		if (rowMatchesAllClauses(str, whereClauses)) {
			count++;
		}
	}
	instream.close();
	return count;
}

std::vector<model::DataRow> CSVReader::readColsFromFile(
		const std::vector<ColumnInTable> &colsToFetch,
		const std::set<ConditionColumn> &whereClauses,
		bool requiresGrouping) const {
	// Open the File
	std::ifstream instream(fpath.c_str());

	// Check if object is valid
	if (!instream) {
		throw RuntimeException(" Cannot open the file : " + fpath);
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
		auto entries = getEntriesForRow(str, colsToFetch, whereClauses);
		if (entries) {
			model::DataRow row(entries.get());
			rows.push_back(row);
		}
	}
	instream.close();
	return rows;
}
}
