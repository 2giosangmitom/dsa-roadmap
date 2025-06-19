#include "solutions_62.hpp"

#include <gtest/gtest.h>

class Solutions_62_Test : public testing::TestWithParam<tuple<int, int, int>> {
   protected:
    Solution solutions;
};

TEST_P(Solutions_62_Test, ) {
    auto [m, n, expected] = GetParam();

    auto actual = solutions.uniquePaths(m, n);

    EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(, Solutions_62_Test,
                         testing::Values(make_tuple(3, 7, 28),
                                         make_tuple(3, 2, 3)));
