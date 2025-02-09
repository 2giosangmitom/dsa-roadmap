#include "../src/add_two_numbers.hpp"
#include <gtest/gtest.h>

class AddTwoNumbersTest : public testing::Test {
protected:
  Solution s;
};

TEST_F(AddTwoNumbersTest, case1) {
  ListNode *l1 = ListNode::from({2, 4, 3});
  ListNode *l2 = ListNode::from({5, 6, 4});
  ListNode *expected = ListNode::from({7, 0, 8});

  ListNode *actual = s.addTwoNumbers(l1, l2);

  EXPECT_EQ(*actual, *expected);

  free_list(l1);
  free_list(l2);
  free_list(expected);
  free_list(actual);
}

// Case where both numbers have different lengths
TEST_F(AddTwoNumbersTest, case2) {
  ListNode *l1 = ListNode::from({1});
  ListNode *l2 = ListNode::from({9, 9, 9});
  ListNode *expected = ListNode::from({0, 0, 0, 1});

  ListNode *actual = s.addTwoNumbers(l1, l2);

  EXPECT_EQ(*actual, *expected);

  free_list(l1);
  free_list(l2);
  free_list(expected);
  free_list(actual);
}

// Case where one list is empty
TEST_F(AddTwoNumbersTest, case3) {
  ListNode *l1 = ListNode::from({});
  ListNode *l2 = ListNode::from({7, 3});
  ListNode *expected = ListNode::from({7, 3});

  ListNode *actual = s.addTwoNumbers(l1, l2);

  EXPECT_EQ(*actual, *expected);

  free_list(l1);
  free_list(l2);
  free_list(expected);
  free_list(actual);
}

// Case where the sum produces an extra carry at the end
TEST_F(AddTwoNumbersTest, case4) {
  ListNode *l1 = ListNode::from({9, 9, 9});
  ListNode *l2 = ListNode::from({1});
  ListNode *expected = ListNode::from({0, 0, 0, 1});

  ListNode *actual = s.addTwoNumbers(l1, l2);

  EXPECT_EQ(*actual, *expected);

  free_list(l1);
  free_list(l2);
  free_list(expected);
  free_list(actual);
}

// Case where both lists contain only zeros
TEST_F(AddTwoNumbersTest, case5) {
  ListNode *l1 = ListNode::from({0, 0, 0});
  ListNode *l2 = ListNode::from({0, 0});
  ListNode *expected = ListNode::from({0, 0, 0});

  ListNode *actual = s.addTwoNumbers(l1, l2);

  EXPECT_EQ(*actual, *expected);

  free_list(l1);
  free_list(l2);
  free_list(expected);
  free_list(actual);
}
