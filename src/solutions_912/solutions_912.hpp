#pragma once

#include <algorithm>
#include <cstdint>
#include <random>
#include <vector>
using namespace std;

class Solution {
 public:
  // Heap sort (if you don't want to implement a heap) :)
  vector<int> sortArray(vector<int> &nums) {
    make_heap(nums.begin(), nums.end());

    for (size_t i = 0; i < nums.size() - 1; i++) {
      pop_heap(nums.begin(), nums.end() - i);
    }

    return nums;
  }

  // Quick sort (using right-most pivot)
  vector<int> sortArray2(vector<int> &nums) {
    quick_sort(nums, 0, nums.size() - 1);
    return nums;
  }

  // Quick sort (using random pivot)
  vector<int> sortArray3(vector<int> &nums) {
    quick_sort2(nums, 0, nums.size() - 1);
    return nums;
  }

 private:
  void quick_sort(vector<int> &nums, int64_t left, int64_t right) {
    if (left >= right) {
      return;
    }

    int &pivot = nums[right];
    int j = left;

    for (int64_t i = left; i < right; i++) {
      if (nums[i] < pivot) {
        swap(nums[i], nums[j++]);
      }
    }
    swap(nums[j], nums[right]);

    quick_sort(nums, left, j - 1);
    quick_sort(nums, j + 1, right);
  }

  void quick_sort2(vector<int> &nums, int64_t left, int64_t right) {
    if (left >= right) {
      return;
    }

    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> dist(left,
                                                                  right - 1);

    swap(nums[dist(rng)], nums[right]);
    int &pivot = nums[right];
    int j = left;

    for (int64_t i = left; i < right; i++) {
      if (nums[i] < pivot) {
        swap(nums[i], nums[j++]);
      }
    }
    swap(nums[j], nums[right]);

    quick_sort2(nums, left, j - 1);
    quick_sort2(nums, j + 1, right);
  }
};
