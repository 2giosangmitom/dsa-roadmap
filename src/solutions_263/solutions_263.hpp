#pragma once

class Solution {
   public:
    bool isUgly(int n) {
        if (n <= 0) {
            return false;
        }

        int k = 2;
        while (n != 1) {
            if (k > 5) {
                return false;
            }
            while (n % k == 0) {
                n /= k;
            }
            if (k != 2) {
                k += 2;
            } else {
                k++;
            }
        }

        return true;
    }
};
