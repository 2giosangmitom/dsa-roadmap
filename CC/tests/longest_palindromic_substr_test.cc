#include "../src/longest_palindromic_substr.hpp"
#include <gtest/gtest.h>

class LongestPalindromicSubstrTest : public testing::Test {
protected:
  Solution solution;
};

TEST_F(LongestPalindromicSubstrTest, HandlesEmptyString) {
  std::string input = "";

  std::string result = solution.longestPalindrome(input);

  EXPECT_EQ(result, "");
}

TEST_F(LongestPalindromicSubstrTest, HandlesSingleCharacter) {
  std::string input = "a";

  std::string result = solution.longestPalindrome(input);

  EXPECT_EQ(result, "a");
}

TEST_F(LongestPalindromicSubstrTest, HandlesTwoIdenticalCharacters) {
  std::string input = "aa";

  std::string result = solution.longestPalindrome(input);

  EXPECT_EQ(result, "aa");
}

TEST_F(LongestPalindromicSubstrTest, HandlesTwoDifferentCharacters) {
  std::string input = "ab";

  std::string result = solution.longestPalindrome(input);

  EXPECT_EQ(result, "a");
}

TEST_F(LongestPalindromicSubstrTest, HandlesMiddlePalindrome) {
  std::string input = "abcba";

  std::string result = solution.longestPalindrome(input);

  EXPECT_EQ(result, "abcba");
}

TEST_F(LongestPalindromicSubstrTest, HandlesFullStringPalindrome) {
  std::string input = "racecar";

  std::string result = solution.longestPalindrome(input);

  EXPECT_EQ(result, "racecar");
}

TEST_F(LongestPalindromicSubstrTest, HandlesMultiplePalindromes) {
  std::string input = "babad";

  std::string result = solution.longestPalindrome(input);

  EXPECT_EQ(result, "bab");
}

TEST_F(LongestPalindromicSubstrTest, HandlesNoLongPalindrome) {
  std::string input = "abcdef";

  std::string result = solution.longestPalindrome(input);

  EXPECT_EQ(result, "a");
}

TEST_F(LongestPalindromicSubstrTest, HandlesEvenLengthPalindrome) {
  std::string input = "abccba";

  std::string result = solution.longestPalindrome(input);

  EXPECT_EQ(result, "abccba");
}

TEST_F(LongestPalindromicSubstrTest, HandlesOddLengthPalindrome) {
  std::string input = "aba";

  std::string result = solution.longestPalindrome(input);

  EXPECT_EQ(result, "aba");
}

TEST_F(LongestPalindromicSubstrTest, HandlesStartPalindrome) {
  std::string input = "aaab";

  std::string result = solution.longestPalindrome(input);

  EXPECT_EQ(result, "aaa");
}

TEST_F(LongestPalindromicSubstrTest, HandlesEndPalindrome) {
  std::string input = "baaa";

  std::string result = solution.longestPalindrome(input);

  EXPECT_EQ(result, "aaa");
}

TEST_F(LongestPalindromicSubstrTest, HandlesAllIdenticalCharacters) {
  std::string input = "aaaa";

  std::string result = solution.longestPalindrome(input);

  EXPECT_EQ(result, "aaaa");
}

TEST_F(LongestPalindromicSubstrTest, HandlesLongString) {
  std::string input = "forgeeksskeegfor";

  std::string result = solution.longestPalindrome(input);

  EXPECT_EQ(result, "geeksskeeg");
}

TEST_F(LongestPalindromicSubstrTest, HandlesSinglePalindrome) {
  std::string input = "abcdeffedcgh";

  std::string result = solution.longestPalindrome(input);

  EXPECT_EQ(result, "cdeffedc");
}
