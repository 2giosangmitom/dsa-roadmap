import { nextPermutation } from '../src/next_permutation.js'
import { test, expect } from 'vitest'

const testCases = [
  {
    input: [1, 2, 3],
    expected: [1, 3, 2],
    description: 'should modify the array to [1,3,2]'
  },
  {
    input: [3, 2, 1],
    expected: [1, 2, 3],
    description: 'should modify the array to [1,2,3]'
  },
  {
    input: [1, 1, 5],
    expected: [1, 5, 1],
    description: 'should modify the array to [1,5,1]'
  },
  {
    input: [0],
    expected: [0],
    description: 'should modify the array to [0]'
  },
  {
    input: [1, 1, 2, 4],
    expected: [1, 1, 4, 2],
    description: 'should modify the array to [1,1,4,2]'
  },
  {
    input: [1, 3, 2],
    expected: [2, 1, 3],
    description: 'should modify the array to [2,1,3]'
  },
  {
    input: [1, 3, 2, 4, 3, 2, 1],
    expected: [1, 3, 3, 1, 2, 2, 4],
    description: 'should modify the array to [1, 3, 3, 1, 2 ,2, 4]'
  }
]

testCases.forEach(({ input, expected, description }) => {
  test(description, () => {
    nextPermutation(input)
    expect(input).toEqual(expected)
  })
})
