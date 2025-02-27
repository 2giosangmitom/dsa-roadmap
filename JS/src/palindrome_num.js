/**
 * @param {number} x
 * @returns {boolean}
 */
function isPalindrome (x) {
  if (x < 0 || (x % 10 === 0 && x !== 0)) {
    return false
  }

  let reversedHalf = 0
  while (x > reversedHalf) {
    reversedHalf = reversedHalf * 10 + (x % 10)
    x = Math.trunc(x / 10)
  }

  return x === reversedHalf || x === Math.trunc(reversedHalf / 10)
}

export { isPalindrome }
