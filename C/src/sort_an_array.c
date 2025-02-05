#include <stdlib.h>

int left_child(const int *i) { return *i * 2 + 1; }
int right_child(const int *i) { return *i * 2 + 2; }

void swap(int *v1, int *v2) {
  int temp = *v1;
  *v1 = *v2;
  *v2 = temp;
}

void heapify(int *nums, int i, const int *numsSize) {
  int left = left_child(&i);
  int right = right_child(&i);

  int max = i;
  if (left < *numsSize && nums[left] > nums[max]) {
    max = left;
  }
  if (right < *numsSize && nums[right] > nums[max]) {
    max = right;
  }

  if (max != i) {
    swap(&nums[i], &nums[max]);
    heapify(nums, max, numsSize);
  }
}

void build_max_heap(int *nums, int numsSize) {
  for (int i = numsSize / 2; i >= 0; i--) {
    heapify(nums, i, &numsSize);
  }
}

int *sortArray(int *nums, int numsSize, int *returnSize) {
  *returnSize = numsSize;

  build_max_heap(nums, numsSize);

  while (numsSize > 0) {
    swap(&nums[0], &nums[numsSize - 1]);
    numsSize--;
    heapify(nums, 0, &numsSize);
  }

  int *res = (int *)malloc(*returnSize * sizeof(int));

  for (int i = 0; i < *returnSize; i++) {
    res[i] = nums[i];
  }

  return res;
}
