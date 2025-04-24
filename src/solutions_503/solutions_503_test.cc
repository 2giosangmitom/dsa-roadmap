#include "solutions_503.hpp"

#include <gtest/gtest.h>

#include <tuple>

class Solutions_503_Test
    : public testing::TestWithParam<tuple<vector<int>, vector<int>>> {
 protected:
  Solution solutions;
};

TEST_P(Solutions_503_Test, ) {
  auto [nums, expected] = GetParam();

  auto actual = solutions.nextGreaterElements(nums);

  EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_503_Test,
    testing::Values(make_tuple(vector<int>{1, 2, 1}, vector<int>{2, -1, 2}),
                    make_tuple(vector<int>{1, 2, 3, 4, 3},
                               vector<int>{2, 3, 4, -1, 4}),
                    make_tuple(vector<int>{1, 2, 1, 0, 3, 10},
                               vector<int>{2, 3, 3, 3, 10, -1}),
                    make_tuple(vector<int>{19, 1, 2, 1, 0, 3, 10},
                               vector<int>{-1, 2, 3, 3, 3, 10, 19})));
