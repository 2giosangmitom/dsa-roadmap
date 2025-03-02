#include "../src/search_insert_position.hpp"
#include "gtest/gtest.h"
#include <gtest/gtest.h>
#include <tuple>
#include <vector>

class SearchInsertPositionTest
    : public testing::TestWithParam<tuple<vector<int>, int, int>> {
protected:
  Solution solution;
};

TEST_P(SearchInsertPositionTest, ) {
  auto [nums, target, expected] = GetParam();

  int actual = solution.searchInsert(nums, target);

  EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(
    , SearchInsertPositionTest,
    testing::Values(make_tuple(vector<int>{1, 3, 5, 6}, 5, 2),
                    make_tuple(vector<int>{1, 3, 5, 6}, 2, 1),
                    make_tuple(vector<int>{1, 3, 5, 6}, 7, 4),
                    make_tuple(vector<int>{1, 2, 3, 4}, 5, 4),
                    make_tuple(vector<int>{1, 2, 3}, 0, 0),
                    make_tuple(vector<int>{1, 3}, 2, 1)));
