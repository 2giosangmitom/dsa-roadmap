#include "linked_list.hh"
#include "utils.hh"
#include <gtest/gtest.h>
#include <nlohmann/detail/macro_scope.hpp>

class Solution {
public:
  ListNode *reverseBetween(ListNode *head, int left, int right) {
    ListNode dummy_head(0, head);
    ListNode *prev = &dummy_head;

    for (int i = 1; i < left; i++) {
      prev = prev->next;
    }

    ListNode *curr = prev->next;
    for (int i = 1; i <= right - left; i++) {
      ListNode *next_node = curr->next;
      curr->next = next_node->next;
      next_node->next = prev->next;
      prev->next = next_node;
    }

    return dummy_head.next;
  }
};

//-- Test cases for reverseBetween function
struct Data {
  std::vector<int> head;
  int left;
  int right;
  std::vector<int> expected;
};

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Data, head, left, right, expected);

TEST(SolutionTest, ReverseLList2) {
  auto test_cases = utils::json::loadJsonArray<Data>(TEST_DATA_DIR "/092.json");
  ASSERT_TRUE(test_cases.has_value());

  Solution solution;
  for (auto &tc : test_cases.value()) {
    auto head = create_list(tc.head);
    auto expected = create_list(tc.expected);
    auto actual = solution.reverseBetween(head, tc.left, tc.right);
    EXPECT_TRUE(list_equal(actual, expected)) << std::format(
        "Failed for input head: {}, left: {}, right: {}\nactual: {}, expected: "
        "{}",
        tc.head, tc.left, tc.right, list_to_vector(actual), tc.expected);
    delete_list({actual, expected});
  }
}
