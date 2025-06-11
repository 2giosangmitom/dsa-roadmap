#include "solutions_2529.hpp"

#include <gtest/gtest.h>

#include <tuple>

class Solutions_2529_Test
    : public testing::TestWithParam<tuple<vector<int>, int>> {
   protected:
    Solution solution;
};

TEST_P(Solutions_2529_Test, ) {
    auto [nums, expected] = GetParam();

    int actual = solution.maximumCount(nums);

    EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_2529_Test,
    testing::Values(make_tuple(vector<int>{-3, -2, -1, 0, 0, 0, 1, 1, 2, 3}, 4),
                    make_tuple(vector<int>{0, 0, 0, 1, 2, 3, 4, 5}, 5),
                    make_tuple(vector<int>{-1, 0, 1}, 1),
                    make_tuple(vector<int>{-5, -4, -3}, 3),
                    make_tuple(vector<int>{-5, -4, -3, -2, -1}, 5),
                    make_tuple(vector<int>{1, 2, 3, 4, 5}, 5),
                    make_tuple(vector<int>{-5, -4, -3, 0, 1, 2}, 3)));
