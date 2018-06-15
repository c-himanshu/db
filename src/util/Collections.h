#pragma once

#include <algorithm>
#include <unordered_map>
#include <set>
#include <vector>

namespace util
{
class Collections
{
  public:
    template<typename K, typename V>
    static bool map_has_key(std::unordered_map<K,V> const &m, K const &k) {
        return (m.find(k) != m.end());
    }

    template<typename V>
    static bool containerHasValue(std::set<V> const &C, V const &v) {
        return (C.find(v) != C.end());
    }

    template<typename V>
    static bool containerHasValue(std::vector<V> const &C, V const &v) {
        return (std::find(C.begin(), C.end(), v) != C.end());
    }
};
}
