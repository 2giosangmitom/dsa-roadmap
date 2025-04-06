#include "solutions_2.hpp"
#include <gtest/gtest.h>
#include <memory>
#include <tuple>
#include <vector>

class Solutions_2_Test : public testing::TestWithParam<
                             tuple<vector<int>, vector<int>, vector<int>>> {
protected:
  Solution solution;
};

TEST_P(Solutions_2_Test, AddTwoNumbers) {
  auto [l1_values, l2_values, expected_values] = GetParam();
  auto l1 = unique_ptr<ListNode>(make_list(l1_values));
  auto l2 = unique_ptr<ListNode>(make_list(l2_values));
  auto expected = unique_ptr<ListNode>(make_list(expected_values));

  auto actual = solution.addTwoNumbers(l1.get(), l2.get());

  EXPECT_EQ(*actual, *expected);

  // Since the actual return a raw pointer, we have to delete it manually
  delete actual;
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_2_Test,
    testing::Values(
        make_tuple(vector<int>{2, 4, 3}, vector<int>{5, 6, 4},
                   vector<int>{7, 0, 8}),
        make_tuple(vector<int>{0}, vector<int>{0}, vector<int>{0}),
        make_tuple(vector<int>{9, 9, 9, 9, 9, 9, 9}, vector<int>{9, 9, 9, 9},
                   vector<int>{8, 9, 9, 9, 0, 0, 0, 1}),
        make_tuple(vector<int>{1, 8}, vector<int>{0}, vector<int>{1, 8}),
        make_tuple(vector<int>{5}, vector<int>{5}, vector<int>{0, 1})));
