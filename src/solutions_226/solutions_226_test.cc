#include "solutions_226.hpp"

#include <gtest/gtest.h>

class Solutions_226_Test
    : public testing::TestWithParam<tuple<vector<any>, vector<any>>> {
   protected:
    Solution solutions;
};

TEST_P(Solutions_226_Test, Stack) {
    auto [input, expected] = GetParam();
    auto root = make_tree(input);
    auto expected_tree = make_tree(expected);

    auto actual = solutions.invertTree(root);

    if (actual == nullptr) {
        EXPECT_EQ(actual, expected_tree);
    } else {
        EXPECT_EQ(*actual, *expected_tree);
    }

    delete_tree(root);
    delete_tree(expected_tree);
}

TEST_P(Solutions_226_Test, Recursion) {
    auto [input, expected] = GetParam();
    auto root = make_tree(input);
    auto expected_tree = make_tree(expected);

    auto actual = solutions.invertTree2(root);

    if (actual == nullptr) {
        EXPECT_EQ(actual, expected_tree);
    } else {
        EXPECT_EQ(*actual, *expected_tree);
    }

    delete_tree(root);
    delete_tree(expected_tree);
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_226_Test,
    testing::Values(make_tuple(vector<any>{4, 2, 7, 1, 3, 6, 9},
                               vector<any>{4, 7, 2, 9, 6, 3, 1}),
                    make_tuple(vector<any>{2, 1, 3}, vector<any>{2, 3, 1}),
                    make_tuple(vector<any>{}, vector<any>{})));
