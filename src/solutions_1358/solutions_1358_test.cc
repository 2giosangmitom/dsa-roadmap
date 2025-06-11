#include "solutions_1358.hpp"

#include <gtest/gtest.h>

class Solutions_1358_Test : public testing::TestWithParam<tuple<string, int>> {
   protected:
    Solution solution;
};

TEST_P(Solutions_1358_Test, ) {
    auto [s, expected] = GetParam();

    int actual = solution.numberOfSubstrings(s);

    EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(, Solutions_1358_Test,
                         testing::Values(make_tuple("abcabc", 10),
                                         make_tuple("abc", 1),
                                         make_tuple("aaacb", 3)));
