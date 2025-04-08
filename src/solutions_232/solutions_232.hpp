#pragma once

#include <stack>
using namespace std;

class MyQueue {
private:
  stack<int> enqueue_stack;
  stack<int> dequeue_stack;

public:
  MyQueue() {}

  void push(int x) { enqueue_stack.push(x); }

  int pop() {
    if (!dequeue_stack.empty()) {
      int result = dequeue_stack.top();
      dequeue_stack.pop();
      return result;
    }

    while (!enqueue_stack.empty()) {
      dequeue_stack.push(enqueue_stack.top());
      enqueue_stack.pop();
    }

    int result = dequeue_stack.top();
    dequeue_stack.pop();
    return result;
  }

  int peek() {
    if (!dequeue_stack.empty()) {
      return dequeue_stack.top();
    }

    while (!enqueue_stack.empty()) {
      dequeue_stack.push(enqueue_stack.top());
      enqueue_stack.pop();
    }

    return dequeue_stack.top();
  }

  bool empty() { return enqueue_stack.empty() && dequeue_stack.empty(); }
};
