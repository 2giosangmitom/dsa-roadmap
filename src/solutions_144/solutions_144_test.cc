#include "solutions_144.hpp"

#include <gtest/gtest.h>

class Solutions_144_Test
    : public testing::TestWithParam<
          std::tuple<std::vector<std::any>, std::vector<int>>> {
   protected:
    Solution solutions;
};

TEST_P(Solutions_144_Test, ) {
    auto [root_vals, expected] = GetParam();

    auto root = make_tree(root_vals);
    auto actual = solutions.preorderTraversal(root);

    EXPECT_EQ(actual, expected);
    delete_tree(root);
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_144_Test,
    testing::Values(
        std::make_tuple(std::vector<std::any>{1, nullptr, 2, 3},
                        std::vector<int>{1, 2, 3}),
        std::make_tuple(std::vector<std::any>{1, 2, 3, 4, 5, nullptr, 8,
                                              nullptr, nullptr, 6, 7, 9},
                        std::vector<int>{1, 2, 4, 5, 6, 7, 3, 8, 9})));
