#pragma once

#include <queue>
#include <vector>

#include "../lib/binary_tree.hpp"
using namespace std;

class Solution {
   public:
    vector<int> rightSideView(TreeNode *root) {
        if (root == nullptr) return {};
        vector<int> result;
        queue<TreeNode *> nodes;
        nodes.push(root);

        while (!nodes.empty()) {
            size_t size = nodes.size();

            for (size_t i = 0; i < size; i++) {
                auto front = nodes.front();
                nodes.pop();

                if (front->left != nullptr) {
                    nodes.push(front->left);
                }
                if (front->right != nullptr) {
                    nodes.push(front->right);
                }

                if (i == size - 1) {
                    result.push_back(front->val);
                }
            }
        }

        return result;
    }
};
