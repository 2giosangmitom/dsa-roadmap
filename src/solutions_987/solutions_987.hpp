#pragma once

#include <algorithm>
#include <deque>
#include <map>
#include <unordered_map>
#include <vector>

#include "../lib/binary_tree.hpp"

class Solution {
 public:
  std::vector<std::vector<int>> verticalTraversal(TreeNode* root) {
    if (!root) return {};

    std::map<int, std::vector<int>> map;
    std::deque<std::pair<int, TreeNode*>> q;

    q.push_back({0, root});

    while (!q.empty()) {
      std::unordered_map<int, std::vector<int>> rows_map;

      // Process current level
      auto current_level_items = q.size();
      while (current_level_items--) {
        auto f = q.front();
        q.pop_front();
        rows_map[f.first].push_back(f.second->val);

        if (f.second->left) {
          q.push_back({f.first - 1, f.second->left});
        }
        if (f.second->right) {
          q.push_back({f.first + 1, f.second->right});
        }
      }

      for (auto& it : rows_map) {
        std::sort(it.second.begin(), it.second.end());

        for (auto& num : it.second) {
          map[it.first].push_back(num);
        }
      }
    }

    std::vector<std::vector<int>> result;
    result.reserve(map.size());

    for (auto& it : map) {
      result.push_back(std::move(it.second));
    }

    return result;
  }
};
