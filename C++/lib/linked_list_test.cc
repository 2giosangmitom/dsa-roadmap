#include "linked_list.hpp"

#include <gtest/gtest.h>

#include <vector>
using namespace std;

class LinkedList_From_Test : public testing::Test {
 protected:
  void check(vector<int> nums, ListNode *expected) {
    auto actual = ListNode::from(nums);

    EXPECT_EQ(*actual, *expected);

    free_list(actual);
    free_list(expected);
  }
};

TEST_F(LinkedList_From_Test, case1) {
  vector<int> nums = {1, 2, 3};
  ListNode *expected = new ListNode(1, new ListNode(2, new ListNode(3)));

  check(nums, expected);
}

TEST_F(LinkedList_From_Test, case2) {
  vector<int> nums = {};
  ListNode *expected = nullptr;

  check(nums, expected);
}

TEST_F(LinkedList_From_Test, case3) {
  vector<int> nums = {1};
  ListNode *expected = new ListNode(1);

  check(nums, expected);
}

class LinkedList_ToString_Test : public testing::Test {
 protected:
  void check(vector<int> nums, string expected) {
    auto actual = ListNode::from(nums);

    EXPECT_EQ(actual->to_string(), expected);

    free_list(actual);
  }
};

TEST_F(LinkedList_ToString_Test, case1) {
  vector<int> nums = {1, 2, 3};
  string expected = "1 -> 2 -> 3";

  check(nums, expected);
}

TEST_F(LinkedList_ToString_Test, case2) {
  vector<int> nums = {};
  string expected = "";

  check(nums, expected);
}
