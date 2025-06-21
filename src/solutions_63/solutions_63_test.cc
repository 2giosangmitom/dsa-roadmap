#include "solutions_63.hpp"

#include <gtest/gtest.h>

class Solutions_63_Test
    : public testing::TestWithParam<tuple<vector<vector<int>>, int>> {
   protected:
    Solution solutions;
};

TEST_P(Solutions_63_Test, ) {
    auto [grid, expected] = GetParam();

    auto actual = solutions.uniquePathsWithObstacles(grid);

    EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_63_Test,
    testing::Values(
        make_tuple(vector<vector<int>>{{0, 0, 0}, {0, 1, 0}, {0, 0, 0}}, 2),
        make_tuple(vector<vector<int>>{{0, 1}, {0, 0}}, 1),
        make_tuple(vector<vector<int>>{{0, 1}, {1, 1}}, 0),
        make_tuple(vector<vector<int>>{{1, 0}}, 0),
        make_tuple(vector<vector<int>>{{0, 1, 0, 0}}, 0)));
