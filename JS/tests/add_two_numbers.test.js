import { test, expect } from "vitest";
import { ListNode } from "../lib/linked_list.js";
import { addTwoNumbers } from "../src/add_two_numbers.js";

const testCases = [
  {
    l1: ListNode.of(2, 4, 3),
    l2: ListNode.of(5, 6, 4),
    expected: ListNode.of(7, 0, 8),
  },
  {
    l1: ListNode.of(9, 9, 9),
    l2: ListNode.of(1),
    expected: ListNode.of(0, 0, 0, 1),
  },
  {
    l1: ListNode.of(1, 8),
    l2: ListNode.of(0),
    expected: ListNode.of(1, 8),
  },
  {
    l1: ListNode.of(0),
    l2: ListNode.of(5, 6, 4),
    expected: ListNode.of(5, 6, 4),
  },
  {
    l1: null,
    l2: null,
    expected: null,
  },
  {
    l1: ListNode.of(1, 2, 3),
    l2: ListNode.of(),
    expected: ListNode.of(1, 2, 3),
  },
];

testCases.forEach(({ l1, l2, expected }, index) => {
  test(`test case ${index + 1}`, () => {
    const result = addTwoNumbers(l1, l2);
    expect(result).toEqual(expected);
  });
});
