#include "same_tree.hpp"

bool Solution::isSameTree(TreeNode *p, TreeNode *q) {
  // If both nodes are nullptr, it's equal
  if (p == nullptr && q == nullptr) {
    return true;
  }

  // If one in two node are nullptr return false
  if (!p || !q) {
    return false;
  }

  // Compare values
  if (p->val != q->val) {
    return false;
  }

  return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}
