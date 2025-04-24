#include "solutions_424.hpp"

#include <gtest/gtest.h>

#include <tuple>

class Solutions_424_Test
    : public testing::TestWithParam<tuple<string, int, int>> {
 protected:
  Solution solution;
};

TEST_P(Solutions_424_Test, ) {
  auto [s, k, expected] = GetParam();

  int actual = solution.characterReplacement(s, k);

  EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(, Solutions_424_Test,
                         testing::Values(make_tuple("ABAB", 2, 4),
                                         make_tuple("ABABB", 2, 5),
                                         make_tuple("AABABBA", 1, 4)));
