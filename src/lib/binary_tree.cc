#include "binary_tree.hpp"

#include <queue>
#include <stack>

// Constructors
/**
 * @brief Default constructor for TreeNode
 */
TreeNode::TreeNode() : val{0}, left{nullptr}, right{nullptr} {}

/**
 * @brief Constructor for TreeNode with a value
 * @param x Value to be assigned to the node
 */
TreeNode::TreeNode(int x) : val{x}, left{nullptr}, right{nullptr} {}

/**
 * @brief Constructor for TreeNode with a value, left and right children
 * @param x Value to be assigned to the node
 * @param left Pointer to the left child node
 * @param right Pointer to the right child node
 */
TreeNode::TreeNode(int x, TreeNode *left, TreeNode *right)
    : val{x}, left{left}, right{right} {}

// Factory function to create a binary tree using level-order traversal
/**
 * @brief Factory function to create a binary tree using level-order traversal
 * @param values Vector of values to create the tree from
 * @return Pointer to the root of the created binary tree
 */
TreeNode *make_tree(const std::vector<std::any> &values) {
  if (values.empty()) return nullptr;

  // Create the root node
  TreeNode *root = new TreeNode(any_cast<int>(values[0]));
  std::queue<TreeNode *> queue;
  queue.push(root);

  size_t i = 1;
  while (!queue.empty() && i < values.size()) {
    TreeNode *front = queue.front();
    queue.pop();

    // Create the left child node if it exists
    if (i < values.size() && values[i].type() != typeid(nullptr)) {
      front->left = new TreeNode(any_cast<int>(values[i]));
      queue.push(front->left);
    }
    ++i;

    // Create the right child node if it exists
    if (i < values.size() && values[i].type() != typeid(nullptr)) {
      front->right = new TreeNode(any_cast<int>(values[i]));
      queue.push(front->right);
    }
    ++i;
  }

  return root;
}

// Overload equality operator
/**
 * @brief Overload equality operator to compare two binary trees
 * @param lhs Left-hand side tree to compare
 * @param rhs Right-hand side tree to compare
 * @return True if the trees are equal, false otherwise
 */
bool operator==(const TreeNode &lhs, const TreeNode &rhs) {
  std::stack<const TreeNode *> left_stack, right_stack;
  left_stack.push(&lhs);
  right_stack.push(&rhs);

  while (!left_stack.empty() && !right_stack.empty()) {
    const TreeNode *l = left_stack.top();
    const TreeNode *r = right_stack.top();
    left_stack.pop();
    right_stack.pop();

    if (l == nullptr && r == nullptr) continue;

    if (l == nullptr || r == nullptr) return false;

    if (l->val != r->val) return false;

    left_stack.push(l->right);
    left_stack.push(l->left);
    right_stack.push(r->right);
    right_stack.push(r->left);
  }

  return left_stack.empty() && right_stack.empty();
}

// Release dynamic allocated memories used by the tree
/**
 * @brief Release dynamic allocated memories used by the tree
 * @param root Pointer to the root of the tree
 */
void delete_tree(TreeNode *root) {
  if (root == nullptr) {
    return;
  }

  delete_tree(root->left);
  delete_tree(root->right);
  delete root;
}
