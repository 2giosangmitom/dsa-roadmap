#include "solutions_322.hpp"

#include <gtest/gtest.h>

#include <vector>

class Solutions_322_Test
    : public testing::TestWithParam<tuple<vector<int>, int, int>> {
   protected:
    Solution solutions;
};

TEST_P(Solutions_322_Test, BottomUp) {
    auto [coins, amount, expected] = GetParam();

    auto actual = solutions.coinChange(coins, amount);

    EXPECT_EQ(actual, expected);
}

TEST_P(Solutions_322_Test, TopDown) {
    auto [coins, amount, expected] = GetParam();

    auto actual = solutions.coinChange2(coins, amount);

    EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_322_Test,
    testing::Values(make_tuple(vector<int>{1, 2, 5}, 11, 3),
                    make_tuple(vector<int>{2}, 3, -1),
                    make_tuple(vector<int>{1}, 0, 0),
                    make_tuple(vector<int>{1, 2, 5}, 10, 2),
                    make_tuple(vector<int>{1, 2, 5}, 100, 20),
                    make_tuple(vector<int>{186, 419, 83, 408}, 6249, 20)));
