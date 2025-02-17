#include "../src/linked_list_cycle.hpp"
#include <gtest/gtest.h>

class LinkedListCycleTest : public testing::Test {
protected:
  Solution s;
};

TEST_F(LinkedListCycleTest, case1) {
  ListNode *head = ListNode::from({3, 2, 0, -4});
  ListNode *pos = head->next;
  head->next->next->next->next = pos;
  bool expected = true;

  bool actual = s.hasCycle(head);

  EXPECT_EQ(actual, expected);

  head->next->next->next->next = nullptr;
  free_list(head);
}

TEST_F(LinkedListCycleTest, case2) {
  ListNode *head = ListNode::from({1, 2, 3, 4, 5, 6});
  bool expected = false;

  bool actual = s.hasCycle(head);

  EXPECT_EQ(actual, expected);

  free_list(head);
}

TEST_F(LinkedListCycleTest, case3) {
  ListNode *head = ListNode::from({1, 2});
  head->next->next = head;
  bool expected = true;

  bool actual = s.hasCycle(head);

  EXPECT_EQ(actual, expected);

  head->next->next = nullptr;
  free_list(head);
}

TEST_F(LinkedListCycleTest, case4) {
  ListNode *head = ListNode::from({1});
  bool expected = false;

  bool actual = s.hasCycle(head);

  EXPECT_EQ(actual, expected);

  free_list(head);
}

TEST_F(LinkedListCycleTest, case5) {
  ListNode *head = ListNode::from({1, 2, 3});
  head->next->next->next = head->next;
  bool expected = true;

  bool actual = s.hasCycle(head);

  EXPECT_EQ(actual, expected);

  head->next->next->next = nullptr;
  free_list(head);
}

TEST_F(LinkedListCycleTest, case6) {
  ListNode *head = ListNode::from({});
  bool expected = false;

  bool actual = s.hasCycle(head);

  EXPECT_EQ(actual, expected);

  free_list(head);
}

TEST_F(LinkedListCycleTest, case7) {
  ListNode *head = ListNode::from({1, 2, 3, 4, 5});
  head->next->next->next->next->next = head->next->next;
  bool expected = true;

  bool actual = s.hasCycle(head);

  EXPECT_EQ(actual, expected);

  head->next->next->next->next->next = nullptr;
  free_list(head);
}

TEST_F(LinkedListCycleTest, case8) {
  ListNode *head = ListNode::from({1});
  bool expected = false;

  bool actual = s.hasCycle(head);

  EXPECT_EQ(actual, expected);

  free_list(head);
}
