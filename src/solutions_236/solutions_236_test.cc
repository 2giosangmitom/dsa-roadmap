#include "solutions_236.hpp"
#include <gtest/gtest.h>

class Solutions_236_Test : public testing::Test {
protected:
  Solution solutions;
};

TEST_F(Solutions_236_Test, case1) {
  auto root = make_tree({3, 5, 1, 6, 2, 0, 8, nullptr, nullptr, 7, 4});
  auto p = root->left;
  auto q = root->right;

  auto actual = solutions.lowestCommonAncestor(root, p, q);
  EXPECT_EQ(actual, root);

  delete_tree(root);
}

TEST_F(Solutions_236_Test, case2) {
  auto root = make_tree({3, 5, 1, 6, 2, 0, 8, nullptr, nullptr, 7, 4});
  auto p = root->left;
  auto q = root->left->right->right;

  auto actual = solutions.lowestCommonAncestor(root, p, q);
  EXPECT_EQ(actual, p);

  delete_tree(root);
}

TEST_F(Solutions_236_Test, case3) {
  auto root = make_tree({1, 2});
  auto p = root;
  auto q = root->left;

  auto actual = solutions.lowestCommonAncestor(root, p, q);
  EXPECT_EQ(actual, root);

  delete_tree(root);
}
