#include "binary_tree.hpp"
#include <gtest/gtest.h>

// --- Test TreeNode constructors ---
TEST(TreeNodeTest, DefaultConstructor) {
  TreeNode *node = new TreeNode();
  EXPECT_EQ(node->val, 0);
  EXPECT_EQ(node->left, nullptr);
  EXPECT_EQ(node->right, nullptr);
  delete_tree(node);
}

TEST(TreeNodeTest, ValueConstructor) {
  TreeNode *node = new TreeNode(42);
  EXPECT_EQ(node->val, 42);
  EXPECT_EQ(node->left, nullptr);
  EXPECT_EQ(node->right, nullptr);
  delete_tree(node);
}

TEST(TreeNodeTest, FullConstructor) {
  TreeNode *left = new TreeNode(1);
  TreeNode *right = new TreeNode(2);
  TreeNode *node = new TreeNode(3, left, right);
  EXPECT_EQ(node->val, 3);
  EXPECT_EQ(node->left, left);
  EXPECT_EQ(node->right, right);
  delete_tree(node); // safely deletes entire tree
}

// --- Test make_tree function ---
TEST(BinaryTree, MakeTree_Complete) {
  TreeNode *root = make_tree({1, 2, 3, 4, 5, 6, 7});
  TreeNode *expected =
      new TreeNode(1, new TreeNode(2, new TreeNode(4), new TreeNode(5)),
                   new TreeNode(3, new TreeNode(6), new TreeNode(7)));
  EXPECT_EQ(*root, *expected);
  delete_tree(root);
  delete_tree(expected);
}

TEST(BinaryTree, MakeTree_WithNulls) {
  TreeNode *root = make_tree({1, 2, nullptr, 3});
  TreeNode *expected =
      new TreeNode(1, new TreeNode(2, new TreeNode(3), nullptr), nullptr);
  EXPECT_EQ(*root, *expected);
  delete_tree(root);
  delete_tree(expected);
}

TEST(BinaryTree, MakeTree_Empty) {
  TreeNode *root = make_tree({});
  EXPECT_EQ(root, nullptr);
}

// --- Test operator== for structural and value equality ---
TEST(BinaryTree, Equals_SameStructureAndValues) {
  TreeNode *a = make_tree({1, 2, 3});
  TreeNode *b = make_tree({1, 2, 3});
  EXPECT_TRUE(*a == *b);
  delete_tree(a);
  delete_tree(b);
}

TEST(BinaryTree, Equals_DifferentStructure) {
  TreeNode *a = make_tree({1, 2, 3});
  TreeNode *b = make_tree({1, nullptr, 2});
  EXPECT_FALSE(*a == *b);
  delete_tree(a);
  delete_tree(b);
}

TEST(BinaryTree, Equals_DifferentValues) {
  TreeNode *a = make_tree({1, 2, 3});
  TreeNode *b = make_tree({1, 2, 4});
  EXPECT_FALSE(*a == *b);
  delete_tree(a);
  delete_tree(b);
}

TEST(BinaryTree, Equals_DeepEqual) {
  TreeNode *root = make_tree({5, 1, 9, nullptr, 3, 6});
  TreeNode *copy = make_tree({5, 1, 9, nullptr, 3, 6});
  EXPECT_TRUE(*root == *copy);
  delete_tree(root);
  delete_tree(copy);
}
