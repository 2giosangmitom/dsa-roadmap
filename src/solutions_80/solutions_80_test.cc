#include "solutions_80.hpp"

#include <gtest/gtest.h>

#include <ranges>
#include <tuple>

class Solutions_80_Test
    : public testing::TestWithParam<tuple<vector<int>, int, vector<int>>> {
   protected:
    Solution solutions;
};

TEST_P(Solutions_80_Test, ) {
    auto [nums, expected, expected_nums] = GetParam();

    int actual = solutions.removeDuplicates(nums);

    ASSERT_EQ(actual, expected);
    EXPECT_TRUE(
        ranges::equal(nums | ranges::views::take(actual), expected_nums));
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_80_Test,
    testing::Values(make_tuple(vector<int>{1, 1, 1, 2, 2, 3}, 5,
                               vector<int>{1, 1, 2, 2, 3}),
                    make_tuple(vector<int>{0, 0, 1, 1, 1, 1, 2, 3, 3}, 7,
                               vector<int>{0, 0, 1, 1, 2, 3, 3})));
