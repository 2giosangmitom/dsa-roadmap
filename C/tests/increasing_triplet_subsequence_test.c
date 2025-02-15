#include "../src/increasing_triplet_subsequence.h"
#include <criterion/criterion.h>

Test(IncreasingTripletSubsequence, case1) {
  int nums[] = {1, 2, 3, 4, 5};
  bool expected = true;

  bool actual = increasingTriplet(nums, 5);

  cr_expect_eq(actual, expected);
}

Test(IncreasingTripletSubsequence, case2) {
  int nums[] = {1, 1, 3, 4, 5};
  bool expected = true;

  bool actual = increasingTriplet(nums, 5);

  cr_expect_eq(actual, expected);
}

Test(IncreasingTripletSubsequence, case3) {
  int nums[] = {9, 1, 3, 7, 5};
  bool expected = true;

  bool actual = increasingTriplet(nums, 5);

  cr_expect_eq(actual, expected);
}

Test(IncreasingTripletSubsequence, case4) {
  int nums[] = {9, 7, 1, 2, -2};
  bool expected = false;

  bool actual = increasingTriplet(nums, 5);

  cr_expect_eq(actual, expected);
}

Test(IncreasingTripletSubsequence, case5) {
  int nums[] = {5, 4, 3, 2, 1};
  bool expected = false;

  bool actual = increasingTriplet(nums, 5);

  cr_expect_eq(actual, expected);
}
