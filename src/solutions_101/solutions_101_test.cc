#include "solutions_101.hpp"

#include <gtest/gtest.h>

#include "gtest/gtest.h"

class Solutions_101_Test
    : public testing::TestWithParam<std::tuple<std::vector<std::any>, bool>> {
 protected:
  Solution solutions;
};

TEST_P(Solutions_101_Test, dfs) {
  auto [tree_vals, expected] = GetParam();

  auto root = make_tree(tree_vals);
  bool actual = solutions.isSymmetric(root);

  EXPECT_EQ(actual, expected);

  delete_tree(root);
}

TEST_P(Solutions_101_Test, bfs) {
  auto [tree_vals, expected] = GetParam();

  auto root = make_tree(tree_vals);
  bool actual = solutions.isSymmetric2(root);

  EXPECT_EQ(actual, expected);

  delete_tree(root);
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_101_Test,
    testing::Values(
        std::make_tuple(std::vector<std::any>{1, 2, 2, 3, 4, 4, 3}, true),
        std::make_tuple(std::vector<std::any>{1, 2, 2, nullptr, 3, nullptr, 3},
                        false)));
