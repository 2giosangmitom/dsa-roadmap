/**
 * @param {number} left
 * @param {number} right
 * @return {number[]}
 */
function closestPrimes (left, right) {
  const primes = sieve(right)
  let max = Number.MAX_SAFE_INTEGER
  const res = [-1, -1]

  for (let i = left; i <= right; i++) {
    if (!primes[i]) {
      continue
    }

    for (let j = i + 1; j <= right; j++) {
      if (primes[j]) {
        const sub = j - i

        if (sub < max) {
          res[0] = i
          res[1] = j
          max = sub
        }

        break
      }
    }
  }

  return res
}

/**
 * @param {number} right
 * @returns {boolean[]}
 */
function sieve (right) {
  const res = new Array(right + 1)
  res[0] = res[1] = false
  res.fill(true, 2)

  for (let i = 2; i < res.length / 2; i++) {
    if (res[i]) {
      for (let j = i * 2; j < res.length; j += i) {
        res[j] = false
      }
    }
  }

  return res
}

export { closestPrimes }
