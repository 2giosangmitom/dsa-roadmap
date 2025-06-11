#pragma once

#include <string>
#include <unordered_map>

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

    bool search(std::string word) {
        auto curr = root;
        for (auto c : word) {
            if (!curr->children.contains(c)) return false;
            curr = curr->children[c];
        }
        return curr->is_word;
    }

    bool startsWith(std::string prefix) {
        auto curr = root;
        for (auto c : prefix) {
            if (!curr->children.contains(c)) return false;
            curr = curr->children[c];
        }
        return true;
    }
};
