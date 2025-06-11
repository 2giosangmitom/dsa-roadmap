#include "solutions_104.hpp"

#include <gtest/gtest.h>

class Solutions_104_Test
    : public testing::TestWithParam<std::tuple<std::vector<std::any>, int>> {
   protected:
    Solution solutions;
};

TEST_P(Solutions_104_Test, ) {
    auto [tree_vals, expected] = GetParam();

    auto root = make_tree(tree_vals);
    auto actual = solutions.maxDepth(root);

    EXPECT_EQ(actual, expected);

    delete_tree(root);
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_104_Test,
    testing::Values(
        std::make_tuple(std::vector<std::any>{}, 0),
        std::make_tuple(std::vector<std::any>{1}, 1),
        std::make_tuple(std::vector<std::any>{1, 2, 3}, 2),
        std::make_tuple(std::vector<std::any>{1, nullptr, 2, nullptr, 3}, 3),
        std::make_tuple(std::vector<std::any>{1, 2, nullptr, 3}, 3),
        std::make_tuple(
            std::vector<std::any>{3, 9, 20, nullptr, nullptr, 15, 7}, 3),
        std::make_tuple(std::vector<std::any>{1, 2, 3, 4, 5, nullptr, 8,
                                              nullptr, nullptr, 6, 7, 9},
                        4)));
