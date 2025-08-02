#include "solutions_300.hpp"

#include <gtest/gtest.h>

#include "gtest/gtest.h"

class Solutions_300_Test
    : public testing::TestWithParam<tuple<vector<int>, int>> {
   protected:
    Solution solution;
};

TEST_P(Solutions_300_Test, ) {
    auto [nums, expected] = GetParam();

    auto actual = solution.lengthOfLIS(nums);

    EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_300_Test,
    testing::Values(std::make_tuple(vector<int>{10, 9, 2, 5, 3, 7, 101, 18}, 4),
                    std::make_tuple(vector<int>{0, 1, 0, 3, 2, 3}, 4),
                    std::make_tuple(vector<int>{7, 7, 7, 7, 7, 7, 7}, 1)));
