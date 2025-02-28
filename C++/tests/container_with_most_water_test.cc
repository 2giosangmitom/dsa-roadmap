#include "../src/container_with_most_water.hpp"
#include <gtest/gtest.h>
#include <tuple>
#include <vector>

class ContainerWithMostWaterTest
    : public testing::TestWithParam<tuple<vector<int>, int>> {
protected:
  Solution solution;
};

TEST_P(ContainerWithMostWaterTest, MaxArea) {
  vector<int> height;
  int expected;
  tie(height, expected) = GetParam();

  int actual = solution.maxArea(height);

  EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(
    , ContainerWithMostWaterTest,
    testing::Values(make_tuple(vector<int>{1, 8, 6, 2, 5, 4, 8, 3, 7}, 49),
                    make_tuple(vector<int>{1, 1}, 1),
                    make_tuple(vector<int>{4, 3, 2, 1, 4}, 16),
                    make_tuple(vector<int>{1, 2, 1}, 2),
                    make_tuple(vector<int>{2, 3, 4, 5, 18, 17, 6}, 17),
                    make_tuple(vector<int>{1, 8, 100, 2, 100, 4, 8, 3, 7}, 200),
                    make_tuple(vector<int>{1, 2, 4, 3}, 4)));
