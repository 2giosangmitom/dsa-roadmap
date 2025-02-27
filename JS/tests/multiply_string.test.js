import { test, expect } from 'vitest'
import { multiply } from '../src/multiply_strings.js'

const testCases = [
  { num1: '2', num2: '3', expected: '6' },
  { num1: '123', num2: '456', expected: '56088' },
  { num1: '0', num2: '12345', expected: '0' },
  { num1: '12345', num2: '0', expected: '0' },
  { num1: '1', num2: '1', expected: '1' },
  { num1: '9999', num2: '9999', expected: '99980001' },
  { num1: '987654321', num2: '1000000001', expected: '987654321987654321' },
  {
    num1: '10000000000',
    num2: '10000000000',
    expected: '100000000000000000000'
  }
]

testCases.forEach(({ num1, num2, expected }) => {
  test(`multiply(${num1}, ${num2})`, () => {
    expect(multiply(num1, num2)).toBe(expected)
  })
})
