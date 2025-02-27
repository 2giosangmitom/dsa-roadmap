#include "find_all_anagrams_in_string.hpp"
#include <array>
#include <cstddef>
#include <vector>

vector<int> Solution::findAnagrams(string s, string p) {
  const size_t len_s = s.size();
  const size_t len_p = p.size();

  if (len_p > len_s) {
    return {};
  }

   array<int, 26> frequencies = {};
   array<int, 26> expected_frequencies = {};

   vector<int> result;
  result.reserve(len_s - len_p + 1); // Optimize memory allocation

  for (char c : p) {
    expected_frequencies[size_t(c) - 'a']++;
  }

  size_t left = 0;
  for (size_t right = 0; right < len_s; right++) {
    frequencies[size_t(s[right]) - 'a']++;

    if (right >= len_p - 1) {
      if (frequencies == expected_frequencies) {
        result.push_back(static_cast<int>(left));
      }
      frequencies[size_t(s[left]) - 'a']--;
      left++;
    }
  }

  return result;
}
