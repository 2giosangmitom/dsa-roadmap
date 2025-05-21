#include "solutions_211.hpp"

#include <gtest/gtest.h>

TEST(WordDictionaryTest, AddAndSearch) {
  WordDictionary dict;
  dict.addWord("bad");
  dict.addWord("dad");
  dict.addWord("mad");

  EXPECT_TRUE(dict.search("bad"));
  EXPECT_TRUE(dict.search("dad"));
  EXPECT_TRUE(dict.search("mad"));
  EXPECT_FALSE(dict.search("pad"));
  EXPECT_TRUE(dict.search(".ad"));
  EXPECT_TRUE(dict.search("b.."));
}

TEST(WordDictionaryTest, SearchWithMultipleDots) {
  WordDictionary dict;
  dict.addWord("a");
  dict.addWord("ab");
  dict.addWord("abc");

  EXPECT_TRUE(dict.search("a"));
  EXPECT_TRUE(dict.search("ab"));
  EXPECT_TRUE(dict.search("abc"));
  EXPECT_FALSE(dict.search("b"));
  EXPECT_TRUE(dict.search("."));
  EXPECT_TRUE(dict.search(".."));
  EXPECT_TRUE(dict.search("..."));
}

TEST(WordDictionaryTest, SearchWithNoWords) {
  WordDictionary dict;

  EXPECT_FALSE(dict.search("a"));
  EXPECT_FALSE(dict.search("bad"));
  EXPECT_FALSE(dict.search("."));
  EXPECT_FALSE(dict.search(".."));
}

TEST(WordDictionaryTest, DuplicateWords) {
  WordDictionary dict;
  dict.addWord("a");
  dict.addWord("a");
  EXPECT_TRUE(dict.search("a"));
  EXPECT_TRUE(dict.search("."));
  EXPECT_FALSE(dict.search(".."));
  EXPECT_FALSE(dict.search("aa"));
}