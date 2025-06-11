#include "solutions_215.hpp"

#include <gtest/gtest.h>

#include <tuple>

class Solutions_215_Test
    : public testing::TestWithParam<tuple<vector<int>, int, int>> {
   protected:
    Solution solutions;
};

TEST_P(Solutions_215_Test, ) {
    auto [nums, k, expected] = GetParam();

    int actual = solutions.findKthLargest(nums, k);

    EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_215_Test,
    testing::Values(make_tuple(vector<int>{3, 2, 1, 5, 6, 4}, 2, 5),
                    make_tuple(vector<int>{3, 2, 3, 1, 2, 4, 5, 5, 6}, 4, 4),
                    make_tuple(vector<int>{4, 6, 7, 1, 9, 2}, 6, 1),
                    make_tuple(vector<int>{9, 3, 2, 4, 8}, 5, 2),
                    make_tuple(vector<int>{1, 2, 3, 4, 5}, 1, 5),
                    make_tuple(vector<int>{3, 2, 3, 1, 2, 4, 5, 5, 6}, 4, 4)));
