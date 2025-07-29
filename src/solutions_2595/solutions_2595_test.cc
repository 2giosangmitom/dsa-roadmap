#include "solutions_2595.hpp"

#include <gtest/gtest.h>

#include <tuple>

using std::tuple;

class Solutions_2595_Test
    : public testing::TestWithParam<tuple<int, vector<int>>> {
   protected:
    Solution s;
};

TEST_P(Solutions_2595_Test, ) {
    auto [n, expected] = GetParam();

    auto actual = s.evenOddBit(n);

    EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(, Solutions_2595_Test,
                         testing::Values(std::make_tuple(50, vector<int>{1, 2}),
                                         std::make_tuple(2,
                                                         vector<int>{0, 1})));
