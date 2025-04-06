#include "solutions_141.hpp"
#include <gtest/gtest.h>
#include <memory>

class Solutions_141_Test : public testing::Test {
protected:
  Solution solutions;

  void check(ListNode *head, bool expected) {
    EXPECT_EQ(solutions.hasCycle(head), expected);
  }
};

TEST_F(Solutions_141_Test, case1) {
  auto head = unique_ptr<ListNode>(make_list({1, 2, 3, 4}));
  check(head.get(), false);
}

TEST_F(Solutions_141_Test, case2) {
  ListNode *head = make_list({1, 2, 3, 4, 5});
  head->next->next->next->next->next = head->next; // Create cycle
  check(head, true);
  head->next->next->next->next->next = nullptr; // Break cycle before freeing
  delete head;
}

TEST_F(Solutions_141_Test, case3) {
  ListNode *head = nullptr;
  EXPECT_FALSE(solutions.hasCycle(head));
}

TEST_F(Solutions_141_Test, case4) {
  ListNode *head = make_list({1});
  check(head, false);
  delete head;
}

TEST_F(Solutions_141_Test, case5) {
  auto head = unique_ptr<ListNode>(make_list({1, 2, 3}));
  head->next->next->next = head->next; // Create cycle
  check(head.get(), true);
  head->next->next->next = nullptr; // Break cycle before freeing
}
