#include "linked_list.hpp"
#include <gtest/gtest.h>
#include <string>
#include <vector>

class LinkedListTest : public testing::TestWithParam<std::vector<int>> {};

// --- Test: Create List ---
TEST_P(LinkedListTest, CreateList) {
  auto list = make_list(GetParam());

  const auto &param = GetParam();

  ListNode *current = list;
  for (size_t i = 0; i < param.size(); ++i) {
    ASSERT_NE(current, nullptr);
    EXPECT_EQ(current->val, param[i]);
    current = current->next;
  }
  EXPECT_EQ(current, nullptr); // End of list

  delete_list({list});
}

// --- Test: Check equality between lists ---
TEST_P(LinkedListTest, Equal) {
  auto listA = make_list(GetParam());
  auto listB = make_list(GetParam());

  EXPECT_TRUE(*listA == *listB);

  delete_list({listA, listB});
}

// --- Test: Check inequality between lists ---
TEST_P(LinkedListTest, InEqual) {
  auto listA = make_list(GetParam());
  auto listB = make_list(GetParam());

  // Modify listB to make it different from listA
  if (listB->next) {
    listB->next->val += 1; // Change the value of the second node
  }

  EXPECT_FALSE(*listA == *listB);

  delete_list({listA, listB});
}

// --- Test: to_string function ---
TEST_P(LinkedListTest, ToString) {
  auto list = make_list(GetParam());
  std::string result = list->to_string();

  const auto &param = GetParam();
  std::string expected = "";
  for (size_t i = 0; i < param.size(); ++i) {
    expected += std::to_string(param[i]);
    if (i < param.size() - 1) {
      expected += " -> ";
    }
  }

  EXPECT_EQ(result, expected);

  delete_list({list});
}

INSTANTIATE_TEST_SUITE_P(, LinkedListTest,
                         testing::Values(std::vector<int>{1, 2, 3},
                                         std::vector<int>{4, 5, 6},
                                         std::vector<int>{10, 20, 30},
                                         std::vector<int>{99, 100, 101},
                                         std::vector<int>{1, 2, 3},
                                         std::vector<int>{10, 20, 30}));
