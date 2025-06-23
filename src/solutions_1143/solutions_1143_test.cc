#include "solutions_1143.hpp"

#include <gtest/gtest.h>

using std::make_tuple;
using std::tuple;

class Solutions_1143_Test
    : public testing::TestWithParam<tuple<string, string, int>> {
   protected:
    Solution solutions;
};

TEST_P(Solutions_1143_Test, ) {
    auto [text1, text2, expected] = GetParam();

    auto actual = solutions.longestCommonSubsequence(text1, text2);

    EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(, Solutions_1143_Test,
                         testing::Values(make_tuple("abcde", "ace", 3),
                                         make_tuple("abc", "abc", 3),
                                         make_tuple("abc", "def", 0)));
