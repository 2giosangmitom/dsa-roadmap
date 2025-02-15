#include "../lib/array.h"
#include <criterion/criterion.h>

Test(ArrayUtilsTest, format_arr_case1) {
  int nums[] = {1, 2, 3};
  int nums_size = 3;
  char expected[] = "[1,2,3]";

  char *result = format_arr(nums, nums_size);

  cr_expect_str_eq(result, expected);

  free(result);
}

Test(ArrayUtilsTest, format_arr_case2) {
  int nums[] = {-1, 200, 3};
  int nums_size = 3;
  char expected[] = "[-1,200,3]";

  char *result = format_arr(nums, nums_size);

  cr_expect_str_eq(result, expected);

  free(result);
}

Test(ArrayUtilsTest, format_arr_large_numbers) {
  int nums[] = {12345, -67890, 0};
  int nums_size = 3;
  char expected[] = "[12345,-67890,0]";

  char *result = format_arr(nums, nums_size);

  cr_expect_str_eq(result, expected);

  free(result);
}
