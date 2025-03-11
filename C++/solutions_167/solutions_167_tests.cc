#include <gtest/gtest.h>

#include "solutions_167.hpp"

class Solutions_167_Test
    : public testing::TestWithParam<tuple<vector<int>, int, vector<int>>> {
 protected:
  Solution solution;
};

TEST_P(Solutions_167_Test, TwoSumTest) {
  auto [nums, target, expected] = GetParam();

  auto actual = solution.twoSum(nums, target);

  EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_167_Test,
    testing::Values(
        make_tuple(vector<int>{2, 7, 11, 15}, 9, vector<int>{1, 2}),
        make_tuple(vector<int>{2, 3, 4}, 6, vector<int>{1, 3}),
        make_tuple(vector<int>{-1, 0}, -1, vector<int>{1, 2}),
        make_tuple(vector<int>{1, 2, 3, 4, 4, 9, 56, 90}, 8, vector<int>{4, 5}),
        make_tuple(vector<int>{5, 25, 75}, 100, vector<int>{2, 3})));
