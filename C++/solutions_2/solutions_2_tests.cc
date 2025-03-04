#include <gtest/gtest.h>

#include "solutions_2.hpp"

class Solutions_2_Test : public testing::Test {
 protected:
  Solution solution;

  void check(ListNode* l1, ListNode* l2, ListNode* expected) {
    auto actual = solution.addTwoNumbers(l1, l2);
    EXPECT_EQ(*actual, *expected);
    free_list(l1);
    free_list(l2);
    free_list(actual);
    free_list(expected);
  }
};

TEST_F(Solutions_2_Test, case1) {
  ListNode* l1 = ListNode::from({2, 4, 3});
  ListNode* l2 = ListNode::from({5, 6, 4});
  ListNode* expected = ListNode::from({7, 0, 8});

  check(l1, l2, expected);
}

TEST_F(Solutions_2_Test, case2) {
  ListNode* l1 = ListNode::from({0});
  ListNode* l2 = ListNode::from({0});
  ListNode* expected = ListNode::from({0});

  check(l1, l2, expected);
}

TEST_F(Solutions_2_Test, case3) {
  ListNode* l1 = ListNode::from({9, 9, 9, 9, 9, 9, 9});
  ListNode* l2 = ListNode::from({9, 9, 9, 9});
  ListNode* expected = ListNode::from({8, 9, 9, 9, 0, 0, 0, 1});

  check(l1, l2, expected);
}

TEST_F(Solutions_2_Test, case4) {
  ListNode* l1 = ListNode::from({1, 8});
  ListNode* l2 = ListNode::from({0});
  ListNode* expected = ListNode::from({1, 8});

  check(l1, l2, expected);
}

TEST_F(Solutions_2_Test, case5) {
  ListNode* l1 = ListNode::from({5});
  ListNode* l2 = ListNode::from({5});
  ListNode* expected = ListNode::from({0, 1});

  check(l1, l2, expected);
}
