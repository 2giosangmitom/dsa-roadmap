#include "solutions_110.hpp"
#include <gtest/gtest.h>
#include <tuple>

class Solutions_110_Test
    : public testing::TestWithParam<std::tuple<std::vector<std::any>, bool>> {
protected:
  Solution sol;
};

TEST_P(Solutions_110_Test, ) {
  auto [input, expected] = GetParam();
  auto root = make_tree(input);

  bool actual = sol.isBalanced(root);
  EXPECT_EQ(actual, expected);

  delete_tree(root);
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_110_Test,
    testing::Values(
        make_tuple(std::vector<std::any>{3, 9, 20, nullptr, nullptr, 15, 7},
                   true),
        make_tuple(std::vector<std::any>{1, 2, 2, 3, 3, nullptr, nullptr, 4, 4},
                   false),
        make_tuple(std::vector<std::any>{1, 2, 2, 3, nullptr, nullptr, 3, 4,
                                         nullptr, nullptr, 4},
                   false)));
