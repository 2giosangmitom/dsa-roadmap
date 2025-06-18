#pragma once

#include <string>
using namespace std;

class Solution {
   public:
    bool isSubsequence(string s, string t) {
        size_t i = 0, j = 0;
        size_t n = t.size();

        while (j < n) {
            if (s[i] == t[j]) {
                i++;
            }
            j++;
        }

        return s.size() == i;
    }
};
