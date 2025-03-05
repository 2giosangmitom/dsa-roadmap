#include <gtest/gtest.h>

#include <tuple>

#include "solutions_3.hpp"

class Solutions_3_Test : public testing::TestWithParam<tuple<string, int>> {
 protected:
  Solution solution;
};

TEST_P(Solutions_3_Test, ) {
  auto [s, expected] = GetParam();

  int actual = solution.lengthOfLongestSubstring(s);

  EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_3_Test,
    testing::Values(make_tuple("abcabcbb", 3), make_tuple("bbbbb", 1),
                    make_tuple("pwwkew", 3), make_tuple("nhucut", 4),
                    make_tuple("anviaj", 5), make_tuple("", 0),
                    make_tuple("a", 1), make_tuple("au", 2),
                    make_tuple("aabaab!bb", 3)));
