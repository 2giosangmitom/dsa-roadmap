/**
 * @param {number} x
 * @return {number}
 */
function reverse (x) {
  const MIN = -(2 ** 31)
  const MAX = -MIN - 1
  let result = 0

  const sign = x < 0 ? -1 : 1
  x = Math.abs(x)

  while (x > 0) {
    const lastDigit = x % 10

    if (
      result > MAX / 10 ||
      (result === Math.trunc(MAX / 10) && lastDigit > 7)
    ) {
      return 0
    }

    if (
      result < MIN / 10 ||
      (result === Math.trunc(MIN / 10) && lastDigit < -8)
    ) {
      return 0
    }

    result = result * 10 + lastDigit
    x = Math.trunc(x / 10)
  }

  return sign * result
}

export { reverse }
