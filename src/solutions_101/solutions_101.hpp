#pragma once

#include <queue>

#include "../lib/binary_tree.hpp"

class Solution {
 public:
  /**
   * @brief Checks if a binary tree is symmetric using depth-first search (DFS).
   * @param root Pointer to the root of the binary tree.
   * @return True if the tree is symmetric, false otherwise.
   */
  bool isSymmetric(TreeNode* root) {
    return helper_dfs(root->left, root->right);
  }

  /**
   * @brief Checks if a binary tree is symmetric using breadth-first search (BFS).
   * @param root Pointer to the root of the binary tree.
   * @return True if the tree is symmetric, false otherwise.
   */
  bool isSymmetric2(TreeNode* root) {
    std::queue<TreeNode*> q;
    q.push(root->left);
    q.push(root->right);

    while (!q.empty()) {
      auto left = q.front();
      q.pop();
      auto right = q.front();
      q.pop();

      if (!left && !right) {
        continue;
      }

      if ((!left || !right) || (left->val != right->val)) {
        return false;
      }

      q.push(left->left);
      q.push(right->right);
      q.push(left->right);
      q.push(right->left);
    }

    return true;
  }

 private:
  /**
   * @brief Helper function to check if two subtrees are symmetric using DFS.
   * @param A Pointer to the root of the first subtree.
   * @param B Pointer to the root of the second subtree.
   * @return True if the subtrees are symmetric, false otherwise.
   */
  bool helper_dfs(TreeNode* A, TreeNode* B) {
    if (!A && !B) {
      return true;
    }

    if ((!A || !B) || (A->val != B->val)) {
      return false;
    }

    return helper_dfs(A->left, B->right) && helper_dfs(A->right, B->left);
  }
};
