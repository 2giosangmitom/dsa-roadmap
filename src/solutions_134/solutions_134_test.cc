#include "solutions_134.hpp"

#include <gtest/gtest.h>

#include <tuple>

using std::tuple;

class Solutions_134_Test
    : public testing::TestWithParam<tuple<vector<int>, vector<int>, int>> {
   protected:
    Solution solutions;
};

TEST_P(Solutions_134_Test, ) {
    auto [gas, cost, expected] = GetParam();

    auto actual = solutions.canCompleteCircuit(gas, cost);

    EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_134_Test,
    testing::Values(std::make_tuple(vector<int>{1, 2, 3, 4, 5},
                                    vector<int>{3, 4, 5, 1, 2}, 3),
                    std::make_tuple(vector<int>{2, 3, 4}, vector<int>{3, 4, 3},
                                    -1)));
