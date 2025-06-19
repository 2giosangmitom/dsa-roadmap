#include "solutions_746.hpp"

#include <gtest/gtest.h>

#include <vector>

class Solutions_746 : public testing::TestWithParam<tuple<vector<int>, int>> {
   protected:
    Solution solutions;
};

TEST_P(Solutions_746, TopDown) {
    auto [cost, expected] = GetParam();

    auto actual = solutions.minCostClimbingStairs(cost);

    EXPECT_EQ(actual, expected);
}

TEST_P(Solutions_746, BottomUp) {
    auto [cost, expected] = GetParam();

    auto actual = solutions.minCostClimbingStairs2(cost);

    EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_746,
    testing::Values(make_tuple(vector<int>{10, 15, 20}, 15),
                    make_tuple(vector<int>{1, 100, 1, 1, 1, 100, 1, 1, 100, 1},
                               6),
                    make_tuple(vector<int>{10, 15, 30, 45, 2}, 42)));
