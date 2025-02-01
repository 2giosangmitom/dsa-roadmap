#include <stdbool.h>
#include <stdlib.h>
#include <uthash.h>

typedef struct {
  int num; // Key
  int index;
  UT_hash_handle hh;
} map_entry;

void add(map_entry **m, int num, int index) {
  map_entry *e;

  // Check if entry exist in the hash table
  HASH_FIND_INT(*m, &num, e);

  if (e == NULL) {
    e = malloc(sizeof(*e));
    e->index = index;
    e->num = num;
    HASH_ADD_INT(*m, num, e);
  }
}

void release(map_entry **m) {
  map_entry *current, *tmp;

  HASH_ITER(hh, *m, current, tmp) {
    HASH_DEL(*m, current);
    free(current);
  }
}

map_entry *find(map_entry **m, int num) {
  map_entry *e;
  HASH_FIND_INT(*m, &num, e);
  return e;
}

int *twoSum(int *nums, int numsSize, int target, int *returnSize) {
  map_entry *m = NULL;

  for (int i = 0; i < numsSize; i++) {
    int need = target - nums[i];
    map_entry *e = find(&m, need);

    if (e != NULL) {
      *returnSize = 2;
      int *res = malloc(sizeof(int) * 2);
      res[0] = e->index;
      res[1] = i;
      release(&m);
      return res;
    }

    add(&m, nums[i], i);
  }

  *returnSize = 1;
  int *res = malloc(sizeof(int));
  res[0] = -1;
  release(&m);
  return res;
}