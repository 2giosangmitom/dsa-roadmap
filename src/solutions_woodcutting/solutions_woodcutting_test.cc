#include "solutions_woodcutting.hpp"
#include <gtest/gtest.h>
#include <tuple>

class WoodCuttingTest
    : public testing::TestWithParam<tuple<vector<int>, int, int>> {
protected:
  Solution solution;
};

TEST_P(WoodCuttingTest, ) {
  auto [heights, k, expected] = GetParam();
  int actual = solution.solve(heights, k);
  EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(
    , WoodCuttingTest,
    testing::Values(make_tuple(vector<int>{2, 6, 3, 8}, 7, 3),
                    make_tuple(vector<int>{20, 15, 10, 17}, 7, 15),
                    make_tuple(vector<int>{4, 42, 40, 26, 46}, 20, 36),
                    make_tuple(vector<int>{1, 2, 3, 4, 5}, 0, 5),
                    make_tuple(vector<int>{10}, 5, 5)));
