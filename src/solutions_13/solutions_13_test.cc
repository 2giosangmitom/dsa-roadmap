#include "solutions_13.hpp"

#include <gtest/gtest.h>

class Solutions_13_Test : public testing::TestWithParam<tuple<string, int>> {
 protected:
  Solution solution;
};

TEST_P(Solutions_13_Test, ) {
  auto [s, expected] = GetParam();

  int actual = solution.romanToInt(s);

  EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_13_Test,
    testing::Values(make_tuple("III", 3), make_tuple("IV", 4),
                    make_tuple("IX", 9), make_tuple("LVIII", 58),
                    make_tuple("MCMXCIV", 1994), make_tuple("XL", 40),
                    make_tuple("XC", 90), make_tuple("CD", 400),
                    make_tuple("CM", 900), make_tuple("MMMCMXCIX", 3999)));
