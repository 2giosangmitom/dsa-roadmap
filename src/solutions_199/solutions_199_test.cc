#include "solutions_199.hpp"
#include <gtest/gtest.h>

class Solutions_199_Test
    : public testing::TestWithParam<tuple<vector<any>, vector<int>>> {
protected:
  Solution solution;
};

TEST_P(Solutions_199_Test, ) {
  auto [tree_vals, expected] = GetParam();
  auto tree = make_tree(tree_vals);

  auto actual = solution.rightSideView(tree);

  EXPECT_EQ(actual, expected);
  delete tree;
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_199_Test,
    testing::Values(make_tuple(vector<any>{1, 2, 3, nullptr, 5, nullptr, 4},
                               vector<int>{1, 3, 4}),
                    make_tuple(vector<any>{1, 2, 3, 4, nullptr, nullptr,
                                           nullptr, 5},
                               vector<int>{1, 3, 4, 5}),
                    make_tuple(vector<any>{1, nullptr, 3}, vector<int>{1, 3})));
