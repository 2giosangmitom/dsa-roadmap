#include <gtest/gtest.h>

#include <tuple>

#include "solutions_204.hpp"
using namespace std;

class Solutions_204_Test : public testing::TestWithParam<tuple<int, int>> {
 protected:
  Solution solution;
};

TEST_P(Solutions_204_Test, ) {
  int n;
  int expected;
  tie(n, expected) = GetParam();

  int actual = solution.countPrimes(n);

  EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(, Solutions_204_Test,
                         testing::Values(make_tuple(10, 4), make_tuple(0, 0),
                                         make_tuple(1, 0), make_tuple(2, 0),
                                         make_tuple(3, 1), make_tuple(100, 25),
                                         make_tuple(1000, 168),
                                         make_tuple(5000, 669),
                                         make_tuple(10000, 1229)));
