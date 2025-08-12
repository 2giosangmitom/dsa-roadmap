#pragma once

#include <stack>
#include <string>
#include <utility>
using namespace std;

class Solution {
    void repeat_string(string& s, int num) {
        string base = s;
        for (int i = 1; i < num; ++i) {
            s += base;
        }
    }

   public:
    string decodeString(string s) {
        int current_num = 0;
        string result;
        stack<pair<int, string>> st;

        for (char c : s) {
            if (isdigit(c)) {
                current_num = current_num * 10 + (c - '0');
            } else {
                if (c == '[') {
                    st.push({current_num, std::move(result)});
                    current_num = 0;
                } else if (c == ']') {
                    auto pair = st.top();
                    st.pop();
                    repeat_string(result, pair.first);
                    result = std::move(pair.second) + result;
                } else {
                    result += c;
                }
            }
        }

        return result;
    }
};
