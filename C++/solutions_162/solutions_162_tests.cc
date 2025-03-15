#include "solutions_162.hpp"
#include <gtest/gtest.h>
#include <tuple>
#include <unordered_set>
#include <vector>

class Solutions_162_Test
    : public testing::TestWithParam<tuple<vector<int>, unordered_set<int>>> {
protected:
  Solution solution;
};

TEST_P(Solutions_162_Test, ) {
  auto [nums, expected] = GetParam();

  int actual = solution.findPeakElement(nums);

  EXPECT_TRUE(expected.contains(actual));
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_162_Test,
    testing::Values(
        make_tuple(vector<int>{1, 2, 3, 1}, unordered_set<int>{2}),
        make_tuple(vector<int>{1, 2, 1, 3, 5, 6, 4}, unordered_set<int>{5}),
        make_tuple(vector<int>{1, 4, 3, 2, 3}, unordered_set<int>{1, 4})));
