#include "solutions_445.hpp"

#include <gtest/gtest.h>

#include <tuple>
#include <vector>

class Solutions_445_Test
    : public testing::TestWithParam<
          std::tuple<std::vector<int>, std::vector<int>, std::vector<int>>> {
   protected:
    Solution solutions;
};

TEST_P(Solutions_445_Test, ) {
    auto get_tail = [](ListNode* head) {
        auto tail = head;
        while (tail->next) {
            tail = tail->next;
        }
        return tail;
    };
    auto [l1_vals, l2_vals, expected_vals] = GetParam();
    auto l1 = make_list(l1_vals);
    auto l2 = make_list(l2_vals);
    auto expected = make_list(expected_vals);
    auto l1_tail = get_tail(l1);
    auto l2_tail = get_tail(l2);

    auto actual = solutions.addTwoNumbers(l1, l2);

    if (actual == nullptr) {
        EXPECT_EQ(expected, nullptr);
    } else {
        EXPECT_EQ(*actual, *expected);
    }
    delete_list({actual, expected, l1_tail, l2_tail});
}

INSTANTIATE_TEST_SUITE_P(
    , Solutions_445_Test,
    testing::Values(std::make_tuple(std::vector<int>{7, 2, 4, 3},
                                    std::vector<int>{5, 6, 4},
                                    std::vector<int>{7, 8, 0, 7}),
                    std::make_tuple(std::vector<int>{2, 4, 3},
                                    std::vector<int>{5, 6, 4},
                                    std::vector<int>{8, 0, 7})));
