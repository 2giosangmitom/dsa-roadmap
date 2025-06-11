#include "solutions_92.hpp"

#include <gtest/gtest.h>

#include <tuple>

class Solutions_92_Test
    : public testing::TestWithParam<
          std::tuple<std::vector<int>, int, int, std::vector<int>>> {
   protected:
    Solution solutions;
};

TEST_P(Solutions_92_Test, ) {
    auto [list_vals, left, right, expected_vals] = GetParam();
    auto head = make_list(list_vals);
    auto expected = make_list(expected_vals);

    auto actual = solutions.reverseBetween(head, left, right);

    EXPECT_EQ(*actual, *expected);
    delete_list({actual, expected});
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_92_Test,
    testing::Values(std::make_tuple(std::vector<int>{1, 2, 3, 4, 5}, 2, 4,
                                    std::vector<int>{1, 4, 3, 2, 5}),
                    std::make_tuple(std::vector<int>{5}, 1, 1,
                                    std::vector<int>{5})));
