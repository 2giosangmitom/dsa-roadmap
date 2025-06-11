#pragma once

#include <vector>

#include "../lib/binary_tree.hpp"

class Solution {
   public:
    std::vector<int> inorderTraversal(TreeNode *root) {
        std::vector<int> result;
        traverse(root, result);
        return result;
    }

    void traverse(TreeNode *root, std::vector<int> &result) {
        if (root) {
            traverse(root->left, result);
            result.push_back(root->val);
            traverse(root->right, result);
        }
    }
};
