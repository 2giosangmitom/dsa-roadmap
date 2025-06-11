#pragma once

#include <string>
#include <vector>
using namespace std;

class Solution {
   private:
    void solve(const string &digits, string &candidate, size_t i,
               vector<string> &result) {
        if (i == digits.size()) {
            result.push_back(candidate);
            return;
        }

        static vector<string> digits_map = {
            "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        string letters = digits_map[digits[i] - '0'];
        for (char &c : letters) {
            candidate.push_back(c);
            solve(digits, candidate, i + 1, result);
            candidate.pop_back();
        }
    }

   public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        vector<string> result;
        string candidate;

        solve(digits, candidate, 0, result);

        return result;
    }
};
