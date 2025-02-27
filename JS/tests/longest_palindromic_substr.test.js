import { test, expect } from 'vitest'
import { lengthOfLongestSubstring } from '../src/longest_substr.js'

const testCases = [
  {
    input: 'abcabcbb',
    expected: 3,
    description: 'string with repeating characters'
  },
  {
    input: 'bbbbb',
    expected: 1,
    description: 'string with all same characters'
  },
  {
    input: 'pwwkew',
    expected: 3,
    description: 'string with multiple repeating characters'
  },
  { input: '', expected: 0, description: 'empty string' },
  { input: 'a', expected: 1, description: 'single character string' },
  {
    input: 'dvdf',
    expected: 3,
    description: 'string with non-consecutive repeating character'
  },
  { input: 'abba', expected: 2, description: 'string with palindrome pattern' }
]

testCases.forEach(({ input, expected, description }) => {
  test(`should return ${expected} for ${description}: "${input}"`, () => {
    const result = lengthOfLongestSubstring(input)
    expect(result).toBe(expected)
  })
})
