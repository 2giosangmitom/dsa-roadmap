import { expect, test } from 'vitest'
import { ListNode } from '../lib/linked_list.js'
import { mergeTwoLists } from '../src/merge_two_sorted_lists.js'

const testCases = [
  {
    name: 'should merge two sorted lists correctly',
    l1: [1, 2, 4],
    l2: [1, 3, 4],
    expected: '1 -> 1 -> 2 -> 3 -> 4 -> 4'
  },
  {
    name: 'should return the second list if the first list is empty',
    l1: [],
    l2: [1, 2, 3],
    expected: '1 -> 2 -> 3'
  },
  {
    name: 'should return the first list if the second list is empty',
    l1: [1, 2, 3],
    l2: [],
    expected: '1 -> 2 -> 3'
  },
  {
    name: 'should merge two lists where one list is shorter than the other',
    l1: [1, 4],
    l2: [2, 3, 5, 6],
    expected: '1 -> 2 -> 3 -> 4 -> 5 -> 6'
  },
  {
    name: 'should handle two identical lists',
    l1: [1, 2, 3],
    l2: [1, 2, 3],
    expected: '1 -> 1 -> 2 -> 2 -> 3 -> 3'
  },
  {
    name: 'should handle lists with only one element each',
    l1: [1],
    l2: [2],
    expected: '1 -> 2'
  },
  {
    name: 'should handle two lists with the same value at the start',
    l1: [1, 3, 5],
    l2: [1, 2, 4],
    expected: '1 -> 1 -> 2 -> 3 -> 4 -> 5'
  }
]

testCases.forEach(({ name, l1, l2, expected }) => {
  test(name, () => {
    const list1 = ListNode.of(...l1)
    const list2 = ListNode.of(...l2)
    const result = mergeTwoLists(list1, list2)
    expect(result.toString()).toBe(expected)
  })
})
