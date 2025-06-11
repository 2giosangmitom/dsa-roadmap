
#include "solutions_145.hpp"

#include <gtest/gtest.h>

class Solutions_145_Test
    : public testing::TestWithParam<
          std::tuple<std::vector<std::any>, std::vector<int>>> {
   protected:
    Solution solutions;
};

TEST_P(Solutions_145_Test, ) {
    auto [root_vals, expected] = GetParam();

    auto root = make_tree(root_vals);
    auto actual = solutions.postorderTraversal(root);

    EXPECT_EQ(actual, expected);
    delete_tree(root);
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_145_Test,
    testing::Values(
        std::make_tuple(std::vector<std::any>{1, nullptr, 2, 3},
                        std::vector<int>{3, 2, 1}),
        std::make_tuple(std::vector<std::any>{1, 2, 3, 4, 5, nullptr, 8,
                                              nullptr, nullptr, 6, 7, 9},
                        std::vector<int>{4, 6, 7, 5, 2, 9, 8, 3, 1})));
