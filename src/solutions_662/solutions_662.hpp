#pragma once

#include "../lib/binary_tree.hpp"
#include <deque>
using namespace std;

class Solution {
public:
  int widthOfBinaryTree(TreeNode *root) {
    if (!root)
      return 0;

    using T = pair<TreeNode *, unsigned long long>;
    deque<T> q;
    q.push_back({root, 0});
    int res = 0;

    while (!q.empty()) {
      size_t size = q.size();
      unsigned long long left = q.front().second;
      unsigned long long right = left; // will be updated in loop

      for (size_t i = 0; i < size; ++i) {
        auto [node, idx] = q.front();
        q.pop_front();
        idx -= left; // Normalize to prevent overflow

        if (node->left)
          q.push_back({node->left, 2 * idx + 1});
        if (node->right)
          q.push_back({node->right, 2 * idx + 2});
        right = idx;
      }

      res = max(res, static_cast<int>(right + 1));
    }

    return res;
  }
};
