#include "binary_tree.hpp"
#include <queue>
#include <stack>

TreeNode::TreeNode() : val(0), left(nullptr), right(nullptr) {}
TreeNode::TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
TreeNode::TreeNode(int x, TreeNode *left, TreeNode *right)
    : val(x), left(left), right(right) {}

// Create a binary tree from a list
TreeNode *TreeNode::from(const vector<any> &vals) {
  size_t length = vals.size();

  if (length == 0)
    return nullptr;

  if (length == 1) {
    const int *val = any_cast<int>(&vals[0]);

    if (!val) {
      return nullptr;
    }

    return new TreeNode(*any_cast<int>(&vals[0]));
  }

  TreeNode *root = new TreeNode(*any_cast<int>(&vals[0]));

  queue<TreeNode *> nodes;
  nodes.push(root);

  size_t i = 1;
  while (i < length) {
    TreeNode *parent = nodes.front();
    nodes.pop();

    const int *left_val = any_cast<int>(&vals[i]);
    if (left_val) {
      TreeNode *new_node = new TreeNode(*left_val);
      parent->left = new_node;
      nodes.push(new_node);
    }

    i++;
    if (i < length) {
      const int *right_val = any_cast<int>(&vals[i]);
      if (right_val != nullptr) {
        TreeNode *new_node = new TreeNode(*right_val);
        parent->right = new_node;
        nodes.push(new_node);
      }
    }
    i++;
  }

  return root;
}

// Delete a binary from root
void free_tree(TreeNode *root) {
  stack<TreeNode *> nodes;
  nodes.push(root);

  while (!nodes.empty()) {
    TreeNode *current = nodes.top();
    nodes.pop();

    if (current->left) {
      nodes.push(current->left);
    }
    if (current->right) {
      nodes.push(current->right);
    }

    delete current;
  }
}

// Overload equality operator
bool operator==(const TreeNode &root1, const TreeNode &root2) {
  queue<const TreeNode *> nodes1;
  queue<const TreeNode *> nodes2;

  nodes1.push(&root1);
  nodes2.push(&root2);

  while (!nodes1.empty() && !nodes2.empty()) {
    const TreeNode *current_1 = nodes1.front();
    const TreeNode *current_2 = nodes2.front();
    nodes1.pop();
    nodes2.pop();

    // If both nodes are nullptr, it's equal
    if (current_1 == nullptr && current_2 == nullptr) {
      continue;
    }

    // If one in two node are nullptr return false
    if (!current_1 || !current_2) {
      return false;
    }

    // Compare values
    if (current_1->val != current_2->val) {
      return false;
    }

    nodes1.push(current_1->left);
    nodes2.push(current_2->left);
    nodes1.push(current_1->right);
    nodes2.push(current_2->right);
  }

  return true;
}
