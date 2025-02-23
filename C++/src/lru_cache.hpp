#pragma once

#include <list>
#include <unordered_map>
#include <utility>
using namespace std;

class LRUCache {
private:
  int capacity;
  list<pair<int, int>> lru_list; // Used to store values of the cache
  unordered_map<int, list<pair<int, int>>::iterator> cache;

public:
  LRUCache(int size);
  int get(int key);
  void put(int key, int value);
};
