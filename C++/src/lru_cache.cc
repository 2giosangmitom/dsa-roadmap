#include "lru_cache.hpp"

LRUCache::LRUCache(int capacity) : capacity{size_t(capacity)} {}

int LRUCache::get(int key) {
  auto it = cache.find(key);
  if (it == cache.end())
    return -1; // Key not found

  // Move accessed key to front
  lru_list.erase(it->second.second);
  lru_list.push_front(key);
  it->second.second = lru_list.begin();

  return it->second.first;
}

void LRUCache::put(int key, int value) {
  auto it = cache.find(key);

  if (it != cache.end()) {
    // Update existing key's value and move it to front
    lru_list.erase(it->second.second);
    lru_list.push_front(key);
    it->second = {value, lru_list.begin()};
  } else {
    if (cache.size() == capacity) {
      // Remove least recently used element
      int lru_key = lru_list.back();
      lru_list.pop_back();
      cache.erase(lru_key);
    }
    // Insert new key-value pair
    lru_list.push_front(key);
    cache[key] = {value, lru_list.begin()};
  }
}
