#include "../src/longest_consecutive_sequence.hpp"
#include <gtest/gtest.h>
#include <vector>

class LongestConsecutiveSequenceTest : public testing::Test {
protected:
  Solution s;
};

TEST_F(LongestConsecutiveSequenceTest, case1) {
  vector<int> nums = {100, 4, 200, 1, 3, 2};
  int expected = 4;
  EXPECT_EQ(s.longestConsecutive(nums), expected);
}

TEST_F(LongestConsecutiveSequenceTest, case2) {
  vector<int> nums = {0, 3, 7, 2, 5, 8, 4, 6, 0, 1};
  int expected = 9;
  EXPECT_EQ(s.longestConsecutive(nums), expected);
}

TEST_F(LongestConsecutiveSequenceTest, emptyArray) {
  vector<int> nums = {};
  int expected = 0;
  EXPECT_EQ(s.longestConsecutive(nums), expected);
}

TEST_F(LongestConsecutiveSequenceTest, singleElement) {
  vector<int> nums = {42};
  int expected = 1;
  EXPECT_EQ(s.longestConsecutive(nums), expected);
}

TEST_F(LongestConsecutiveSequenceTest, allSameNumbers) {
  vector<int> nums = {7, 7, 7, 7};
  int expected = 1;
  EXPECT_EQ(s.longestConsecutive(nums), expected);
}

TEST_F(LongestConsecutiveSequenceTest, duplicateNumbers) {
  vector<int> nums = {1, 2, 2, 3, 4, 4, 5};
  int expected = 5;
  EXPECT_EQ(s.longestConsecutive(nums), expected);
}

TEST_F(LongestConsecutiveSequenceTest, negativeAndPositive) {
  vector<int> nums = {-3, -2, -1, 0, 1, 2, 3, 4};
  int expected = 8;
  EXPECT_EQ(s.longestConsecutive(nums), expected);
}

TEST_F(LongestConsecutiveSequenceTest, longSequenceInMiddle) {
  vector<int> nums = {10, 20, 30, 40, 1, 2, 3, 4, 5, 100, 200};
  int expected = 5;
  EXPECT_EQ(s.longestConsecutive(nums), expected);
}

TEST_F(LongestConsecutiveSequenceTest, largeNumbers) {
  vector<int> nums = {INT_MIN, INT_MIN + 1, INT_MAX - 1, INT_MAX};
  int expected = 2;
  EXPECT_EQ(s.longestConsecutive(nums), expected);
}
