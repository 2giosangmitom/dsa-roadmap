#include "solutions_148.hpp"
#include <gtest/gtest.h>
#include <tuple>

class Solutions_148_Test
    : public testing::TestWithParam<tuple<vector<int>, vector<int>>> {
protected:
  Solution solutions;
};

TEST_P(Solutions_148_Test, merge_sort) {
  auto [nums, expected] = GetParam();
  auto expected_list = make_list(expected);

  auto actual = solutions.sortList(make_list(nums));

  if (!actual) {
    EXPECT_TRUE(expected_list == nullptr);
  } else {
    EXPECT_EQ(*actual, *expected_list);
  }
  delete_list({actual, expected_list});
}

TEST_P(Solutions_148_Test, insertion_sort) {
  auto [nums, expected] = GetParam();
  auto expected_list = make_list(expected);

  auto actual = solutions.sortList2(make_list(nums));

  if (!actual) {
    EXPECT_TRUE(expected_list == nullptr);
  } else {
    EXPECT_EQ(*actual, *expected_list)
        << "Actual: " << actual->to_string() << endl
        << "Expected: " << expected_list->to_string();
  }
  delete_list({actual, expected_list});
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_148_Test,
    testing::Values(
        make_tuple(vector<int>{4, 2, 1, 3}, vector<int>{1, 2, 3, 4}),
        make_tuple(vector<int>{1, 2, 3, 4, 5}, vector<int>{1, 2, 3, 4, 5}),
        make_tuple(vector<int>{5, 4, 3, 2, 1}, vector<int>{1, 2, 3, 4, 5}),
        make_tuple(vector<int>{-1, 5, 3, 4, 0}, vector<int>{-1, 0, 3, 4, 5})));
