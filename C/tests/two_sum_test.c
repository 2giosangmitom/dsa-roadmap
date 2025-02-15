#include "../src/two_sum.h"
#include "../utils/array.h"
#include <criterion/criterion.h>
#include <stdlib.h>
#include <string.h>

Test(TwoSumTest, case1) {
  int nums[] = {2, 7, 11, 15};
  int numsSize = 4;
  int returnSize;
  int target = 9;
  int expected[] = {0, 1};
  int expected_returnSize = 2;
  char *expected_str = format_arr(expected, expected_returnSize);

  int *result = twoSum(nums, numsSize, target, &returnSize);
  char *result_str = format_arr(result, returnSize);

  cr_expect_eq(returnSize, expected_returnSize, "Expected: %d\nActual: %d",
               expected_returnSize, returnSize);
  cr_expect_arr_eq(result, expected, expected_returnSize,
                   "Expected: %s\nActual: %s", expected_str, result_str);

  free(result);
  free(result_str);
  free(expected_str);
}

Test(TwoSumTest, case_negative_numbers) {
  int nums[] = {-3, 4, 3, 90};
  int numsSize = 4;
  int returnSize;
  int target = 0;
  int expected[] = {0, 2};
  int expected_returnSize = 2;
  char *expected_str = format_arr(expected, expected_returnSize);

  int *result = twoSum(nums, numsSize, target, &returnSize);
  char *result_str = format_arr(result, returnSize);

  cr_expect_eq(returnSize, expected_returnSize, "Expected: %d\nActual: %d",
               expected_returnSize, returnSize);
  cr_expect_arr_eq(result, expected, expected_returnSize,
                   "Expected: %s\nActual: %s", expected_str, result_str);

  free(result);
  free(result_str);
  free(expected_str);
}

Test(TwoSumTest, case_with_zero) {
  int nums[] = {0, 4, 3, 0};
  int numsSize = 4;
  int returnSize;
  int target = 0;
  int expected[] = {0, 3};
  int expected_returnSize = 2;
  char *expected_str = format_arr(expected, expected_returnSize);

  int *result = twoSum(nums, numsSize, target, &returnSize);
  char *result_str = format_arr(result, returnSize);

  cr_expect_eq(returnSize, expected_returnSize, "Expected: %d\nActual: %d",
               expected_returnSize, returnSize);
  cr_expect_arr_eq(result, expected, expected_returnSize,
                   "Expected: %s\nActual: %s", expected_str, result_str);

  free(result);
  free(result_str);
  free(expected_str);
}

Test(TwoSumTest, case_no_solution) {
  int nums[] = {1, 2, 3, 4, 5};
  int numsSize = 5;
  int returnSize;
  int target = 20;
  char *expected_str = format_arr(NULL, 0);

  int *result = twoSum(nums, numsSize, target, &returnSize);
  char *result_str = format_arr(result, returnSize);

  cr_expect_eq(returnSize, 0, "Expected: %d\nActual: %d", 0, returnSize);
  cr_expect_null(result, "Expected: %s\nActual: %s", expected_str, result_str);

  free(result);
  free(result_str);
  free(expected_str);
}

Test(TwoSumTest, case_two_elements) {
  int nums[] = {1, 3};
  int numsSize = 2;
  int returnSize;
  int target = 4;
  int expected[] = {0, 1};
  int expected_returnSize = 2;
  char *expected_str = format_arr(expected, expected_returnSize);

  int *result = twoSum(nums, numsSize, target, &returnSize);
  char *result_str = format_arr(result, returnSize);

  cr_expect_eq(returnSize, expected_returnSize, "Expected: %d\nActual: %d",
               expected_returnSize, returnSize);
  cr_expect_arr_eq(result, expected, expected_returnSize,
                   "Expected: %s\nActual: %s", expected_str, result_str);

  free(result);
  free(result_str);
  free(expected_str);
}

Test(TwoSumTest, case_duplicate_numbers) {
  int nums[] = {3, 3, 4, 5};
  int numsSize = 4;
  int returnSize;
  int target = 6;
  int expected[] = {0, 1};
  int expected_returnSize = 2;
  char *expected_str = format_arr(expected, expected_returnSize);

  int *result = twoSum(nums, numsSize, target, &returnSize);
  char *result_str = format_arr(result, returnSize);

  cr_expect_eq(returnSize, expected_returnSize, "Expected: %d\nActual: %d",
               expected_returnSize, returnSize);
  cr_expect_arr_eq(result, expected, expected_returnSize,
                   "Expected: %s\nActual: %s", expected_str, result_str);

  free(result);
  free(result_str);
  free(expected_str);
}
