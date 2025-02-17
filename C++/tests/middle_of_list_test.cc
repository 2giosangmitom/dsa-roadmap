#include "../src/middle_of_list.hpp"
#include <gtest/gtest.h>

class MiddleOfListTest : public testing::Test {
protected:
  Solution s;
};

TEST_F(MiddleOfListTest, case1) {
  ListNode *head = ListNode::from({1, 2, 3, 4, 5});
  ListNode *expected = head->next->next;

  ListNode *actual = s.middleNode(head);

  EXPECT_EQ(actual, expected);

  free_list(head);
}

TEST_F(MiddleOfListTest, case2) {
  ListNode *head = ListNode::from({1, 2, 3, 4, 5, 6});
  ListNode *expected = head->next->next->next;

  ListNode *actual = s.middleNode(head);

  EXPECT_EQ(actual, expected);

  free_list(head);
}

TEST_F(MiddleOfListTest, case3) {
  ListNode *head = ListNode::from({1});
  ListNode *expected = head;

  ListNode *actual = s.middleNode(head);

  EXPECT_EQ(actual, expected);

  free_list(head);
}

TEST_F(MiddleOfListTest, case4) {
  ListNode *head = ListNode::from({1, 2});
  ListNode *expected = head->next;

  ListNode *actual = s.middleNode(head);

  EXPECT_EQ(actual, expected);

  free_list(head);
}

TEST_F(MiddleOfListTest, case5) {
  ListNode *head = ListNode::from({1, 2, 3});
  ListNode *expected = head->next;

  ListNode *actual = s.middleNode(head);

  EXPECT_EQ(actual, expected);

  free_list(head);
}

TEST_F(MiddleOfListTest, case6) {
  ListNode *head = ListNode::from({1, 2, 3, 4});
  ListNode *expected = head->next->next;

  ListNode *actual = s.middleNode(head);

  EXPECT_EQ(actual, expected);

  free_list(head);
}

TEST_F(MiddleOfListTest, case7) {
  ListNode *head = ListNode::from({1, 2, 3, 4, 5, 6, 7});
  ListNode *expected = head->next->next->next;

  ListNode *actual = s.middleNode(head);

  EXPECT_EQ(actual, expected);

  free_list(head);
}

TEST_F(MiddleOfListTest, case8) {
  ListNode *head = ListNode::from({1, 2, 3, 4, 5, 6, 7, 8});
  ListNode *expected = head->next->next->next->next;

  ListNode *actual = s.middleNode(head);

  EXPECT_EQ(actual, expected);

  free_list(head);
}

TEST_F(MiddleOfListTest, case9) {
  ListNode *head = ListNode::from({1, 2, 3, 4, 5, 6, 7, 8, 9});
  ListNode *expected = head->next->next->next->next;

  ListNode *actual = s.middleNode(head);

  EXPECT_EQ(actual, expected);

  free_list(head);
}

TEST_F(MiddleOfListTest, case10) {
  ListNode *head = ListNode::from({1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
  ListNode *expected = head->next->next->next->next->next;

  ListNode *actual = s.middleNode(head);

  EXPECT_EQ(actual, expected);

  free_list(head);
}

TEST_F(MiddleOfListTest, case11) {
  ListNode *head = ListNode::from({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11});
  ListNode *expected = head->next->next->next->next->next;

  ListNode *actual = s.middleNode(head);

  EXPECT_EQ(actual, expected);

  free_list(head);
}

TEST_F(MiddleOfListTest, case12) {
  ListNode *head = ListNode::from({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12});
  ListNode *expected = head->next->next->next->next->next->next;

  ListNode *actual = s.middleNode(head);

  EXPECT_EQ(actual, expected);

  free_list(head);
}

TEST_F(MiddleOfListTest, case13) {
  ListNode *head = ListNode::from({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13});
  ListNode *expected = head->next->next->next->next->next->next;

  ListNode *actual = s.middleNode(head);

  EXPECT_EQ(actual, expected);

  free_list(head);
}

TEST_F(MiddleOfListTest, case14) {
  ListNode *head =
      ListNode::from({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14});
  ListNode *expected = head->next->next->next->next->next->next->next;

  ListNode *actual = s.middleNode(head);

  EXPECT_EQ(actual, expected);

  free_list(head);
}

TEST_F(MiddleOfListTest, case15) {
  ListNode *head =
      ListNode::from({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15});
  ListNode *expected = head->next->next->next->next->next->next->next;

  ListNode *actual = s.middleNode(head);

  EXPECT_EQ(actual, expected);

  free_list(head);
}

TEST_F(MiddleOfListTest, case16) {
  ListNode *head =
      ListNode::from({1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16});
  ListNode *expected = head->next->next->next->next->next->next->next->next;

  ListNode *actual = s.middleNode(head);

  EXPECT_EQ(actual, expected);

  free_list(head);
}

TEST_F(MiddleOfListTest, case17) {
  ListNode *head = ListNode::from(
      {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17});
  ListNode *expected = head->next->next->next->next->next->next->next->next;

  ListNode *actual = s.middleNode(head);

  EXPECT_EQ(actual, expected);

  free_list(head);
}

TEST_F(MiddleOfListTest, case18) {
  ListNode *head = ListNode::from(
      {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18});
  ListNode *expected =
      head->next->next->next->next->next->next->next->next->next;

  ListNode *actual = s.middleNode(head);

  EXPECT_EQ(actual, expected);

  free_list(head);
}

TEST_F(MiddleOfListTest, case19) {
  ListNode *head = ListNode::from(
      {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19});
  ListNode *expected =
      head->next->next->next->next->next->next->next->next->next;

  ListNode *actual = s.middleNode(head);

  EXPECT_EQ(actual, expected);

  free_list(head);
}

TEST_F(MiddleOfListTest, case20) {
  ListNode *head = ListNode::from(
      {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20});
  ListNode *expected =
      head->next->next->next->next->next->next->next->next->next->next;

  ListNode *actual = s.middleNode(head);

  EXPECT_EQ(actual, expected);

  free_list(head);
}
