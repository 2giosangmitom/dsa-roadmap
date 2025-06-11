#include "solutions_1047.hpp"

#include <gtest/gtest.h>

#include <tuple>

class Solutions_1047_Test
    : public testing::TestWithParam<tuple<string, string>> {
   protected:
    Solution solutions;
};

TEST_P(Solutions_1047_Test, ) {
    auto [s, expected] = GetParam();

    string actual = solutions.removeDuplicates(s);

    EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(, Solutions_1047_Test,
                         testing::Values(make_tuple("abbaca", "ca"),
                                         make_tuple("azxxzy", "ay")));
