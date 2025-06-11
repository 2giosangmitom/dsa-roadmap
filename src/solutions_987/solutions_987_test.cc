#include "solutions_987.hpp"

#include <gtest/gtest.h>

#include <tuple>

class Solutions_987_Test
    : public testing::TestWithParam<
          std::tuple<std::vector<std::any>, std::vector<std::vector<int>>>> {
   protected:
    Solution solutions;
};

TEST_P(Solutions_987_Test, ) {
    auto [tree_vals, expected] = GetParam();
    auto root = make_tree(tree_vals);

    auto actual = solutions.verticalTraversal(root);

    EXPECT_EQ(actual, expected);

    delete_tree(root);
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_987_Test,
    testing::Values(
        std::make_tuple(std::vector<std::any>{3, 9, 20, nullptr, nullptr, 15,
                                              7},
                        std::vector<std::vector<int>>{{9}, {3, 15}, {20}, {7}}),
        std::make_tuple(std::vector<std::any>{1, 2, 3, 4, 5, 6, 7},
                        std::vector<std::vector<int>>{
                            {4}, {2}, {1, 5, 6}, {3}, {7}}),
        std::make_tuple(std::vector<std::any>{1, 2, 3, 4, 6, 5, 7},
                        std::vector<std::vector<int>>{
                            {4}, {2}, {1, 5, 6}, {3}, {7}}),
        std::make_tuple(
            std::vector<std::any>{3, 9, 20, nullptr, nullptr, 15, 13, 24, 11,
                                  nullptr, 3, 1, 2, 3},
            std::vector<std::vector<int>>{
                {1}, {9, 24}, {3, 15, 2, 3}, {20, 11}, {13}, {3}})));
