#include "solutions_3360.hpp"
#include <gtest/gtest.h>
using namespace std;

class Solutions_3360_Test : public testing::TestWithParam<tuple<int, bool>> {
protected:
  Solution solutions;
};

TEST_P(Solutions_3360_Test, ) {
  auto [n, expected] = GetParam();

  EXPECT_EQ(solutions.canAliceWin(n), expected);
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_3360_Test,
    testing::Values(make_tuple(0, false), make_tuple(1, false),
                    make_tuple(10, true), make_tuple(11, true),
                    make_tuple(54, true), make_tuple(55, false),
                    make_tuple(56, false), make_tuple(100, false)));
