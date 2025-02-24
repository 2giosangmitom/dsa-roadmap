#include "count_primes.hpp"
#include <cmath>
#include <vector>
using namespace std;

int Solution::countPrimes(int n) {
  auto sieve = [](size_t max) {
    vector<bool> res(max + 1, true);
    res[0] = res[1] = false;

    for (size_t i = 2; i <= static_cast<size_t>(sqrt(max)); i++) {
      if (res[i]) {
        for (size_t j = i + i; j <= max; j += i) {
          res[j] = false;
        }
      }
    }

    return res;
  };

  int count = 0;
  vector<bool> primes = sieve(size_t(n));

  if (n > 2) {
    count++;
  }
  for (size_t i = 3; i < size_t(n); i += 2) {
    if (primes[i]) {
      count++;
    }
  }

  return count;
}
