#pragma once

#include <string>
#include <vector>

using std::string;
using std::vector;

struct Trie {
    vector<Trie *> children;

    Trie() : children(26, nullptr) {}

    ~Trie() {
        for (int i = 0; i < 26; i++) {
            if (children[i]) {
                delete children[i];
            }
        }
    }
};

class Solution {
   public:
    vector<string> partitionString(string s) {
        Trie trie;
        Trie *node = &trie;
        vector<string> result;
        string t;

        for (const char &c : s) {
            int i = c - 'a';
            t += c;

            if (node->children[i] == nullptr) {
                node->children[i] = new Trie();
                result.push_back(t);
                t.clear();
                node = &trie;
            } else {
                node = node->children[i];
            }
        }

        return result;
    }
};
