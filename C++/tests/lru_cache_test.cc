#include "../src/lru_cache.hpp"
#include <gtest/gtest.h>

TEST(LRUCacheTest, BasicOperations) {
  LRUCache lru(2);

  lru.put(1, 10);
  lru.put(2, 20);

  EXPECT_EQ(lru.get(1), 10);
  EXPECT_EQ(lru.get(2), 20);
  EXPECT_EQ(lru.get(3), -1);

  lru.put(3, 30);
  EXPECT_EQ(lru.get(1), -1);
  EXPECT_EQ(lru.get(3), 30);
  EXPECT_EQ(lru.get(2), 20);
}

TEST(LRUCacheTest, UpdateValue) {
  LRUCache lru(2);

  lru.put(1, 100);
  lru.put(2, 200);

  lru.put(1, 150);

  EXPECT_EQ(lru.get(1), 150);
  EXPECT_EQ(lru.get(2), 200);
}

TEST(LRUCacheTest, EvictionOrder) {
  LRUCache lru(2);

  lru.put(1, 10);
  lru.put(2, 20);
  lru.get(1);
  lru.put(3, 30);

  EXPECT_EQ(lru.get(1), 10);
  EXPECT_EQ(lru.get(2), -1);
  EXPECT_EQ(lru.get(3), 30);
}

TEST(LRUCacheTest, SingleElementCache) {
  LRUCache lru(1);

  lru.put(1, 10);
  EXPECT_EQ(lru.get(1), 10);

  lru.put(2, 20);
  EXPECT_EQ(lru.get(1), -1);
  EXPECT_EQ(lru.get(2), 20);
}

TEST(LRUCacheTest, ChangeEvictionOrder) {
  LRUCache lru(3);

  lru.put(1, 10);
  lru.put(2, 20);
  lru.put(3, 30);

  lru.get(1);
  lru.put(4, 40);

  EXPECT_EQ(lru.get(2), -1);
  EXPECT_EQ(lru.get(1), 10);
  EXPECT_EQ(lru.get(3), 30);
  EXPECT_EQ(lru.get(4), 40);
}
