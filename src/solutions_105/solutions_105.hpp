#pragma once

#include <unordered_map>

#include "../lib/binary_tree.hpp"

class Solution {
 public:
  TreeNode* buildTree(std::vector<int>& preorder, std::vector<int>& inorder) {
    std::unordered_map<int, int> inorder_indexes_map;

    for (size_t i = 0; i < inorder.size(); i++) {
      inorder_indexes_map[inorder[i]] = i;
    }

    size_t current_index = 0;

    return helper(inorder_indexes_map, current_index, 0, preorder.size() - 1,
                  preorder, inorder);
  }

 private:
  TreeNode* helper(std::unordered_map<int, int>& inorder_indexes_map,
                   size_t& current_index, int left, int right,
                   std::vector<int>& preorder, std::vector<int>& inorder) {
    if (left > right) {
      return nullptr;
    }
    if (current_index >= preorder.size()) return nullptr;

    int val = preorder[current_index];
    int split_index = inorder_indexes_map[val];

    current_index++;

    TreeNode* new_node =
        new TreeNode(val,
                     helper(inorder_indexes_map, current_index, left,
                            split_index - 1, preorder, inorder),
                     helper(inorder_indexes_map, current_index, split_index + 1,
                            right, preorder, inorder));

    return new_node;
  }
};
