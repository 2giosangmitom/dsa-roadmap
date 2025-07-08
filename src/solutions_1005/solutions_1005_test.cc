#include "solutions_1005.hpp"

#include <gtest/gtest.h>

#include <tuple>

using std::tuple;

class Solutions_1005_Test
    : public testing::TestWithParam<tuple<vector<int>, int, int>> {
   protected:
    Solution solutions;
};

TEST_P(Solutions_1005_Test, ) {
    auto [nums, k, expected] = GetParam();

    auto actual = solutions.largestSumAfterKNegations(nums, k);

    EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_1005_Test,
    testing::Values(std::make_tuple(vector<int>{4, 2, 3}, 1, 5),
                    std::make_tuple(vector<int>{3, -1, 0, 2}, 3, 6)));
