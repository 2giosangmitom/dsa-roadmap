#pragma once

#include <queue>

#include "../lib/binary_tree.hpp"

class Solution {
   public:
    bool isSymmetric(TreeNode* root) {
        return helper_dfs(root->left, root->right);
    }

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
