#pragma once

#include <string> 

#include "constants/Constants.h"
#include "exception/RuntimeException.h"

namespace util {
    using namespace std;
bool compareAsInts(const string &left, const string &right);
bool compareAsDoubles(const string &left, const string &right);

template<typename T>
inline bool compare(const T &left, const constants::COMPARE_OP &op, const T &right) {
	using namespace constants;
	switch (op) {
	case EQ:
		return left == right;
	case NEQ:
		return left != right;
	case GT:
		return left > right;
	case GE:
		return left >= right;
	case LT:
		return left < right;
	case LE:
		return left <= right;
	default:
		throw QueryRuntimeException("Operation not supported") ;
	}
} 
}