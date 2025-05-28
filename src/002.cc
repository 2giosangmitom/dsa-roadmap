#include "linked_list.hh"
#include "utils.hh"
#include <gtest/gtest.h>
#include <nlohmann/json.hpp>
#include <vector>

class Solution {
public:
  // Overall time complexity is O(n) where n is the maximum length of the two
  // input linked lists. The space complexity is O(n) for the output linked
  // list.
  ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
    ListNode dummy_head(0);
    ListNode *curr = &dummy_head;
    int carry = 0; // Holds the carry for addition

    while (l1 != nullptr || l2 != nullptr || carry != 0) {
      int digit1 = l1 != nullptr ? l1->val : 0;
      int digit2 = l2 != nullptr ? l2->val : 0;
      // Calculate the sum of the two digits and carry
      int sum = digit1 + digit2 + carry;

      // Calculate the digit to store in the current node and the new carry
      int digit = sum % 10;
      carry = sum / 10;

      // Create a new node with the calculated digit and move the current
      // pointer
      curr->next = new ListNode(digit);
      curr = curr->next;

      if (l1 != nullptr) {
        l1 = l1->next;
      }
      if (l2 != nullptr) {
        l2 = l2->next;
      }
    }

    return dummy_head.next;
  }
};

//-- Test cases for the addTwoNumbers function
struct Data {
  std::vector<int> l1;
  std::vector<int> l2;
  std::vector<int> expected;
};

NLOHMANN_DEFINE_TYPE_NON_INTRUSIVE(Data, l1, l2, expected);

TEST(SolutionTest, AddTwoNumbers) {
  auto test_cases = utils::json::loadJsonArray<Data>(TEST_DATA_DIR "/002.json");
  ASSERT_TRUE(test_cases.has_value());

  Solution solution;
  for (const auto &test_case : test_cases.value()) {
    ListNode *l1 = create_list(test_case.l1);
    ListNode *l2 = create_list(test_case.l2);
    ListNode *expected = create_list(test_case.expected);

    ListNode *actual = solution.addTwoNumbers(l1, l2);
    EXPECT_TRUE(list_equal(actual, expected));

    delete_list({l1, l2, expected, actual});
  }
}