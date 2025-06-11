#include "solutions_105.hpp"

#include <gtest/gtest.h>

#include <any>
#include <tuple>
#include <vector>

class Solutions_105_Test
    : public testing::TestWithParam<std::tuple<
          std::vector<int>, std::vector<int>, std::vector<std::any>>> {
   protected:
    Solution solutions;
};

TEST_P(Solutions_105_Test, ) {
    auto [preorder, inorder, expected] = GetParam();
    auto expected_tree = make_tree(expected);

    auto actual = solutions.buildTree(preorder, inorder);

    if (actual == nullptr) {
        EXPECT_EQ(expected_tree, nullptr);
    } else {
        EXPECT_EQ(*actual, *expected_tree);
    }

    delete_tree(actual);
    delete_tree(expected_tree);
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_105_Test,
    testing::Values(std::make_tuple(std::vector<int>{3, 9, 20, 15, 7},
                                    std::vector<int>{9, 3, 15, 20, 7},
                                    std::vector<std::any>{3, 9, 20, nullptr,
                                                          nullptr, 15, 7}),
                    std::make_tuple(std::vector<int>{5, 9, 2, 3, 4, 7},
                                    std::vector<int>{2, 9, 5, 4, 3, 7},
                                    std::vector<std::any>{5, 9, 3, 2, nullptr,
                                                          4, 7})));
