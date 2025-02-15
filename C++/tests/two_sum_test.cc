#include "../src/two_sum.hpp"
#include <gtest/gtest.h>

class TwoSumTest : public testing::Test {
protected:
  Solution s;
};

TEST_F(TwoSumTest, case1) {
  vector<int> nums = {2, 7, 11, 15};
  int target = 9;
  vector<int> expected = {0, 1};
  EXPECT_EQ(s.twoSum(nums, target), expected);
}

TEST_F(TwoSumTest, case2) {
  vector<int> nums = {3, 2, 4};
  int target = 6;
  vector<int> expected = {1, 2};
  EXPECT_EQ(s.twoSum(nums, target), expected);
}

TEST_F(TwoSumTest, case3) {
  vector<int> nums = {5, 10, 15};
  int target = 20;
  vector<int> expected = {0, 2};
  EXPECT_EQ(s.twoSum(nums, target), expected);
}

TEST_F(TwoSumTest, case4) {
  vector<int> nums = {1, 5, -3, -2};
  int target = -5;
  vector<int> expected = {2, 3};
  EXPECT_EQ(s.twoSum(nums, target), expected);
}

TEST_F(TwoSumTest, case5) {
  vector<int> nums = {0, 8, 5, -8};
  int target = -8;
  vector<int> expected = {0, 3};
  EXPECT_EQ(s.twoSum(nums, target), expected);
}

TEST_F(TwoSumTest, case6) {
  vector<int> nums = {9, 14, 2, 8, -5};
  int target = 9;
  vector<int> expected = {1, 4};
  EXPECT_EQ(s.twoSum(nums, target), expected);
}

TEST_F(TwoSumTest, case7) {
  vector<int> nums = {1, 2, 3, 4000, 5000};
  int target = 9000;
  vector<int> expected = {3, 4};
  EXPECT_EQ(s.twoSum(nums, target), expected);
}

TEST_F(TwoSumTest, case8) {
  vector<int> nums = {-10, 7, 8, 2, 12};
  int target = 20;
  vector<int> expected = {2, 4};
  EXPECT_EQ(s.twoSum(nums, target), expected);
}

TEST_F(TwoSumTest, case9) {
  vector<int> nums = {-6, 1, -7, 3, 8};
  int target = -13;
  vector<int> expected = {0, 2};
  EXPECT_EQ(s.twoSum(nums, target), expected);
}

TEST_F(TwoSumTest, case10) {
  vector<int> nums = {1, 2};
  int target = 3;
  vector<int> expected = {0, 1};
  EXPECT_EQ(s.twoSum(nums, target), expected);
}

TEST_F(TwoSumTest, case11) {
  vector<int> nums = {-3, 3};
  int target = 0;
  vector<int> expected = {0, 1};
  EXPECT_EQ(s.twoSum(nums, target), expected);
}
