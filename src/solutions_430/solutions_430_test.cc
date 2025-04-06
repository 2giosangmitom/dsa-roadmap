#include "solutions_430.hpp"
#include <gtest/gtest.h>
#include <sstream>
#include <string>
using namespace std;

class Solutions_430_Test : public testing::Test {
protected:
  Solution solution;
};

void free_list(Node *head) {
  while (head != nullptr) {
    Node *next = head->next;
    delete head;
    head = next;
  }
}

string to_string(Node *head) {
  stringstream ss;

  while (head != nullptr) {
    ss << head->val;
    if (head->next != nullptr) {
      ss << " -> ";
    }
    head = head->next;
  }

  return ss.str();
}

// Create a linked list from vector
Node *create_list(const vector<int> &nums) {
  if (nums.empty())
    return nullptr; // Return nullptr for empty input

  Node *head = nullptr;    // Head of linked list
  Node *current = nullptr; // Pointer to track current node

  for (int num : nums) {
    if (!head) {
      // Initialize head for the first element
      head = new Node(num);
      current = head;
    } else {
      // Create new node and link it to the current list
      Node *new_node = new Node(num);
      current->next = new_node;
      new_node->prev = current;
      current = current->next;
    }
  }

  return head;
}

TEST_F(Solutions_430_Test, case1) {
  Node *lv1 = create_list({1});
  Node *lv2 = create_list({2});
  Node *lv3 = create_list({3});

  lv1->child = lv2;
  lv2->child = lv3;

  Node *actual = solution.flatten(lv1);

  EXPECT_EQ(to_string(actual), "1 -> 2 -> 3");

  free_list(actual);
}

TEST_F(Solutions_430_Test, case2) {
  Node *lv1 = create_list({1, 2, 3, 4, 5, 6});
  Node *lv2 = create_list({7, 8, 9, 10});
  Node *lv3 = create_list({11, 12});
  lv1->next->next->child = lv2;
  lv2->next->child = lv3;

  Node *actual = solution.flatten(lv1);

  EXPECT_EQ(to_string(actual),
            "1 -> 2 -> 3 -> 7 -> 8 -> 11 -> 12 -> 9 -> 10 -> 4 -> 5 -> 6");

  free_list(actual);
}

TEST_F(Solutions_430_Test, case3) {
  Node *actual = solution.flatten(nullptr);
  EXPECT_EQ(actual, nullptr);
}

TEST_F(Solutions_430_Test, case4) {
  Node *lv1 = create_list({1, 2});
  Node *lv2 = create_list({3});
  lv1->child = lv2;
  Node *actual = solution.flatten(lv1);
  EXPECT_EQ(to_string(actual), "1 -> 3 -> 2");

  free_list(actual);
}
