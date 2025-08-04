#pragma once

class Solution {
   public:
    int hammingDistance(int x, int y) {
        int c = x ^ y;
        int count = 0;

        for (int i = 0; i < 32; ++i) {
            if (c & (1 << i)) {
                ++count;
            }
        }

        return count;
    }
};
