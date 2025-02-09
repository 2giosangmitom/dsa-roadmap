#include "../src/3sum.hpp"
#include <gtest/gtest.h>
using namespace ThreeSum;

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
