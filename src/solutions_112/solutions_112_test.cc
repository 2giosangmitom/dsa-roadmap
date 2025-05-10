#include "solutions_112.hpp"

#include <gtest/gtest.h>

class Solutions_112_Test : public testing::TestWithParam<
                               std::tuple<std::vector<std::any>, int, bool>> {
 protected:
  Solution solutions;
};

TEST_P(Solutions_112_Test, ) {
  auto [tree_vals, targetSum, expected] = GetParam();
  auto root = make_tree(tree_vals);

  auto actual = solutions.hasPathSum(root, targetSum);

  EXPECT_EQ(actual, expected);

  delete_tree(root);
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_112_Test,
    testing::Values(std::make_tuple(std::vector<std::any>{5, 4, 8, 11, nullptr,
                                                          13, 4, 7, 2, nullptr,
                                                          nullptr, nullptr, 1},
                                    22, true),
                    std::make_tuple(std::vector<std::any>{1, 2, 3}, 5, false),
                    std::make_tuple(std::vector<std::any>{}, 0, false)));
