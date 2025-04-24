#pragma once

#include "../lib/binary_tree.hpp"
#include <stack>
using namespace std;

class Solution {
public:
  TreeNode *invertTree(TreeNode *root) {
    if (root == nullptr)
      return nullptr;

    stack<TreeNode *> stack;
    stack.push(root);

    while (!stack.empty()) {
      auto top = stack.top();
      stack.pop();

      swap(top->left, top->right);

      if (top->left != nullptr) {
        stack.push(top->left);
      }
      if (top->right != nullptr) {
        stack.push(top->right);
      }
    }

    return root;
  }
};
