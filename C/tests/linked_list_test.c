#include "../lib/linked_list.h"
#include <criterion/criterion.h>
#include <criterion/internal/test.h>

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
