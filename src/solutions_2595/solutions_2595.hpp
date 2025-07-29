#pragma once

#include <vector>
using std::vector;

class Solution {
   public:
    vector<int> evenOddBit(int n) {
        int count_even = 0;
        int count_bit_1 = 0;

        for (int i = 0; i < 32; ++i) {
            if (n & (1 << i)) {
                count_bit_1++;
                if ((i & 1) == 0) {
                    count_even++;
                }
            }
        }

        return {count_even, count_bit_1 - count_even};
    }
};
