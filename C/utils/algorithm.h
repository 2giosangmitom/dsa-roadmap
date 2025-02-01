#ifndef ALGORITHM_H
#define ALGORITHM_H

#define swap(v1, v2)                                                           \
  int temp = v1;                                                               \
  v1 = v2;                                                                     \
  v2 = temp

#define sort(nums, numsSize)                                                   \
  for (int i = 0; i < numsSize; i++) {                                         \
    bool haveSwap = false;                                                     \
    for (int j = 0; j < numsSize - i - 1; j++) {                               \
      if (nums[j] > nums[j + 1]) {                                             \
        swap(nums[j], nums[j + 1]);                                            \
        haveSwap = true;                                                       \
      }                                                                        \
    }                                                                          \
    if (!haveSwap) {                                                           \
      break;                                                                   \
    }                                                                          \
  }

#endif // ALGORITHM_H