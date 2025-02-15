#include "two_sum.h"
#include <uthash.h>

typedef struct {
  int num; // Key
  int index;
  UT_hash_handle hh;
} map_entry;

void release(map_entry **m) {
  map_entry *current, *tmp;
  HASH_ITER(hh, *m, current, tmp) {
    HASH_DEL(*m, current);
    free(current);
  }
}

int *twoSum(int *nums, int numsSize, int target, int *returnSize) {
  map_entry *m = NULL;

  for (int i = 0; i < numsSize; i++) {
    int need = target - nums[i];
    map_entry *e;
    HASH_FIND_INT(m, &need, e);

    if (e) {
      *returnSize = 2;
      int *res = malloc(2 * sizeof(int));
      res[0] = e->index;
      res[1] = i;
      release(&m);
      return res;
    }

    e = malloc(sizeof(*e));
    e->index = i;
    e->num = nums[i];
    HASH_ADD_INT(m, num, e);
  }

  *returnSize = 0;
  release(&m);
  return NULL;
}
