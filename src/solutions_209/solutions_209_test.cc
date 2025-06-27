#include "solutions_209.hpp"

#include <gtest/gtest.h>

#include <tuple>

using std::make_tuple;
using std::tuple;

class Solution_209_Tests
    : public testing::TestWithParam<tuple<int, vector<int>, int>> {
   protected:
    Solution solutions;
};

TEST_P(Solution_209_Tests, ) {
    auto [target, nums, expected] = GetParam();

    auto actual = solutions.minSubArrayLen(target, nums);

    EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(
    , Solution_209_Tests,
    testing::Values(make_tuple(7, vector<int>{2, 3, 1, 2, 4, 3}, 2),
                    make_tuple(4, vector<int>{1, 4, 4}, 1),
                    make_tuple(11, vector<int>{1, 1, 1, 1, 1, 1, 1, 1}, 0),
                    make_tuple(11, vector<int>{1, 2, 3, 4, 5}, 3),
                    make_tuple(6, vector<int>{10, 3, 3}, 1)));
