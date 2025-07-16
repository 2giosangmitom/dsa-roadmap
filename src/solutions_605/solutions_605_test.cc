#include "solutions_605.hpp"

#include <gtest/gtest.h>

#include <tuple>

class Solutions_605_Test
    : public testing::TestWithParam<std::tuple<vector<int>, int, bool>> {
   protected:
    Solution solution;
};

TEST_P(Solutions_605_Test, ) {
    auto [flowerbed, n, expected] = GetParam();

    auto actual = solution.canPlaceFlowers(flowerbed, n);

    EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_605_Test,
    testing::Values(std::make_tuple(vector<int>{1, 0, 0, 0, 1}, 1, true),
                    std::make_tuple(vector<int>{1, 0, 0, 0, 1}, 2, false),
                    std::make_tuple(vector<int>{1, 0, 0, 0, 0, 1}, 1, true)));