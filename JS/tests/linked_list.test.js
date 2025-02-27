import { test, expect } from 'vitest'
import { ListNode } from '../lib/linked_list.js'

test('should create a ListNode with the correct value and next node', () => {
  const node = new ListNode(5)
  expect(node.val).toBe(5)
  expect(node.next).toBe(null)
})

test('should create a ListNode with a given value and next node', () => {
  const node2 = new ListNode(10)
  const node1 = new ListNode(5, node2)
  expect(node1.val).toBe(5)
  expect(node1.next).toBe(node2)
  expect(node2.val).toBe(10)
  expect(node2.next).toBe(null)
})

test('should create a linked list from an array of numbers using the "of" method', () => {
  const list = ListNode.of(1, 2, 3, 4, 5)
  expect(list.val).toBe(1)
  expect(list.next.val).toBe(2)
  expect(list.next.next.val).toBe(3)
  expect(list.next.next.next.val).toBe(4)
  expect(list.next.next.next.next.val).toBe(5)
  expect(list.next.next.next.next.next).toBe(null)
})

test('should return null when calling "of" with an empty array', () => {
  const list = ListNode.of()
  expect(list).toBe(null)
})

test('return string representation of linked list correctly', () => {
  const list = ListNode.of(1, 2, 3, 4).toString()
  expect(list).toBe('1 -> 2 -> 3 -> 4')
})
