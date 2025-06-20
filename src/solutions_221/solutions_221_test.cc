#include "solutions_221.hpp"

#include <gtest/gtest.h>

class Solutions_221_Test
    : public testing::TestWithParam<tuple<vector<vector<char>>, int>> {
   protected:
    Solution solutions;
};

TEST_P(Solutions_221_Test, ) {
    auto [matrix, expected] = GetParam();

    auto actual = solutions.maximalSquare(matrix);

    EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_221_Test,
    testing::Values(make_tuple(vector<vector<char>>{{'1', '0', '1', '0', '0'},
                                                    {'1', '0', '1', '1', '1'},
                                                    {'1', '1', '1', '1', '1'},
                                                    {'1', '0', '0', '1', '0'}},
                               4),
                    make_tuple(vector<vector<char>>{{'0'}}, 0)));
