import { test, expect } from 'vitest'
import { isPalindrome } from '../src/palindrome_num.js'

const testCases = [
  { input: 7, expected: true, description: 'single-digit number' },
  { input: 121, expected: true, description: 'positive palindrome number' },
  { input: -121, expected: false, description: 'negative number' },
  { input: 123, expected: false, description: 'non-palindrome number' },
  { input: 123454321, expected: true, description: 'large palindrome number' },
  {
    input: 123456789,
    expected: false,
    description: 'large non-palindrome number'
  },
  { input: 0, expected: true, description: 'zero' },
  { input: 22, expected: true, description: 'two-digit palindrome number' },
  {
    input: 23,
    expected: false,
    description: 'two-digit non-palindrome number'
  },
  { input: 1221, expected: true, description: 'even digits palindrome number' },
  { input: 12321, expected: true, description: 'odd digits palindrome number' },
  { input: 10, expected: false, description: 'number ending with 0' },
  {
    input: 100000000000001,
    expected: true,
    description: 'very large palindrome number'
  },
  {
    input: 1000000000000021,
    expected: false,
    description: 'very large non-palindrome number'
  }
]

testCases.forEach(({ input, expected, description }) => {
  test(`isPalindrome ${description}`, () => {
    expect(isPalindrome(input)).toBe(expected)
  })
})
