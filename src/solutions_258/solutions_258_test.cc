#include "solutions_258.hpp"

#include <gtest/gtest.h>
using namespace std;

class Solutions_258_Test : public testing::TestWithParam<tuple<int, int>> {
 protected:
  Solution sol;
};

TEST_P(Solutions_258_Test, ) {
  auto [num, expected] = GetParam();

  int actual = sol.addDigits(num);

  EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(, Solutions_258_Test,
                         testing::Values(make_tuple(9, 9), make_tuple(10, 1),
                                         make_tuple(99, 9), make_tuple(0, 0),
                                         make_tuple(38, 2)));
