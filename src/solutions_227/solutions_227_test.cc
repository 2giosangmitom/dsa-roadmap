#include "solutions_227.hpp"

#include <gtest/gtest.h>

#include <tuple>

class Solutions_227_Test : public testing::TestWithParam<tuple<string, int>> {
   protected:
    Solution solutions;
};

TEST_P(Solutions_227_Test, ) {
    auto [s, expected] = GetParam();

    int actual = solutions.calculate(s);

    EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_227_Test,
    testing::Values(make_tuple("3+2*2", 7), make_tuple(" 3/2 ", 1),
                    make_tuple(" 3+5 / 2 ", 5), make_tuple("2*3+4", 10),
                    make_tuple("2*3*4", 24), make_tuple("4/3+2", 3),
                    make_tuple(" 3/2 ", 1)));
