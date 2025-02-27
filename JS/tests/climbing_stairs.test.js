import { test, expect } from 'vitest'
import { climbStairs } from '../src/climbing_stairs.js'

test('return 34 for input 8', () => {
  const n = 8
  const expected = 34

  const actual = climbStairs(n)

  expect(actual).toBe(expected)
})

test('return 1 for input 1', () => {
  const n = 1
  const expected = 1

  const actual = climbStairs(n)

  expect(actual).toBe(expected)
})

test('return 2 for input 2', () => {
  const n = 2
  const expected = 2

  const actual = climbStairs(n)

  expect(actual).toBe(expected)
})

test('return 3 for input 3', () => {
  const n = 3
  const expected = 3

  const actual = climbStairs(n)

  expect(actual).toBe(expected)
})

test('return 5 for input 4', () => {
  const n = 4
  const expected = 5

  const actual = climbStairs(n)

  expect(actual).toBe(expected)
})

test('return 13 for input 6', () => {
  const n = 6
  const expected = 13

  const actual = climbStairs(n)

  expect(actual).toBe(expected)
})
