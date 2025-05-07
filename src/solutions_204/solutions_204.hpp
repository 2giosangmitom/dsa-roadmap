#pragma once

#include <vector>
using namespace std;

class Solution {
 private:
  /**
   * @brief Generates a sieve of Eratosthenes to identify prime numbers up to n.
   * @param n The upper limit for the sieve.
   * @return A vector of booleans where true indicates a prime number.
   */
  vector<bool> sieve(int n) {
    vector<bool> primes(n + 1, true);
    primes[0] = primes[1] = false;

    // Mark non-prime numbers in the sieve
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
  /**
   * @brief Counts the number of prime numbers less than n.
   * @param n The upper limit (exclusive) to count prime numbers.
   * @return The number of prime numbers less than n.
   */
  int countPrimes(int n) {
    auto primes = sieve(n);

    int count = 0;
    if (n >= 3) count++;

    // Count the number of prime numbers less than n
    for (int i = 3; i < n; i += 2) {
      if (primes[i]) {
        count++;
      }
    }

    return count;
  }
};
