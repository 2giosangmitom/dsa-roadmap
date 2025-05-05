#pragma once

#include "../lib/binary_tree.hpp"

class Solution {
 public:
  int minDepth(TreeNode* root) {
    if (!root) return 0;

    bool isLeafNode = !root->left && !root->right;
    if (isLeafNode) {
      return 1;
    }

    int left_depth = minDepth(root->left);
    int right_depth = minDepth(root->right);

    if ((left_depth == 0 || right_depth == 0) && !isLeafNode) {
      return 1 + std::max(left_depth, right_depth);
    }

    return 1 + std::min(left_depth, right_depth);
  }
};
