#include "solutions_23.hpp"
#include <gtest/gtest.h>
#include <memory>
#include <vector>

class Solutions_23_Test
    : public testing::TestWithParam<tuple<vector<vector<int>>, vector<int>>> {
protected:
  Solution solution;
};

TEST_P(Solutions_23_Test, ) {
  auto [lists, expected] = GetParam();
  auto expected_list = unique_ptr<ListNode>(make_list(expected));
  vector<ListNode *> list_nodes;
  for (const auto &list : lists) {
    list_nodes.push_back(make_list(list));
  }

  auto result = unique_ptr<ListNode>(solution.mergeKLists(list_nodes));
  if (result.get() == nullptr) {
    EXPECT_EQ(result.get(), expected_list.get());
  } else {
    EXPECT_EQ(*result.get(), *expected_list.get());
  }
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_23_Test,
    testing::Values(
        make_tuple(vector<vector<int>>{{1, 4, 5}, {1, 3, 4}, {2, 6}},
                   vector<int>{1, 1, 2, 3, 4, 4, 5, 6}),
        make_tuple(vector<vector<int>>{}, vector<int>{}),
        make_tuple(vector<vector<int>>{{}}, vector<int>{}),
        make_tuple(vector<vector<int>>{{1}}, vector<int>{1}),
        make_tuple(vector<vector<int>>{{1}, {2}}, vector<int>{1, 2}),
        make_tuple(vector<vector<int>>{{1}, {2}, {3}}, vector<int>{1, 2, 3})));
