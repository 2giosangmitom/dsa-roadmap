#include "solutions_206.hpp"

#include <gtest/gtest.h>

#include <vector>

struct Tt {
    std::vector<int> head_vals;
    std::vector<int> expected_vals;
};

class Solutions_206_Test : public testing::TestWithParam<Tt> {
   protected:
    Solution solutions;
};

TEST_P(Solutions_206_Test, ) {
    auto [head_vals, expected_vals] = GetParam();
    auto head = make_list(head_vals);
    auto expected = make_list(expected_vals);

    auto actual = solutions.reverseList(head);

    if (actual == nullptr) {
        EXPECT_EQ(expected, nullptr);
    } else {
        EXPECT_EQ(*actual, *expected);
        delete_list({actual, expected});
    }
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_206_Test,
    testing::Values(Tt{std::vector<int>{1, 2, 3, 4, 5},
                       std::vector<int>{5, 4, 3, 2, 1}},
                    Tt{std::vector<int>{1, 2}, std::vector<int>{2, 1}},
                    Tt{std::vector<int>{}, std::vector<int>{}}));
