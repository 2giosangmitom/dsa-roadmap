#include "solutions_295.hpp"
#include <gtest/gtest.h>

TEST(Solutions_295_Test, case1) {
  MedianFinder s;

  s.addNum(1);
  s.addNum(2);

  EXPECT_EQ(s.findMedian(), 1.5);

  s.addNum(3);

  EXPECT_EQ(s.findMedian(), 2);
}

TEST(Solutions_295_Test, case2) {
  MedianFinder s;

  s.addNum(-1);
  EXPECT_EQ(s.findMedian(), -1);

  s.addNum(-2);
  EXPECT_EQ(s.findMedian(), -1.5);

  s.addNum(-3);
  EXPECT_EQ(s.findMedian(), -2);
}

TEST(Solutions_295_Test, singleElement) {
  MedianFinder s;
  s.addNum(42);
  EXPECT_EQ(s.findMedian(), 42);
}

TEST(Solutions_295_Test, evenNumberOfElements) {
  MedianFinder s;
  s.addNum(10);
  s.addNum(20);
  s.addNum(30);
  s.addNum(40);
  EXPECT_EQ(s.findMedian(), 25);
}

TEST(Solutions_295_Test, withDuplicates) {
  MedianFinder s;
  s.addNum(5);
  s.addNum(15);
  s.addNum(5);
  s.addNum(5);
  EXPECT_EQ(s.findMedian(), 5);
}

TEST(Solutions_295_Test, highLowAlternating) {
  MedianFinder s;
  s.addNum(1000);
  EXPECT_EQ(s.findMedian(), 1000);

  s.addNum(1);
  EXPECT_EQ(s.findMedian(), 500.5);

  s.addNum(999);
  EXPECT_EQ(s.findMedian(), 999);

  s.addNum(2);
  EXPECT_EQ(s.findMedian(), 500.5);
}
