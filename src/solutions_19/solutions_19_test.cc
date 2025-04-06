#include "solutions_19.hpp"
#include <gtest/gtest.h>

class Solutions_19_Test
    : public testing::TestWithParam<tuple<vector<int>, int, vector<int>>> {
protected:
  Solution solution;
};

TEST_P(Solutions_19_Test, ) {
  auto [head_values, pos, expected_values] = GetParam();
  auto head = unique_ptr<ListNode>(make_list(head_values));
  auto expected = unique_ptr<ListNode>(make_list(expected_values));

  ListNode *actual = solution.removeNthFromEnd(head.get(), pos);

  EXPECT_TRUE(actual == expected.get() || *actual == *expected);
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_19_Test,
    testing::Values(make_tuple(vector<int>{1, 2, 3, 4, 5}, 2,
                               vector<int>{1, 2, 3, 5}),
                    make_tuple(vector<int>{1}, 1, vector<int>{}),
                    make_tuple(vector<int>{1, 2}, 1, vector<int>{1})));
