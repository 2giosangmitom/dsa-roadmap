#include "solutions_50.hpp"

#include <gtest/gtest.h>

#include <tuple>
using namespace std;

class Solutions_50_Test
    : public testing::TestWithParam<tuple<double, int, double>> {
 protected:
  Solution solution;
};

TEST_P(Solutions_50_Test, ) {
  auto [x, n, expected] = GetParam();

  double actual = solution.myPow(x, n);

  EXPECT_NEAR(actual, expected, 0.00001);
}

INSTANTIATE_TEST_SUITE_P(, Solutions_50_Test,
                         testing::Values(make_tuple(2.0, 10, 1024.0),
                                         make_tuple(2.1, 3, 9.261),
                                         make_tuple(2.0, -2, 0.25),
                                         make_tuple(2.0, 2, 4.0),
                                         make_tuple(34.00515, -3, 0.00003)));
