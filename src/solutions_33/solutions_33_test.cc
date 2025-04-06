#include "solutions_33.hpp"
#include <gtest/gtest.h>
#include <tuple>

class Solutions_33_Test
    : public testing::TestWithParam<tuple<vector<int>, int, int>> {
protected:
  Solution solution;
};

TEST_P(Solutions_33_Test, ) {
  auto [nums, target, expected] = GetParam();

  int actual = solution.search(nums, target);

  EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_33_Test,
    testing::Values(make_tuple(vector<int>{4, 5, 6, 7, 0, 1, 2}, 0, 4),
                    make_tuple(vector<int>{4, 5, 6, 7, 0, 1, 2}, 3, -1),
                    make_tuple(vector<int>{1}, 0, -1),
                    make_tuple(vector<int>{8, 9, 1, 2, 3, 4, 5, 6, 7}, 1, 2)));
