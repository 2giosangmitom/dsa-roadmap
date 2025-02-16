#include "../src/3sum.hpp"
#include <gtest/gtest.h>

class ThreeSumTest : public testing::Test {
protected:
  Solution s;
};

TEST_F(ThreeSumTest, case1) {
  vector<int> nums = {-1, 0, 1, 2, -1, -4};
  vector<vector<int>> expected = {{-1, -1, 2}, {-1, 0, 1}};
  EXPECT_EQ(s.threeSum(nums), expected);
}

TEST_F(ThreeSumTest, case2) {
  vector<int> nums = {};
  vector<vector<int>> expected = {};
  EXPECT_EQ(s.threeSum(nums), expected);
}

TEST_F(ThreeSumTest, case3) {
  vector<int> nums = {0};
  vector<vector<int>> expected = {};
  EXPECT_EQ(s.threeSum(nums), expected);
}

TEST_F(ThreeSumTest, case4) {
  vector<int> nums = {0, 0, 0};
  vector<vector<int>> expected = {{0, 0, 0}};
  EXPECT_EQ(s.threeSum(nums), expected);
}

TEST_F(ThreeSumTest, case5) {
  vector<int> nums = {-2, 0, 1, 1, 2};
  vector<vector<int>> expected = {{-2, 0, 2}, {-2, 1, 1}};
  EXPECT_EQ(s.threeSum(nums), expected);
}

TEST_F(ThreeSumTest, case6) {
  vector<int> nums = {-4, -2, -2, -2, 0, 1, 2, 2, 2, 3, 3, 4, 4, 6, 6};
  vector<vector<int>> expected = {{-4, -2, 6}, {-4, 0, 4},  {-4, 1, 3},
                                  {-4, 2, 2},  {-2, -2, 4}, {-2, 0, 2}};
  EXPECT_EQ(s.threeSum(nums), expected);
}

TEST_F(ThreeSumTest, case7) {
  vector<int> nums = {-1, -1, 2, 2, 0, 0, 1, 1};
  vector<vector<int>> expected = {{-1, -1, 2}, {-1, 0, 1}};
  EXPECT_EQ(s.threeSum(nums), expected);
}

TEST_F(ThreeSumTest, case8) {
  vector<int> nums = {-5, 2, 3, 0, 0, -2, -1, 1};
  vector<vector<int>> expected = {
      {-5, 2, 3}, {-2, -1, 3}, {-2, 0, 2}, {-1, 0, 1}};
  EXPECT_EQ(s.threeSum(nums), expected);
}

TEST_F(ThreeSumTest, case9) {
  vector<int> nums = {-3, -2, -1, 0, 1, 2, 3};
  vector<vector<int>> expected = {
      {-3, 0, 3}, {-3, 1, 2}, {-2, -1, 3}, {-2, 0, 2}, {-1, 0, 1}};
  EXPECT_EQ(s.threeSum(nums), expected);
}

TEST_F(ThreeSumTest, case10) {
  vector<int> nums = {4, -1, -4, 2, -2, 1};
  vector<vector<int>> expected = {};
  EXPECT_EQ(s.threeSum(nums), expected);
}

TEST_F(ThreeSumTest, case11) {
  vector<int> nums = {0, 1, 1, -2, -1, 2, -1};
  vector<vector<int>> expected = {
      {-2, 0, 2}, {-2, 1, 1}, {-1, -1, 2}, {-1, 0, 1}};
  EXPECT_EQ(s.threeSum(nums), expected);
}

TEST_F(ThreeSumTest, case12) {
  vector<int> nums = {3, 3, 3, 3, 3};
  vector<vector<int>> expected = {};
  EXPECT_EQ(s.threeSum(nums), expected);
}

TEST_F(ThreeSumTest, case13) {
  vector<int> nums = {0, 0, 0, 0};
  vector<vector<int>> expected = {{0, 0, 0}};
  EXPECT_EQ(s.threeSum(nums), expected);
}

TEST_F(ThreeSumTest, case14) {
  vector<int> nums = {1, -1, -1, 0};
  vector<vector<int>> expected = {{-1, 0, 1}};
  EXPECT_EQ(s.threeSum(nums), expected);
}

TEST_F(ThreeSumTest, case15) {
  vector<int> nums = {-10, -3, 1, 2, 3, 5, 7};
  vector<vector<int>> expected = {{-10, 3, 7}, {-3, 1, 2}};
  EXPECT_EQ(s.threeSum(nums), expected);
}
