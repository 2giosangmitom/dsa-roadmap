#include "../src/remove_nth_node.hpp"
#include <gtest/gtest.h>

class RemoveNthNodeTest : public testing::Test {
protected:
  Solution s;
};

TEST_F(RemoveNthNodeTest, case1) {
  ListNode *head = ListNode::from({1, 2, 3, 4, 5});
  ListNode *expected = ListNode::from({1, 2, 3, 5});
  int n = 2;

  ListNode *res = s.removeNthFromEnd(head, n);

  EXPECT_EQ(*res, *expected);

  free_list(res);
  free_list(expected);
}

TEST_F(RemoveNthNodeTest, case2) {
  ListNode *head = ListNode::from({1, 2, 3, 4, 5});
  ListNode *expected = ListNode::from({1, 2, 3, 4, 5});
  int n = 7;

  ListNode *res = s.removeNthFromEnd(head, n);

  EXPECT_EQ(*res, *expected);

  free_list(res);
  free_list(expected);
}

TEST_F(RemoveNthNodeTest, case3) {
  ListNode *head = ListNode::from({1, 2, 3, 4, 5});
  ListNode *expected = ListNode::from({2, 3, 4, 5});
  int n = 5;

  ListNode *res = s.removeNthFromEnd(head, n);

  EXPECT_EQ(*res, *expected);

  free_list(res);
  free_list(expected);
}

TEST_F(RemoveNthNodeTest, case4) {
  ListNode *head = ListNode::from({1, 2, 3, 4, 5});
  ListNode *expected = ListNode::from({1, 2, 4, 5});
  int n = 3;

  ListNode *res = s.removeNthFromEnd(head, n);

  EXPECT_EQ(*res, *expected);

  free_list(res);
  free_list(expected);
}

TEST_F(RemoveNthNodeTest, case5) {
  ListNode *head = ListNode::from({1});
  ListNode *expected = nullptr;
  int n = 1;

  ListNode *res = s.removeNthFromEnd(head, n);

  EXPECT_EQ(res, expected);

  free_list(res);
}
