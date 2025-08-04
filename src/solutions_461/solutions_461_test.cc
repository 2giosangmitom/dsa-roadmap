#include "solutions_461.hpp"

#include <gtest/gtest.h>

#include <tuple>

class Solutions_461_Test
    : public testing::TestWithParam<std::tuple<int, int, int>> {
   protected:
    Solution sol;
};

TEST_P(Solutions_461_Test, hammingDistance) {
    int x, y, expected;
    std::tie(x, y, expected) = GetParam();
    EXPECT_EQ(sol.hammingDistance(x, y), expected);
}

INSTANTIATE_TEST_SUITE_P(Solutions_461_TestSuite, Solutions_461_Test,
                         testing::Values(std::make_tuple(1, 4, 2),
                                         std::make_tuple(3, 1, 1),
                                         std::make_tuple(0, 0, 0),
                                         std::make_tuple(1, 2, 2),
                                         std::make_tuple(4, 5, 1)));
