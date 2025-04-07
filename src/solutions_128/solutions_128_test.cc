#include "solutions_128.hpp"
#include <gtest/gtest.h>

class Solutions_128 : public testing::TestWithParam<tuple<vector<int>, int>> {
protected:
  Solution solutions;
};

TEST_P(Solutions_128, ) {
  auto [input, expected] = GetParam();

  int actual = solutions.longestConsecutive(input);

  EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_128,
    testing::Values(make_tuple(vector<int>{}, 0),
                    make_tuple(vector<int>{100}, 1),
                    make_tuple(vector<int>{10, 30, 50}, 1),
                    make_tuple(vector<int>{100, 4, 200, 1, 3, 2}, 4),
                    make_tuple(vector<int>{1, 2, 2, 3}, 3),
                    make_tuple(vector<int>{1, 9, 3, 10, 4, 20, 2}, 4),
                    make_tuple(vector<int>{-2, -3, -1, -4, 2, 3}, 4)));
