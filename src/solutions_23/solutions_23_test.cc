#include "solutions_23.hpp"

#include <gtest/gtest.h>

#include <vector>

class Solutions_23_Test
    : public testing::TestWithParam<
          std::tuple<std::vector<std::vector<int>>, std::vector<int>>> {
   protected:
    Solution solution;
};

TEST_P(Solutions_23_Test, ) {
    auto [lists, expected] = GetParam();
    auto expected_list = make_list(expected);
    std::vector<ListNode *> list_nodes;
    for (const auto &list : lists) {
        list_nodes.push_back(make_list(list));
    }

    auto result = solution.mergeKLists(list_nodes);
    if (result == nullptr) {
        EXPECT_EQ(result, expected_list);
    } else {
        EXPECT_EQ(*result, *expected_list);
    }

    delete_list({result, expected_list});
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_23_Test,
    testing::Values(
        make_tuple(std::vector<std::vector<int>>{{1, 4, 5}, {1, 3, 4}, {2, 6}},
                   std::vector<int>{1, 1, 2, 3, 4, 4, 5, 6}),
        make_tuple(std::vector<std::vector<int>>{}, std::vector<int>{}),
        make_tuple(std::vector<std::vector<int>>{{}}, std::vector<int>{}),
        make_tuple(std::vector<std::vector<int>>{{1}}, std::vector<int>{1}),
        make_tuple(std::vector<std::vector<int>>{{1}, {2}},
                   std::vector<int>{1, 2}),
        make_tuple(std::vector<std::vector<int>>{{1}, {2}, {3}},
                   std::vector<int>{1, 2, 3})));
