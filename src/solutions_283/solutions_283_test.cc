#include "solutions_283.hpp"

#include <gtest/gtest.h>

#include <tuple>

class Solutions_283_Test
    : public testing::TestWithParam<std::tuple<vector<int>, vector<int>>> {
   protected:
    Solution solutions;
};

TEST_P(Solutions_283_Test, ) {
    auto [nums, expected] = GetParam();

    solutions.moveZeroes(nums);

    EXPECT_EQ(nums, expected);
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_283_Test,
    testing::Values(std::make_tuple(vector<int>{0, 1, 0, 3, 12},
                                    vector<int>{1, 3, 12, 0, 0})));
