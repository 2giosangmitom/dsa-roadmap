import { assert, test } from 'vitest'
import { groupAnagrams } from '../src/group_anagrams.js'

test("should group anagrams correctly for ['eat', 'tea', 'tan', 'ate', 'nat', 'bat']", () => {
  const input = ['eat', 'tea', 'tan', 'ate', 'nat', 'bat']
  const output = groupAnagrams(input)

  const expected = [['bat'], ['tan', 'nat'], ['eat', 'tea', 'ate']]
  assert.deepEqual(
    output.map((group) => group.sort()).sort(),
    expected.map((group) => group.sort()).sort()
  )
})

test("should return [['']] for ['']", () => {
  const input = ['']
  const output = groupAnagrams(input)
  assert.deepEqual(output, [['']])
})

test("should return [['a']] for ['a']", () => {
  const input = ['a']
  const output = groupAnagrams(input)
  assert.deepEqual(output, [['a']])
})

test("should group anagrams correctly for ['abc', 'cba', 'bca', 'xyz', 'zyx']", () => {
  const input = ['abc', 'cba', 'bca', 'xyz', 'zyx']
  const output = groupAnagrams(input)

  const expected = [
    ['abc', 'cba', 'bca'],
    ['xyz', 'zyx']
  ]
  assert.deepEqual(
    output.map((group) => group.sort()).sort(),
    expected.map((group) => group.sort()).sort()
  )
})

test('should handle an input with no anagrams', () => {
  const input = ['hello', 'world', 'java', 'python']
  const output = groupAnagrams(input)
  assert.equal(output.length, 4)
})
