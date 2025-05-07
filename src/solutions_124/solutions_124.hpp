#pragma once

#include <limits>

#include "../lib/binary_tree.hpp"

class Solution {
 public:
  /**
   * @brief Finds the maximum path sum in a binary tree.
   * @param root Pointer to the root of the binary tree.
   * @return The maximum path sum.
   */
  int maxPathSum(TreeNode* root) {
    int result = std::numeric_limits<int>::min();
    helper(result, root);
    return result;
  }

 private:
  /**
   * @brief Helper function to calculate the maximum path sum.
   * @param result Reference to the variable storing the maximum path sum.
   * @param root Pointer to the current node in the binary tree.
   * @return The maximum path sum including the current node.
   */
  int helper(int& result, TreeNode* root) {
    if (!root) return 0;

    // Calculate the maximum path sum for the left and right subtrees
    int left_sum = std::max(helper(result, root->left), 0);
    int right_sum = std::max(helper(result, root->right), 0);

    // Update the result with the maximum path sum including the current node
    result = std::max(result, root->val + left_sum + right_sum);

    // Return the maximum path sum including the current node
    return root->val + std::max(left_sum, right_sum);
  }
};
