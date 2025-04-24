#include "solutions_15.hpp"

#include <gtest/gtest.h>

class Solutions_15_Test
    : public testing::TestWithParam<tuple<vector<int>, vector<vector<int>>>> {
 protected:
  Solution solution;
};

TEST_P(Solutions_15_Test, ) {
  auto [nums, expected] = GetParam();

  auto actual = solution.threeSum(nums);

  EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_15_Test,
    testing::Values(
        make_tuple(vector<int>{-1, 0, 1, 2, -1, -4},
                   vector<vector<int>>{{-1, -1, 2}, {-1, 0, 1}}),
        make_tuple(vector<int>{}, vector<vector<int>>{}),
        make_tuple(vector<int>{0}, vector<vector<int>>{}),
        make_tuple(vector<int>{0, 0, 0}, vector<vector<int>>{{0, 0, 0}}),
        make_tuple(vector<int>{-1, 0, 1, 0}, vector<vector<int>>{{-1, 0, 1}}),
        make_tuple(vector<int>{-2, 0, 1, 1, 2},
                   vector<vector<int>>{{-2, 0, 2}, {-2, 1, 1}})));
