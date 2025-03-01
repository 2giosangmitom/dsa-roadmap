#include "../src/move_zeroes.hpp"
#include "gtest/gtest.h"
#include <gtest/gtest.h>
#include <tuple>

class MoveZeroesTest
    : public testing::TestWithParam<tuple<vector<int>, vector<int>>> {
protected:
  Solution solution;
};

TEST_P(MoveZeroesTest, ) {
  auto [nums, expected] = GetParam();

  solution.moveZeroes(nums);

  EXPECT_EQ(nums, expected);
}

INSTANTIATE_TEST_SUITE_P(
    , MoveZeroesTest,
    testing::Values(
        make_tuple(vector<int>{0, 1, 0, 3, 12}, vector<int>{1, 3, 12, 0, 0}),
        make_tuple(vector<int>{1, 1, 0, 2, 0}, vector<int>{1, 1, 2, 0, 0}),
        make_tuple(vector<int>{0}, vector<int>{0}),
        make_tuple(vector<int>{0, 0, 1}, vector<int>{1, 0, 0}),
        make_tuple(vector<int>{1, 0, 1}, vector<int>{1, 1, 0}),
        make_tuple(vector<int>{0, 0, 0, 0, 0}, vector<int>{0, 0, 0, 0, 0}),
        make_tuple(vector<int>{1, 2, 3, 4, 5}, vector<int>{1, 2, 3, 4, 5}),
        make_tuple(vector<int>{0, 0, 1, 2, 3}, vector<int>{1, 2, 3, 0, 0}),
        make_tuple(vector<int>{4, 2, 4, 0, 0, 3, 0, 5, 1, 0},
                   vector<int>{4, 2, 4, 3, 5, 1, 0, 0, 0, 0})));