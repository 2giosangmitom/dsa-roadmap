#include "solutions_560.hpp"

#include <gtest/gtest.h>

#include <tuple>

class Solutions_560_Test
    : public testing::TestWithParam<tuple<vector<int>, int, int>> {
 protected:
  Solution solutions;
};

TEST_P(Solutions_560_Test, ) {
  auto [nums, k, expected] = GetParam();

  int actual = solutions.subarraySum(nums, k);

  EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(, Solutions_560_Test,
                         testing::Values(make_tuple(vector<int>{1, 1, 1}, 2, 2),
                                         make_tuple(vector<int>{1, 2, 3}, 3, 2),
                                         make_tuple(vector<int>{1}, 1, 1),
                                         make_tuple(vector<int>{1}, 0, 0)));
