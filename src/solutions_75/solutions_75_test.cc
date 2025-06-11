#include "solutions_75.hpp"

#include <gtest/gtest.h>

#include <tuple>

class Solutions_75_Test : public testing::TestWithParam<
                              std::tuple<std::vector<int>, std::vector<int>>> {
   protected:
    Solution solutions;
};

TEST_P(Solutions_75_Test, ) {
    auto [nums, expected] = GetParam();

    solutions.sortColors(nums);

    EXPECT_EQ(nums, expected);
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_75_Test,
    testing::Values(std::make_tuple(std::vector<int>{2, 0, 2, 1, 1, 0},
                                    std::vector<int>{0, 0, 1, 1, 2, 2}),
                    std::make_tuple(std::vector<int>{2, 0, 1},
                                    std::vector<int>{0, 1, 2})));
