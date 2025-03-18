#include "solutions_146.hpp"
#include <gtest/gtest.h>

TEST(LRUCacheTest, case1) {
  LRUCache lru_cache(2);

  lru_cache.put(1, 1);
  lru_cache.put(2, 2);

  EXPECT_EQ(lru_cache.get(1), 1);
  lru_cache.put(3, 3);
  EXPECT_EQ(lru_cache.get(2), -1);
}

TEST(LRUCacheTest, case2) {
  LRUCache lru_cache(2);

  lru_cache.put(1, 1);
  lru_cache.put(2, 2);
  lru_cache.put(1, 10);

  EXPECT_EQ(lru_cache.get(1), 10);
  EXPECT_EQ(lru_cache.get(2), 2);
}

TEST(LRUCacheTest, case3) {
  LRUCache lru_cache(2);

  lru_cache.put(1, 1);
  lru_cache.put(2, 2);
  lru_cache.get(1);
  lru_cache.put(3, 3);

  EXPECT_EQ(lru_cache.get(1), 1);
  EXPECT_EQ(lru_cache.get(2), -1);
}

TEST(LRUCacheTest, case4) {
  LRUCache lru_cache(1);

  lru_cache.put(1, 1);
  lru_cache.put(2, 2);

  EXPECT_EQ(lru_cache.get(1), -1);
  EXPECT_EQ(lru_cache.get(2), 2);
}

TEST(LRUCacheTest, case5) {
  LRUCache lru_cache(2);

  EXPECT_EQ(lru_cache.get(1), -1);
}
