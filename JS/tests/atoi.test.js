import { test, expect } from 'vitest'
import { myAtoi } from '../src/atoi.js'

test('should return 42 for the input "42"', () => {
  const result = myAtoi('42')
  expect(result).toBe(42)
})

test('should return -42 for the input "   -042"', () => {
  const result = myAtoi('   -042')
  expect(result).toBe(-42)
})

test('should return 1337 for the input "1337c0d3"', () => {
  const result = myAtoi('1337c0d3')
  expect(result).toBe(1337)
})

test('should return 0 for the input "0-1"', () => {
  const result = myAtoi('0-1')
  expect(result).toBe(0)
})

test('should return 0 for the input "words and 987"', () => {
  const result = myAtoi('words and 987')
  expect(result).toBe(0)
})

test('should return -2147483648 for the input "-91283472332" (out of bounds)', () => {
  const result = myAtoi('-91283472332')
  expect(result).toBe(-2147483648)
})

test('should return 2147483647 for the input "91283472332" (out of bounds)', () => {
  const result = myAtoi('91283472332')
  expect(result).toBe(2147483647)
})

test('should return 0 for an empty string', () => {
  const result = myAtoi('')
  expect(result).toBe(0)
})

test('should return 1 for the input "+1"', () => {
  const result = myAtoi('+1')
  expect(result).toBe(1)
})

test('should return -1 for the input "-1"', () => {
  const result = myAtoi('-1')
  expect(result).toBe(-1)
})

test('should return 0 for the input "."', () => {
  const result = myAtoi('.')
  expect(result).toBe(0)
})

test('should return 0 for the input "+-2"', () => {
  const result = myAtoi('+-2')
  expect(result).toBe(0)
})

test('should return 0 for the input "   "', () => {
  const result = myAtoi('   ')
  expect(result).toBe(0)
})

test('should return 2147483647 for the input "2147483648" (boundary case)', () => {
  const result = myAtoi('2147483648')
  expect(result).toBe(2147483647)
})

test('should return -2147483648 for the input "-2147483649" (boundary case)', () => {
  const result = myAtoi('-2147483649')
  expect(result).toBe(-2147483648)
})

test('should return 4193 for the input "4193 with words"', () => {
  const result = myAtoi('4193 with words')
  expect(result).toBe(4193)
})

test('should return 0 for the input "with words 4193"', () => {
  const result = myAtoi('with words 4193')
  expect(result).toBe(0)
})

test('should return -5 for the input "   -5x42"', () => {
  const result = myAtoi('   -5x42')
  expect(result).toBe(-5)
})

test('should return 123 for the input "   00000000000123"', () => {
  const result = myAtoi('   00000000000123')
  expect(result).toBe(123)
})
