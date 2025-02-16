#pragma once

#include <list>
#include <unordered_map>
#include <utility>
using namespace std;

class LRUCache {
private:
  size_t capacity;
  list<int> lru_list;
  unordered_map<int, pair<int, list<int>::iterator>> cache;

public:
  LRUCache(int capacity);
  int get(int key);
  void put(int key, int value);
};
