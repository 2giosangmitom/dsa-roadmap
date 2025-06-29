#pragma once

#include <any>
#include <vector>

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    // Constructors
    TreeNode();
    TreeNode(int x);
    TreeNode(int x, TreeNode *left, TreeNode *right);
};

// Factory function to create a binary tree using level-order traversal
TreeNode *make_tree(const std::vector<std::any> &values);

// Overload equality operator
bool operator==(const TreeNode &lhs, const TreeNode &rhs);

// Release dynamic allocated memories used by the tree
void delete_tree(TreeNode *root);
