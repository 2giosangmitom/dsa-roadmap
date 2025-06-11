#include "solutions_88.hpp"

#include <gtest/gtest.h>

class Solutions_88_Test
    : public testing::TestWithParam<
          tuple<vector<int>, int, vector<int>, int, vector<int>>> {
   protected:
    Solution solution;
};

TEST_P(Solutions_88_Test, ) {
    auto [nums1, m, nums2, n, expected] = GetParam();

    solution.merge(nums1, m, nums2, n);

    EXPECT_EQ(nums1, expected);
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_88_Test,
    testing::Values(
        make_tuple(vector<int>{1, 2, 3, 0, 0, 0}, 3, vector<int>{2, 5, 6}, 3,
                   vector<int>{1, 2, 2, 3, 5, 6}),
        make_tuple(vector<int>{1}, 1, vector<int>{}, 0, vector<int>{1}),
        make_tuple(vector<int>{1, 4, 5, 0, 0}, 3, vector<int>{2, 6}, 2,
                   vector<int>{1, 2, 4, 5, 6})));
