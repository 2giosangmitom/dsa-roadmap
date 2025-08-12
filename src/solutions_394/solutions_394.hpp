#pragma once

#include <stack>
#include <string>
#include <utility>
using namespace std;

class Solution {
    string repeat_string(string& s, int num) {
        string res;
        for (int i = 0; i < num; ++i) {
            res += s;
        }
        return res;
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
                    st.push({current_num, result});
                    result.clear();
                    current_num = 0;
                } else if (c == ']') {
                    auto pair = st.top();
                    st.pop();
                    result =
                        pair.second + repeat_string(result, pair.first);
                } else {
                    result += c;
                }
            }
        }

        return result;
    }
};
