#pragma once

#include <string>
#include <unordered_map>
using namespace std;

class Solution {
   public:
    int romanToInt(string s) {
        unordered_map<char, int> pairs = {
            {'I', 1},   {'V', 5},   {'X', 10},   {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000},
        };

        int result = 0;
        for (size_t i = 0; i < s.size(); i++) {
            if (i + 1 < s.size() && pairs[s[i]] < pairs[s[i + 1]]) {
                result -= pairs[s[i]];
            } else {
                result += pairs[s[i]];
            }
        }

        return result;
    }
};
