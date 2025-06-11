#include "solutions_34.hpp"

#include <gtest/gtest.h>

#include <tuple>

class Solutions_34_Test
    : public testing::TestWithParam<tuple<vector<int>, int, vector<int>>> {
   protected:
    Solution solution;
};

TEST_P(Solutions_34_Test, ) {
    auto [nums, target, expected] = GetParam();

    auto actual = solution.searchRange(nums, target);

    EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_34_Test,
    testing::Values(
        make_tuple(vector<int>{5, 7, 7, 8, 8, 10}, 8, vector<int>{3, 4}),
        make_tuple(vector<int>{5, 7, 7, 8, 8, 10}, 6, vector<int>{-1, -1}),
        make_tuple(vector<int>{}, 0, vector<int>{-1, -1})));
