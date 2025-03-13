#include <gtest/gtest.h>

#include <tuple>
#include <vector>

#include "solutions_31.hpp"

class Solutions_31_Test
    : public testing::TestWithParam<tuple<vector<int>, vector<int>>> {
 protected:
  Solution solution;
};

TEST_P(Solutions_31_Test, ) {
  auto [nums, expected] = GetParam();

  solution.nextPermutation(nums);

  EXPECT_EQ(nums, expected);
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_31_Test,
    testing::Values(make_tuple(vector<int>{1, 2, 3}, vector<int>{1, 3, 2}),
                    make_tuple(vector<int>{3, 2, 1}, vector<int>{1, 2, 3}),
                    make_tuple(vector<int>{1, 1, 5}, vector<int>{1, 5, 1})));