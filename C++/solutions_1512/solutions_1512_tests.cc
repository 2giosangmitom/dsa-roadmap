#include <gtest/gtest.h>

#include <tuple>

#include "solutions_1512.hpp"

class Solutions_1512_Test
    : public testing::TestWithParam<tuple<vector<int>, int>> {
 protected:
  Solution solution;
};

TEST_P(Solutions_1512_Test, ) {
  auto [nums, expected] = GetParam();

  int actual = solution.numIdenticalPairs(nums);

  EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_1512_Test,
    testing::Values(make_tuple(vector<int>{1, 2, 3, 1, 1, 3}, 4),
                    make_tuple(vector<int>{1, 1, 1, 1}, 6),
                    make_tuple(vector<int>{1, 2, 3}, 0)));
