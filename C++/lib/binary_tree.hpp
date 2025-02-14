#pragma once

#include <any>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode();
  TreeNode(int x);
  TreeNode(int x, TreeNode *left, TreeNode *right);

  // Create a binary tree from a list
  static TreeNode *from(const vector<any> &vals);
};

// Overload equality operator
bool operator==(const TreeNode &root1, const TreeNode &root2);

// Delete a binary from root
void free_tree(TreeNode *root);
