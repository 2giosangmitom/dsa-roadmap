#pragma once

#include <vector>
using namespace std;

class Solution {
   private:
    vector<bool> sieve(int n) {
        vector<bool> primes(n + 1, true);
        primes[0] = primes[1] = false;

        for (int i = 2; i * i <= n; i++) {
            if (primes[i]) {
                for (int j = i * 2; j <= n; j += i) {
                    primes[j] = false;
                }
            }
        }

        return primes;
    }

   public:
    int countPrimes(int n) {
        if (n < 2) return 0;

        auto primes = sieve(n);

        int count = 0;
        if (n >= 3) count++;

        for (int i = 3; i < n; i += 2) {
            if (primes[i]) {
                count++;
            }
        }

        return count;
    }
};
