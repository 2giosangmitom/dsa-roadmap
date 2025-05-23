#pragma once

#include <vector>

#include "../lib/binary_tree.hpp"

class Solution {
 private:
  void helper(std::vector<int>& result, TreeNode* root) {
    if (!root) return;

    helper(result, root->left);
    helper(result, root->right);
    result.push_back(root->val);
  }

 public:
  std::vector<int> postorderTraversal(TreeNode* root) {
    std::vector<int> result;
    helper(result, root);
    return result;
  }
};
