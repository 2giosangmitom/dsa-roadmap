#pragma once

#include "../lib/binary_tree.hpp"
#include <cstdlib>

class Solution {
private:
  int get_height_imbalanced(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }

    int left_height = get_height_imbalanced(root->left);
    int right_height = get_height_imbalanced(root->right);

    if (abs(left_height - right_height) > 1 || left_height == -1 ||
        right_height == -1) {
      return -1;
    }

    return 1 + std::max(left_height, right_height);
  }

public:
  bool isBalanced(TreeNode *root) { return get_height_imbalanced(root) != -1; }
};
