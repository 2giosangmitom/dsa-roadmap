#pragma once

#include "../lib/binary_tree.hpp"

class Solution {
   private:
    TreeNode *lca = nullptr;

    bool dfs(TreeNode *&node, TreeNode *&p, TreeNode *&q) {
        if (!node) return false;

        bool node_is_p_or_q = node == p || node == q;
        bool dfs_left = dfs(node->left, p, q);
        bool dfs_right = dfs(node->right, p, q);

        if (node_is_p_or_q + dfs_left + dfs_right == 2) {
            lca = node;
        }

        return node_is_p_or_q || dfs_left || dfs_right;
    }

   public:
    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        dfs(root, p, q);
        return lca;
    }
};
