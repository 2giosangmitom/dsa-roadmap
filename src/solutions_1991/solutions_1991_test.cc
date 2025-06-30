#include "solutions_1991.hpp"

#include <gtest/gtest.h>

#include <tuple>

using std::tuple;

class Solutions_1991_Test
    : public testing::TestWithParam<tuple<vector<int>, int>> {
   protected:
    Solution solutions;
};

TEST_P(Solutions_1991_Test, ) {
    auto [nums, expected] = GetParam();

    auto actual = solutions.findMiddleIndex(nums);

    EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_1991_Test,
    testing::Values(std::make_tuple(vector<int>{2, 3, -1, 8, 4}, 3),
                    std::make_tuple(vector<int>{1, -1, 4}, 2),
                    std::make_tuple(vector<int>{2, 5}, -1)));
