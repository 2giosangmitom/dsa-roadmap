#include "../src/reverse_linked_list.hpp"
#include <gtest/gtest.h>

class ReverseLinkedListTest : public testing::Test {
protected:
  Solution s;
};

TEST_F(ReverseLinkedListTest, case1) {
  ListNode *head = ListNode::from({1, 2, 3, 4, 5});
  ListNode *expected = ListNode::from({5, 4, 3, 2, 1});

  ListNode *res = s.reverseList(head);
  EXPECT_EQ(*res, *expected);

  free_list(res);
  free_list(expected);
}

TEST_F(ReverseLinkedListTest, case2) {
  ListNode *head = ListNode::from({3, 2, 1});
  ListNode *expected = ListNode::from({1, 2, 3});

  ListNode *res = s.reverseList(head);
  EXPECT_EQ(*res, *expected);

  free_list(res);
  free_list(expected);
}
