#pragma once

#include "../lib/binary_tree.hpp"

class Solution {
   public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) {
            return false;
        }

        int curr = targetSum - root->val;
        bool isLeafNode = !root->left && !root->right;
        if (isLeafNode && curr == 0) {
            return true;
        }

        return hasPathSum(root->left, curr) || hasPathSum(root->right, curr);
    }
};
