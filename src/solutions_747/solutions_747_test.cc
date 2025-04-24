#include "solutions_747.hpp"

#include <gtest/gtest.h>

#include <tuple>

class Solutions_747_Test
    : public testing::TestWithParam<tuple<vector<int>, int>> {
 protected:
  Solution solution;
};

TEST_P(Solutions_747_Test, ) {
  auto [nums, expected] = GetParam();

  int actual = solution.dominantIndex(nums);

  EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_747_Test,
    testing::Values(make_tuple(vector<int>{3, 6, 1, 0}, 1),
                    make_tuple(vector<int>{1, 2, 3, 4}, -1),
                    make_tuple(vector<int>{1, 1, 2, 9}, 3),
                    make_tuple(vector<int>{1, 24, 9, 2}, 1),
                    make_tuple(vector<int>{1, 0}, 0),
                    make_tuple(vector<int>{9, 3, 2, 1, 0}, 0)));
