#include "solutions_125.hpp"

#include <gtest/gtest.h>

#include <tuple>

class Solutions_125_Test : public testing::TestWithParam<tuple<string, bool>> {
   protected:
    Solution solution;
};

TEST_P(Solutions_125_Test, ) {
    auto [s, expected] = GetParam();

    bool actual = solution.isPalindrome(s);

    EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_125_Test,
    testing::Values(make_tuple("A man, a plan, a canal: Panama", true),
                    make_tuple("race a car", false), make_tuple(" ", true),
                    make_tuple("a dog! a panic in a pagoda.", true),
                    make_tuple("abc123", false), make_tuple("0P", false)));
