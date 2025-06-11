#include "./solutions_74.hpp"

#include <gtest/gtest.h>

#include <tuple>

class Solutions_74_Test
    : public testing::TestWithParam<tuple<vector<vector<int>>, int, bool>> {
   protected:
    Solution solution;
};

TEST_P(Solutions_74_Test, ) {
    auto [matrix, target, expected] = GetParam();

    bool actual = solution.searchMatrix(matrix, target);

    EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_74_Test,
    testing::Values(
        make_tuple(
            vector<vector<int>>{
                {1, 3, 5, 7},
                {10, 11, 16, 20},
                {23, 30, 34, 60},
            },
            3, true),
        make_tuple(vector<vector<int>>{{1, 3, 5, 7},
                                       {10, 11, 16, 20},
                                       {23, 30, 34, 60}},
                   13, false),
        make_tuple(
            vector<vector<int>>{
                {2, 3, 4, 6},
                {7, 10, 11, 17},
                {20, 21, 24, 33},
            },
            21, true),
        make_tuple(vector<vector<int>>{{1, 2, 3, 4, 5}}, 3, true),
        make_tuple(vector<vector<int>>{{1, 2, 3, 4, 5}}, 6, false),
        make_tuple(vector<vector<int>>{{1}, {2}, {3}, {4}, {5}}, 4, true),
        make_tuple(vector<vector<int>>{{1}, {2}, {3}, {4}, {5}}, 6, false),
        make_tuple(vector<vector<int>>{{1, 3, 5, 7},
                                       {10, 11, 16, 20},
                                       {23, 30, 34, 60}},
                   1, true),
        make_tuple(vector<vector<int>>{{1, 3, 5, 7},
                                       {10, 11, 16, 20},
                                       {23, 30, 34, 60}},
                   60, true),
        make_tuple(vector<vector<int>>{{5}}, 5, true),
        make_tuple(vector<vector<int>>{{5}}, 3, false)));
