import { moveZeroes } from '../src/move_zeroes.js'
import { test, expect } from 'vitest'

const testCases = [
  {
    input: [0, 1, 0, 3, 12],
    expected: [1, 3, 12, 0, 0],
    name: 'should modify [0,1,0,3,12] to [1,3,12,0,0]'
  },
  {
    input: [0],
    expected: [0],
    name: 'should modify [0] to [0]'
  },
  {
    input: [1],
    expected: [1],
    name: 'should modify [1] to [1]'
  },
  {
    input: [2, 1],
    expected: [2, 1],
    name: 'should modify [2,1] to [2,1]'
  },
  {
    input: [1, 2, 3],
    expected: [1, 2, 3],
    name: 'should modify [1,2,3] to [1,2,3]'
  }
]

testCases.forEach(({ input, expected, name }) => {
  test(name, () => {
    moveZeroes(input)
    expect(input).toEqual(expected)
  })
})
