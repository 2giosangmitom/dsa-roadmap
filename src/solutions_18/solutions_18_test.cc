#include "solutions_18.hpp"

#include <gtest/gtest.h>

using namespace std;

class Solutions_18_Test : public testing::TestWithParam<
                              tuple<vector<int>, int, vector<vector<int>>>> {
   protected:
    Solution solution;
};

TEST_P(Solutions_18_Test, ) {
    auto [nums, target, expected] = GetParam();

    auto actual = solution.fourSum(nums, target);

    EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_18_Test,
    testing::Values(
        // Basic test case - should find triplets that sum to target
        make_tuple(vector<int>{1, 0, -1, 0, -2, 2}, 0,
                   vector<vector<int>>{
                       {-2, -1, 1, 2}, {-2, 0, 0, 2}, {-1, 0, 0, 1}}),

        // Test case with all same numbers
        make_tuple(vector<int>{2, 2, 2, 2, 2}, 8,
                   vector<vector<int>>{{2, 2, 2, 2}}),

        // Empty result case - no valid quadruplets
        make_tuple(vector<int>{1000000000, 1000000000, 1000000000, 1000000000},
                   -294967268, vector<vector<int>>{}),

        // Test with fewer than 4 elements - should return empty
        make_tuple(vector<int>{1, 2, 3}, 6, vector<vector<int>>{})));
