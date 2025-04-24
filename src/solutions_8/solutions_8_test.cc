#include "solutions_8.hpp"

#include <gtest/gtest.h>

#include <tuple>

class Solutions_8_Test : public testing::TestWithParam<tuple<string, int>> {
 protected:
  Solution solution;
};

TEST_P(Solutions_8_Test, ) {
  auto [s, expected] = GetParam();

  int actual = solution.myAtoi(s);

  EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_8_Test,
    testing::Values(
        make_tuple("42", 42), make_tuple("-42", -42), make_tuple("   -42", -42),
        make_tuple("4193 with words", 4193), make_tuple("words and 987", 0),
        make_tuple("2147483647", 2147483647),
        make_tuple("2147483648", 2147483647),
        make_tuple("-2147483648", -2147483648),
        make_tuple("-2147483649", -2147483648), make_tuple("", 0),
        make_tuple("   ", 0), make_tuple("+", 0), make_tuple("+1", 1),
        make_tuple("-", 0), make_tuple("+-12", 0), make_tuple("  +  413", 0),
        make_tuple("00000-42a1234", 0),
        make_tuple("  0000000000012345678", 12345678),
        make_tuple("20000000000000000000", 2147483647),
        make_tuple("-20000000000000000000", -2147483648)));
