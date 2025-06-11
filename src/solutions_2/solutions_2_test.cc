#include "solutions_2.hpp"

#include <gtest/gtest.h>

#include <tuple>
#include <vector>

class Solutions_2_Test
    : public testing::TestWithParam<
          std::tuple<std::vector<int>, std::vector<int>, std::vector<int>>> {
   protected:
    Solution solution;
};

TEST_P(Solutions_2_Test, AddTwoNumbers) {
    auto [l1_values, l2_values, expected_values] = GetParam();
    auto l1 = make_list(l1_values);
    auto l2 = make_list(l2_values);
    auto expected = make_list(expected_values);

    auto actual = solution.addTwoNumbers(l1, l2);

    EXPECT_EQ(*actual, *expected);

    delete_list({actual, l1, l2, expected});
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_2_Test,
    testing::Values(make_tuple(std::vector<int>{2, 4, 3},
                               std::vector<int>{5, 6, 4},
                               std::vector<int>{7, 0, 8}),
                    make_tuple(std::vector<int>{0}, std::vector<int>{0},
                               std::vector<int>{0}),
                    make_tuple(std::vector<int>{9, 9, 9, 9, 9, 9, 9},
                               std::vector<int>{9, 9, 9, 9},
                               std::vector<int>{8, 9, 9, 9, 0, 0, 0, 1}),
                    make_tuple(std::vector<int>{1, 8}, std::vector<int>{0},
                               std::vector<int>{1, 8}),
                    make_tuple(std::vector<int>{5}, std::vector<int>{5},
                               std::vector<int>{0, 1})));
