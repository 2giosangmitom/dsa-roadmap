#include "solutions_518.hpp"

#include <gtest/gtest.h>

class Solutions_518_Test
    : public testing::TestWithParam<std::tuple<int, std::vector<int>, int>> {
   protected:
    Solution solution;
};

TEST_P(Solutions_518_Test, Change) {
    auto [amount, coins, expected] = GetParam();
    EXPECT_EQ(solution.change(amount, coins), expected);
}

INSTANTIATE_TEST_SUITE_P(
    Solutions_518, Solutions_518_Test,
    testing::Values(std::make_tuple(5, std::vector<int>{1, 2, 5}, 4),
                    std::make_tuple(3, std::vector<int>{2}, 0),
                    std::make_tuple(10, std::vector<int>{10}, 1),
                    std::make_tuple(0, std::vector<int>{1, 2, 5}, 1),
                    std::make_tuple(7, std::vector<int>{1, 3, 4}, 5)));
