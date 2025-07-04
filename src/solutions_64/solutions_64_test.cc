#include "solutions_64.hpp"

#include <gtest/gtest.h>

#include <tuple>

using std::tuple;

class Solutions_64_Tests
    : public testing::TestWithParam<tuple<vector<vector<int>>, int>> {
   protected:
    Solution solutions;
};

TEST_P(Solutions_64_Tests, ) {
    auto [grid, expected] = GetParam();

    auto actual = solutions.minPathSum(grid);

    EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_64_Tests,
    testing::Values(std::make_tuple(
        vector<vector<int>>{{1, 3, 1}, {1, 5, 1}, {4, 2, 1}}, 7)));
