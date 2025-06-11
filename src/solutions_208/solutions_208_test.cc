#include "solutions_208.hpp"

#include <gtest/gtest.h>

TEST(Solutions_208_Test, case1) {
    auto trie = Trie();
    trie.insert("apple");
    EXPECT_TRUE(trie.search("apple"));

    EXPECT_FALSE(trie.search("app"));
    trie.insert("app");
    EXPECT_TRUE(trie.search("app"));

    EXPECT_FALSE(trie.startsWith("pp"));
    EXPECT_TRUE(trie.startsWith("ap"));
    EXPECT_TRUE(trie.startsWith("app"));
}

TEST(Solutions_208_Test, emptyTrie) {
    auto trie = Trie();
    EXPECT_FALSE(trie.search(""));
    EXPECT_FALSE(trie.search("a"));
    EXPECT_FALSE(trie.startsWith("a"));
}

TEST(Solutions_208_Test, insertAndSearchMultipleWords) {
    auto trie = Trie();
    trie.insert("cat");
    trie.insert("cap");
    trie.insert("cape");
    trie.insert("can");

    EXPECT_TRUE(trie.search("cat"));
    EXPECT_TRUE(trie.search("cap"));
    EXPECT_TRUE(trie.search("cape"));
    EXPECT_TRUE(trie.search("can"));

    EXPECT_FALSE(trie.search("ca"));
    EXPECT_FALSE(trie.search("cab"));
}

TEST(Solutions_208_Test, startsWithVariousPrefixes) {
    auto trie = Trie();
    trie.insert("hello");
    trie.insert("helium");

    EXPECT_TRUE(trie.startsWith("he"));
    EXPECT_TRUE(trie.startsWith("hel"));
    EXPECT_TRUE(trie.startsWith("hell"));
    EXPECT_TRUE(trie.startsWith("hello"));
    EXPECT_TRUE(trie.startsWith("heli"));
    EXPECT_FALSE(trie.startsWith("hero"));
    EXPECT_FALSE(trie.startsWith("ham"));
}

TEST(Solutions_208_Test, duplicateInsertions) {
    auto trie = Trie();
    trie.insert("go");
    trie.insert("go");
    trie.insert("gone");

    EXPECT_TRUE(trie.search("go"));
    EXPECT_TRUE(trie.search("gone"));
    EXPECT_FALSE(trie.search("gon"));
    EXPECT_TRUE(trie.startsWith("gon"));
}

TEST(Solutions_208_Test, insertEmptyString) {
    auto trie = Trie();
    trie.insert("");
    EXPECT_TRUE(trie.search(""));
    EXPECT_TRUE(trie.startsWith(""));
}
