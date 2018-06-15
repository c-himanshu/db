#pragma once 

#include <string>
#include <set>

namespace constants {
    const int _ALL_COLS = 0xFFF;
    const int MAX_ROWS_TO_PRINT = 100;
    const std::string NO_DISPLAY_NAME("NO_DISPLAY");
    const std::string STAR("*");
    const std::string DELIMITER(",");
    const std::string EQUAL("=");
    const std::string NOT_EQUAL("!=");
    const std::string GREATER_EQUAL(">=");
    const std::string GREATER_THAN(">");
    const std::string LESS_THAN("<");
    const std::string LESS_EQUAL("<=");
    const std::string NO_TBL_ALIAS_GIVEN("NO_TBL_ALIAS_GIVEN");
    const std::string NO_COL_ALIAS_GIVEN("NO_COL_ALIAS_GIVEN");
    const std::string NO_DB_NAME("NO_DB_NAME");
    const std::string NO_TBL_NAME("NO_TBL_NAME");
    const std::string NO_DATA_PATH("_no_path_given");
    const std::string NO_COLNAME("NO_COLNAME"); 
    const std::string NO_OP("_NO_OP"); 
    const std::string NO_VALUE("_NO_VALUE");
    enum COMPARE_OP { GT, GE, LT, LE, EQ, NEQ, COMPARE_OP_NOT_SUPPORTED };
    enum AGGREGATE_FN { NO_FUN, COUNT, COUNT_DISTINCT, AVG, SUM };
}
namespace data_types {
    enum DATA_TYPE { INT, CHAR, VARCHAR50, DBL };
}
