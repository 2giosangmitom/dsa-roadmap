#include "../src/next_permutation.hpp"
#include <gtest/gtest.h>

class NextPermutationTest : public testing::Test {
protected:
  Solution s;
};

TEST_F(NextPermutationTest, case1) {
  vector<int> nums = {1, 2, 3};
  vector<int> expected = {1, 3, 2};

  s.nextPermutation(nums);

  EXPECT_EQ(nums, expected);
}

TEST_F(NextPermutationTest, case2) {
  vector<int> nums = {1, 3, 2};
  vector<int> expected = {2, 1, 3};

  s.nextPermutation(nums);

  EXPECT_EQ(nums, expected);
}

TEST_F(NextPermutationTest, case3) {
  vector<int> nums = {3, 2, 1};
  vector<int> expected = {1, 2, 3};

  s.nextPermutation(nums);

  EXPECT_EQ(nums, expected);
}

TEST_F(NextPermutationTest, case4) {
  vector<int> nums = {3};
  vector<int> expected = {3};

  s.nextPermutation(nums);

  EXPECT_EQ(nums, expected);
}

TEST_F(NextPermutationTest, case5) {
  vector<int> nums = {1, 3, 2, 4, 3, 2, 1};
  vector<int> expected = {1, 3, 3, 1, 2, 2, 4};

  s.nextPermutation(nums);

  EXPECT_EQ(nums, expected);
}

TEST_F(NextPermutationTest, case6) {
  vector<int> nums = {2, 2, 3, 3};
  vector<int> expected = {2, 3, 2, 3};

  s.nextPermutation(nums);

  EXPECT_EQ(nums, expected);
}

TEST_F(NextPermutationTest, case7) {
  vector<int> nums = {1, 1, 5};
  vector<int> expected = {1, 5, 1};

  s.nextPermutation(nums);

  EXPECT_EQ(nums, expected);
}

TEST_F(NextPermutationTest, case8) {
  vector<int> nums = {1, 5, 1};
  vector<int> expected = {5, 1, 1};

  s.nextPermutation(nums);

  EXPECT_EQ(nums, expected);
}

TEST_F(NextPermutationTest, case9) {
  vector<int> nums = {2, 3, 1, 3, 3};
  vector<int> expected = {2, 3, 3, 1, 3};

  s.nextPermutation(nums);

  EXPECT_EQ(nums, expected);
}

TEST_F(NextPermutationTest, case10) {
  vector<int> nums = {1, 4, 3, 2};
  vector<int> expected = {2, 1, 3, 4};

  s.nextPermutation(nums);

  EXPECT_EQ(nums, expected);
}

TEST_F(NextPermutationTest, case11) {
  vector<int> nums = {1, 2, 3, 6, 5, 4};
  vector<int> expected = {1, 2, 4, 3, 5, 6};

  s.nextPermutation(nums);

  EXPECT_EQ(nums, expected);
}

TEST_F(NextPermutationTest, case12) {
  vector<int> nums = {9, 8, 7, 6};
  vector<int> expected = {6, 7, 8, 9};

  s.nextPermutation(nums);

  EXPECT_EQ(nums, expected);
}

TEST_F(NextPermutationTest, case13) {
  vector<int> nums = {1, 1, 1, 1};
  vector<int> expected = {1, 1, 1, 1};

  s.nextPermutation(nums);

  EXPECT_EQ(nums, expected);
}

TEST_F(NextPermutationTest, case14) {
  vector<int> nums = {3, 2, 2, 1};
  vector<int> expected = {1, 2, 2, 3};

  s.nextPermutation(nums);

  EXPECT_EQ(nums, expected);
}

TEST_F(NextPermutationTest, case15) {
  vector<int> nums = {1, 9, 8, 7};
  vector<int> expected = {7, 1, 8, 9};

  s.nextPermutation(nums);

  EXPECT_EQ(nums, expected);
}
