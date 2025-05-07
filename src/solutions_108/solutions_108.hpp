#pragma once

#include <vector>

#include "../lib/binary_tree.hpp"

class Solution {
 private:
  /**
   * @brief Helper function to convert a sorted array to a balanced BST.
   * @param nums Vector of integers representing the sorted array.
   * @param left Left boundary of the current subarray.
   * @param right Right boundary of the current subarray.
   * @return Pointer to the root of the constructed subtree.
   */
  TreeNode* helper(std::vector<int>& nums, int left, int right) {
    if (left > right) return nullptr;

    // Find the middle element of the current subarray
    auto mid = (left + right) / 2;
    // Create a new node with the middle element
    auto root = new TreeNode(nums[mid]);

    // Recursively construct the left and right subtrees
    root->left = helper(nums, left, mid - 1);
    root->right = helper(nums, mid + 1, right);

    return root;
  }

 public:
  /**
   * @brief Converts a sorted array to a balanced binary search tree (BST).
   * @param nums Vector of integers representing the sorted array.
   * @return Pointer to the root of the constructed BST.
   */
  TreeNode* sortedArrayToBST(std::vector<int>& nums) {
    if (nums.empty()) return nullptr;

    // Call the helper function to construct the BST
    auto root = helper(nums, 0, nums.size() - 1);

    return root;
  }
};
