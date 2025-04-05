#include "solutions_1.hpp"
#include <gtest/gtest.h>
#include <tuple>
#include <vector>

class Solutions_1_Test
    : public testing::TestWithParam<tuple<vector<int>, int, vector<int>>> {
  protected:
    Solution solution;
};

TEST_P(Solutions_1_Test, ) {
    auto [nums, target, expected] = GetParam();

    auto actual = solution.twoSum(nums, target);

    EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_1_Test,
    testing::Values(
        make_tuple(vector<int>{2, 7, 11, 15}, 9, vector<int>{0, 1}),
        make_tuple(vector<int>{3, 2, 4}, 6, vector<int>{1, 2}),
        make_tuple(vector<int>{1, 5, -3, -2}, -5, vector<int>{2, 3}),
        make_tuple(vector<int>{-10, 7, 8, 2, 12}, 20, vector<int>{2, 4}),
        make_tuple(vector<int>{-6, 1, -7, 3, 8}, -13, vector<int>{0, 2}),
        make_tuple(vector<int>{}, 0, vector<int>{}),
        make_tuple(vector<int>{0, 4, 1, 2}, 9, vector<int>{})));