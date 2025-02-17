#include "../lib/array.h"
#include "../src/two_sum_2.h"
#include <criterion/criterion.h>

void run_test(int *nums, int numsSize, int target, int *expected,
              int expectedSize) {
  int returnSize;
  char *expected_str = format_arr(expected, expectedSize);

  int *actual = twoSum2(nums, numsSize, target, &returnSize);
  char *actual_str = format_arr(actual, returnSize);

  if (returnSize != expectedSize) {
    cr_expect_fail("Expected: %d\nActual: %d", expectedSize, returnSize);
    free(actual);
    free(expected_str);
    free(actual_str);
    return;
  }

  cr_expect_arr_eq(actual, expected, expectedSize, "Expected: %s\nActual: %s",
                   expected_str, actual_str);

  free(actual);
  free(expected_str);
  free(actual_str);
}

Test(TwoSum2, case1) {
  int nums[] = {2, 7, 11, 15};
  int expected[] = {1, 2};
  run_test(nums, 4, 9, expected, 2);
}

Test(TwoSum2, case2) {
  int nums[] = {1, 2, 3, 4, 5};
  int expected[] = {1, 3};
  run_test(nums, 5, 4, expected, 2);
}

Test(TwoSum2, case3) {
  int nums[] = {-3, 4, 3, 90};
  int expected[] = {1, 3};
  run_test(nums, 4, 0, expected, 2);
}

Test(TwoSum2, case4) {
  int nums[] = {1, 2, 3, 4};
  int *expected = NULL;
  run_test(nums, 4, 10, expected, 0);
}

Test(TwoSum2, case5) {
  int nums[] = {1, 3, 3, 4, 5};
  int expected[] = {1, 2};
  run_test(nums, 5, 4, expected, 2);
}

Test(TwoSum2, case6) {
  int nums[] = {1000000, 2030210, 3000000, 4000000};
  int expected[] = {1, 4};
  run_test(nums, 4, 5000000, expected, 2);
}

Test(TwoSum2, case7) {
  int nums[] = {42};
  int *expected = NULL;
  run_test(nums, 1, 42, expected, 0);
}

Test(TwoSum2, case8) {
  int nums[] = {-1, 0, 1};
  int expected[] = {1, 3};
  run_test(nums, 3, 0, expected, 2);
}

Test(TwoSum2, case9) {
  int nums[] = {-2, 1, 2};
  int expected[] = {1, 3};
  run_test(nums, 3, 0, expected, 2);
}

Test(TwoSum2, case10) {
  int nums[] = {-1000000, -500000, -100000, -50000, 500000};
  int expected[] = {2, 5};
  run_test(nums, 5, 0, expected, 2);
}

Test(TwoSum2, case11) {
  int nums[] = {10, 20, 30, 40, 50};
  int expected[] = {1, 5};
  run_test(nums, 5, 60, expected, 2);
}

Test(TwoSum2, case12) {
  int nums[] = {3, 3, 4, 4, 5, 5};
  int expected[] = {1, 2};
  run_test(nums, 6, 6, expected, 2);
}

Test(TwoSum2, case13) {
  int nums[] = {3, 7};
  int expected[] = {1, 2};
  run_test(nums, 2, 10, expected, 2);
}

Test(TwoSum2, case14) {
  int nums[] = {2, 5};
  int *expected = NULL;
  run_test(nums, 2, 10, expected, 0);
}

Test(TwoSum2, case15) {
  int nums[] = {-10, -20, 30, 50};
  int expected[] = {1, 3};
  run_test(nums, 4, 20, expected, 2);
}

Test(TwoSum2, case16) {
  int nums[] = {1, 4, 5, 9, 10};
  int expected[] = {2, 4};
  run_test(nums, 5, 14, expected, 2);
}

Test(TwoSum2, case17) {
  int nums[] = {1, 3, 5, 7, 9, 11};
  int expected[] = {2, 6};
  run_test(nums, 6, 14, expected, 2);
}

Test(TwoSum2, case18) {
  int nums[] = {2, 4, 5, 8, 10, 12, 14};
  int expected[] = {2, 7};
  run_test(nums, 7, 18, expected, 2);
}

Test(TwoSum2, case19) {
  int nums[] = {-1000, -500, 0, 500, 1000};
  int expected[] = {1, 5};
  run_test(nums, 5, 0, expected, 2);
}

Test(TwoSum2, case20) {
  int nums[] = {1, 2, 3, 5};
  int expected[] = {2, 3};
  run_test(nums, 4, 5, expected, 2);
}
