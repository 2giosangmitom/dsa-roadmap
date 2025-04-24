#include "solutions_704.hpp"

#include <gtest/gtest.h>

class Solutions_704_Test
    : public testing::TestWithParam<tuple<vector<int>, int, int>> {
 protected:
  Solution solution;
};

TEST_P(Solutions_704_Test, ) {
  auto [nums, target, expected] = GetParam();

  int actual = solution.search(nums, target);

  EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_704_Test,
    testing::Values(make_tuple(vector<int>{1, 2, 3, 4, 5}, 5, 4),
                    make_tuple(vector<int>{1, 2, 3, 4, 5}, 9, -1),
                    make_tuple(vector<int>{1, 2, 3, 4, 5}, 1, 0),
                    make_tuple(vector<int>{1, 2, 3, 4, 5}, 3, 2),
                    make_tuple(vector<int>{7, 9, 20, 88, 99, 102, 120, 300},
                               120, 6)));
