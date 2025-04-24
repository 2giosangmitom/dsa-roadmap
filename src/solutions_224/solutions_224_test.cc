#include "solutions_224.hpp"

#include <gtest/gtest.h>

#include <tuple>

class Solutions_224_Test : public testing::TestWithParam<tuple<string, int>> {
 protected:
  Solution solutions;
};

TEST_P(Solutions_224_Test, ) {
  auto [s, expected] = GetParam();

  int actual = solutions.calculate(s);

  EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_224_Test,
    testing::Values(make_tuple("(1 + 6) - 1 + 2 - (1 + 1)", 6),
                    make_tuple("1+1", 2), make_tuple("(1+(4+5+2)-3)+(6+8)", 23),
                    make_tuple("2-(5-6)", 3),
                    make_tuple("10 + (2 - 3) + 4", 13),
                    make_tuple("((2 + 3) - (1 + 2)) + 4", 6),
                    make_tuple("1 - (2 + 3) + 4", 0),
                    make_tuple("1 - (2 - (3 + 4))", 6),
                    make_tuple("1 - (2 - (3 - 4))", -2),
                    make_tuple("- (3 + (2 - 1))", -4)));
