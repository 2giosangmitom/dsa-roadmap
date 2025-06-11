#include "solutions_347.hpp"

#include <gtest/gtest.h>

#include <tuple>

class Solutions_347_Test
    : public testing::TestWithParam<tuple<vector<int>, int, vector<int>>> {
   protected:
    Solution solution;
};

TEST_P(Solutions_347_Test, ) {
    auto [nums, k, expected] = GetParam();

    auto actual = solution.topKFrequent(nums, k);
    sort(actual.begin(), actual.end());

    EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_347_Test,
    testing::Values(make_tuple(vector<int>{1, 1, 1, 2, 2, 3}, 2,
                               vector<int>{1, 2}),
                    make_tuple(vector<int>{1}, 1, vector<int>{1}),
                    make_tuple(vector<int>{1, 1, 2, 2, 3, 3, 3, 4, 4, 4, 4}, 2,
                               vector<int>{3, 4})));
