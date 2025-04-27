#pragma once

#include <limits>

#include "../lib/binary_tree.hpp"

class Solution {
 public:
  int maxPathSum(TreeNode* root) {
    int result = std::numeric_limits<int>::min();
    helper(result, root);
    return result;
  }

 private:
  int helper(int& result, TreeNode* root) {
    if (!root) return 0;

    int left_sum = std::max(helper(result, root->left), 0);
    int right_sum = std::max(helper(result, root->right), 0);

    result = std::max(result, root->val + left_sum + right_sum);

    return root->val + std::max(left_sum, right_sum);
  }
};
