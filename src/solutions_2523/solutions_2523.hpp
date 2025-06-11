#pragma once

#include <cstdint>
#include <vector>
using namespace std;

class Solution {
   private:
    vector<bool> sieve(int right) {
        vector<bool> res(right + 1, true);
        res[0] = res[1] = false;

        for (int i = 2; i * i <= right; i++) {
            if (res[i]) {
                for (int j = i * i; j <= right; j += i) {
                    res[j] = false;
                }
            }
        }

        return res;
    }

   public:
    vector<int> closestPrimes(int left, int right) {
        if (left == right) return {-1, -1};
        if (left <= 2) return {2, 3};

        auto primes = sieve(right);
        int prev_prime = -1;
        int min_diff = INT32_MAX;
        vector<int> result(2, -1);

        // Optimization: only check odd numbers
        if (left % 2 == 0) {
            left++;
        }

        for (int i = left; i <= right; i += 2) {
            if (primes[i]) {
                if (prev_prime != -1 && i - prev_prime < min_diff) {
                    min_diff = i - prev_prime;
                    result[0] = prev_prime;
                    result[1] = i;
                }
                prev_prime = i;
            }
        }

        return result;
    }
};
