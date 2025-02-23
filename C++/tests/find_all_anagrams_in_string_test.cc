#include "../src/find_all_anagrams_in_string.hpp"
#include "gtest/gtest.h"
#include <gtest/gtest.h>
#include <tuple>
#include <vector>

class AnagramsSubStringTest
    : public testing::TestWithParam<tuple<string, string, vector<int>>> {
protected:
  Solution solution;
};

TEST_P(AnagramsSubStringTest, findAnagrams) {
  string s, p;
  vector<int> expected;
  tie(s, p, expected) = GetParam();

  vector<int> actual = solution.findAnagrams(s, p);

  EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(
    , AnagramsSubStringTest,
    testing::Values(make_tuple("cbaebabacd", "abc", vector<int>{0, 6}),
                    make_tuple("abab", "ab", vector<int>{0, 1, 2}),
                    make_tuple("aaaaaaaaaa", "a",
                               vector<int>{0, 1, 2, 3, 4, 5, 6, 7, 8, 9}),
                    make_tuple("abcd", "e", vector<int>{}),
                    make_tuple("a", "a", vector<int>{0}),
                    make_tuple("a", "b", vector<int>{}),
                    make_tuple("abcdefg", "gfedcba", vector<int>{0}),
                    make_tuple("abcdefgabcdefg", "gfedcba",
                               vector<int>{0, 1, 2, 3, 4, 5, 6, 7}),
                    make_tuple("aaabbbccc", "abc", vector<int>{}),
                    make_tuple("abacbabc", "abc", vector<int>{1, 2, 3, 5})));