#include "solutions_3597.hpp"

#include <gtest/gtest.h>

#include <tuple>

using std::make_tuple;
using std::tuple;

class Solutions_3597_Test
    : public testing::TestWithParam<tuple<string, vector<string>>> {
   protected:
    Solution solutions;
};

TEST_P(Solutions_3597_Test, ) {
    auto [s, expected] = GetParam();

    auto actual = solutions.partitionString(s);

    EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_3597_Test,
    testing::Values(make_tuple("abbccccd",
                               vector<string>{"a", "b", "bc", "c", "cc", "d"}),
                    make_tuple("aaaa", vector<string>{"a", "aa"})));
