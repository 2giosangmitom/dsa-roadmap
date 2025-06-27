#pragma once

#include <algorithm>
#include <cstdint>
#include <random>
#include <span>
#include <utility>
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

    // Merge sort
    vector<int> sortArray4(vector<int> &nums) {
        merge_sort(nums);
        return nums;
    }

    // Bubble sort
    vector<int> sortArray5(vector<int> &nums) {
        size_t n = nums.size();

        for (size_t i = 0; i < n; i++) {
            bool have_swap = false;
            for (size_t j = 0; j < n - i - 1; j++) {
                if (nums[j] > nums[j + 1]) {
                    swap(nums[j], nums[j + 1]);
                    have_swap = true;
                }
            }
            if (!have_swap) {
                break;
            }
        }

        return nums;
    }

    // Insertion sort
    vector<int> sortArray6(vector<int> &nums) {
        size_t n = nums.size();
        for (size_t i = 1; i < n; i++) {
            int key = nums[i];
            int j = i - 1;

            while (j >= 0 && nums[j] > key) {
                nums[j + 1] = nums[j];
                j--;
            }
            nums[j + 1] = key;
        }

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
        std::uniform_int_distribution<std::mt19937::result_type> dist(
            left, right - 1);

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

    void merge(std::span<int> origin, std::span<int> left,
               std::span<int> right) {
        size_t i = 0, j = 0, k = 0;

        while (i < left.size() && j < right.size()) {
            origin[k++] = (left[i] < right[j]) ? left[i++] : right[j++];
        }

        while (i < left.size()) origin[k++] = left[i++];
        while (j < right.size()) origin[k++] = right[j++];
    }

    void merge_sort(std::span<int> nums) {
        if (nums.size() <= 1) return;

        size_t mid = nums.size() / 2;

        std::vector<int> buffer(nums.begin(), nums.end());
        auto left = std::span<int>(buffer.data(), mid);
        auto right = std::span<int>(buffer.data() + mid, buffer.size() - mid);

        merge_sort(left);
        merge_sort(right);

        merge(nums, left, right);
    }
};
