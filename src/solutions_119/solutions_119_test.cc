#include "solutions_119.hpp"

#include <gtest/gtest.h>

#include <tuple>

class Solutions_119_Test
    : public testing::TestWithParam<std::tuple<int, std::vector<int>>> {
   protected:
    Solution solutions;
};

TEST_P(Solutions_119_Test, ) {
    auto [rowIndex, expected] = GetParam();

    auto actual = solutions.getRow(rowIndex);

    EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_119_Test,
    testing::Values(std::make_tuple(3, std::vector<int>{1, 3, 3, 1}),
                    std::make_tuple(1, std::vector<int>{1, 1}),
                    std::make_tuple(0, std::vector<int>{1})));
