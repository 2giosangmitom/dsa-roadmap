#include "solutions_26.hpp"
#include <gtest/gtest.h>
#include <ranges>

class Solutions_26_Test
    : public testing::TestWithParam<tuple<vector<int>, int, vector<int>>> {
protected:
  Solution solution;
};

TEST_P(Solutions_26_Test, ) {
  auto [nums, expected, expected_nums] = GetParam();

  int actual = solution.removeDuplicates(nums);
  auto p = nums | ranges::views::take(actual);

  EXPECT_EQ(actual, expected);
  EXPECT_TRUE(ranges::equal(p, expected_nums));
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_26_Test,
    testing::Values(
        make_tuple(vector<int>{1, 1, 2}, 2, vector<int>{1, 2}),
        make_tuple(vector<int>{0, 0, 1, 1, 1, 2, 2, 3, 3, 4}, 5,
                   vector<int>{0, 1, 2, 3, 4}),
        make_tuple(vector<int>{1, 1, 1, 1}, 1, vector<int>{1}),
        make_tuple(vector<int>{1, 2, 3, 4, 5}, 5, vector<int>{1, 2, 3, 4, 5}),
        make_tuple(vector<int>{1, 1, 1, 2, 2, 3}, 3, vector<int>{1, 2, 3}),
        make_tuple(vector<int>{1, 2, 2, 3, 3, 3, 4, 4, 5}, 5,
                   vector<int>{1, 2, 3, 4, 5})));
