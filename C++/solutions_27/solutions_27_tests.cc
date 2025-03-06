#include <gtest/gtest.h>

#include <ranges>
#include <tuple>

#include "solutions_27.hpp"

class Solutions_27_Test
    : public testing::TestWithParam<tuple<vector<int>, int, int, vector<int>>> {
 protected:
  Solution solution;

 public:
};

TEST_P(Solutions_27_Test, ) {
  vector<int> nums;
  int val;
  int expected;
  vector<int> expected_nums;
  tie(nums, val, expected, expected_nums) = GetParam();

  int actual = solution.removeElement(nums, val);

  auto p = nums | std::ranges::views::take(expected);

  EXPECT_EQ(actual, expected);
  EXPECT_TRUE(ranges::equal(p, expected_nums));
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_27_Test,
    testing::Values(
        make_tuple(vector<int>{3, 2, 2, 3}, 3, 2, vector<int>{2, 2}),
        make_tuple(vector<int>{0, 1, 2, 2, 3, 0, 4, 2}, 2, 5,
                   vector<int>{0, 1, 3, 0, 4}),
        make_tuple(vector<int>{1}, 1, 0, vector<int>{}),
        make_tuple(vector<int>{1, 2, 3, 4, 5}, 6, 5,
                   vector<int>{1, 2, 3, 4, 5}),
        make_tuple(vector<int>{4, 5, 4, 4, 4, 6, 7, 4}, 4, 3,
                   vector<int>{5, 6, 7}),
        make_tuple(vector<int>{1, 2, 1, 2, 1, 2}, 1, 3, vector<int>{2, 2, 2}),
        make_tuple(vector<int>{2, 2, 2, 2, 2}, 2, 0, vector<int>{}),
        make_tuple(vector<int>{5, 6, 7, 8, 9}, 10, 5,
                   vector<int>{5, 6, 7, 8, 9})));
