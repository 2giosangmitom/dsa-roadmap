#pragma once

#include <algorithm>
#include <cstddef>
#include <string>

struct TrieNode {
  bool isWord;
  TrieNode* children[26];

  TrieNode() : isWord{false} { std::fill_n(children, 26, nullptr); }

  ~TrieNode() {
    for (size_t i = 0; i < 26; i++) {
      delete children[i];
    }
  }
};

class WordDictionary {
 private:
  TrieNode* root;

  bool search_helper(TrieNode* node, const std::string& word, size_t index) {
    size_t n = word.size();
    if (index == n) return node->isWord;

    for (; index < n; index++) {
      if (word[index] == '.') {
        for (size_t i = 0; i < 26; i++) {
          if (node->children[i]) {
            if (search_helper(node->children[i], word, index + 1)) return true;
          }
        }
        return false;
      } else {
        if (node->children[word[index] - 'a']) {
          node = node->children[word[index] - 'a'];
        } else {
          return false;
        }
      }
    }

    return node->isWord;
  }

 public:
  WordDictionary() : root{new TrieNode()} {}

  ~WordDictionary() {
    delete root;
    root = nullptr;
  }

  void addWord(std::string word) {
    TrieNode* node = root;
    for (char c : word) {
      size_t index = c - 'a';
      if (node->children[index] == nullptr) {
        node->children[index] = new TrieNode();
      }
      node = node->children[index];
    }
    node->isWord = true;
  }

  bool search(std::string word) { return search_helper(root, word, 0); }
};