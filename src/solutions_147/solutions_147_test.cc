#include "solutions_147.hpp"

#include <gtest/gtest.h>

#include <tuple>
#include <vector>

using std::tuple;
using std::vector;

class Solutions_147_Test
    : public testing::TestWithParam<tuple<vector<int>, vector<int>>> {
   protected:
    Solution solutions;
};

TEST_P(Solutions_147_Test, ) {
    auto [nums, expected] = GetParam();
    auto expected_list = make_list(expected);

    auto actual = solutions.insertionSortList(make_list(nums));

    if (!actual) {
        EXPECT_TRUE(expected_list == nullptr);
    } else {
        EXPECT_EQ(*actual, *expected_list);
    }
    delete_list({actual, expected_list});
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_147_Test,
    testing::Values(
        make_tuple(vector<int>{4, 2, 1, 3}, vector<int>{1, 2, 3, 4}),
        make_tuple(vector<int>{1, 2, 3, 4, 5}, vector<int>{1, 2, 3, 4, 5}),
        make_tuple(vector<int>{5, 4, 3, 2, 1}, vector<int>{1, 2, 3, 4, 5}),
        make_tuple(vector<int>{-1, 5, 3, 4, 0}, vector<int>{-1, 0, 3, 4, 5})));
