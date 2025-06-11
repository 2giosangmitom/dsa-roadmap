#pragma once

#include <vector>
using namespace std;

class Solution {
   public:
    int maximumCount(vector<int> &nums) {
        int lower = lower_bound(nums);
        int upper = upper_bound(nums);

        int positive = lower != -1 ? nums.size() - lower : 0;
        int negative = upper + 1;
        return max(positive, negative);
    }

   private:
    int lower_bound(const vector<int> &nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = (left + right) / 2;

            if (nums[mid] > 0) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }

        return nums[left] > 0 ? left : -1;
    }

    int upper_bound(const vector<int> &nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left < right) {
            int mid = (left + right) / 2 + 1;

            if (nums[mid] < 0) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }

        return nums[right] < 0 ? right : -1;
    }
};
