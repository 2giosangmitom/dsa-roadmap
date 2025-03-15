#include "solutions_14.hpp"
#include <gtest/gtest.h>
#include <tuple>

class Solutions_14_Test
    : public testing::TestWithParam<tuple<vector<string>, string>> {
protected:
  Solution solution;
};

TEST_P(Solutions_14_Test, ) {
  auto [strs, expected] = GetParam();

  string actual = solution.longestCommonPrefix(strs);

  EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_14_Test,
    testing::Values(
        make_tuple(vector<string>{"leetcode", "leets", "leet"}, "leet"),
        make_tuple(vector<string>{"flower", "flow", "flight"}, "fl"),
        make_tuple(vector<string>{"dog", "racecar", "car"}, "")));
