#include "../src/longest_substr_without_repeat.hpp"
#include <gtest/gtest.h>
#include <tuple>

class LongestSubstrWithoutRepeatTest
    : public testing::TestWithParam<tuple<string, int>> {
protected:
  Solution solution;
};

TEST_P(LongestSubstrWithoutRepeatTest, LengthOfLongestSubstring) {
  string s;
  int expected;
  tie(s, expected) = GetParam();

  int actual = solution.lengthOfLongestSubstring(s);

  EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(
    Default, LongestSubstrWithoutRepeatTest,
    testing::Values(make_tuple("abcabcbb", 3), make_tuple("bbbbb", 1),
                    make_tuple("pwwkew", 3), make_tuple("abcdef", 6),
                    make_tuple("aab", 2), make_tuple("dvdf", 3),
                    make_tuple("anviaj", 5), make_tuple("", 0),
                    make_tuple("a", 1), make_tuple("au", 2),
                    make_tuple("aabaab!bb", 3)));
