#include "linked_list.hpp"
#include <gtest/gtest.h>
#include <memory>
#include <string>
#include <vector>

class LinkedListTest : public testing::TestWithParam<vector<int>> {
protected:
  unique_ptr<ListNode> makeListFromParam() {
    return unique_ptr<ListNode>(make_list(GetParam()));
  }
};

// --- Test: Create List ---
TEST_P(LinkedListTest, CreateList) {
  auto list = makeListFromParam();

  const auto &param = GetParam();

  ListNode *current = list.get();
  for (size_t i = 0; i < param.size(); ++i) {
    ASSERT_NE(current, nullptr);
    EXPECT_EQ(current->val, param[i]);
    current = current->next;
  }
  EXPECT_EQ(current, nullptr); // End of list
}

// --- Test: Check equality between lists ---
TEST_P(LinkedListTest, Equal) {
  auto listA = makeListFromParam();
  auto listB = makeListFromParam();
  EXPECT_TRUE(*listA == *listB);
}

// --- Test: Check inequality between lists ---
TEST_P(LinkedListTest, InEqual) {
  auto listA = makeListFromParam();
  auto listB = makeListFromParam();
  // Modify listB to make it different from listA
  if (listB->next) {
    listB->next->val += 1; // Change the value of the second node
  }
  EXPECT_FALSE(*listA == *listB);
}

// --- Test: to_string function ---
TEST_P(LinkedListTest, ToString) {
  auto list = makeListFromParam();
  string result = to_string(*list);

  const auto &param = GetParam();
  string expected = "";
  for (size_t i = 0; i < param.size(); ++i) {
    expected += to_string(param[i]);
    if (i < param.size() - 1) {
      expected += " -> ";
    }
  }

  EXPECT_EQ(result, expected);
}

INSTANTIATE_TEST_SUITE_P(
    , LinkedListTest,
    testing::Values(vector<int>{1, 2, 3}, vector<int>{4, 5, 6},
                    vector<int>{10, 20, 30}, vector<int>{99, 100, 101},
                    vector<int>{1, 2, 3}, vector<int>{10, 20, 30}));
