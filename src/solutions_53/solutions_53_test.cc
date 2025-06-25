#include "solutions_53.hpp"

#include <gtest/gtest.h>

#include <tuple>

using std::make_tuple;
using std::tuple;

class Solutions_53_Tests
    : public testing::TestWithParam<tuple<vector<int>, int>> {
   protected:
    Solution solutions;
};

TEST_P(Solutions_53_Tests, Kadane) {
    auto [nums, expected] = GetParam();

    auto actual = solutions.maxSubArray(nums);

    EXPECT_EQ(actual, expected);
}

TEST_P(Solutions_53_Tests, TraditionalDP) {
    auto [nums, expected] = GetParam();

    auto actual = solutions.maxSubArray(nums);

    EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_53_Tests,
    testing::Values(make_tuple(vector<int>{-2, 1, -3, 4, -1, 2, 1, -5, 4}, 6),
                    make_tuple(vector<int>{1}, 1),
                    make_tuple(vector<int>{5, 4, -1, 7, 8}, 23),
                    make_tuple(vector<int>{-2, 1}, 1)));
