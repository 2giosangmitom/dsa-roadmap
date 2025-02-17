#include "two_sum_2.h"
#include <stdlib.h>

int *twoSum2(int *numbers, int numbersSize, int target, int *returnSize) {
  int left = 0;
  int right = numbersSize - 1;

  while (left < right) {
    int sum = numbers[left] + numbers[right];

    if (sum == target) {
      int *result = (int *)calloc(2, sizeof(int));
      *returnSize = 2;
      result[0] = left + 1;
      result[1] = right + 1;
      return result;
    }

    if (sum < target) {
      left++;
    } else {
      right--;
    }
  }

  *returnSize = 0;
  return NULL;
}
