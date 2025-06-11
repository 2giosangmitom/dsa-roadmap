#include "solutions_9.hpp"

#include <gtest/gtest.h>

#include <tuple>
using namespace std;

class Solutions_13_Test : public testing::TestWithParam<tuple<int, bool>> {
   protected:
    Solution solution;
};

TEST_P(Solutions_13_Test, ) {
    auto [input, expected] = GetParam();

    bool actual = solution.isPalindrome(input);

    EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_13_Test,
    testing::Values(make_tuple(121, true), make_tuple(1221, true),
                    make_tuple(12321, true), make_tuple(-121, false),
                    make_tuple(-1221, false), make_tuple(123, false),
                    make_tuple(10, false), make_tuple(1231, false),
                    make_tuple(0, true), make_tuple(1, true),
                    make_tuple(9, true), make_tuple(123454321, true),
                    make_tuple(123456789, false), make_tuple(1001, true)));
