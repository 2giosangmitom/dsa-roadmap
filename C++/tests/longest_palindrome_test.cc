#include "../src/longest_palindrome.hpp"
#include "gtest/gtest.h"
#include <gtest/gtest.h>
#include <tuple>

class LongestPalindromeTest
    : public testing::TestWithParam<tuple<string, int>> {
protected:
  Solution solution;
};

TEST_P(LongestPalindromeTest, ) {
  string s;
  int expected;
  tie(s, expected) = GetParam();

  int actual = solution.longestPalindrome(s);

  EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(, LongestPalindromeTest,
                         testing::Values(make_tuple("abccccdd", 7),
                                         make_tuple("a", 1),
                                         make_tuple("bb", 2),
                                         make_tuple("ab", 1),
                                         make_tuple("aabbccddd", 9)));