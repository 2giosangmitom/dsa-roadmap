/**
 * @param {string} s
 * @return {boolean}
 */
function isPalindrome (s) {
  s = s.replace(/[^a-z]|\s/gi, '').toLowerCase()

  for (let i = 0; i < s.length; i++) {
    if (s[i] !== s[s.length - i - 1]) {
      return false
    }
  }

  return true
}

/**
 * @param {string} s
 * @return {boolean}
 */
function isPalindrome2 (s) {
  let left = 0
  let right = s.length - 1

  while (left < right) {
    const pattern = /[a-z0-9]/i
    while (left < right && !pattern.test(s[left])) {
      left++
    }
    while (left < right && !pattern.test(s[right])) {
      right--
    }

    if (s[left].toLowerCase() !== s[right].toLowerCase()) {
      return false
    }
    left++
    right--
  }

  return true
}

export { isPalindrome, isPalindrome2 }
