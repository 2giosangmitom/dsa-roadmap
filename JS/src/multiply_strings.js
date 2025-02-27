/**
 * @param {string} num1
 * @param {string} num2
 * @return {string}
 */
function multiply (num1, num2) {
  if (num1 === '0' || num2 === '0') {
    return '0'
  }

  const reversedNum1 = [...num1].reverse().join('')
  const reversedNum2 = [...num2].reverse().join('')

  const parts = []
  const l1 = reversedNum1.length
  const l2 = reversedNum2.length

  for (let i = 0; i < l2; i++) {
    let rs = '0'.repeat(i)
    let carry = 0

    for (let j = 0; j < l1; j++) {
      const mul = Number(reversedNum2[i]) * Number(reversedNum1[j]) + carry
      const digit = mul % 10
      carry = Math.floor(mul / 10)

      rs += digit
    }

    if (carry !== 0) {
      rs += carry
    }

    parts.push(rs)
  }

  let sum = '0'.repeat(l1 + l2)

  for (const part of parts) {
    sum = add(sum, part)
  }

  sum = sum.replace(/0+$/, '')

  return [...sum].reverse().join('')
}

/**
 * @param {string} num1
 * @param {string} num2
 * @return {string}
 */
function add (a, b) {
  const n1 = a.length
  const n2 = b.length

  let result = ''
  let i = 0
  let j = 0
  let carry = 0

  while (i < n1 || j < n2 || carry !== 0) {
    const digit1 = i < n1 ? Number(a[i]) : 0
    const digit2 = j < n2 ? Number(b[j]) : 0

    const sum = digit1 + digit2 + carry

    const digit = sum % 10
    carry = Math.floor(sum / 10)

    result += digit
    i++
    j++
  }

  return result
}

export { multiply }
