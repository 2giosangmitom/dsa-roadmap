#pragma once

#include <stack>
#include <string>
using namespace std;

class Solution {
public:
  int calculate(const string &s) {
    stack<int> stack;
    int result = 0;
    int current_number = 0;
    int sign = 1;
    size_t len = s.size();

    for (size_t i = 0; i < len; i++) {
      char current_char = s[i];

      if (isdigit(current_char)) {
        current_number = current_number * 10 + (current_char - '0');
      } else if (current_char == '+' || current_char == '-') {
        // If the current_char is an operator, add the current_number to result
        // after multiplying it by its sign.
        result += current_number * sign;

        // Reset the current_number to 0 and update the sign.
        current_number = 0;
        sign = current_char == '+' ? 1 : -1;
      } else if (current_char == '(') {
        // If current_char is an opening parenthesis, a new nested expression is
        // starting. Save the current result and sign by pushing to the stack
        // and reset the sign and result.
        stack.push(result);
        stack.push(sign); // This is the sign of the nested expression.
        result = 0;
        sign = 1;
      } else if (current_char == ')') {
        // Finalize the result of the current nested expression.
        result += sign * current_number;

        result *= stack.top(); // Apply the sign of the nested expression.
        stack.pop();
        result += stack.top(); // Add result of the current nested expression to
                               // previous result.
        stack.pop();
        current_number = 0;
      }
    }

    return result + current_number * sign;
  }
};
