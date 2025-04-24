#include "solutions_239.hpp"

#include <gtest/gtest.h>

class Solutions_239_Test
    : public testing::TestWithParam<tuple<vector<int>, int, vector<int>>> {
 protected:
  Solution solutions;
};

TEST_P(Solutions_239_Test, ) {
  auto [nums, k, expected] = GetParam();

  auto actual = solutions.maxSlidingWindow(nums, k);

  EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_239_Test,
    testing::Values(
        make_tuple(vector<int>{1, 3, -1, -3, 5, 3, 6, 7}, 3,
                   vector<int>{3, 3, 5, 5, 6, 7}),
        make_tuple(vector<int>{1}, 1, vector<int>{1}),
        make_tuple(vector<int>{9, 11}, 2, vector<int>{11}),
        make_tuple(vector<int>{4, -2}, 2, vector<int>{4}),
        make_tuple(vector<int>{1, 3, 1, 2, 0, 5}, 3, vector<int>{3, 3, 2, 5}),
        make_tuple(vector<int>{10, 9, 8, 7, 6, 5, 4, 3, 2, 1}, 4,
                   vector<int>{10, 9, 8, 7, 6, 5, 4}),
        make_tuple(vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, 5,
                   vector<int>{5, 6, 7, 8, 9, 10}),
        make_tuple(vector<int>{100, 200, 300, 400}, 2,
                   vector<int>{200, 300, 400}),
        make_tuple(vector<int>{7, 2, 4}, 2, vector<int>{7, 4}),
        make_tuple(vector<int>{3, 1, -1, -3, 5, 3, 6, 7}, 4,
                   vector<int>{3, 5, 5, 6, 7}),
        make_tuple(vector<int>{1, 3, 1, 2, 0, 5, 2, 8}, 3,
                   vector<int>{3, 3, 2, 5, 5, 8}),
        make_tuple(vector<int>{10, -1, -2, -3, -4, -5}, 2,
                   vector<int>{10, -1, -2, -3, -4}),
        make_tuple(vector<int>{1, 3, 1, 2, 0, 5, 2, 8, 9, 10}, 5,
                   vector<int>{3, 5, 5, 8, 9, 10}),
        make_tuple(vector<int>{4, 2, 12, 3, -1, -3, 5, 3, 6, 7}, 3,
                   vector<int>{12, 12, 12, 3, 5, 5, 6, 7}),
        make_tuple(vector<int>{1, -1, -2, 3, 5, 6, 7, 8, 9, 10}, 4,
                   vector<int>{3, 5, 6, 7, 8, 9, 10}),
        make_tuple(vector<int>{2, 3, 4, 2, 6, 2, 5, 1}, 3,
                   vector<int>{4, 4, 6, 6, 6, 5}),
        make_tuple(vector<int>{1, 1, 1, 1, 1, 1}, 2,
                   vector<int>{1, 1, 1, 1, 1}),
        make_tuple(vector<int>{10, 9, 8, 7, 6, 5, 4, 3, 2, 1}, 2,
                   vector<int>{10, 9, 8, 7, 6, 5, 4, 3, 2}),
        make_tuple(vector<int>{3, 3, 3, 3, 3, 3}, 3, vector<int>{3, 3, 3, 3}),
        make_tuple(vector<int>{-10, -20, -30, -40, -50}, 2,
                   vector<int>{-10, -20, -30, -40})));
