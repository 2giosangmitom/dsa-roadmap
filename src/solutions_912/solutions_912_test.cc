#include "solutions_912.hpp"
#include <gtest/gtest.h>
#include <tuple>

class Solutions_912_Test
    : public testing::TestWithParam<tuple<vector<int>, vector<int>>> {
protected:
  Solution solutions;
};

TEST_P(Solutions_912_Test, heap_sort) {
  auto [nums, expected] = GetParam();

  auto actual = solutions.sortArray(nums);

  EXPECT_EQ(actual, expected);
}

TEST_P(Solutions_912_Test, quick_sort) {
  auto [nums, expected] = GetParam();

  auto actual = solutions.sortArray2(nums);

  EXPECT_EQ(actual, expected);
}

TEST_P(Solutions_912_Test, quick_sort2) {
  auto [nums, expected] = GetParam();

  auto actual = solutions.sortArray3(nums);

  EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_912_Test,
    testing::Values(
        make_tuple(vector<int>{4, 2, 1, 3}, vector<int>{1, 2, 3, 4}),
        make_tuple(vector<int>{1, 2, 3, 4, 5}, vector<int>{1, 2, 3, 4, 5}),
        make_tuple(vector<int>{5, 4, 3, 2, 1}, vector<int>{1, 2, 3, 4, 5}),
        make_tuple(vector<int>{-1, 5, 3, 4, 0}, vector<int>{-1, 0, 3, 4, 5})));
