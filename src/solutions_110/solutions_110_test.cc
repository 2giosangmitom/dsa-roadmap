#include "solutions_110.hpp"
#include <gtest/gtest.h>
#include <memory>
#include <tuple>

class Solutions_110_Test
    : public testing::TestWithParam<tuple<vector<any>, bool>> {
protected:
  Solution sol;
};

TEST_P(Solutions_110_Test, ) {
  auto [input, expected] = GetParam();
  auto root = unique_ptr<TreeNode>(make_tree(input));

  bool actual = sol.isBalanced(root.get());
  EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_110_Test,
    testing::Values(
        make_tuple(vector<any>{3, 9, 20, nullptr, nullptr, 15, 7}, true),
        make_tuple(vector<any>{1, 2, 2, 3, 3, nullptr, nullptr, 4, 4}, false),
        make_tuple(vector<any>{1, 2, 2, 3, nullptr, nullptr, 3, 4, nullptr,
                               nullptr, 4},
                   false)));
