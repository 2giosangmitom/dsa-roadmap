#include "solutions_200.hpp"

#include <gtest/gtest.h>

class Solutions_200_Test
    : public testing::TestWithParam<tuple<vector<vector<char>>, int>> {
   protected:
    Solution solutions;
};

TEST_P(Solutions_200_Test, ) {
    auto [grid, expected] = GetParam();

    int actual = solutions.numIslands(grid);

    EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_200_Test,
    testing::Values(make_tuple(vector<vector<char>>{{'1', '1', '1', '1', '0'},
                                                    {'1', '1', '0', '1', '0'},
                                                    {'1', '1', '0', '0', '0'},
                                                    {'0', '0', '0', '0', '0'}},
                               1),
                    make_tuple(vector<vector<char>>{{'1', '1', '0', '0', '0'},
                                                    {'1', '1', '0', '0', '0'},
                                                    {'0', '0', '1', '0', '0'},
                                                    {'0', '0', '0', '1', '1'}},
                               3)));
