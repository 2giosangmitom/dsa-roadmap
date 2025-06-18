#include "solutions_983.hpp"

#include <gtest/gtest.h>

class Solutions_983_Test
    : public testing::TestWithParam<tuple<vector<int>, vector<int>, int>> {
   protected:
    Solution solutions;
};

TEST_P(Solutions_983_Test, TopDown) {
    auto [days, costs, expected] = GetParam();

    auto actual = solutions.mincostTickets(days, costs);

    EXPECT_EQ(actual, expected);
}

TEST_P(Solutions_983_Test, BottomUp) {
    auto [days, costs, expected] = GetParam();

    auto actual = solutions.mincostTickets2(days, costs);

    EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_983_Test,
    testing::Values(
        make_tuple(vector<int>{1, 3, 4, 8}, vector<int>{2, 4, 7}, 6),
        make_tuple(vector<int>{1, 4, 6, 7, 8, 20}, vector<int>{2, 7, 15}, 11),
        make_tuple(vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 30, 31},
                   vector<int>{2, 7, 15}, 17)));
