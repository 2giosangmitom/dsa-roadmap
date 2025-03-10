#include <gtest/gtest.h>

#include "solutions_2570.hpp"

class Solutions_2570_Test
    : public testing::TestWithParam<tuple<
          vector<vector<int>>, vector<vector<int>>, vector<vector<int>>>> {
 protected:
  Solution solution;
};

TEST_P(Solutions_2570_Test, HashMap) {
  auto [nums1, nums2, expected] = GetParam();

  auto actual = solution.mergeArrays(nums1, nums2);

  EXPECT_EQ(actual, expected);
}

TEST_P(Solutions_2570_Test, TwoPointer) {
  auto [nums1, nums2, expected] = GetParam();

  auto actual = solution.mergeArrays2(nums1, nums2);

  EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_2570_Test,
    testing::Values(make_tuple(vector<vector<int>>{{1, 2}, {2, 3}, {4, 5}},
                               vector<vector<int>>{{1, 4}, {3, 2}, {4, 1}},
                               vector<vector<int>>{
                                   {1, 6}, {2, 3}, {3, 2}, {4, 6}}),
                    make_tuple(vector<vector<int>>{{2, 4}, {3, 6}, {5, 5}},
                               vector<vector<int>>{{1, 3}, {4, 3}},
                               vector<vector<int>>{
                                   {1, 3}, {2, 4}, {3, 6}, {4, 3}, {5, 5}})));
