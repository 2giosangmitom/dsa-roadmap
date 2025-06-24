#include "solutions_494.hpp"

#include <gtest/gtest.h>

#include <tuple>

using std::make_tuple;
using std::tuple;

class Solutions_494_Test
    : public testing::TestWithParam<tuple<vector<int>, int, int>> {
   protected:
    Solution solutions;
};

TEST_P(Solutions_494_Test, ) {
    auto [nums, target, expected] = GetParam();

    auto actual = solutions.findTargetSumWays(nums, target);

    EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_494_Test,
    testing::Values(make_tuple(vector<int>{1, 1, 1, 1, 1}, 3, 5),
                    make_tuple(vector<int>{1}, 1, 1),
                    make_tuple(vector<int>{5, 3, 2}, 99, 0)));
