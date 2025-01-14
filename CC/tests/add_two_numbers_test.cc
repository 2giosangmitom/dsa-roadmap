#include "../src/add_two_numbers.hpp"
#include <gtest/gtest.h>

class AddTwoNumbersTest : public ::testing::Test {
protected:
  Solution solution;

public:
  void check(ListNode *l1, ListNode *l2, ListNode *expected) {
    ListNode *actual = solution.addTwoNumbers(l1, l2);
    EXPECT_EQ(expected->to_string(), actual->to_string());
    delete l1;
    delete l2;
    delete expected;
    delete actual;
  }
};

TEST_F(AddTwoNumbersTest, small_input) {
  ListNode *l1 = ListNode::from({2, 4, 3});
  ListNode *l2 = ListNode::from({5, 6, 4});
  ListNode *expected = ListNode::from({7, 0, 8});
  check(l1, l2, expected);
}

TEST_F(AddTwoNumbersTest, carry_over) {
  ListNode *l1 = ListNode::from({9, 9, 9});
  ListNode *l2 = ListNode::from({1});
  ListNode *expected = ListNode::from({0, 0, 0, 1});
  check(l1, l2, expected);
}

TEST_F(AddTwoNumbersTest, single_node) {
  ListNode *l1 = ListNode::from({1});
  ListNode *l2 = ListNode::from({9});
  ListNode *expected = ListNode::from({0, 1});
  check(l1, l2, expected);
}

TEST_F(AddTwoNumbersTest, different_lengths) {
  ListNode *l1 = ListNode::from({1, 2});
  ListNode *l2 = ListNode::from({9});
  ListNode *expected = ListNode::from({0, 3});
  check(l1, l2, expected);
}

TEST_F(AddTwoNumbersTest, empty_lists) {
  ListNode *l1 = nullptr;
  ListNode *l2 = nullptr;
  ListNode *expected = nullptr;
  check(l1, l2, expected);
}

TEST_F(AddTwoNumbersTest, zero_case) {
  ListNode *l1 = ListNode::from({0});
  ListNode *l2 = ListNode::from({0});
  ListNode *expected = ListNode::from({0});
  check(l1, l2, expected);
}

TEST_F(AddTwoNumbersTest, large_input) {
  ListNode *l1 = ListNode::from({9, 9, 9, 9, 9, 9, 9});
  ListNode *l2 = ListNode::from({9, 9, 9, 9});
  ListNode *expected = ListNode::from({8, 9, 9, 9, 0, 0, 0, 1});
  check(l1, l2, expected);
}

TEST_F(AddTwoNumbersTest, no_carry) {
  ListNode *l1 = ListNode::from({1, 2, 3});
  ListNode *l2 = ListNode::from({4, 5, 6});
  ListNode *expected = ListNode::from({5, 7, 9});
  check(l1, l2, expected);
}
