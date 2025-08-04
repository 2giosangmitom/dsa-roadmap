#include "solutions_190.hpp"

#include <gtest/gtest.h>

#include <tuple>

class Solutions_190_Test : public testing::TestWithParam<std::tuple<int, int>> {
   protected:
    Solution sol;
};

TEST_P(Solutions_190_Test, ReverseBits) {
    int n = std::get<0>(GetParam());
    int expected = std::get<1>(GetParam());
    EXPECT_EQ(sol.reverseBits(n), expected);
}

INSTANTIATE_TEST_SUITE_P(
    Solutions_190, Solutions_190_Test,
    testing::Values(std::make_tuple(43261596, 964176192),
                    std::make_tuple(4294967293, 3221225471),
                    std::make_tuple(0, 0), std::make_tuple(1, 2147483648)));
