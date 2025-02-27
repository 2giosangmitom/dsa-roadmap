/**
 * @param {string} s
 * @returns {number}
 */
function lengthOfLongestSubstring (s) {
  const set = new Set()
  let left = 0
  let right = 0
  let result = 0

  while (right < s.length) {
    if (set.has(s[right])) {
      set.delete(s[left++])
    } else {
      result = Math.max(result, right - left + 1)
      set.add(s[right++])
    }
  }

  return result
}

export { lengthOfLongestSubstring }
