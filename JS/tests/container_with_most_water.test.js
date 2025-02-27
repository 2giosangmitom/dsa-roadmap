import { maxArea, maxArea2 } from '../src/container_with_most_water.js'
import { describe, it, expect } from 'vitest'

const testCases = [
  { nums: [2, 7, 8, 3, 7, 6], expected: 24 },
  { nums: [1, 8, 6, 2, 5, 4, 8, 3, 7], expected: 49 },
  { nums: [1, 1], expected: 1 },
  { nums: [1], expected: 0 },
  { nums: [0, 1, 0], expected: 0 },
  { nums: [4, 3, 2, 1, 4], expected: 16 },
  { nums: [1, 2, 1], expected: 2 },
  { nums: [1, 3, 2, 5, 25, 24, 5], expected: 24 },
  { nums: [1, 2, 4, 3], expected: 4 },
  { nums: [6, 9, 3, 4, 5, 8], expected: 32 }
]

describe('maxArea', () => {
  testCases.forEach(({ nums, expected }) => {
    it(`should return ${expected} for input ${JSON.stringify(nums)}`, () => {
      const actual = maxArea(nums)
      expect(actual).toBe(expected)
    })
  })
})

describe('maxArea2', () => {
  testCases.forEach(({ nums, expected }) => {
    it(`should return ${expected} for input ${JSON.stringify(nums)}`, () => {
      const actual = maxArea2(nums)
      expect(actual).toBe(expected)
    })
  })
})
