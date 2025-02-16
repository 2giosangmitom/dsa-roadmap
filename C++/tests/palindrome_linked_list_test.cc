#include "../src/palindrome_linked_list.hpp"
#include <gtest/gtest.h>

class PalindromeLinkedListTest : public testing::Test {
protected:
  Solution s;
};

TEST_F(PalindromeLinkedListTest, case1) {
  ListNode *head = ListNode::from({1, 2, 2, 1});
  bool expected = true;

  bool actual = s.isPalindrome(head);

  EXPECT_EQ(actual, expected);

  free_list(head);
}

TEST_F(PalindromeLinkedListTest, case2) {
  ListNode *head = ListNode::from({1, 2});
  bool expected = false;

  bool actual = s.isPalindrome(head);

  EXPECT_EQ(actual, expected);

  free_list(head);
}

TEST_F(PalindromeLinkedListTest, case3) {
  ListNode *head = ListNode::from({1, 2, 1});
  bool expected = true;

  bool actual = s.isPalindrome(head);

  EXPECT_EQ(actual, expected);

  free_list(head);
}

TEST_F(PalindromeLinkedListTest, case4) {
  ListNode *head = ListNode::from({1});
  bool expected = true;

  bool actual = s.isPalindrome(head);

  EXPECT_EQ(actual, expected);

  free_list(head);
}
