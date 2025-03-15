#include "solutions_189.hpp"
#include <gtest/gtest.h>

class Solutions_189_Test
    : public testing::TestWithParam<tuple<vector<int>, int, vector<int>>> {
protected:
  Solution solution;
};

TEST_P(Solutions_189_Test, ) {
  auto [nums, k, expected] = GetParam();

  solution.rotate(nums, k);

  EXPECT_EQ(nums, expected);
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_189_Test,
    testing::Values(make_tuple(vector<int>{1, 2, 3, 4, 5, 6, 7}, 3,
                               vector<int>{5, 6, 7, 1, 2, 3, 4}),
                    make_tuple(vector<int>{-1, -100, 3, 99}, 2,
                               vector<int>{3, 99, -1, -100}),
                    make_tuple(vector<int>{1, 2, 3, 4}, 4,
                               vector<int>{1, 2, 3, 4}),
                    make_tuple(vector<int>{1, 2, 3}, 0, vector<int>{1, 2, 3}),
                    make_tuple(vector<int>{1}, 1, vector<int>{1}),
                    make_tuple(vector<int>{1, 2}, 1, vector<int>{2, 1}),
                    make_tuple(vector<int>{1, 2, 3}, 4, vector<int>{3, 1, 2}),
                    make_tuple(vector<int>{1, 2, 3, 4, 5, 6}, 2,
                               vector<int>{5, 6, 1, 2, 3, 4})));
