#include "solutions_24.hpp"

#include <gtest/gtest.h>

class Solutions_24_Test : public testing::TestWithParam<
                              std::tuple<std::vector<int>, std::vector<int>>> {
   public:
    Solution solutions;
};

TEST_P(Solutions_24_Test, swapPairs) {
    auto [head_vals, expected_vals] = GetParam();
    auto head = make_list(head_vals);
    auto expected = make_list(expected_vals);

    auto actual = solutions.swapPairs(head);

    if (!actual) {
        EXPECT_EQ(expected, nullptr);
    } else {
        EXPECT_EQ(*actual, *expected);
        delete_list({actual, expected});
    }
}

TEST_P(Solutions_24_Test, swapPairs2) {
    auto [head_vals, expected_vals] = GetParam();
    auto head = make_list(head_vals);
    auto expected = make_list(expected_vals);

    auto actual = solutions.swapPairs2(head);

    if (!actual) {
        EXPECT_EQ(expected, nullptr);
    } else {
        EXPECT_EQ(*actual, *expected);
        delete_list({actual, expected});
    }
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_24_Test,
    testing::Values(std::make_tuple(std::vector<int>{1, 2, 3, 4},
                                    std::vector<int>{2, 1, 4, 3}),
                    std::make_tuple(std::vector<int>{1, 2, 3},
                                    std::vector<int>{2, 1, 3})

                        ));
