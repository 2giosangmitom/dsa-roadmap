#include "../src/two_sum.hpp"
#include <gtest/gtest.h>
using namespace TwoSum;

class TwoSumTest : public testing::Test {
protected:
  Solution s;
};

TEST_F(TwoSumTest, case1) {
  vector<int> nums = {2, 7, 11, 15};
  int target = 9;
  vector<int> expected = {0, 1};

  vector<int> actual = s.twoSum(nums, target);

  EXPECT_EQ(actual, expected);
}
