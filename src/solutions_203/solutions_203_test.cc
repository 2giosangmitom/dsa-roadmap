#include "solutions_203.hpp"

#include <gtest/gtest.h>

#include <tuple>

class Solutions_203_Test
    : public testing::TestWithParam<
          std::tuple<std::vector<int>, int, std::vector<int>>> {
   protected:
    Solution solutions;
};

TEST_P(Solutions_203_Test, ) {
    auto [list_vals, val, expected_vals] = GetParam();
    auto head = make_list(list_vals);
    auto expected = make_list(expected_vals);

    auto actual = solutions.removeElements(head, val);

    if (actual == nullptr) {
        EXPECT_TRUE(expected == nullptr);
    } else {
        EXPECT_EQ(*actual, *expected);
    }
    delete_list({actual, expected});
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_203_Test,
    testing::Values(
        std::make_tuple(std::vector<int>{1, 2, 6, 3, 4, 5, 6}, 6,
                        std::vector<int>{1, 2, 3, 4, 5}),
        std::make_tuple(std::vector<int>{7, 7, 7, 7}, 7, std::vector<int>{}),
        std::make_tuple(std::vector<int>{}, 1, std::vector<int>{})));
