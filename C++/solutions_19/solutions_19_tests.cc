#include "solutions_19.hpp"
#include <gtest/gtest.h>

class Solutions_19_Test : public testing::Test {
protected:
  Solution solution;
};

TEST_F(Solutions_19_Test, case1) {
  ListNode *head = ListNode::from({1, 2, 3, 4, 5});
  ListNode *expected = ListNode::from({1, 2, 3, 5});

  ListNode *actual = solution.removeNthFromEnd(head, 2);

  EXPECT_EQ(*actual, *expected);
  free_list(head);
  free_list(expected);
}

TEST_F(Solutions_19_Test, case2) {
  ListNode *head = ListNode::from({1});

  ListNode *actual = solution.removeNthFromEnd(head, 1);

  EXPECT_EQ(actual, nullptr);
}

TEST_F(Solutions_19_Test, case3) {
  ListNode *head = ListNode::from({1, 2});
  ListNode *expected = ListNode::from({1});

  ListNode *actual = solution.removeNthFromEnd(head, 1);

  EXPECT_EQ(*actual, *expected);
  free_list(head);
  free_list(expected);
}
