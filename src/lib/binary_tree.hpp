#pragma once

#include <any>
#include <vector>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;

  // Constructors
  TreeNode();
  TreeNode(int x);
  TreeNode(int x, TreeNode *left, TreeNode *right);

  // Destructor
  ~TreeNode();
};

// Factory function to create a binary tree using level-order traversal
TreeNode *make_tree(const vector<any> &values);

// Overload equality operator
bool operator==(const TreeNode &lhs, const TreeNode &rhs);
