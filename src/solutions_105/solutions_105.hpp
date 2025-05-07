#pragma once

#include <unordered_map>

#include "../lib/binary_tree.hpp"

class Solution {
 public:
  /**
   * @brief Builds a binary tree from preorder and inorder traversal vectors.
   * @param preorder Vector of integers representing the preorder traversal of the tree.
   * @param inorder Vector of integers representing the inorder traversal of the tree.
   * @return Pointer to the root of the constructed binary tree.
   */
  TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
    std::unordered_map<int, int> inorder_indexes_map;

    // Create a map to store the index of each value in the inorder vector
    for (size_t i = 0; i < inorder.size(); i++) {
      inorder_indexes_map[inorder[i]] = i;
    }

    size_t current_index = 0;

    // Call the helper function to construct the tree
    return helper(inorder_indexes_map, current_index, 0, preorder.size() - 1,
                  preorder, inorder);
  }

 private:
  /**
   * @brief Helper function to construct the binary tree.
   * @param inorder_indexes_map Map of values to their indices in the inorder vector.
   * @param current_index Reference to the current index in the preorder vector.
   * @param left Left boundary of the current subtree in the inorder vector.
   * @param right Right boundary of the current subtree in the inorder vector.
   * @param preorder Vector of integers representing the preorder traversal of the tree.
   * @param inorder Vector of integers representing the inorder traversal of the tree.
   * @return Pointer to the root of the constructed subtree.
   */
  TreeNode* helper(std::unordered_map<int, int>& inorder_indexes_map,
                   size_t& current_index, int left, int right,
                   std::vector<int>& preorder, std::vector<int>& inorder) {
    // Base case: if the left boundary exceeds the right boundary, return nullptr
    if (left > right) {
      return nullptr;
    }
    if (current_index >= preorder.size()) return nullptr;

    // Get the value of the current node from the preorder vector
    int val = preorder[current_index];
    // Find the index of the current node in the inorder vector
    int split_index = inorder_indexes_map[val];

    current_index++;

    // Create a new node with the current value and recursively construct the left and right subtrees
    TreeNode* new_node =
        new TreeNode(val,
                     helper(inorder_indexes_map, current_index, left,
                            split_index - 1, preorder, inorder),
                     helper(inorder_indexes_map, current_index, split_index + 1,
                            right, preorder, inorder));

    return new_node;
  }
};
