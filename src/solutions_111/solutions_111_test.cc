#include "solutions_111.hpp"

#include <gtest/gtest.h>

#include <tuple>

class Solutions_111_Test
    : public testing::TestWithParam<std::tuple<std::vector<std::any>, int>> {
 protected:
  Solution solutions;
};

TEST_P(Solutions_111_Test, ) {
  auto [tree_vals, expected] = GetParam();
  auto root = make_tree(tree_vals);

  auto actual = solutions.minDepth(root);

  EXPECT_EQ(actual, expected);

  delete_tree(root);
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_111_Test,
    testing::Values(std::make_tuple(std::vector<std::any>{2, nullptr, 3,
                                                          nullptr, 4, nullptr,
                                                          5, nullptr, 6},
                                    5),
                    std::make_tuple(std::vector<std::any>{3, 9, 20, nullptr,
                                                          nullptr, 15, 7},
                                    2)));
