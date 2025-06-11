#pragma once

#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

struct TrieNode {
    bool is_word;
    std::unordered_map<char, TrieNode*> children;
};

class Trie {
   private:
    TrieNode* root;

    void delete_trie(TrieNode* root) {
        for (auto& p : root->children) {
            delete_trie(p.second);
        }
        delete root;
    }

   public:
    Trie() : root{new TrieNode{false, {}}} {}

    ~Trie() { delete_trie(root); }

    void insert(std::string word) {
        auto curr = root;
        for (auto c : word) {
            if (!curr->children.contains(c)) {
                curr->children[c] = new TrieNode{false, {}};
            }
            curr = curr->children[c];
        }
        curr->is_word = true;
    }

    std::string find_longest_common_prefix() {
        auto curr = root;
        std::stringstream ss;
        while (curr->children.size() == 1) {
            auto it = curr->children.begin();
            ss << it->first;
            curr = it->second;
            if (curr->is_word) {
                break;
            }
        }
        return ss.str();
    }
};

class Solution {
   public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        std::string prefix = strs[0];

        for (size_t i = 1; i < strs.size(); i++) {
            while (strs[i].find(prefix) != 0) {
                prefix.erase(prefix.end() - 1);
                if (prefix.empty()) return "";
            }
        }

        return prefix;
    }

    std::string longestCommonPrefix2(std::vector<std::string>& strs) {
        auto trie = Trie();
        for (auto& s : strs) {
            if (s.empty()) {
                return s;
            }
            trie.insert(s);
        }
        return trie.find_longest_common_prefix();
    }
};
