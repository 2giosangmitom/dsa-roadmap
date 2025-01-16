#include "../src/two_sum.hpp"
#include <gtest/gtest.h>
#include <vector>

class TwoSumTest : public testing::Test {
protected:
  Solution solution;
};

TEST_F(TwoSumTest, BasicTest) {
  vector<int> nums = {2, 7, 11, 15};
  int target = 9;
  vector<int> expected = {0, 1};
  EXPECT_EQ(solution.twoSum(nums, target), expected);
}

TEST_F(TwoSumTest, NegativeNumbers) {
  vector<int> nums = {-3, 4, 3, 90};
  int target = 0;
  vector<int> expected = {0, 2};
  EXPECT_EQ(solution.twoSum(nums, target), expected);
}

TEST_F(TwoSumTest, NoSolution) {
  vector<int> nums = {1, 2, 3};
  int target = 10;
  vector<int> expected = {};
  EXPECT_EQ(solution.twoSum(nums, target), expected);
}

TEST_F(TwoSumTest, Duplicates) {
  vector<int> nums = {3, 3};
  int target = 6;
  vector<int> expected = {0, 1};
  EXPECT_EQ(solution.twoSum(nums, target), expected);
}

TEST_F(TwoSumTest, LargeInput) {
  vector<int> nums(1000, 1);
  nums[999] = 5;
  int target = 6;
  vector<int> expected = {0, 999};
  EXPECT_EQ(solution.twoSum(nums, target), expected);
}
