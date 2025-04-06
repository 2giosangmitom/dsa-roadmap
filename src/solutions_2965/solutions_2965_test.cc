#include "solutions_2965.hpp"
#include <gtest/gtest.h>

class Solutions_2965_Test
    : public testing::TestWithParam<tuple<vector<vector<int>>, vector<int>>> {
protected:
  Solution solution;
};

TEST_P(Solutions_2965_Test, first) {
  auto [grid, expected] = GetParam();

  auto actual = solution.findMissingAndRepeatedValues(grid);

  EXPECT_EQ(actual, expected);
}

TEST_P(Solutions_2965_Test, second) {
  auto [grid, expected] = GetParam();

  auto actual = solution.findMissingAndRepeatedValues2(grid);

  EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_2965_Test,
    testing::Values(
        make_tuple(vector<vector<int>>{{1, 3}, {2, 2}}, vector<int>{2, 4}),
        make_tuple(vector<vector<int>>{{9, 1, 7}, {8, 9, 2}, {3, 4, 6}},
                   vector<int>{9, 5})));
