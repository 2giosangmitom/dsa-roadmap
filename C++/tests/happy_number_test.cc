#include "../src/happy_number.hpp"
#include "gtest/gtest.h"
#include <gtest/gtest.h>
#include <tuple>
using namespace std;

class HappyNumberTest : public testing::TestWithParam<tuple<int, bool>> {
protected:
  Solution s;
};

TEST_P(HappyNumberTest, IsHappy) {
  int n;
  bool expected;
  tie(n, expected) = GetParam();
  EXPECT_EQ(s.isHappy(n), expected);
}

INSTANTIATE_TEST_SUITE_P(
    , HappyNumberTest,
    testing::Values(make_tuple(23, true), make_tuple(19, true),
                    make_tuple(2, false), make_tuple(1, true),
                    make_tuple(0, false), make_tuple(7, true),
                    make_tuple(1111111, true), make_tuple(1000, true),
                    make_tuple(999, false)));
