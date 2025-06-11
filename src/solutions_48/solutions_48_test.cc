#include "solutions_48.hpp"

#include <gtest/gtest.h>

class Solutions_48_Test
    : public testing::TestWithParam<std::tuple<std::vector<std::vector<int>>,
                                               std::vector<std::vector<int>>>> {
   protected:
    Solution solutions;
};

TEST_P(Solutions_48_Test, ) {
    auto [matrix, expected] = GetParam();

    solutions.rotate(matrix);

    EXPECT_EQ(matrix, expected);
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_48_Test,
    testing::Values(
        std::make_tuple(
            std::vector<std::vector<int>>{{1, 2, 3}, {4, 5, 6}, {7, 8, 9}},
            std::vector<std::vector<int>>{{7, 4, 1}, {8, 5, 2}, {9, 6, 3}}),
        std::make_tuple(
            std::vector<std::vector<int>>{
                {5, 1, 9, 11}, {2, 4, 8, 10}, {13, 3, 6, 7}, {15, 14, 12, 16}},
            std::vector<std::vector<int>>{
                {15, 13, 2, 5}, {14, 3, 4, 1}, {12, 6, 8, 9}, {16, 7, 10, 11}}),
        std::make_tuple(std::vector<std::vector<int>>{{1, 2}, {3, 4}},
                        std::vector<std::vector<int>>{{3, 1}, {4, 2}}),
        std::make_tuple(std::vector<std::vector<int>>{{1}},
                        std::vector<std::vector<int>>{{1}}),
        std::make_tuple(std::vector<std::vector<int>>{{1, 2, 3, 4, 5},
                                                      {6, 7, 8, 9, 10},
                                                      {11, 12, 13, 14, 15},
                                                      {16, 17, 18, 19, 20},
                                                      {21, 22, 23, 24, 25}},
                        std::vector<std::vector<int>>{{21, 16, 11, 6, 1},
                                                      {22, 17, 12, 7, 2},
                                                      {23, 18, 13, 8, 3},
                                                      {24, 19, 14, 9, 4},
                                                      {25, 20, 15, 10, 5}})));
