#include "../src/sort_an_array.c"
#include <criterion/criterion.h>

Test(sort_an_array, case1) {
  int nums[] = {65, 3, 4, 2, 1};
  int expected[] = {1, 2, 3, 4, 65};
  int returnSize;

  int *actual = sortArray(nums, 5, &returnSize);

  cr_assert_eq(returnSize, 5);
  cr_expect_arr_eq(actual, expected, 5);
  free(actual);
}

Test(sort_an_array, single_element) {
  int nums[] = {42};
  int expected[] = {42};
  int returnSize;

  int *actual = sortArray(nums, 1, &returnSize);

  cr_assert_eq(returnSize, 1);
  cr_expect_arr_eq(actual, expected, 1);
  free(actual);
}

Test(sort_an_array, already_sorted) {
  int nums[] = {1, 2, 3, 4, 5};
  int expected[] = {1, 2, 3, 4, 5};
  int returnSize;

  int *actual = sortArray(nums, 5, &returnSize);

  cr_assert_eq(returnSize, 5);
  cr_expect_arr_eq(actual, expected, 5);
  free(actual);
}

Test(sort_an_array, reverse_sorted) {
  int nums[] = {5, 4, 3, 2, 1};
  int expected[] = {1, 2, 3, 4, 5};
  int returnSize;

  int *actual = sortArray(nums, 5, &returnSize);

  cr_assert_eq(returnSize, 5);
  cr_expect_arr_eq(actual, expected, 5);
  free(actual);
}

Test(sort_an_array, duplicate_elements) {
  int nums[] = {4, 2, 2, 4, 1};
  int expected[] = {1, 2, 2, 4, 4};
  int returnSize;

  int *actual = sortArray(nums, 5, &returnSize);

  cr_assert_eq(returnSize, 5);
  cr_expect_arr_eq(actual, expected, 5);
  free(actual);
}
