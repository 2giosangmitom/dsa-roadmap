/**
 * @param {number} n
 * @return {boolean}
 */
function isPowerOfTwo (n) {
  const x = Math.log2(n)
  return n > 0 && x === Math.trunc(x)
}

export { isPowerOfTwo }
