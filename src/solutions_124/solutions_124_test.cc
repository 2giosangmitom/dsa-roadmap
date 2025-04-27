#include "solutions_124.hpp"

#include <gtest/gtest.h>

class Solutions_124_Test
    : public testing::TestWithParam<std::tuple<std::vector<std::any>, int>> {
 protected:
  Solution solutions;
};

TEST_P(Solutions_124_Test, ) {
  auto [vals, expected] = GetParam();
  auto root = make_tree(vals);

  int actual = solutions.maxPathSum(root);

  EXPECT_EQ(actual, expected);

  delete_tree(root);
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_124_Test,
    testing::Values(std::make_tuple(std::vector<std::any>{1, 2, 3}, 6),
                    std::make_tuple(std::vector<std::any>{-10, 9, 20, nullptr,
                                                          nullptr, 15, 7},
                                    42),
                    std::make_tuple(std::vector<std::any>{5, -10, 8, 1, -7, 9,
                                                          7, 11, nullptr, -1,
                                                          nullptr, nullptr,
                                                          nullptr, 6, -3},
                                    30),
                    std::make_tuple(std::vector<std::any>{-3}, -3)));
