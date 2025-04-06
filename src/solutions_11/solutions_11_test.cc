#include "solutions_11.hpp"
#include <gtest/gtest.h>

class Solutions_11_Test
    : public testing::TestWithParam<tuple<vector<int>, int>> {
protected:
  Solution solution;
};

TEST_P(Solutions_11_Test, ) {
  auto [height, expected] = GetParam();

  int actual = solution.maxArea(height);

  EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_11_Test,
    testing::Values(make_tuple(vector<int>{1, 8, 6, 2, 5, 4, 8, 3, 7}, 49),
                    make_tuple(vector<int>{1, 1}, 1),
                    make_tuple(vector<int>{4, 3, 2, 1, 4}, 16),
                    make_tuple(vector<int>{1, 2, 1}, 2),
                    make_tuple(vector<int>{1, 2, 4, 3}, 4)));
