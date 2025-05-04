#include "solutions_108.hpp"

#include <gtest/gtest.h>

#include <vector>

class Solutions_108_Test
    : public testing::TestWithParam<
          std::tuple<std::vector<int>, std::vector<std::any>>> {
 protected:
  Solution solutions;
};

TEST_P(Solutions_108_Test, ) {
  auto [nums, expected_vals] = GetParam();
  auto expected = make_tree(expected_vals);

  auto actual = solutions.sortedArrayToBST(nums);

  if (actual == nullptr) {
    EXPECT_TRUE(expected == nullptr);
  } else {
    EXPECT_EQ(*actual, *expected);
  }

  delete_tree(expected);
  delete_tree(actual);
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_108_Test,
    testing::Values(
        std::make_tuple(std::vector<int>{-10, -3, 0, 5, 9},
                        std::vector<std::any>{0, -10, 5, nullptr, -3, nullptr,
                                              9}),
        std::make_tuple(std::vector<int>{1, 3},
                        std::vector<std::any>{1, nullptr, 3}),
        std::make_tuple(std::vector<int>{1, 2, 3, 4, 5},
                        std::vector<std::any>{3, 1, 4, nullptr, 2, nullptr, 5}),
        std::make_tuple(std::vector<int>{0, 1, 2, 3, 4, 5},
                        std::vector<std::any>{2, 0, 4, nullptr, 1, 3, 5})));
