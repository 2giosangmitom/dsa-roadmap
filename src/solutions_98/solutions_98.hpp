#pragma once

#include "../lib/binary_tree.hpp"
#include <cmath>
#include <cstdint>
using namespace std;

class Solution {
public:
  bool isValidBST(TreeNode *root) { return helper(root, INT64_MIN, INT64_MAX); }

private:
  bool helper(TreeNode *root, long lower_bound, long upper_bound) {
    if (root == nullptr) {
      return true;
    }

    if (!(root->val > lower_bound && root->val < upper_bound)) {
      return false;
    }

    if (!(helper(root->left, lower_bound, root->val))) {
      return false;
    }

    return helper(root->right, root->val, upper_bound);
  }
};
