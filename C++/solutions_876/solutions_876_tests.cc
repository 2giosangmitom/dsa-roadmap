#include "solutions_876.hpp"
#include <gtest/gtest.h>

class Solutions_876_Test : public testing::Test {
protected:
  Solution solution;

  void check(vector<int> &nums, int expectedVal) {
    ListNode *head = ListNode::from(nums);
    ListNode *actual = solution.middleNode(head);

    ASSERT_NE(actual, nullptr);
    EXPECT_EQ(actual->val, expectedVal);

    free_list(head);
  }
};

TEST_F(Solutions_876_Test, case1) {
  vector<int> nums{1, 2, 3, 4, 5};
  check(nums, 3);
}

TEST_F(Solutions_876_Test, case2) {
  vector<int> nums{1, 2, 3, 4, 5, 6};
  check(nums, 4);
}

TEST_F(Solutions_876_Test, case3) {
  vector<int> nums{1};
  check(nums, 1);
}

TEST_F(Solutions_876_Test, case4) {
  vector<int> nums{1, 2};
  check(nums, 2);
}
