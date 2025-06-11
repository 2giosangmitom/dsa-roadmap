#include "solutions_263.hpp"

#include <gtest/gtest.h>

class Solutions_263_Test
    : public testing::TestWithParam<std::tuple<int, bool>> {
   protected:
    Solution solutions;
};

TEST_P(Solutions_263_Test, ) {
    auto [n, expected] = GetParam();

    bool actual = solutions.isUgly(n);

    EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(, Solutions_263_Test,
                         testing::Values(std::make_tuple(6, true),
                                         std::make_tuple(1, true),
                                         std::make_tuple(14, false),
                                         std::make_tuple(-6, false)));
