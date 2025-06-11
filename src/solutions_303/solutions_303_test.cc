#include "solutions_303.hpp"

#include <gtest/gtest.h>

#include <tuple>

class Solutions_303_Test
    : public testing::TestWithParam<
          tuple<vector<int>, vector<tuple<int, int, int>>>> {};

TEST_P(Solutions_303_Test, ) {
    auto [nums, calls] = GetParam();

    NumArray sol(nums);

    for (const auto &call : calls) {
        int actual = sol.sumRange(get<0>(call), get<1>(call));
        EXPECT_EQ(actual, get<2>(call));
    }
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_303_Test,
    testing::Values(
        make_tuple(vector<int>{-2, 0, 3, -5, 2, -1},
                   vector<tuple<int, int, int>>{
                       {0, 2, 1}, {2, 5, -1}, {0, 5, -3}}),
        make_tuple(
            vector<int>{1, 2, 3, 4, 5},
            vector<tuple<int, int, int>>{
                {0, 0, 1}, {0, 1, 3}, {1, 3, 9}, {2, 4, 12}, {0, 4, 15}}),
        make_tuple(
            vector<int>{10, -10, 10, -10, 10},
            vector<tuple<int, int, int>>{
                {0, 0, 10}, {0, 1, 0}, {0, 2, 10}, {1, 3, -10}, {2, 4, 10}}),
        make_tuple(vector<int>{5}, vector<tuple<int, int, int>>{{0, 0, 5}}),
        make_tuple(vector<int>{1, -1},
                   vector<tuple<int, int, int>>{
                       {0, 0, 1}, {1, 1, -1}, {0, 1, 0}}),
        make_tuple(vector<int>{0, 0, 0, 0, 0},
                   vector<tuple<int, int, int>>{
                       {0, 4, 0}, {1, 3, 0}, {2, 2, 0}}),
        make_tuple(vector<int>{100, 200, 300, 400},
                   vector<tuple<int, int, int>>{
                       {0, 0, 100}, {0, 3, 1000}, {1, 2, 500}}),
        make_tuple(vector<int>{-1, -1, -1, -1, -1},
                   vector<tuple<int, int, int>>{
                       {0, 4, -5}, {2, 3, -2}, {1, 1, -1}}),
        make_tuple(vector<int>{1, 3, 5, 7, 9, 11},
                   vector<tuple<int, int, int>>{
                       {0, 2, 9}, {2, 5, 32}, {0, 5, 36}}),
        make_tuple(vector<int>{8, 6, 7, 5, 3, 0, 9},
                   vector<tuple<int, int, int>>{
                       {0, 6, 38}, {3, 5, 8}, {1, 4, 21}})));
