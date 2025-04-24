#include "solutions_160.hpp"

#include <gtest/gtest.h>

#include <tuple>

class Solutions_160_Test
    : public testing::TestWithParam<
          std::tuple<std::vector<int>, std::vector<int>, int>> {
 protected:
  Solution solution;
};

TEST_P(Solutions_160_Test, ) {
  auto [headA_vals, headB_vals, intersect_idx] = GetParam();
  auto headA = make_list(headA_vals);
  auto headB = make_list(headB_vals);

  // Create intersection
  ListNode *intersect_node = intersect_idx == -1 ? nullptr : headA;
  for (int i = 0; i <= intersect_idx; i++) {
    intersect_node = intersect_node->next;
  }

  // Connect tailB with intersect_node
  ListNode *tailB = headB;
  while (tailB->next != nullptr) {
    tailB = tailB->next;
  }
  tailB->next = intersect_node;

  ListNode *actual = solution.getIntersectionNode(headA, headB);
  EXPECT_EQ(actual, intersect_node);

  // Disconnect tailB and intersect_node to avoid double free
  tailB->next = nullptr;

  delete_list({headA, headB});
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_160_Test,
    testing::Values(
        make_tuple(std::vector<int>{4, 1, 8, 4, 5}, std::vector<int>{5, 6, 1},
                   2),
        make_tuple(std::vector<int>{1, 9, 1, 2, 4}, std::vector<int>{3}, 3),
        make_tuple(std::vector<int>{2, 6, 4}, std::vector<int>{1, 5}, -1)));
