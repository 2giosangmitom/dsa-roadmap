#include "lru_cache.hpp"

LRUCache::LRUCache(int size) : capacity{size} {}

int LRUCache::get(int key) {
  auto it = cache.find(key);
  if (it == cache.end()) {
    return -1;
  }

  auto val = *(it->second);
  lru_list.erase(it->second);
  lru_list.push_back(val);
  it->second = --lru_list.end();

  return val.second;
}

void LRUCache::put(int key, int value) {
  auto it = cache.find(key);
  if (it != cache.end()) {
    // Update existing cache
    lru_list.erase(it->second);
    lru_list.push_back({key, value});
    cache[key] = --lru_list.end();
  } else {
    lru_list.push_back({key, value});
    cache[key] = --lru_list.end();

    // If adding the cache caused overflow of the capacity,
    // remove the least recently used cache
    if (cache.size() > static_cast<size_t>(capacity)) {
      auto need_del = lru_list.begin()->first;
      cache.erase(need_del);
      lru_list.pop_front();
    }
  }
}
