#pragma once

class Solution {
   public:
    bool checkPowersOfThree(int n) {
        // The number can not be represented as sum of powers of 3 if its
        // ternary representation has a 2 in it So we convert the number to
        // tenary representation and check if it contains a 2 to return false
        // Wiki: https://en.wikipedia.org/wiki/Ternary_numeral_system
        while (n > 0) {
            if (n % 3 == 2) return false;
            n /= 3;
        }

        return true;
    }
};