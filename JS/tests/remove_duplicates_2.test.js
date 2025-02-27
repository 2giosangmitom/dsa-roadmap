import { expect, test } from 'vitest'
import { removeDuplicates } from '../src/remove_duplicates_2.js'

const testCases = [
  {
    nums: [0, 0, 1, 1, 1, 1, 2, 3, 3],
    expected: 7,
    expected_nums: [0, 0, 1, 1, 2, 3, 3]
  },
  {
    nums: [1, 1, 1, 2, 2, 3],
    expected: 5,
    expected_nums: [1, 1, 2, 2, 3]
  },
  {
    nums: [0, 0, 1, 1, 1, 2, 2, 3, 3, 3],
    expected: 8,
    expected_nums: [0, 0, 1, 1, 2, 2, 3, 3]
  },
  {
    nums: [],
    expected: 0,
    expected_nums: []
  },
  {
    nums: [1],
    expected: 1,
    expected_nums: [1]
  },
  {
    nums: [1, 1],
    expected: 2,
    expected_nums: [1, 1]
  },
  {
    nums: [1, 1, 1],
    expected: 2,
    expected_nums: [1, 1]
  }
]

testCases.forEach(({ nums, expected, expected_nums }) => {
  test(`should return ${expected} for input ${JSON.stringify(nums)}`, () => {
    const actual = removeDuplicates(nums)
    expect(actual).toBe(expected)
    expect(nums.slice(0, expected)).toEqual(expected_nums)
  })
})
