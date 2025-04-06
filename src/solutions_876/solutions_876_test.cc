#include "solutions_876.hpp"
#include <gtest/gtest.h>
#include <tuple>

class Solutions_876_Test
    : public testing::TestWithParam<tuple<vector<int>, int>> {
protected:
  Solution solution;
};

TEST_P(Solutions_876_Test, ) {
  auto [nums, index] = GetParam();
  auto head = make_list(nums);
  ListNode *expected = head.get();
  for (int i = 0; i < index; i++) {
    expected = expected->next;
  }

  ListNode *actual = solution.middleNode(head.get());

  ASSERT_NE(actual, nullptr);
  EXPECT_EQ(actual, expected);
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_876_Test,
    testing::Values(make_tuple(vector<int>{1, 2, 3, 4, 5}, 2),
                    make_tuple(vector<int>{1, 2, 3, 4, 5, 6}, 3),
                    make_tuple(vector<int>{1, 2}, 1)));
