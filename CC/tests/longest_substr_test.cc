#include "../src/longest_substr.hpp"
#include <gtest/gtest.h>

class LongestSubstrTest : public ::testing::Test {
protected:
  Solution solution;
};

TEST_F(LongestSubstrTest, basic_cases) {
  EXPECT_EQ(solution.lengthOfLongestSubstring("abcabcbb"), 3);
  EXPECT_EQ(solution.lengthOfLongestSubstring("bbbbb"), 1);
  EXPECT_EQ(solution.lengthOfLongestSubstring("pwwkew"), 3);
}

TEST_F(LongestSubstrTest, edge_cases) {
  EXPECT_EQ(solution.lengthOfLongestSubstring(""), 0);
  EXPECT_EQ(solution.lengthOfLongestSubstring(" "), 1);
  EXPECT_EQ(solution.lengthOfLongestSubstring("au"), 2);
  EXPECT_EQ(solution.lengthOfLongestSubstring("dvdf"), 3);
}

TEST_F(LongestSubstrTest, special_characters) {
  EXPECT_EQ(solution.lengthOfLongestSubstring("!@#!!@"), 3);
  EXPECT_EQ(solution.lengthOfLongestSubstring("123123123"), 3);
  EXPECT_EQ(solution.lengthOfLongestSubstring("a1b2c3"), 6);
}

TEST_F(LongestSubstrTest, longer_strings) {
  EXPECT_EQ(solution.lengthOfLongestSubstring("abcdefg"), 7);
  EXPECT_EQ(solution.lengthOfLongestSubstring("ababab"), 2);
  EXPECT_EQ(solution.lengthOfLongestSubstring("abba"), 2);
}

TEST_F(LongestSubstrTest, repeating_patterns) {
  EXPECT_EQ(solution.lengthOfLongestSubstring("abcabcbbabcabcbb"), 3);
  EXPECT_EQ(solution.lengthOfLongestSubstring("aaaaaaaa"), 1);
  EXPECT_EQ(solution.lengthOfLongestSubstring("abcdabcabcd"), 4);
}
