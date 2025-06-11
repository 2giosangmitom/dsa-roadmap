#pragma once

#include <array>
#include <string>
#include <vector>

struct TrieNode {
    std::array<TrieNode*, 26> childrens;
    std::string word;

    TrieNode(std::string word) : word{word} { childrens.fill(nullptr); }
};

struct Trie {
   private:
    void delete_trie(TrieNode* node) {
        for (auto child : node->childrens) {
            if (child) {
                delete_trie(child);
            }
        }
        delete node;
    }

   public:
    TrieNode* root;

    Trie() : root{new TrieNode("")} {}
    ~Trie() { delete_trie(root); }

    void add_word(std::string new_word) {
        TrieNode* curr = root;
        for (const char& c : new_word) {
            if (!curr->childrens[c - 'a']) {
                curr->childrens[c - 'a'] = new TrieNode("");
            }
            curr = curr->childrens[c - 'a'];
        }
        curr->word = new_word;
    }
};

class Solution {
   private:
    bool is_within_bounds(int i, int j, int rows, int cols) {
        return i >= 0 && j >= 0 && i < rows && j < cols;
    }

    void dfs(std::vector<std::vector<char>>& board, TrieNode* node, int i,
             int j, std::vector<std::string>& result, int rows, int cols) {
        if (!node->word.empty()) {
            result.push_back(node->word);
            node->word.clear();
        }

        char temp = board[i][j];
        board[i][j] = '#';

        std::array<std::pair<int, int>, 4> dirs{
            {{1, 0}, {-1, 0}, {0, 1}, {0, -1}}};
        for (const auto& dir : dirs) {
            int next_i = i + dir.first;
            int next_j = j + dir.second;
            if (!is_within_bounds(next_i, next_j, rows, cols)) {
                continue;
            }

            char c = board[next_i][next_j];
            if (c != '#' && node->childrens[c - 'a']) {
                dfs(board, node->childrens[c - 'a'], next_i, next_j, result,
                    rows, cols);
            }
        }

        board[i][j] = temp;
    }

   public:
    std::vector<std::string> findWords(std::vector<std::vector<char>>& board,
                                       std::vector<std::string>& words) {
        Trie trie;
        for (auto& word : words) {
            trie.add_word(word);
        }

        std::vector<std::string> result;

        int n = board.size(), m = board[0].size();

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                char c = board[i][j];
                if (trie.root->childrens[c - 'a']) {
                    dfs(board, trie.root->childrens[c - 'a'], i, j, result, n,
                        m);
                }
            }
        }

        return result;
    }
};
