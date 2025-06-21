#pragma once

#include <stack>

#include "../lib/binary_tree.hpp"
using namespace std;

class Solution {
   private:
    void helper(TreeNode *root) {
        if (!root) {
            return;
        }

        swap(root->left, root->right);

        helper(root->left);
        helper(root->right);
    }

   public:
    TreeNode *invertTree(TreeNode *root) {
        if (root == nullptr) return nullptr;

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

    TreeNode *invertTree2(TreeNode *root) {
        helper(root);

        return root;
    }
};
