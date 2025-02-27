/**
 * @param {string} s
 * @return {number}
 */
function romanToInt (s) {
  const map = {
    I: 1,
    V: 5,
    X: 10,
    L: 50,
    C: 100,
    D: 500,
    M: 1000
  }

  let result = 0
  let nextNumber = 0

  for (let i = s.length - 1; i >= 0; i--) {
    const number = map[s[i]]

    if (nextNumber > number) {
      result -= number
    } else {
      result += number
    }

    nextNumber = number
  }

  return result
}

export { romanToInt }
