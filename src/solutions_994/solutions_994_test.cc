#include "solutions_994.hpp"

#include <gtest/gtest.h>

class Solutions_994_Test
    : public testing::TestWithParam<tuple<vector<vector<int>>, int>> {
   protected:
    Solution sol;
};

TEST_P(Solutions_994_Test, ) {
    auto [grid, expected] = GetParam();

    int actual = sol.orangesRotting(grid);

    EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_994_Test,
    testing::Values(
        make_tuple(vector<vector<int>>{{2, 1, 1}, {1, 1, 0}, {0, 1, 1}}, 4),
        make_tuple(vector<vector<int>>{{2, 1, 1}, {0, 1, 1}, {1, 0, 1}}, -1),
        make_tuple(vector<vector<int>>{{0, 2}}, 0)));
