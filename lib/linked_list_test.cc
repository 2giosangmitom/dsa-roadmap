#include "linked_list.hh"
#include <gtest/gtest.h>

//-- Test cases for the linked list functions
TEST(ListNodeTest, CreateAndEqual) {
  ListNode *list1 = create_list({1, 2, 3});
  ListNode *list2 = create_list({1, 2, 3});
  ListNode *list3 = create_list({4, 5});

  EXPECT_TRUE(list_equal(list1, list2));
  EXPECT_FALSE(list_equal(list1, list3));

  delete_list({list1, list2, list3});
}

TEST(ListNodeTest, CreateEmptyList) {
  ListNode *empty_list = create_list({});
  EXPECT_TRUE(empty_list == nullptr);
}

TEST(ListNodeTest, CreateSingleElementList) {
  ListNode *single_element_list = create_list({42});
  EXPECT_TRUE(single_element_list != nullptr);
  EXPECT_EQ(single_element_list->val, 42);
  EXPECT_TRUE(single_element_list->next == nullptr);

  delete_list({single_element_list});
}

TEST(ListNodeTest, ListEqualWithDifferentLengths) {
  ListNode *list1 = create_list({1, 2, 3});
  ListNode *list2 = create_list({1, 2, 3, 4});

  EXPECT_FALSE(list_equal(list1, list2));

  delete_list({list1, list2});
}

TEST(ListNodeTest, ListEqualWithNullptr) {
  ListNode *list1 = create_list({1, 2, 3});
  ListNode *list2 = nullptr;

  EXPECT_FALSE(list_equal(list1, list2));

  delete_list({list1});
}

TEST(ListNodeTest, ListEqualWithBothNullptr) {
  ListNode *list1 = nullptr;
  ListNode *list2 = nullptr;

  EXPECT_TRUE(list_equal(list1, list2));
}

TEST(ListNodeTest, ListToVector) {
  ListNode *list = create_list({1, 2, 3, 4, 5});
  std::vector<int> expected_vector = {1, 2, 3, 4, 5};

  EXPECT_EQ(list_to_vector(list), expected_vector);

  delete_list({list});
}

TEST(ListNodeTest, ListToVectorEmpty) {
  ListNode *empty_list = create_list({});
  std::vector<int> expected_vector = {};

  EXPECT_EQ(list_to_vector(empty_list), expected_vector);

  delete_list({empty_list});
}