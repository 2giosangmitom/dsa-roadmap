#include "solutions_52.hpp"

#include <gtest/gtest.h>

class Solutions_57_Test : public testing::TestWithParam<std::tuple<int, int>> {
   protected:
    Solution solutions;
};

TEST_P(Solutions_57_Test, ) {
    auto [n, expected] = GetParam();

    auto actual = solutions.totalNQueens(n);

    EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(, Solutions_57_Test,
                         testing::Values(std::make_tuple(4, 2),
                                         std::make_tuple(1, 1)));
