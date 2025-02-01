#include "../src/two_sum.h"
#include "../utils/algorithm.h"
#include <criterion/criterion.h>
#include <stdlib.h>

Test(two_sum, case1) {
  int nums[] = {2, 7, 11, 15};
  int returnSize;
  int *actual = twoSum(nums, 4, 9, &returnSize);
  sort(actual, returnSize);

  int want[] = {0, 1};

  cr_assert_not_null(actual, "Expected non-NULL result");
  cr_assert_eq(returnSize, 2, "Expected returnSize to be 2");
  cr_assert_arr_eq(actual, want, 2, "Expected [0, 1]");

  free(actual);
}

Test(two_sum, case2) {
  int nums[] = {3, 2, 4};
  int returnSize;
  int *actual = twoSum(nums, 3, 6, &returnSize);
  sort(actual, returnSize);

  int want[] = {1, 2};

  cr_assert_not_null(actual, "Expected non-NULL result");
  cr_assert_eq(returnSize, 2, "Expected returnSize to be 2");
  cr_assert_arr_eq(actual, want, 2, "Expected [1, 2]");

  free(actual);
}

Test(two_sum, case3) {
  int nums[] = {3, 3};
  int returnSize;
  int *actual = twoSum(nums, 2, 6, &returnSize);
  sort(actual, returnSize);

  int want[] = {0, 1};

  cr_assert_not_null(actual, "Expected non-NULL result");
  cr_assert_eq(returnSize, 2, "Expected returnSize to be 2");
  cr_assert_arr_eq(actual, want, 2, "Expected [0, 1]");

  free(actual);
}

Test(two_sum, case4_no_solution) {
  int nums[] = {1, 2, 3, 4, 5};
  int returnSize;
  int *actual = twoSum(nums, 5, 10, &returnSize);

  cr_assert_null(actual, "Expected NULL result when no solution exists");
  cr_assert_eq(returnSize, 0, "Expected returnSize to be 0");
}

Test(two_sum, case5_large_numbers) {
  int nums[] = {1000000, 250000, 750000, -1000000};
  int returnSize;
  int *actual = twoSum(nums, 4, 0, &returnSize);
  sort(actual, returnSize);

  int want[] = {0, 3};

  cr_assert_not_null(actual, "Expected non-NULL result");
  cr_assert_eq(returnSize, 2, "Expected returnSize to be 2");
  cr_assert_arr_eq(actual, want, 2, "Expected [0, 3]");

  free(actual);
}