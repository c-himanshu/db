#pragma once

#include <memory>
#include <string>
#include <iostream>
#include <cstdio>
#include <unordered_map>

#include "constants/Constants.h"
#include <boost/algorithm/string.hpp>
#include <boost/algorithm/string/split.hpp>

namespace util
{
class StringUtil
{
  public:
    template <typename... Args>
    static std::string string_format(const std::string &format, Args... args)
    {
        size_t size = snprintf(nullptr, 0, format.c_str(), args...) + 1; // Extra space for '\0'
        std::unique_ptr<char[]> buf(new char[size]);
        std::snprintf(buf.get(), size, format.c_str(), args...);
        return std::string(buf.get(), buf.get() + size - 1); // We don't want the '\0' inside
    }

    template <typename T>
    static void print_container(T const &coll, const std::string &header)
    {
        typename T::const_iterator pos;             // iterator to iterate over container
        typename T::const_iterator end(coll.end()); // end position
        std::cout << header << ": ";
        for (pos = coll.begin(); pos != end; ++pos)
        {
            std::cout << *pos << ' ';
        }
        std::cout << std::endl;
    }

    static std::string operationAsString(const constants::COMPARE_OP &op)
    {
        switch (op)
        {
        case constants::EQ:
            return "=";
        case constants::NEQ:
            return "!=";
        case constants::GE:
            return ">=";
        case constants::GT:
            return ">";
        case constants::LE:
            return "<=";
        case constants::LT:
            return "<";
        default:
            return "UNSUPPORTED_OP";
        }
    }

    static bool valueIsZero(std::string qstring)
    {
        boost::trim(qstring);
        boost::erase_all(qstring, " ");
        return qstring == "0";
    }
    static std::pair<std::string, std::string> extractTableColumnNames(std::string qualColName)
{
    std::string emptyTbl("");
    auto dotPos = qualColName.find(".");
    if (dotPos == std::string::npos)
        return make_pair(emptyTbl, qualColName);

    return make_pair(qualColName.substr(0, dotPos), qualColName.substr(dotPos + 1));
}

    static std::pair<std::string, std::string> splitJoinConstraint(std::string cosntraint)
{
    auto equalPos = cosntraint.find("=");
    if(equalPos == std::string::npos)
        return std::make_pair("","");

    return make_pair(cosntraint.substr(0, equalPos), cosntraint.substr(equalPos + 1));
}
//     static std::pair<std::string, std::string> extractTableColumnNames(std::string qualColName)
// {
//     std::string emptyTbl("");
//     auto dotPos = qualColName.find(".");
//     if (dotPos == std::string::npos)
//         return make_pair(emptyTbl, qualColName);

//     return make_pair(qualColName.substr(0, dotPos), qualColName.substr(dotPos + 1));
// }
    static bool valueIsEmptyOrNull(std::string qstring)
    {
        boost::trim(qstring);
        boost::to_lower(qstring);
        boost::erase_all(qstring, " ");
        return qstring.empty() || qstring == "null";
    }

    static constants::COMPARE_OP operationFromString(const std::string &opStr)
    {

        if (opStr == "=")
            return constants::EQ;
        if (opStr == "!=")
            return constants::NEQ;

        if (opStr == ">=")
            return constants::GE;

        if (opStr == ">")
            return constants::GT;

        if (opStr == "<=")
            return constants::LE;

        if (opStr == "<")
            return constants::LT;
        return constants::COMPARE_OP_NOT_SUPPORTED;
        //throw InvalidQueryException("Comparison operation " + opStr + " not currently supported");
    }

    static std::string dataTypeAsString(const data_types::DATA_TYPE &dtype)
    {
        switch (dtype)
        {
        case data_types::INT:
            return "INT";
        case data_types::DBL:
            return "DOUBLE";
        case data_types::VARCHAR50:
            return "VARCHAR50";
        case data_types::CHAR:
            return "CHAR";
        default:
            return "UNSUPPORTED_OP";
        }
    }

    static bool string_contains(const std::string &haystack, const std::string &needle)
    {
        return (haystack.find(needle) != std::string::npos);
    }

    static bool has_suffix(const std::string &str, const std::string &suffix)
    {
        return str.size() >= suffix.size() &&
               str.compare(str.size() - suffix.size(), suffix.size(), suffix) == 0;
    }

    template <typename K, typename V>
    static void print_map(std::unordered_map<K, V> const &m)
    {
        for (auto const &pair : m)
        {
            std::cout << "{" << pair.first << ": " << pair.second << "}\n";
        }
    }

    template <typename K, typename V>
    static void print_map_keys(std::unordered_map<K, V> const &m, std::string const &title = "map")
    {
        std::cout << title << " keys: ";
        for (auto const &pair : m)
        {
            std::cout << pair.first << " ";
        }
        std::cout << std::endl;
    }
};
} // namespace util