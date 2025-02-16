#include "../src/intersection_of_two_linked_list.hpp"
#include <gtest/gtest.h>

class IntersectionLinkedListTest : public testing::Test {
protected:
  Solution s;
};

TEST_F(IntersectionLinkedListTest, case1) {
  ListNode *headA = ListNode::from({4, 1, 8, 4, 5});
  ListNode *headB = ListNode::from({5, 6, 1});
  ListNode *lastB = headB;
  // Get last node of headB
  while (lastB->next) {
    lastB = lastB->next;
  }
  ListNode *intersect = headA->next->next;
  lastB->next = intersect;

  ListNode *actual = s.getIntersectionNode(headA, headB);

  EXPECT_EQ(actual, intersect);

  lastB->next = nullptr;
  free_list(headA);
  free_list(headB);
}

TEST_F(IntersectionLinkedListTest, case2) {
  ListNode *headA = ListNode::from({1, 9, 1, 2, 4});
  ListNode *headB = ListNode::from({3});
  ListNode *intersect = headA->next->next->next;
  headB->next = intersect;

  ListNode *actual = s.getIntersectionNode(headA, headB);

  EXPECT_EQ(actual, intersect);

  headB->next = nullptr;
  free_list(headA);
  free_list(headB);
}

TEST_F(IntersectionLinkedListTest, case3) {
  ListNode *headA = ListNode::from({1, 9, 1, 2, 4});
  ListNode *headB = ListNode::from({3, 2, 1});
  ListNode *intersect = headA->next->next->next;
  headB->next->next->next = intersect;

  ListNode *actual = s.getIntersectionNode(headA, headB);

  EXPECT_EQ(actual, intersect);

  headB->next->next->next = nullptr;
  free_list(headA);
  free_list(headB);
}

TEST_F(IntersectionLinkedListTest, second_case1) {
  ListNode *headA = ListNode::from({4, 1, 8, 4, 5});
  ListNode *headB = ListNode::from({5, 6, 1});
  ListNode *lastB = headB;
  // Get last node of headB
  while (lastB->next) {
    lastB = lastB->next;
  }
  ListNode *intersect = headA->next->next;
  lastB->next = intersect;

  ListNode *actual = s.getIntersectionNode2(headA, headB);

  EXPECT_EQ(actual, intersect);

  lastB->next = nullptr;
  free_list(headA);
  free_list(headB);
}

TEST_F(IntersectionLinkedListTest, second_case2) {
  ListNode *headA = ListNode::from({1, 9, 1, 2, 4});
  ListNode *headB = ListNode::from({3});
  ListNode *intersect = headA->next->next->next;
  headB->next = intersect;

  ListNode *actual = s.getIntersectionNode2(headA, headB);

  EXPECT_EQ(actual, intersect);

  headB->next = nullptr;
  free_list(headA);
  free_list(headB);
}

TEST_F(IntersectionLinkedListTest, second_case3) {
  ListNode *headA = ListNode::from({1, 9, 1, 2, 4});
  ListNode *headB = ListNode::from({3, 2, 1});
  ListNode *intersect = headA->next->next->next;
  headB->next->next->next = intersect;

  ListNode *actual = s.getIntersectionNode2(headA, headB);

  EXPECT_EQ(actual, intersect);

  headB->next->next->next = nullptr;
  free_list(headA);
  free_list(headB);
}
