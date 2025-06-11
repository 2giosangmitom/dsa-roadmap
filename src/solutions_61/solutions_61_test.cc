#include "solutions_61.hpp"

#include <gtest/gtest.h>

class Solutions_61_Test
    : public testing::TestWithParam<
          std::tuple<std::vector<int>, int, std::vector<int>>> {
   protected:
    Solution solutions;
};

TEST_P(Solutions_61_Test, ) {
    auto [head_vals, k, expected_vals] = GetParam();
    auto head = make_list(head_vals);
    auto expected = make_list(expected_vals);

    auto actual = solutions.rotateRight(head, k);

    if (actual == nullptr) {
        EXPECT_TRUE(expected == nullptr);
    } else {
        EXPECT_EQ(*actual, *expected);
        delete_list({actual, expected});
    }
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_61_Test,
    testing::Values(
        std::make_tuple(std::vector<int>{1, 2, 3, 4, 5}, 2,
                        std::vector<int>{4, 5, 1, 2, 3}),
        std::make_tuple(std::vector<int>{0, 1, 2}, 4,
                        std::vector<int>{2, 0, 1}),
        std::make_tuple(std::vector<int>{1, 2, 3, 4, 5, 2, 4, 1, 9, 8}, 123,
                        std::vector<int>{1, 9, 8, 1, 2, 3, 4, 5, 2, 4})));
