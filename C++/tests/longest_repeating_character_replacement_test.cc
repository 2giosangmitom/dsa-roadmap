#include "../src/longest_repeating_character_replacement.hpp"
#include "gtest/gtest.h"
#include <gtest/gtest.h>
#include <tuple>

class LongestRepeatingCharacterReplacementTest
    : public testing::TestWithParam<tuple<string, int, int>> {
protected:
  Solution solution;
};

TEST_P(LongestRepeatingCharacterReplacementTest, ) {
  string s;
  int k;
  int expected;
  tie(s, k, expected) = GetParam();

  int actual = solution.characterReplacement(s, k);

  EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(
    , LongestRepeatingCharacterReplacementTest,
    testing::Values(make_tuple("ABAB", 2, 4), make_tuple("AABCDCCA", 2, 5),
                    make_tuple("AABABBA", 1, 4), make_tuple("AAAA", 0, 4),
                    make_tuple("AAAB", 1, 4), make_tuple("ABCDE", 0, 1),
                    make_tuple("ABCDE", 5, 5)));