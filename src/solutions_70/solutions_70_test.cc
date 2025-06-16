#include "solutions_70.hpp"

#include <gtest/gtest.h>

#include <tuple>

class Solutions_70_Test : public testing::TestWithParam<tuple<int, int>> {
   protected:
    Solution solutions;
};

TEST_P(Solutions_70_Test, TopDown) {
    auto [n, expected] = GetParam();

    auto actual = solutions.climbStairs(n);

    EXPECT_EQ(actual, expected);
}

TEST_P(Solutions_70_Test, BottomUp) {
    auto [n, expected] = GetParam();

    auto actual = solutions.climbStairs2(n);

    EXPECT_EQ(actual, expected);
}

TEST_P(Solutions_70_Test, BottomUpOptimization) {
    auto [n, expected] = GetParam();

    auto actual = solutions.climbStairs3(n);

    EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(, Solutions_70_Test,
                         testing::Values(make_tuple(2, 2), make_tuple(1, 1),
                                         make_tuple(3, 3), make_tuple(5, 8),
                                         make_tuple(30, 1346269),
                                         make_tuple(45, 1836311903)));
