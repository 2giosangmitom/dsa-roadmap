#include "solutions_40.hpp"

#include <gtest/gtest.h>

#include <tuple>
#include <vector>

class Solutions_40_Test : public testing::TestWithParam<
                              tuple<vector<int>, int, vector<vector<int>>>> {
   protected:
    Solution solutions;
};

TEST_P(Solutions_40_Test, ) {
    auto [candidates, target, expected] = GetParam();

    auto actual = solutions.combinationSum2(candidates, target);

    EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_40_Test,
    testing::Values(make_tuple(vector<int>{10, 1, 2, 7, 6, 1, 5}, 8,
                               vector<vector<int>>{
                                   {1, 1, 6}, {1, 2, 5}, {1, 7}, {2, 6}}),
                    make_tuple(vector<int>{2, 5, 2, 1, 2}, 5,
                               vector<vector<int>>{{1, 2, 2}, {5}})));