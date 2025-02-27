/**
 * @param {string} s
 * @return {number}
 */
function lengthOfLastWord (s) {
  let res = 0

  let i = s.length - 1

  // Skip trailing spaces
  while (i >= 0 && s[i] === ' ') {
    i--
  }

  while (i >= 0 && s[i--] !== ' ') {
    res++
  }

  return res
}

export { lengthOfLastWord }
