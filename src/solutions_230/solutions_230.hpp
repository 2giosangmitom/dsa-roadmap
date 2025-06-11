#pragma once

#include <stack>
#include <vector>

#include "../lib/binary_tree.hpp"

class Solution {
   public:
    int kthSmallest(TreeNode* root, int k) {
        std::vector<int> vals;
        inorder(root, vals);

        return vals[k - 1];
    }

    int kthSmallest2(TreeNode* root, int k) {
        std::stack<TreeNode*> stack;
        auto node = root;

        while (node != nullptr || !stack.empty()) {
            while (node) {
                stack.push(node);
                node = node->left;
            }

            node = stack.top();
            stack.pop();
            k--;

            if (k == 0) return node->val;

            node = node->right;
        }

        return 0;
    }

   private:
    void inorder(TreeNode* root, std::vector<int>& vals) {
        if (!root) {
            return;
        }

        inorder(root->left, vals);
        vals.push_back(root->val);
        inorder(root->right, vals);
    }
};
