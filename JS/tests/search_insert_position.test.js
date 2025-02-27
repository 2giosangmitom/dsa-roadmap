import { test, expect } from 'vitest'
import { searchInsert } from '../src/search_insert_position.js'

const testCases = [
  { nums: [1, 3, 5, 6], target: 5, expected: 2 },
  { nums: [1, 3, 5, 6], target: 2, expected: 1 },
  { nums: [1, 3, 5, 6], target: 7, expected: 4 },
  { nums: [1, 3, 5, 6], target: 0, expected: 0 },
  { nums: [1], target: 0, expected: 0 },
  { nums: [1], target: 2, expected: 1 },
  { nums: [2, 4, 6, 8, 10], target: 7, expected: 3 },
  { nums: [2, 4, 6, 8, 10], target: 11, expected: 5 }
]

testCases.forEach(({ nums, target, expected }) => {
  test(`should return ${expected} for input [${nums}] and target ${target}`, () => {
    expect(searchInsert(nums, target)).toBe(expected)
  })
})
