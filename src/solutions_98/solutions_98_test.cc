#include "solutions_98.hpp"

#include <gtest/gtest.h>

#include <any>
#include <tuple>
#include <vector>

class Solutions_98_Test
    : public testing::TestWithParam<tuple<vector<any>, bool>> {
 protected:
  Solution solutions;
};

TEST_P(Solutions_98_Test, ) {
  auto [vals, expected] = GetParam();
  auto root = make_tree(vals);

  auto actual = solutions.isValidBST(root);
  EXPECT_EQ(actual, expected);

  delete_tree(root);
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_98_Test,
    testing::Values(make_tuple(vector<any>{2, 1, 3}, true),
                    make_tuple(vector<any>{5, 1, 4, nullptr, nullptr, 3, 6},
                               false),
                    make_tuple(vector<any>{2147483647}, true)));
