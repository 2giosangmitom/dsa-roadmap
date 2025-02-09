#include "../lib/linked_list.hpp"
#include <gtest/gtest.h>

TEST(LinkedListTest, from_method_case1) {
  ListNode *expected = new ListNode(1, new ListNode(2, new ListNode(3)));
  ListNode *actual = ListNode::from({1, 2, 3});
  EXPECT_EQ(*actual, *expected);
  free_list(actual);
  free_list(expected);
}

TEST(LinkedListTest, from_method_case2) {
  ListNode *expected =
      new ListNode(1, new ListNode(2, new ListNode(3, new ListNode(5))));
  ListNode *actual = ListNode::from({1, 2, 3});
  EXPECT_NE(*actual, *expected);
  free_list(actual);
  free_list(expected);
}

TEST(LinkedListTest, from_method_empty_list) {
  ListNode *actual = ListNode::from({});
  EXPECT_EQ(actual, nullptr); // Should return nullptr for empty list
}

TEST(LinkedListTest, from_method_single_element) {
  ListNode *expected = new ListNode(42);
  ListNode *actual = ListNode::from({42});
  EXPECT_EQ(*actual, *expected);
  free_list(actual);
  free_list(expected);
}

TEST(LinkedListTest, to_string_method_case1) {
  string expected = "1 -> 2 -> 3";
  ListNode *actual = ListNode::from({1, 2, 3});
  EXPECT_EQ(actual->to_string(), expected);
  free_list(actual);
}

TEST(LinkedListTest, to_string_method_empty_list) {
  ListNode *actual = nullptr;
  EXPECT_EQ(actual == nullptr ? "empty" : actual->to_string(), "empty");
}

TEST(LinkedListTest, to_string_method_single_element) {
  string expected = "7";
  ListNode *actual = ListNode::from({7});
  EXPECT_EQ(actual->to_string(), expected);
  free_list(actual);
}

TEST(LinkedListTest, operator_equals_identical_lists) {
  ListNode *list1 = ListNode::from({1, 2, 3, 4});
  ListNode *list2 = ListNode::from({1, 2, 3, 4});
  EXPECT_EQ(*list1, *list2);
  free_list(list1);
  free_list(list2);
}

TEST(LinkedListTest, operator_equals_different_length) {
  ListNode *list1 = ListNode::from({1, 2, 3});
  ListNode *list2 = ListNode::from({1, 2, 3, 4});
  EXPECT_NE(*list1, *list2);
  free_list(list1);
  free_list(list2);
}

TEST(LinkedListTest, operator_equals_different_values) {
  ListNode *list1 = ListNode::from({1, 2, 3});
  ListNode *list2 = ListNode::from({1, 2, 4});
  EXPECT_NE(*list1, *list2);
  free_list(list1);
  free_list(list2);
}
