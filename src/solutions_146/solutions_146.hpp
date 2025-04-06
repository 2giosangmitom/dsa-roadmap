#pragma once

#include <list>
#include <unordered_map>
using namespace std;

class LRUCache {
public:
  LRUCache(int capacity) : capacity{capacity} { caches.reserve(capacity); }

  int get(int key) {
    auto it = caches.find(key);
    if (it == caches.end())
      return -1;

    // Move accessed element to the back
    lru_list.splice(lru_list.end(), lru_list, it->second);
    return it->second->second;
  }

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
  int capacity;
  list<pair<int, int>> lru_list;
  unordered_map<int, list<pair<int, int>>::iterator> caches;
};
