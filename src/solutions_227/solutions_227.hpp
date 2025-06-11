#pragma once

#include <string>
using namespace std;

class Solution {
   public:
    int calculate(string s) {
        int len = s.length();

        if (len == 0) return 0;

        int current_number = 0;
        int last_number = 0;
        int result = 0;
        char sign = '+';

        for (int i = 0; i < len; i++) {
            char current_char = s[i];

            if (isdigit(current_char)) {
                current_number = (current_number * 10) + (current_char - '0');
            }

            if ((!isdigit(current_char) && !isspace(current_char)) ||
                i == len - 1) {
                if (sign == '+' || sign == '-') {
                    result += last_number;
                    last_number =
                        (sign == '+') ? current_number : -current_number;
                } else if (sign == '*') {
                    last_number = last_number * current_number;
                } else if (sign == '/') {
                    last_number = last_number / current_number;
                }

                sign = current_char;
                current_number = 0;
            }
        }

        result += last_number;

        return result;
    }
};
