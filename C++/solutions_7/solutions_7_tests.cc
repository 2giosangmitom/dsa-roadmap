#include "solutions_7.hpp"
#include <gtest/gtest.h>

class Solutions_7_Test : public testing::TestWithParam<tuple<int, int>> {
protected:
  Solution solution;
};

TEST_P(Solutions_7_Test, ) {
  auto [input, expected] = GetParam();
  int actual = solution.reverse(input);
  EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_7_Test,
    testing::Values(make_tuple(123, 321), make_tuple(-123, -321),
                    make_tuple(120, 21), make_tuple(0, 0),
                    make_tuple(1534236469, 0), make_tuple(-2147483648, 0),
                    make_tuple(1000000003, 0), make_tuple(1, 1),
                    make_tuple(-1, -1), make_tuple(1000, 1)));
