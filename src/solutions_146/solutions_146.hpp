#pragma once

#include <list>
#include <unordered_map>
using namespace std;

/**
 * @brief A class representing a Least Recently Used (LRU) cache.
 */
class LRUCache {
 public:
  /**
   * @brief Constructor to initialize the LRUCache with a given capacity.
   * @param capacity The maximum number of items the cache can hold.
   */
  LRUCache(int capacity) : capacity{capacity} { caches.reserve(capacity); }

  /**
   * @brief Retrieves the value associated with the given key from the cache.
   * @param key The key to look up in the cache.
   * @return The value associated with the key, or -1 if the key is not found.
   */
  int get(int key) {
    auto it = caches.find(key);
    if (it == caches.end()) return -1;

    // Move accessed element to the back
    lru_list.splice(lru_list.end(), lru_list, it->second);
    return it->second->second;
  }

  /**
   * @brief Inserts a key-value pair into the cache. If the key already exists, updates its value.
   * @param key The key to insert or update in the cache.
   * @param value The value to associate with the key.
   */
  void put(int key, int value) {
    auto it = caches.find(key);

    // Key already exists, update it
    if (it != caches.end()) {
      lru_list.splice(lru_list.end(), lru_list, it->second);
      it->second->second = value;
      return;
    }

    // If cache is full, remove LRU item
    if (lru_list.size() == size_t(capacity)) {
      caches.erase(lru_list.front().first);
      lru_list.pop_front();
    }

    // Insert new value
    lru_list.emplace_back(key, value);
    caches[key] = --lru_list.end();
  }

 private:
  int capacity; ///< The maximum number of items the cache can hold.
  list<pair<int, int>> lru_list; ///< List to maintain the order of LRU items.
  unordered_map<int, list<pair<int, int>>::iterator> caches; ///< Map to store key-value pairs and their positions in the list.
};
