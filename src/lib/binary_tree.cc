#include "binary_tree.hpp"
#include <queue>
#include <stack>

// Constructors
TreeNode::TreeNode() : val{0}, left{nullptr}, right{nullptr} {}
TreeNode::TreeNode(int x) : val{x}, left{nullptr}, right{nullptr} {}
TreeNode::TreeNode(int x, TreeNode *left, TreeNode *right)
    : val{x}, left{left}, right{right} {}

// Destructor
TreeNode::~TreeNode() {
  delete left;
  delete right;
}

// Factory function to create a binary tree using level-order traversal
TreeNode *make_tree(const vector<any> &values) {
  if (values.empty())
    return nullptr;

  TreeNode *root = new TreeNode(any_cast<int>(values[0]));
  queue<TreeNode *> queue;
  queue.push(root);

  size_t i = 1;
  while (!queue.empty() && i < values.size()) {
    TreeNode *front = queue.front();
    queue.pop();

    if (i < values.size() && values[i].type() != typeid(nullptr)) {
      front->left = new TreeNode(any_cast<int>(values[i]));
      queue.push(front->left);
    }
    ++i;

    if (i < values.size() && values[i].type() != typeid(nullptr)) {
      front->right = new TreeNode(any_cast<int>(values[i]));
      queue.push(front->right);
    }
    ++i;
  }

  return root;
}

// Overload equality operator
bool operator==(const TreeNode &lhs, const TreeNode &rhs) {
  stack<const TreeNode *> left_stack, right_stack;
  left_stack.push(&lhs);
  right_stack.push(&rhs);

  while (!left_stack.empty() && !right_stack.empty()) {
    const TreeNode *l = left_stack.top();
    const TreeNode *r = right_stack.top();
    left_stack.pop();
    right_stack.pop();

    if (l == nullptr && r == nullptr)
      continue;

    if (l == nullptr || r == nullptr)
      return false;

    if (l->val != r->val)
      return false;

    left_stack.push(l->right);
    left_stack.push(l->left);
    right_stack.push(r->right);
    right_stack.push(r->left);
  }

  return left_stack.empty() && right_stack.empty();
}
