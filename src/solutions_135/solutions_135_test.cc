#include "solutions_135.hpp"

#include <gtest/gtest.h>

#include <tuple>

using std::tuple;

class Solutions_135_Test
    : public testing::TestWithParam<tuple<vector<int>, int>> {
   protected:
    Solution solutions;
};

TEST_P(Solutions_135_Test, ) {
    auto [ratings, expected] = GetParam();

    auto actual = solutions.candy(ratings);

    EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_135_Test,
    testing::Values(std::make_tuple(vector<int>{1, 0, 2}, 5),
                    std::make_tuple(vector<int>{1, 2, 2}, 4),
                    std::make_tuple(vector<int>{1, 3, 4, 5, 2}, 11)));
