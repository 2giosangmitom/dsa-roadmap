#include "../lib/linked_list.h"
#include "../src/add_two_numbers.c"
#include <criterion/criterion.h>

Test(add_two_numbers, case1) {
  int l1_vals[] = {2, 4, 3};
  struct ListNode *l1 = create_list(l1_vals, 3);
  int l2_vals[] = {5, 6, 4};
  struct ListNode *l2 = create_list(l2_vals, 3);

  struct ListNode *actual = addTwoNumbers(l1, l2);
  char *actual_str = list_to_str(actual);
  char *want = "7 -> 0 -> 8";

  cr_assert_eq(strlen(actual_str), strlen(want));
  cr_assert_eq(strcmp(actual_str, want), 0);

  free_list(l1);
  free_list(l2);
  free_list(actual);
  free(actual_str);
}

Test(add_two_numbers, empty_list) {
  struct ListNode *l1 = NULL;
  int l2_vals[] = {1, 2, 3};
  struct ListNode *l2 = create_list(l2_vals, 3);

  struct ListNode *actual = addTwoNumbers(l1, l2);
  char *actual_str = list_to_str(actual);
  char *want = "1 -> 2 -> 3";

  cr_assert_eq(strcmp(actual_str, want), 0);

  free_list(l2);
  free_list(actual);
  free(actual_str);
}

Test(add_two_numbers, different_length) {
  int l1_vals[] = {1};
  struct ListNode *l1 = create_list(l1_vals, 1);
  int l2_vals[] = {9, 9, 9};
  struct ListNode *l2 = create_list(l2_vals, 3);

  struct ListNode *actual = addTwoNumbers(l1, l2);
  char *actual_str = list_to_str(actual);
  char *want = "0 -> 0 -> 0 -> 1";

  cr_assert_eq(strcmp(actual_str, want), 0);

  free_list(l1);
  free_list(l2);
  free_list(actual);
  free(actual_str);
}

Test(add_two_numbers, single_element) {
  int l1_vals[] = {5};
  struct ListNode *l1 = create_list(l1_vals, 1);
  int l2_vals[] = {7};
  struct ListNode *l2 = create_list(l2_vals, 1);

  struct ListNode *actual = addTwoNumbers(l1, l2);
  char *actual_str = list_to_str(actual);
  char *want = "2 -> 1"; // 5 + 7 = 12

  cr_assert_eq(strcmp(actual_str, want), 0);

  free_list(l1);
  free_list(l2);
  free_list(actual);
  free(actual_str);
}
