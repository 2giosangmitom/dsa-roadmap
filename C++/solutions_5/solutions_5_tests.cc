#include <gtest/gtest.h>

#include <tuple>

#include "solutions_5.hpp"

class Solutions_5_Test : public testing::TestWithParam<tuple<string, string>> {
 protected:
  Solution solution;
};

TEST_P(Solutions_5_Test, ) {
  auto [s, expected] = GetParam();

  string actual = solution.longestPalindrome(s);

  EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_5_Test,
    testing::Values(make_tuple("babad", "bab"), make_tuple("cbbd", "bb"),
                    make_tuple("a", "a"), make_tuple("ac", "a"),
                    make_tuple("racecar", "racecar"),
                    make_tuple("noon", "noon"), make_tuple("", ""),
                    make_tuple("abcda", "a"), make_tuple("abb", "bb")));