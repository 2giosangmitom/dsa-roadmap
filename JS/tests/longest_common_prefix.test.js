import { test, expect } from 'vitest'
import { longestCommonPrefix } from '../src/longest_common_prefix.js'

const testCases = [
  {
    input: ['flower', 'flow', 'flight'],
    expected: 'fl',
    description:
      'should return "fl" for the input ["flower", "flow", "flight"]'
  },
  {
    input: ['dog', 'racecar', 'car'],
    expected: '',
    description: 'should return "" for the input ["dog", "racecar", "car"]'
  },
  {
    input: ['apple', 'apricot', 'ap'],
    expected: 'ap',
    description: 'should return "ap" for the input ["apple", "apricot", "ap"]'
  },
  {
    input: ['root', 'rooting', 'rooted'],
    expected: 'root',
    description:
      'should return "root" for the input ["root", "rooting", "rooted"]'
  },
  {
    input: ['abacus', 'abbreviation', 'abnormal'],
    expected: 'ab',
    description:
      'should return "ab" for the input ["abacus", "abbreviation", "abnormal"]'
  },
  {
    input: ['', '', ''],
    expected: '',
    description:
      'should return "" for the input array containing only empty strings'
  },
  {
    input: ['a'],
    expected: 'a',
    description: 'should return "a" for the input ["a"]'
  }
]

testCases.forEach(({ input, expected, description }) => {
  test(description, () => {
    const result = longestCommonPrefix(input)
    expect(result).toBe(expected)
  })
})
