cmake_minimum_required (VERSION 2.6)
project (sql C CXX)

set (CMAKE_CXX_STANDARD 17)
set (ANTLR_CPP_DIR /runtime/Cpp/run/usr/local/include/)

include_directories(src)
include_directories(../libs/runtime/src)
SET(Boost_USE_STATIC_LIBS ON)
find_package(Boost COMPONENTS date_time filesystem system regex log REQUIRED)

#src/query/SelectNode.cpp

if(Boost_FOUND)
  include_directories(${Boost_INCLUDE_DIRS})
  add_executable(sql 
src/grammar/SqlBaseListener.cpp
src/grammar/SqlBaseVisitor.cpp
src/grammar/SqlLexer.cpp
src/grammar/SqlListener.cpp
src/grammar/SqlParser.cpp
src/grammar/SqlVisitor.cpp
src/metadata/CatalogBuilder.cpp
src/metadata/DBCatalog.cpp
src/model/DataRow.cpp
src/model/ColumnSpec.cpp
src/util/Comparisons.cpp
src/parser/QueryParser.cpp
src/query/QueryExecutor.cpp
           src/fileops/CSVReader.cpp
           src/run/RunDB.cpp
            )
  target_link_libraries(sql ${Boost_LIBRARIES} /Users/hchauhan/code/dbexercise/libs/dist/libantlr4-runtime.a)
endif()



