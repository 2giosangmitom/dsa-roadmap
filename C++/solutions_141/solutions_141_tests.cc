#include "solutions_141.hpp"
#include <gtest/gtest.h>

class Solutions_141_Test : public testing::Test {
protected:
  Solution solutions;
};

TEST_F(Solutions_141_Test, case1) {
  ListNode *head = ListNode::from({1, 2, 3, 4});
  EXPECT_FALSE(solutions.hasCycle(head));
  free_list(head);
}

TEST_F(Solutions_141_Test, case2) {
  ListNode *head = ListNode::from({1, 2, 3, 4, 5});
  head->next->next->next->next->next = head->next; // Create cycle
  EXPECT_TRUE(solutions.hasCycle(head));
  head->next->next->next->next->next = nullptr; // Break cycle before freeing
  free_list(head);
}

TEST_F(Solutions_141_Test, case3) {
  ListNode *head = nullptr;
  EXPECT_FALSE(solutions.hasCycle(head));
}

TEST_F(Solutions_141_Test, case4) {
  ListNode *head = ListNode::from({1});
  EXPECT_FALSE(solutions.hasCycle(head));
  free_list(head);
}

TEST_F(Solutions_141_Test, case5) {
  ListNode *head = ListNode::from({1, 2});
  head->next->next = head; // Create cycle
  EXPECT_TRUE(solutions.hasCycle(head));
  head->next->next = nullptr; // Break cycle before freeing
  free_list(head);
}

TEST_F(Solutions_141_Test, case6) {
  ListNode *head = ListNode::from({1, 2, 3});
  EXPECT_FALSE(solutions.hasCycle(head));
  free_list(head);
}

TEST_F(Solutions_141_Test, case7) {
  ListNode *head = ListNode::from({1, 2, 3});
  head->next->next->next = head->next; // Create cycle
  EXPECT_TRUE(solutions.hasCycle(head));
  head->next->next->next = nullptr; // Break cycle before freeing
  free_list(head);
}

TEST_F(Solutions_141_Test, case8) {
  ListNode *head = ListNode::from({1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
  EXPECT_FALSE(solutions.hasCycle(head));
  free_list(head);
}
