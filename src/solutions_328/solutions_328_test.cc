#include "solutions_328.hpp"

#include <gtest/gtest.h>

#include <tuple>

class Solutions_328_Test : public testing::TestWithParam<
                               std::tuple<std::vector<int>, std::vector<int>>> {
   protected:
    Solution solutions;
};

TEST_P(Solutions_328_Test, ) {
    auto [head_vals, expected_vals] = GetParam();
    auto head = make_list(head_vals);
    auto expected = make_list(expected_vals);

    auto actual = solutions.oddEvenList(head);

    EXPECT_EQ(*actual, *expected);
    delete_list({actual, expected});
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_328_Test,
    testing::Values(std::make_tuple(std::vector<int>{2, 1, 3, 5, 6, 4, 7},
                                    std::vector<int>{2, 3, 6, 7, 1, 5, 4}),
                    std::make_tuple(std::vector<int>{1, 2, 3, 4, 5},
                                    std::vector<int>{1, 3, 5, 2, 4})));
