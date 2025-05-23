#pragma once

#include <vector>

#include "../lib/binary_tree.hpp"

class Solution {
 private:
  void helper(std::vector<int>& result, TreeNode* root) {
    if (!root) return;

    result.push_back(root->val);
    helper(result, root->left);
    helper(result, root->right);
  }

 public:
  std::vector<int> preorderTraversal(TreeNode* root) {
    std::vector<int> result;
    helper(result, root);
    return result;
  }
};
