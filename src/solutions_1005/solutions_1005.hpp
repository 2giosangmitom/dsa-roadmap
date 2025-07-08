#pragma once

#include <algorithm>
#include <functional>
#include <numeric>
#include <vector>

using std::vector;

class Solution {
   public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        std::make_heap(nums.begin(), nums.end(), std::greater<>());

        while (k > 0) {
            std::pop_heap(nums.begin(), nums.end(), std::greater<>());
            int num = nums.back();
            nums.pop_back();
            nums.push_back(-num);
            std::push_heap(nums.begin(), nums.end(), std::greater<>());
            k--;
        }

        return std::accumulate(nums.begin(), nums.end(), 0);
    }
};
