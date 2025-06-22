#include "solutions_198.hpp"

#include <gtest/gtest.h>

using std::make_tuple;
using std::tuple;

class Solutions_198_Test
    : public testing::TestWithParam<tuple<vector<int>, int>> {
   protected:
    Solution solutions;
};

TEST_P(Solutions_198_Test, ) {
    auto [nums, expected] = GetParam();

    auto actual = solutions.rob(nums);

    EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(, Solutions_198_Test,
                         testing::Values(make_tuple(vector<int>{1, 2, 3, 1}, 4),
                                         make_tuple(vector<int>{2, 7, 9, 3, 1},
                                                    12)));
