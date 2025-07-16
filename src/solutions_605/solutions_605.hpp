#pragma once

#include <vector>

using std::vector;

class Solution {
   public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size = flowerbed.size();
        for (int i = 0; i < size; ++i) {
            if (n == 0) {
                return true;
            }
            bool canPlant = flowerbed[i] == 0 &&
                            (i == 0 || flowerbed[i - 1] == 0) &&
                            (i == size - 1 || flowerbed[i + 1] == 0);
            if (canPlant) {
                flowerbed[i] = 1;
                n--;
            }
        }

        return n == 0;
    }
};
