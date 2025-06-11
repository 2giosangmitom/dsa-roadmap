#include "solutions_148.hpp"

#include <gtest/gtest.h>

#include <tuple>

class Solutions_148_Test : public testing::TestWithParam<
                               std::tuple<std::vector<int>, std::vector<int>>> {
   protected:
    Solution solutions;
};

TEST_P(Solutions_148_Test, merge_sort) {
    auto [nums, expected] = GetParam();
    auto expected_list = make_list(expected);

    auto actual = solutions.sortList(make_list(nums));

    if (!actual) {
        EXPECT_TRUE(expected_list == nullptr);
    } else {
        EXPECT_EQ(*actual, *expected_list);
    }
    delete_list({actual, expected_list});
}

TEST_P(Solutions_148_Test, insertion_sort) {
    auto [nums, expected] = GetParam();
    auto expected_list = make_list(expected);

    auto actual = solutions.sortList2(make_list(nums));

    if (!actual) {
        EXPECT_TRUE(expected_list == nullptr);
    } else {
        EXPECT_EQ(*actual, *expected_list) << "Actual: " << actual << std::endl
                                           << "Expected: " << expected_list;
    }
    delete_list({actual, expected_list});
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_148_Test,
    testing::Values(make_tuple(std::vector<int>{4, 2, 1, 3},
                               std::vector<int>{1, 2, 3, 4}),
                    make_tuple(std::vector<int>{1, 2, 3, 4, 5},
                               std::vector<int>{1, 2, 3, 4, 5}),
                    make_tuple(std::vector<int>{5, 4, 3, 2, 1},
                               std::vector<int>{1, 2, 3, 4, 5}),
                    make_tuple(std::vector<int>{-1, 5, 3, 4, 0},
                               std::vector<int>{-1, 0, 3, 4, 5})));
