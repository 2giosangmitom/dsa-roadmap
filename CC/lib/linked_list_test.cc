#include "linked_list.hpp"
#include <gtest/gtest.h>

TEST(LinkedListTest, CreateListFromValues) {
  ListNode *list = ListNode::from({1, 2, 3, 4});
  string expected = "1 -> 2 -> 3 -> 4";
  EXPECT_EQ(list->to_string(), expected);
  delete list;
}

TEST(LinkedListTest, CreateEmptyList) {
  ListNode *list = ListNode::from({});
  EXPECT_EQ(list, nullptr);
}

TEST(LinkedListTest, CreateSingleElementList) {
  ListNode *list = ListNode::from({42});
  string expected = "42";
  EXPECT_EQ(list->to_string(), expected);
  delete list;
}

TEST(LinkedListTest, HandlesNullNextPointerGracefully) {
  ListNode *node = new ListNode(5);
  EXPECT_EQ(node->to_string(), "5");
  delete node;
}

TEST(LinkedListTest, HandlesLongListCreation) {
  ListNode *list = ListNode::from({1, 2, 3, 4, 5, 6, 7, 8, 9, 10});
  string expected = "1 -> 2 -> 3 -> 4 -> 5 -> 6 -> 7 -> 8 -> 9 -> 10";
  EXPECT_EQ(list->to_string(), expected);
  delete list;
}

TEST(LinkedListTest, HandlesListWithNegativeValues) {
  ListNode *list = ListNode::from({-1, -2, -3});
  string expected = "-1 -> -2 -> -3";
  EXPECT_EQ(list->to_string(), expected);
  delete list;
}

TEST(LinkedListTest, HandlesListWithZeroValues) {
  ListNode *list = ListNode::from({0, 0, 0});
  string expected = "0 -> 0 -> 0";
  EXPECT_EQ(list->to_string(), expected);
  delete list;
}

TEST(LinkedListTest, HandlesMixedPositiveAndNegativeValues) {
  ListNode *list = ListNode::from({-1, 0, 2, -3, 4});
  string expected = "-1 -> 0 -> 2 -> -3 -> 4";
  EXPECT_EQ(list->to_string(), expected);
  delete list;
}

TEST(LinkedListTest, HandlesDeletingList) {
  ListNode *list = ListNode::from({1, 2, 3});
  delete list;
  SUCCEED(); // If no memory issues, test passes.
}
