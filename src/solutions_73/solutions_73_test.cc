#include "solutions_73.hpp"

#include <gtest/gtest.h>

#include <tuple>

class Solutions_73_Test : public testing::TestWithParam<
                              tuple<vector<vector<int>>, vector<vector<int>>>> {
   protected:
    Solution solution;
};

TEST_P(Solutions_73_Test, first) {
    auto [matrix, expected] = GetParam();

    solution.setZeroes(matrix);

    EXPECT_EQ(matrix, expected);
}

TEST_P(Solutions_73_Test, second) {
    auto [matrix, expected] = GetParam();

    solution.setZeroes2(matrix);

    EXPECT_EQ(matrix, expected);
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_73_Test,
    testing::Values(make_tuple(
                        vector<vector<int>>{
                            {1, 1, 1},
                            {1, 0, 1},
                            {1, 1, 1},
                        },
                        vector<vector<int>>{{1, 0, 1}, {0, 0, 0}, {1, 0, 1}}),
                    make_tuple(
                        vector<vector<int>>{
                            {0, 1, 2, 0},
                            {3, 4, 5, 2},
                            {1, 3, 1, 5},
                        },
                        vector<vector<int>>{
                            {0, 0, 0, 0}, {0, 4, 5, 0}, {0, 3, 1, 0}})));
