// @see
//  https://github.com/korovkin/WNUtils

#pragma once

#include <map>
#include <set>

namespace wn {

/** 
    check if a given key is contained in the given map
 */
template <class K, class V>
bool contains_key(const std::map<K, V>& m, const K& key) {
    return m.find(key) != m.end();
}
    
/** if key contained in map, 
      set value=m[key] and return true
    else:
      set value=defaultValue and return false
 */
template <class K, class V>
bool get_key(const std::map<K, V>& m,
             const K& key,
             V& value,
             const V& defaultValue)
{
    auto iter = m.find(key);
    if (iter == m.end()) {
        value = defaultValue;
        return false;
    }
    
    value = iter->second;
    return true;
}

/**
    check if a given key is contained in the given set
 */
template <class K>
bool contains(const std::set<K>& s, const K& key) {
    return s.find(key) != s.end();
}

};
