#include "solutions_232.hpp"

#include <gtest/gtest.h>

TEST(MyQueueTest, BasicOperations) {
  MyQueue q;
  EXPECT_TRUE(q.empty());

  q.push(1);
  EXPECT_FALSE(q.empty());
  EXPECT_EQ(q.peek(), 1);

  q.push(2);
  EXPECT_EQ(q.peek(), 1);

  EXPECT_EQ(q.pop(), 1);
  EXPECT_EQ(q.peek(), 2);

  EXPECT_EQ(q.pop(), 2);
  EXPECT_TRUE(q.empty());
}

TEST(MyQueueTest, InterleavedPushPop) {
  MyQueue q;

  q.push(10);
  EXPECT_EQ(q.peek(), 10);

  q.push(20);
  q.push(30);
  EXPECT_EQ(q.pop(), 10);

  q.push(40);
  EXPECT_EQ(q.pop(), 20);
  EXPECT_EQ(q.peek(), 30);
  EXPECT_FALSE(q.empty());

  EXPECT_EQ(q.pop(), 30);
  EXPECT_EQ(q.pop(), 40);
  EXPECT_TRUE(q.empty());
}

TEST(MyQueueTest, SingleElement) {
  MyQueue q;
  q.push(99);
  EXPECT_EQ(q.peek(), 99);
  EXPECT_EQ(q.pop(), 99);
  EXPECT_TRUE(q.empty());
}
