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