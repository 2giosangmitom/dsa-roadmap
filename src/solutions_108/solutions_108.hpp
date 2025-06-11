#pragma once

#include <vector>

#include "../lib/binary_tree.hpp"

class Solution {
   private:
    TreeNode* helper(std::vector<int>& nums, int left, int right) {
        if (left > right) return nullptr;

        auto mid = (left + right) / 2;
        auto root = new TreeNode(nums[mid]);

        root->left = helper(nums, left, mid - 1);
        root->right = helper(nums, mid + 1, right);

        return root;
    }

   public:
    TreeNode* sortedArrayToBST(std::vector<int>& nums) {
        if (nums.empty()) return nullptr;

        auto root = helper(nums, 0, nums.size() - 1);

        return root;
    }
};
