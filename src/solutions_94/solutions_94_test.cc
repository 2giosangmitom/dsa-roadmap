#include "solutions_94.hpp"

#include <gtest/gtest.h>

#include <any>

class Solutions_94_Test
    : public testing::TestWithParam<
          std::tuple<std::vector<std::any>, std::vector<int>>> {
   protected:
    Solution solutions;
};

TEST_P(Solutions_94_Test, ) {
    auto [tree_vals, expected] = GetParam();

    auto root = make_tree(tree_vals);
    auto actual = solutions.inorderTraversal(root);

    EXPECT_EQ(actual, expected);

    delete_tree(root);
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_94_Test,
    testing::Values(
        std::make_tuple(std::vector<std::any>{1, nullptr, 2, 3},
                        std::vector<int>{1, 3, 2}),
        std::make_tuple(std::vector<std::any>{1, 2, 3, 4, 5, nullptr, 8,
                                              nullptr, nullptr, 6, 7, 9},
                        std::vector<int>{4, 2, 6, 5, 7, 1, 3, 9, 8}),
        std::make_tuple(std::vector<std::any>{}, std::vector<int>{}),
        std::make_tuple(std::vector<std::any>{1}, std::vector<int>{1}),
        std::make_tuple(std::vector<std::any>{1, 2, nullptr, 3},
                        std::vector<int>{3, 2, 1}),
        std::make_tuple(std::vector<std::any>{1, nullptr, 2, nullptr, 3},
                        std::vector<int>{1, 2, 3}),
        std::make_tuple(std::vector<std::any>{1, 2, 3},
                        std::vector<int>{2, 1, 3})));
