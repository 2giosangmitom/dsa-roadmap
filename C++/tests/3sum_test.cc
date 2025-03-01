#include "../src/3sum.hpp"
#include <gtest/gtest.h>

class ThreeSumTest
    : public testing::TestWithParam<tuple<vector<int>, vector<vector<int>>>> {
protected:
  Solution s;
};

TEST_P(ThreeSumTest, ) {
  auto [nums, expected] = GetParam();
  EXPECT_EQ(s.threeSum(nums), expected);
}

INSTANTIATE_TEST_SUITE_P(
    , ThreeSumTest,
    testing::Values(
        make_tuple(vector<int>{-1, 0, 1, 2, -1, -4},
                   vector<vector<int>>{{-1, -1, 2}, {-1, 0, 1}}),
        make_tuple(vector<int>{}, vector<vector<int>>{}),
        make_tuple(vector<int>{0}, vector<vector<int>>{}),
        make_tuple(vector<int>{0, 0, 0}, vector<vector<int>>{{0, 0, 0}}),
        make_tuple(vector<int>{-2, 0, 1, 1, 2},
                   vector<vector<int>>{{-2, 0, 2}, {-2, 1, 1}}),
        make_tuple(vector<int>{-4, -2, -2, -2, 0, 1, 2, 2, 2, 3, 3, 4, 4, 6, 6},
                   vector<vector<int>>{{-4, -2, 6},
                                       {-4, 0, 4},
                                       {-4, 1, 3},
                                       {-4, 2, 2},
                                       {-2, -2, 4},
                                       {-2, 0, 2}}),
        make_tuple(vector<int>{-1, -1, 2, 2, 0, 0, 1, 1},
                   vector<vector<int>>{{-1, -1, 2}, {-1, 0, 1}}),
        make_tuple(vector<int>{-5, 2, 3, 0, 0, -2, -1, 1},
                   vector<vector<int>>{
                       {-5, 2, 3}, {-2, -1, 3}, {-2, 0, 2}, {-1, 0, 1}}),
        make_tuple(
            vector<int>{-3, -2, -1, 0, 1, 2, 3},
            vector<vector<int>>{
                {-3, 0, 3}, {-3, 1, 2}, {-2, -1, 3}, {-2, 0, 2}, {-1, 0, 1}}),
        make_tuple(vector<int>{4, -1, -4, 2, -2, 1}, vector<vector<int>>{}),
        make_tuple(vector<int>{0, 1, 1, -2, -1, 2, -1},
                   vector<vector<int>>{
                       {-2, 0, 2}, {-2, 1, 1}, {-1, -1, 2}, {-1, 0, 1}}),
        make_tuple(vector<int>{3, 3, 3, 3, 3}, vector<vector<int>>{}),
        make_tuple(vector<int>{0, 0, 0, 0}, vector<vector<int>>{{0, 0, 0}}),
        make_tuple(vector<int>{1, -1, -1, 0}, vector<vector<int>>{{-1, 0, 1}}),
        make_tuple(vector<int>{-10, -3, 1, 2, 3, 5, 7},
                   vector<vector<int>>{{-10, 3, 7}, {-3, 1, 2}})));
