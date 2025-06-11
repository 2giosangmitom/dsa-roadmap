#pragma once

#include <queue>
#include <sstream>
#include <string>

#include "../lib/binary_tree.hpp"

class Codec {
   public:
    // Encodes a tree to a single string.
    std::string serialize(TreeNode* root) {
        std::queue<TreeNode*> queue;
        queue.push(root);
        std::stringstream ss;

        while (!queue.empty()) {
            auto top = queue.front();
            queue.pop();

            if (!top) {
                ss << "#";
            } else {
                ss << top->val;
                queue.push(top->left);
                queue.push(top->right);
            }

            if (!queue.empty()) {
                ss << ',';
            }
        }

        return ss.str();
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(std::string data) {
        std::istringstream ss(data);
        std::string token;
        std::queue<TreeNode*> queue;

        std::getline(ss, token, ',');
        if (token == "#") {
            return nullptr;
        }

        TreeNode* root = new TreeNode(std::stoi(token));
        queue.push(root);

        while (std::getline(ss, token, ',')) {
            auto top = queue.front();
            queue.pop();

            if (token != "#") {
                TreeNode* left_node = new TreeNode(std::stoi(token));
                top->left = left_node;
                queue.push(left_node);
            }

            // Get next token for right_node
            if (!std::getline(ss, token, ',')) {
                break;
            }

            if (token != "#") {
                TreeNode* right_node = new TreeNode(std::stoi(token));
                top->right = right_node;
                queue.push(right_node);
            }
        }

        return root;
    }
};
