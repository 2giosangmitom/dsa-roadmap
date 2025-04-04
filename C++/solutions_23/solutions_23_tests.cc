#include "solutions_23.hpp"
#include <gtest/gtest.h>

class Solutions_23_Test : public testing::Test {
protected:
  Solution solution;
};

TEST_F(Solutions_23_Test, case1) {
  ListNode *l1 = ListNode::from({1, 4, 5});
  ListNode *l2 = ListNode::from({1, 3, 4});
  ListNode *l3 = ListNode::from({2, 6});
  ListNode *expected = ListNode::from({1, 1, 2, 3, 4, 4, 5, 6});
  vector<ListNode *> lists = {l1, l2, l3};

  ListNode *actual = solution.mergeKLists(lists);

  EXPECT_EQ(*actual, *expected);

  free_list(actual);
  free_list(expected);
}

TEST_F(Solutions_23_Test, case2) {
  vector<ListNode *> lists = {};
  EXPECT_EQ(solution.mergeKLists(lists), nullptr);
}

TEST_F(Solutions_23_Test, case3) {
  vector<ListNode *> lists = {nullptr, nullptr};
  EXPECT_EQ(solution.mergeKLists(lists), nullptr);
}

TEST_F(Solutions_23_Test, case4) {
  ListNode *l1 = ListNode::from({1, 2});
  ListNode *l2 = nullptr;
  ListNode *l3 = ListNode::from({3});
  ListNode *expected = ListNode::from({1, 2, 3});
  vector<ListNode *> lists = {l1, l2, l3};

  ListNode *actual = solution.mergeKLists(lists);
  EXPECT_EQ(*actual, *expected);

  free_list(actual);
  free_list(expected);
}

TEST_F(Solutions_23_Test, case5) {
  ListNode *l1 = ListNode::from({1, 3, 5});
  ListNode *l2 = ListNode::from({1, 3, 5});
  ListNode *expected = ListNode::from({1, 1, 3, 3, 5, 5});
  vector<ListNode *> lists = {l1, l2};

  ListNode *actual = solution.mergeKLists(lists);
  EXPECT_EQ(*actual, *expected);

  free_list(actual);
  free_list(expected);
}

TEST_F(Solutions_23_Test, case6) {
  ListNode *l1 = ListNode::from({0, 1, 2});
  ListNode *expected = ListNode::from({0, 1, 2});
  vector<ListNode *> lists = {l1};

  ListNode *actual = solution.mergeKLists(lists);
  EXPECT_EQ(*actual, *expected);

  free_list(actual);
  free_list(expected);
}

TEST_F(Solutions_23_Test, case7) {
  ListNode *l1 = ListNode::from({-10, 1000});
  ListNode *l2 = ListNode::from({-5, 0, 999});
  ListNode *expected = ListNode::from({-10, -5, 0, 999, 1000});
  vector<ListNode *> lists = {l1, l2};

  ListNode *actual = solution.mergeKLists(lists);
  EXPECT_EQ(*actual, *expected);

  free_list(actual);
  free_list(expected);
}
