#include "solutions_17.hpp"

#include <gtest/gtest.h>

#include <tuple>
#include <vector>

class Solutions_17_Test
    : public testing::TestWithParam<tuple<string, vector<string>>> {
   protected:
    Solution solutions;
};

TEST_P(Solutions_17_Test, ) {
    auto [digits, expected] = GetParam();

    auto actual = solutions.letterCombinations(digits);

    EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_17_Test,
    testing::Values(make_tuple("23",
                               vector<string>{"ad", "ae", "af", "bd", "be",
                                              "bf", "cd", "ce", "cf"}),
                    make_tuple("", vector<string>{}),
                    make_tuple("2", vector<string>{"a", "b", "c"})));
