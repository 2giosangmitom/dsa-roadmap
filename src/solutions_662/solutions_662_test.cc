#include "solutions_662.hpp"

#include <gtest/gtest.h>

#include <tuple>
#include <vector>

class Solutions_662_Test
    : public testing::TestWithParam<tuple<vector<any>, int>> {
 protected:
  Solution solutions;
};

TEST_P(Solutions_662_Test, ) {
  auto [tree_vals, expected] = GetParam();
  auto tree = make_tree(tree_vals);

  int actual = solutions.widthOfBinaryTree(tree);

  EXPECT_EQ(actual, expected);

  delete_tree(tree);
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_662_Test,
    testing::Values(make_tuple(vector<any>{1, 3, 2, 5, 3, nullptr, 9}, 4),
                    make_tuple(vector<any>{1, 3, 2, 5, nullptr, nullptr, 9, 6,
                                           nullptr, 7},
                               7),
                    make_tuple(vector<any>{1, 3, 2, 5}, 2)));
