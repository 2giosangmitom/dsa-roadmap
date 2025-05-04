#include "solutions_297.hpp"

#include <gtest/gtest.h>

#include <any>

class Solutions_297_Test
    : public testing::TestWithParam<std::vector<std::any> > {
 protected:
  Codec solutions;
};

TEST_P(Solutions_297_Test, ) {
  auto tree_vals = GetParam();
  auto root = make_tree(tree_vals);

  auto actual = solutions.deserialize(solutions.serialize(root));

  if (actual == nullptr) {
    EXPECT_TRUE(root == nullptr);
  } else {
    EXPECT_EQ(*actual, *root);
  }

  delete_tree(actual);
  delete_tree(root);
}

INSTANTIATE_TEST_SUITE_P(, Solutions_297_Test,
                         testing::Values(std::vector<std::any>{1, 2, 3, nullptr,
                                                               nullptr, 4, 5},
                                         std::vector<std::any>{}));
