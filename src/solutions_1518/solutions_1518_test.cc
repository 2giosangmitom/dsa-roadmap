#include "solutions_1518.hpp"

#include <gtest/gtest.h>

#include <tuple>
using namespace std;

class Solutions_1518_Test
    : public testing::TestWithParam<tuple<int, int, int>> {
 protected:
  Solution solution;
};

TEST_P(Solutions_1518_Test, ) {
  auto [num_bottles, num_exchange, expected] = GetParam();

  int actual = solution.numWaterBottles(num_bottles, num_exchange);

  EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(, Solutions_1518_Test,
                         testing::Values(make_tuple(9, 3, 13),
                                         make_tuple(15, 4, 19),
                                         make_tuple(4, 5, 4)));
