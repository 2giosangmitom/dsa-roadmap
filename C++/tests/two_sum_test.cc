#include "../src/two_sum.hpp"
#include <gtest/gtest.h>

class TwoSumTest : public testing::Test {
protected:
  Solution s;
};

TEST_F(TwoSumTest, case1) {
  std::vector<int> nums = {2, 7, 11, 15};
  int target = 9;
  std::vector<int> expected = {0, 1};
  EXPECT_EQ(s.twoSum(nums, target), expected);
}

TEST_F(TwoSumTest, case2) {
  std::vector<int> nums = {3, 2, 4};
  int target = 6;
  std::vector<int> expected = {1, 2};
  EXPECT_EQ(s.twoSum(nums, target), expected);
}

TEST_F(TwoSumTest, case3) {
  std::vector<int> nums = {5, 10, 15};
  int target = 20;
  std::vector<int> expected = {0, 2};
  EXPECT_EQ(s.twoSum(nums, target), expected);
}

TEST_F(TwoSumTest, case4) {
  std::vector<int> nums = {1, 5, -3, -2};
  int target = -5;
  std::vector<int> expected = {2, 3};
  EXPECT_EQ(s.twoSum(nums, target), expected);
}

TEST_F(TwoSumTest, case5) {
  std::vector<int> nums = {0, 8, 5, -8};
  int target = -8;
  std::vector<int> expected = {0, 3};
  EXPECT_EQ(s.twoSum(nums, target), expected);
}

TEST_F(TwoSumTest, case6) {
  std::vector<int> nums = {9, 14, 2, 8, -5};
  int target = 9;
  std::vector<int> expected = {1, 4};
  EXPECT_EQ(s.twoSum(nums, target), expected);
}

TEST_F(TwoSumTest, case7) {
  std::vector<int> nums = {1, 2, 3, 4000, 5000};
  int target = 9000;
  std::vector<int> expected = {3, 4};
  EXPECT_EQ(s.twoSum(nums, target), expected);
}

TEST_F(TwoSumTest, case8) {
  std::vector<int> nums = {-10, 7, 8, 2, 12};
  int target = 20;
  std::vector<int> expected = {2, 4};
  EXPECT_EQ(s.twoSum(nums, target), expected);
}

TEST_F(TwoSumTest, case9) {
  std::vector<int> nums = {-6, 1, -7, 3, 8};
  int target = -13;
  std::vector<int> expected = {0, 2};
  EXPECT_EQ(s.twoSum(nums, target), expected);
}

TEST_F(TwoSumTest, case10) {
  std::vector<int> nums = {1, 2};
  int target = 3;
  std::vector<int> expected = {0, 1};
  EXPECT_EQ(s.twoSum(nums, target), expected);
}

TEST_F(TwoSumTest, case11) {
  std::vector<int> nums = {-3, 3};
  int target = 0;
  std::vector<int> expected = {0, 1};
  EXPECT_EQ(s.twoSum(nums, target), expected);
}
