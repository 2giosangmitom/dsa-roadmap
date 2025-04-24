#include "solutions_1780.hpp"

#include <gtest/gtest.h>

#include <tuple>
using namespace std;

class Solutions_1780_Test : public testing::TestWithParam<tuple<int, bool>> {
 protected:
  Solution solution;
};

TEST_P(Solutions_1780_Test, ) {
  auto [n, expected] = GetParam();

  bool actual = solution.checkPowersOfThree(n);

  EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(, Solutions_1780_Test,
                         testing::Values(make_tuple(12, true),
                                         make_tuple(91, true),
                                         make_tuple(21, false),
                                         make_tuple(20, false),
                                         make_tuple(19, false)));
