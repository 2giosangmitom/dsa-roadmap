#include "../src/solutions_0034.hpp"
#include "gtest/gtest.h"
#include <gtest/gtest.h>
#include <tuple>
#include <vector>

class Solutions0034Test
    : public testing::TestWithParam<tuple<vector<int>, int, vector<int>>> {
protected:
  Solution solution;
};

TEST_P(Solutions0034Test, ) {
  auto [nums, target, expected] = GetParam();

  auto actual = solution.searchRange(nums, target);

  EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions0034Test,
    testing::Values(
        make_tuple(vector<int>{5, 7, 7, 8, 8, 10}, 8, vector<int>{3, 4}),
        make_tuple(vector<int>{5, 7, 7, 8, 8, 10}, 6, vector<int>{-1, -1}),
        make_tuple(vector<int>{}, 0, vector<int>{-1, -1}),
        make_tuple(vector<int>{2, 2}, 3, vector<int>{-1, -1}),
        make_tuple(vector<int>{1, 2, 3, 4}, 5, vector<int>{-1, -1}),
        make_tuple(vector<int>{1, 2, 2, 2, 3, 3, 4, 4, 5, 6}, 2,
                   vector<int>{1, 3})));