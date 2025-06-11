#include "solutions_1952.hpp"

#include <gtest/gtest.h>

#include <tuple>

class Solutions_1952_Test
    : public testing::TestWithParam<std::tuple<int, bool>> {
   protected:
    Solution solutions;
};

TEST_P(Solutions_1952_Test, ) {
    auto [n, expected] = GetParam();

    bool actual = solutions.isThree(n);

    EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(, Solutions_1952_Test,
                         testing::Values(std::make_tuple(2, false),
                                         std::make_tuple(4, true),
                                         std::make_tuple(3, false),
                                         std::make_tuple(14, false),
                                         std::make_tuple(12, false)));