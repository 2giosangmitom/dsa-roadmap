#include "../lib/linked_list.h"
#include <criterion/criterion.h>
#include <criterion/internal/assert.h>
#include <criterion/internal/test.h>
#include <string.h>

Test(linked_list, case1) {
  int values[] = {1, 2, 3, 4, 5};
  struct ListNode *list = create_list(values, 5);

  struct ListNode *current = list;
  int i = 0;

  while (current) {
    cr_assert_eq(current->val, values[i]);
    i++;
    current = current->next;
  }

  free_list(list);
}

Test(linked_list, empty_list) {
  struct ListNode *list = create_list(NULL, 0);
  cr_assert_null(list);
}

Test(linked_list, single_element) {
  int values[] = {42};
  struct ListNode *list = create_list(values, 1);

  cr_assert_not_null(list);
  cr_assert_eq(list->val, 42);
  cr_assert_null(list->next);

  free_list(list);
}

Test(linked_list, duplicate_values) {
  int values[] = {3, 3, 3, 3};
  struct ListNode *list = create_list(values, 4);

  struct ListNode *current = list;
  for (int i = 0; i < 4; i++) {
    cr_assert_eq(current->val, 3);
    current = current->next;
  }

  cr_assert_null(current);
  free_list(list);
}

Test(linked_list, negative_values) {
  int values[] = {-5, -10, -15};
  struct ListNode *list = create_list(values, 3);

  int expected[] = {-5, -10, -15};
  struct ListNode *current = list;
  for (int i = 0; i < 3; i++) {
    cr_assert_eq(current->val, expected[i]);
    current = current->next;
  }

  cr_assert_null(current);
  free_list(list);
}

Test(linked_list, to_string_empty) {
  struct ListNode *list = NULL;

  char *expected = "Empty list";
  char *actual = list_to_str(list);

  cr_assert_eq(strlen(actual), strlen(expected));
  cr_assert_eq(strcmp(actual, expected), 0);

  free(actual);
}

Test(linked_list, to_string_single_element) {
  int values[] = {99};
  struct ListNode *list = create_list(values, 1);

  char *expected = "99";
  char *actual = list_to_str(list);

  cr_assert_eq(strlen(actual), strlen(expected));
  cr_assert_eq(strcmp(actual, expected), 0);

  free_list(list);
  free(actual);
}

Test(linked_list, to_string_contains_zero) {
  int values[] = {0, 1, 2};
  struct ListNode *list = create_list(values, 3);

  char *expected = "0 -> 1 -> 2";
  char *actual = list_to_str(list);

  cr_assert_eq(strlen(actual), strlen(expected));
  cr_assert_eq(strcmp(actual, expected), 0);

  free_list(list);
  free(actual);
}

Test(linked_list, to_string_large_numbers) {
  int values[] = {12345, 67890, 54321};
  struct ListNode *list = create_list(values, 3);

  char *expected = "12345 -> 67890 -> 54321";
  char *actual = list_to_str(list);

  cr_assert_eq(strlen(actual), strlen(expected));
  cr_assert_eq(strcmp(actual, expected), 0);

  free_list(list);
  free(actual);
}
