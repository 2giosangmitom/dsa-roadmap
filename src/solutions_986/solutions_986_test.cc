#include "solutions_986.hpp"

#include <gtest/gtest.h>

#include <tuple>

class Solutions_986_Test
    : public testing::TestWithParam<tuple<
          vector<vector<int>>, vector<vector<int>>, vector<vector<int>>>> {
   protected:
    Solution solutions;
};

TEST_P(Solutions_986_Test, ) {
    auto [firstList, secondList, expected] = GetParam();

    auto actual = solutions.intervalIntersection(firstList, secondList);

    EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_986_Test,
    testing::Values(
        make_tuple(vector<vector<int>>{{0, 2}, {5, 10}, {13, 23}, {24, 25}},
                   vector<vector<int>>{{1, 5}, {8, 12}, {15, 24}, {25, 26}},
                   vector<vector<int>>{
                       {1, 2}, {5, 5}, {8, 10}, {15, 23}, {24, 24}, {25, 25}}),
        make_tuple(vector<vector<int>>{}, vector<vector<int>>{},
                   vector<vector<int>>{}),
        make_tuple(vector<vector<int>>{{1, 3}, {5, 9}}, vector<vector<int>>{},
                   vector<vector<int>>{}),
        make_tuple(vector<vector<int>>{{1, 5}}, vector<vector<int>>{{2, 3}},
                   vector<vector<int>>{{2, 3}}),
        make_tuple(vector<vector<int>>{{1, 2}, {3, 5}},
                   vector<vector<int>>{{6, 7}, {8, 10}}, vector<vector<int>>{}),
        make_tuple(vector<vector<int>>{{1, 3}, {5, 7}},
                   vector<vector<int>>{{1, 3}, {5, 7}},
                   vector<vector<int>>{{1, 3}, {5, 7}})));