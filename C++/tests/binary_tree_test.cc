#include "../lib/binary_tree.hpp"
#include <gtest/gtest.h>

TEST(BinaryTreeTest, from_method_case1) {
  TreeNode *root = TreeNode::from({1, 2, 3});
  TreeNode *expected = new TreeNode(1, new TreeNode(2), new TreeNode(3));

  EXPECT_EQ(*root, *expected);

  free_tree(root);
  free_tree(expected);
}

TEST(BinaryTreeTest, from_method_case2) {
  TreeNode *root = TreeNode::from({1, 2, 3, 4});
  TreeNode *expected = new TreeNode(
      1, new TreeNode(2, new TreeNode(4), nullptr), new TreeNode(3));

  EXPECT_EQ(*root, *expected);

  free_tree(root);
  free_tree(expected);
}

TEST(BinaryTreeTest, from_method_case3) {
  TreeNode *root = TreeNode::from({1, 2, 3, 4, 5, 6, 7});
  TreeNode *expected =
      new TreeNode(1, new TreeNode(2, new TreeNode(4), new TreeNode(5)),
                   new TreeNode(3, new TreeNode(6), new TreeNode(7)));

  EXPECT_EQ(*root, *expected);

  free_tree(root);
  free_tree(expected);
}

TEST(BinaryTreeTest, from_method_case4) {
  TreeNode *root = TreeNode::from({1, 2, nullptr, 3, nullptr, 4});
  TreeNode *expected = new TreeNode(
      1, new TreeNode(2, new TreeNode(3, new TreeNode(4), nullptr), nullptr),
      nullptr);

  EXPECT_EQ(*root, *expected);

  free_tree(root);
  free_tree(expected);
}

TEST(BinaryTreeTest, from_method_case5) {
  TreeNode *root = TreeNode::from({1, nullptr, 2, nullptr, 3, nullptr, 4});
  TreeNode *expected = new TreeNode(
      1, nullptr,
      new TreeNode(2, nullptr, new TreeNode(3, nullptr, new TreeNode(4))));

  EXPECT_EQ(*root, *expected);

  free_tree(root);
  free_tree(expected);
}

TEST(BinaryTreeTest, from_method_case6) {
  TreeNode *root = TreeNode::from({1, 2, 3, nullptr, 5, 6});
  TreeNode *expected =
      new TreeNode(1, new TreeNode(2, nullptr, new TreeNode(5)),
                   new TreeNode(3, new TreeNode(6), nullptr));

  EXPECT_EQ(*root, *expected);

  free_tree(root);
  free_tree(expected);
}

TEST(BinaryTreeTest, from_method_case7) {
  TreeNode *root = TreeNode::from({});
  EXPECT_EQ(root, nullptr);
}

TEST(BinaryTreeTest, from_method_case8) {
  TreeNode *root = TreeNode::from({1});
  TreeNode *expected = new TreeNode(1);

  EXPECT_EQ(*root, *expected);

  free_tree(root);
  free_tree(expected);
}
