import { test, expect } from 'vitest'
import { strStr } from '../src/find_idx_of_the_first_occur_str.js'

test('returns 0 for "sad" in "sadbutsad"', () => {
  const result = strStr('sadbutsad', 'sad')
  expect(result).toBe(0)
})

test('returns 0 for "sad" in "sadbutsad"', () => {
  const result = strStr('sadbutsad', 'sad')
  expect(result).toBe(0)
})

test('returns -1 for "leeto" in "leetcode"', () => {
  const result = strStr('leetcode', 'leeto')
  expect(result).toBe(-1)
})

test('returns 0 for "a" in "a"', () => {
  const result = strStr('a', 'a')
  expect(result).toBe(0)
})

test('returns -1 for "abc" in "xyz"', () => {
  const result = strStr('xyz', 'abc')
  expect(result).toBe(-1)
})

test('returns 0 for "abc" in "abcabc"', () => {
  const result = strStr('abcabc', 'abc')
  expect(result).toBe(0)
})
