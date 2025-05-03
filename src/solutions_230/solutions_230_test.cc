#include "solutions_230.hpp"

#include <gtest/gtest.h>

class Solutions_230_Test : public testing::TestWithParam<
                               std::tuple<std::vector<std::any>, int, int>> {
 protected:
  Solution solutions;
};

TEST_P(Solutions_230_Test, recursive) {
  auto [tree_vals, k, expected] = GetParam();
  auto root = make_tree(tree_vals);

  int actual = solutions.kthSmallest(root, k);
  EXPECT_EQ(actual, expected);

  delete_tree(root);
}

TEST_P(Solutions_230_Test, iterative) {
  auto [tree_vals, k, expected] = GetParam();
  auto root = make_tree(tree_vals);

  int actual = solutions.kthSmallest2(root, k);
  EXPECT_EQ(actual, expected);

  delete_tree(root);
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_230_Test,
    testing::Values(
        std::make_tuple(std::vector<std::any>{42}, 1, 42),
        std::make_tuple(std::vector<std::any>{4, 2, 6, 1, 3, 5, 7}, 4, 4),
        std::make_tuple(std::vector<std::any>{4, 2, 6, 1, 3, 5, 7}, 7, 7),
        std::make_tuple(std::vector<std::any>{5, 4, nullptr, 3, nullptr, 2,
                                              nullptr, 1},
                        2, 2),
        std::make_tuple(std::vector<std::any>{1, nullptr, 2, nullptr, 3,
                                              nullptr, 4},
                        3, 3)));
