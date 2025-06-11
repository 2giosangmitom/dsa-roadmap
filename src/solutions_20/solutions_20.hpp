#pragma once

#include <stack>
#include <string>
using namespace std;

class Solution {
   public:
    bool isValid(string s) {
        int length = s.length();
        if (length % 2 != 0) {
            return false;
        }

        stack<char> stack;
        for (int i = 0; i < length; i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                stack.push(s[i]);
            } else {
                if (stack.empty()) {
                    return false;
                }

                if ((s[i] == ')' && stack.top() == '(') ||
                    (s[i] == '}' && stack.top() == '{') ||
                    (s[i] == ']' && stack.top() == '[')) {
                    stack.pop();
                } else {
                    return false;
                }
            }
        }

        return stack.empty();
    }
};
