import { test, expect } from 'vitest'
import { lengthOfLongestSubstring } from '../src/longest_substr.js'

test('should return 3 for the input "abcabcbb"', () => {
  const input = 'abcabcbb'
  const result = lengthOfLongestSubstring(input)
  expect(result).toBe(3)
})

test('should return 1 for the input "bbbbb"', () => {
  const input = 'bbbbb'
  const result = lengthOfLongestSubstring(input)
  expect(result).toBe(1)
})

test('should return 3 for the input "pwwkew"', () => {
  const input = 'pwwkew'
  const result = lengthOfLongestSubstring(input)
  expect(result).toBe(3)
})

test('should return 0 for an empty string', () => {
  const input = ''
  const result = lengthOfLongestSubstring(input)
  expect(result).toBe(0)
})

test('should return 1 for a single character string', () => {
  const input = 'a'
  const result = lengthOfLongestSubstring(input)
  expect(result).toBe(1)
})

test('should return 3 for the input "dvdf"', () => {
  const input = 'dvdf'
  const result = lengthOfLongestSubstring(input)
  expect(result).toBe(3)
})

test('should return 2 for the input "abba"', () => {
  const input = 'abba'
  const result = lengthOfLongestSubstring(input)
  expect(result).toBe(2)
})
