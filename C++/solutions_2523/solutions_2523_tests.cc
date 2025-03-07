#include <gtest/gtest.h>

#include "solutions_2523.hpp"

class Solutions_2523_Test
    : public testing::TestWithParam<tuple<int, int, vector<int>>> {
 protected:
  Solution solution;
};

TEST_P(Solutions_2523_Test, ) {
  auto [left, right, expected] = GetParam();

  auto actual = solution.closestPrimes(left, right);

  EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_2523_Test,
    testing::Values(make_tuple(10, 19, vector<int>{11, 13}),
                    make_tuple(4, 6, vector<int>{-1, -1}),
                    make_tuple(25, 35, vector<int>{29, 31}),
                    make_tuple(100, 110, vector<int>{101, 103}),
                    make_tuple(1, 100000, vector<int>{2, 3}),
                    make_tuple(1, 1, vector<int>{-1, -1})));
