#include "solutions_77.hpp"

#include <gtest/gtest.h>

class Solutions_77_Test
    : public testing::TestWithParam<tuple<int, int, vector<vector<int>>>> {
   protected:
    Solution solutions;
};

TEST_P(Solutions_77_Test, ) {
    auto [n, k, expected] = GetParam();

    auto actual = solutions.combine(n, k);

    EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_77_Test,
    testing::Values(
        make_tuple(4, 2,
                   vector<vector<int>>{
                       {1, 2}, {1, 3}, {1, 4}, {2, 3}, {2, 4}, {3, 4}}),
        make_tuple(1, 1, vector<vector<int>>{{1}})));