import { test, expect } from 'vitest'
import { generateMatrix } from '../src/spiral_matrix_2.js'

const testCases = [
  {
    input: 3,
    expected: [
      [1, 2, 3],
      [8, 9, 4],
      [7, 6, 5]
    ]
  },
  {
    input: 1,
    expected: [[1]]
  },
  {
    input: 2,
    expected: [
      [1, 2],
      [4, 3]
    ]
  },
  {
    input: 4,
    expected: [
      [1, 2, 3, 4],
      [12, 13, 14, 5],
      [11, 16, 15, 6],
      [10, 9, 8, 7]
    ]
  },
  {
    input: 5,
    expected: [
      [1, 2, 3, 4, 5],
      [16, 17, 18, 19, 6],
      [15, 24, 25, 20, 7],
      [14, 23, 22, 21, 8],
      [13, 12, 11, 10, 9]
    ]
  },
  {
    input: 0,
    expected: []
  }
]

testCases.forEach(({ input, expected }) => {
  test(`should return correct spiral matrix for input ${input}`, () => {
    const actual = generateMatrix(input)
    expect(actual).toEqual(expected)
  })
})
