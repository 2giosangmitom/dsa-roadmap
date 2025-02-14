#include "../src/same_tree.hpp"
#include <gtest/gtest.h>

class SameTreeTest : public testing::Test {
protected:
  Solution s;
};

TEST_F(SameTreeTest, case1) {
  TreeNode *p = TreeNode::from({1, 2, 3});
  TreeNode *q = TreeNode::from({1, 2, 3});
  bool expected = true;

  bool actual = s.isSameTree(p, q);

  EXPECT_EQ(actual, expected);

  free_tree(p);
  free_tree(q);
}

TEST_F(SameTreeTest, case2) {
  TreeNode *p = TreeNode::from({1, 2});
  TreeNode *q = TreeNode::from({1, nullptr, 2});
  bool expected = false;

  bool actual = s.isSameTree(p, q);

  EXPECT_EQ(actual, expected);

  free_tree(p);
  free_tree(q);
}

TEST_F(SameTreeTest, case3) {
  TreeNode *p = TreeNode::from({1, 2, 1});
  TreeNode *q = TreeNode::from({1, 1, 2});
  bool expected = false;

  bool actual = s.isSameTree(p, q);

  EXPECT_EQ(actual, expected);

  free_tree(p);
  free_tree(q);
}

TEST_F(SameTreeTest, case4) {
  TreeNode *p = nullptr;
  TreeNode *q = nullptr;
  bool expected = true;

  bool actual = s.isSameTree(p, q);

  EXPECT_EQ(actual, expected);
}

TEST_F(SameTreeTest, case5) {
  TreeNode *p = nullptr;
  TreeNode *q = TreeNode::from({0});
  bool expected = false;

  bool actual = s.isSameTree(p, q);

  EXPECT_EQ(actual, expected);

  free_tree(q);
}

TEST_F(SameTreeTest, case6) {
  TreeNode *p = TreeNode::from({1, 2, 3, 4, 5, 6, 7});
  TreeNode *q = TreeNode::from({1, 2, 3, 4, 5, 6, 7});
  bool expected = true;

  bool actual = s.isSameTree(p, q);

  EXPECT_EQ(actual, expected);

  free_tree(p);
  free_tree(q);
}

TEST_F(SameTreeTest, case7) {
  TreeNode *p = TreeNode::from({1, 2, 3, 4, 5, 6, 7});
  TreeNode *q = TreeNode::from({1, 2, 3, 4, 5, 6, 8});
  bool expected = false;

  bool actual = s.isSameTree(p, q);

  EXPECT_EQ(actual, expected);

  free_tree(p);
  free_tree(q);
}
