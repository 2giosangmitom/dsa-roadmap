#include "solutions_238.hpp"

#include <gtest/gtest.h>

#include <tuple>

class Solutions_238_Test
    : public testing::TestWithParam<tuple<vector<int>, vector<int>>> {
   protected:
    Solution solutions;
};

TEST_P(Solutions_238_Test, first) {
    auto [nums, expected] = GetParam();

    auto actual = solutions.productExceptSelf(nums);

    EXPECT_EQ(actual, expected);
}

TEST_P(Solutions_238_Test, second) {
    auto [nums, expected] = GetParam();

    auto actual = solutions.productExceptSelf2(nums);

    EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_238_Test,
    testing::Values(
        make_tuple(vector<int>{1, 2, 3, 4}, vector<int>{24, 12, 8, 6}),
        make_tuple(vector<int>{-1, 1, 0, -3, 3}, vector<int>{0, 0, 9, 0, 0}),
        make_tuple(vector<int>{5}, vector<int>{1}),
        make_tuple(vector<int>{2, 3}, vector<int>{3, 2}),
        make_tuple(vector<int>{1, 1, 1, 1}, vector<int>{1, 1, 1, 1}),
        make_tuple(vector<int>{100, 200, 300},
                   vector<int>{60000, 30000, 20000}),
        make_tuple(vector<int>{-1, -2, -3, -4}, vector<int>{-24, -12, -8, -6}),
        make_tuple(vector<int>{-1, 2, -3, 4}, vector<int>{-24, 12, -8, 6}),
        make_tuple(vector<int>{0, 0, 2, 3}, vector<int>{0, 0, 0, 0}),
        make_tuple(vector<int>{1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
                   vector<int>{3628800, 1814400, 1209600, 907200, 725760,
                               604800, 518400, 453600, 403200, 362880})));
