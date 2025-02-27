import { expect, test } from 'vitest'
import { reverse } from '../src/reverse_integer.js'

const testCases = [
  {
    name: 'should reverse a positive number',
    input: 123,
    expected: 321
  },
  {
    name: 'should reverse a negative number',
    input: -123,
    expected: -321
  },
  {
    name: 'should remove leading zeros after reversing',
    input: 120,
    expected: 21
  },
  {
    name: 'should return 0 when the input is 0',
    input: 0,
    expected: 0
  },
  {
    name: 'should return 0 if the reversed number exceeds 32-bit integer range',
    input: 1534236469,
    expected: 0
  },
  {
    name: 'should return 0 if the reversed negative number exceeds 32-bit integer range',
    input: -1534236469,
    expected: 0
  },
  {
    name: 'should handle large negative numbers within bounds',
    input: -2147483412,
    expected: -2143847412
  },
  {
    name: 'should return the correct reversed number within 32-bit bounds',
    input: 1463847412,
    expected: 2147483641
  },
  {
    name: 'should return 0 if the reversed number goes out of bounds',
    input: -2147483648,
    expected: 0
  }
]

testCases.forEach(({ name, input, expected }) => {
  test(name, () => {
    const result = reverse(input)
    expect(result).toBe(expected)
  })
})
