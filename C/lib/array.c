#include "array.h"
#include <stdio.h>
#include <stdlib.h>

char *format_arr(int *arr, int arr_size) {
  int buffer_size = 3; // Default size ([]\0)

  for (int i = 0; i < arr_size; i++) {
    buffer_size += snprintf(nullptr, 0, "%d", arr[i]);
    if (i != arr_size - 1) {
      buffer_size++; // For ','
    }
  }

  char *res = malloc(buffer_size);
  char *ptr = res;

  *ptr++ = '[';

  for (int i = 0; i < arr_size; i++) {
    ptr += sprintf(ptr, "%d", arr[i]);
    if (i != arr_size - 1) {
      *ptr++ = ',';
    }
  }

  *ptr++ = ']';
  *ptr++ = '\0';

  return res;
}
