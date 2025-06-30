#include "solutions_55.hpp"

#include <gtest/gtest.h>

#include <tuple>

using std::make_tuple;
using std::tuple;

class Solutions_55_Test
    : public testing::TestWithParam<tuple<vector<int>, bool>> {
   protected:
    Solution solutions;
};

TEST_P(Solutions_55_Test, ) {
    auto [nums, expected] = GetParam();

    auto actual = solutions.canJump(nums);

    EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_55_Test,
    testing::Values(make_tuple(vector<int>{2, 3, 1, 1, 4}, true),
                    make_tuple(vector<int>{3, 2, 1, 0, 4}, false)));
