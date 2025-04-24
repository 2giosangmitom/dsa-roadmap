#include "solutions_19.hpp"

#include <gtest/gtest.h>

class Solutions_19_Test
    : public testing::TestWithParam<
          std::tuple<std::vector<int>, int, std::vector<int>>> {
 protected:
  Solution solution;
};

TEST_P(Solutions_19_Test, ) {
  auto [head_values, pos, expected_values] = GetParam();
  auto head = make_list(head_values);
  auto expected = make_list(expected_values);

  ListNode *actual = solution.removeNthFromEnd(head, pos);

  EXPECT_TRUE(actual == expected || *actual == *expected);

  delete_list({head, expected});
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_19_Test,
    testing::Values(make_tuple(std::vector<int>{1, 2, 3, 4, 5}, 2,
                               std::vector<int>{1, 2, 3, 5}),
                    make_tuple(std::vector<int>{1}, 1, std::vector<int>{}),
                    make_tuple(std::vector<int>{1, 2}, 1,
                               std::vector<int>{1})));
