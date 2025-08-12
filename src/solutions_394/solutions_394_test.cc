#include "solutions_394.hpp"

#include <gtest/gtest.h>

#include <tuple>

class Solutions_394_Test
    : public testing::TestWithParam<tuple<string, string>> {
   protected:
    Solution solution;
};

TEST_P(Solutions_394_Test, ) {
    auto [s, expected] = GetParam();

    auto actual = solution.decodeString(s);

    EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_394_Test,
    testing::Values(
        make_tuple("3[a]2[bc]", "aaabcbc"), make_tuple("3[a2[c]]", "accaccacc"),
        make_tuple("2[abc]3[cd]ef", "abcabccdcdcdef"),
        make_tuple(
            "2[abc]3[cd]efd4[a12[d4[dd]]]",
            "abcabccdcdcdefdadddddddddddddddddddddddddddddddddddddddddddddddddd"
            "ddddddddddddddddddddddddddddddddddddddddddddddddddddddddddaddddddd"
            "dddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd"
            "dddddddddddddddddddddddddddddddddddadddddddddddddddddddddddddddddd"
            "dddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd"
            "ddddddddddddaddddddddddddddddddddddddddddddddddddddddddddddddddddd"
            "ddddddddddddddddddddddddddddddddddddddddddddddddddddddd")));
