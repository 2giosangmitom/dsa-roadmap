#include "solutions_4.hpp"
#include <gtest/gtest.h>
#include <tuple>

class Solutions_4_Test
    : public testing::TestWithParam<tuple<vector<int>, vector<int>, double>> {
protected:
  Solution solution;
};

TEST_P(Solutions_4_Test, ) {
  auto [nums1, nums2, expected] = GetParam();

  double actual = solution.findMedianSortedArrays(nums1, nums2);

  EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_4_Test,
    testing::Values(
        make_tuple(vector<int>{0, 2, 5, 6, 8}, vector<int>{1, 3, 7}, 4),
        make_tuple(vector<int>{0, 2, 5, 6, 8}, vector<int>{1, 3, 7, 9}, 5),
        make_tuple(vector<int>{}, vector<int>{1, 2, 3}, 2),
        make_tuple(vector<int>{1, 2, 3, 4}, vector<int>{}, 2.5),
        make_tuple(vector<int>{1, 2, 3}, vector<int>{0}, 1.5),
        make_tuple(vector<int>{1, 2}, vector<int>{3, 4}, 2.5),
        make_tuple(vector<int>{3}, vector<int>{-2, -1}, -1)));
