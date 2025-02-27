import { test, expect } from 'vitest'
import { closestPrimes } from '../src/closest_prime.js'

test('should return [11, 13] for input (10, 19)', () => {
  const expected = [11, 13]

  const actual = closestPrimes(10, 19)

  expect(actual).toEqual(expected)
})

test('should return [17, 19] for input (15, 23)', () => {
  const expected = [17, 19]

  const actual = closestPrimes(15, 23)

  expect(actual).toEqual(expected)
})

test('should return [29, 31] for input (25, 35)', () => {
  const expected = [29, 31]

  const actual = closestPrimes(25, 35)

  expect(actual).toEqual(expected)
})

test('should return [-1, -1] for input (20, 21) with no primes', () => {
  const expected = [-1, -1]

  const actual = closestPrimes(20, 21)

  expect(actual).toEqual(expected)
})

test('should return [101, 103] for input (100, 110)', () => {
  const expected = [101, 103]

  const actual = closestPrimes(100, 110)

  expect(actual).toEqual(expected)
})

test('should return [-1, -1] for input (0, 1) with no primes', () => {
  const expected = [-1, -1]

  const actual = closestPrimes(0, 1)

  expect(actual).toEqual(expected)
})

test('should return [2, 3] for input (1, 5)', () => {
  const expected = [2, 3]

  const actual = closestPrimes(1, 5)

  expect(actual).toEqual(expected)
})
