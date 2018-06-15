#include "Comparisons.h"

#include "constants/Constants.h"
#include "exception/RuntimeException.h"


namespace util {
	using namespace std;
bool compareAsInts(const string &left, const string &right)
{
    return std::stoi(left) <= std::stoi(right) ;
}
bool compareAsDoubles(const string &left, const string &right)
{
    return std::stod(left) <= std::stod(right);
}
}