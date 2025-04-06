#include "solutions_20.hpp"
#include <gtest/gtest.h>

class Solutions_20_Test : public testing::TestWithParam<tuple<string, bool>> {
protected:
  Solution solution;
};

TEST_P(Solutions_20_Test, ) {
  auto [s, expected] = GetParam();

  bool actual = solution.isValid(s);

  EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(, Solutions_20_Test,
                         testing::Values(make_tuple("()", true),
                                         make_tuple("{}(", false),
                                         make_tuple("}}{", false),
                                         make_tuple("{}()[]", true),
                                         make_tuple("{()}", true)));
