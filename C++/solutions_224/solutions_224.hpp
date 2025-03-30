#pragma once

#include <stack>
#include <string>
using namespace std;

class Solution {
public:
  int calculate(const string &s) {
    stack<int> stack;       // Stack to manage nested expressions
    int result = 0;         // Stores the running sum of evaluated expressions
    int current_number = 0; // Stores the number being built
    int sign = 1;           // Tracks the current sign (1 for '+', -1 for '-')

    for (char current_char : s) {
      if (isdigit(current_char)) {
        // Build the current number from consecutive digits
        current_number = current_number * 10 + (current_char - '0');
      } else if (current_char == '+' || current_char == '-') {
        // Apply the previous number and update the sign for the next number
        result += current_number * sign;
        sign = (current_char == '+') ? 1 : -1;
        current_number = 0;
      } else if (current_char == '(') {
        // Push the current result and sign onto the stack before entering a
        // nested expression
        stack.push(result);
        stack.push(sign);
        result = 0;
        sign = 1;
      } else if (current_char == ')') {
        // Apply the last computed number before exiting the nested expression
        result += current_number * sign;
        result *= stack.top(); // Retrieve the sign before '('
        stack.pop();
        result += stack.top(); // Retrieve the result before '('
        stack.pop();
        current_number = 0;
      }
    }

    // Add any remaining number in the expression
    return result + current_number * sign;
  }
};
