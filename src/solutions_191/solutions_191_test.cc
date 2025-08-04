#include "solutions_191.hpp"

#include <gtest/gtest.h>

#include <tuple>

class Solutions_191_Test : public testing::TestWithParam<std::tuple<int, int>> {
   protected:
    Solution s;
};

TEST_P(Solutions_191_Test, HammingWeight) {
    int n = std::get<0>(GetParam());
    int expected = std::get<1>(GetParam());

    EXPECT_EQ(s.hammingWeight(n), expected);
}

INSTANTIATE_TEST_SUITE_P(
    Solutions_191, Solutions_191_Test,
    testing::Values(
        std::make_tuple(0, 0), std::make_tuple(1, 1), std::make_tuple(2, 1),
        std::make_tuple(3, 2), std::make_tuple(4, 1), std::make_tuple(5, 2),
        std::make_tuple(6, 2), std::make_tuple(7, 3), std::make_tuple(8, 1),
        std::make_tuple(9, 2), std::make_tuple(10, 2), std::make_tuple(11, 3),
        std::make_tuple(12, 2), std::make_tuple(13, 3), std::make_tuple(14, 3),
        std::make_tuple(15, 4), std::make_tuple(16, 1), std::make_tuple(31, 5),
        std::make_tuple(32, 1), std::make_tuple(33, 2),
        std::make_tuple(2147483647, 31)));
