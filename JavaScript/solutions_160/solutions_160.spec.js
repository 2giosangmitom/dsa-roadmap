import { describe, expect, test } from "vitest";
import { ListNode } from "../lib/linked_list.js";
import { getIntersectionNode } from "./solutions_160.js";

const testCases = [
  (() => {
    const headA = ListNode.from([3, 7, 8, 10]);
    const headB = ListNode.from([99, 1, 8, 10]);
    headA.next.next.next.next = headB.next;

    return { headA, headB, expected: headB.next };
  })(),
  {
    headA: ListNode.from([1, 2, 3]),
    headB: ListNode.from([4, 5, 6]),
    expected: null,
  },
  {
    headA: ListNode.from([1, 2, 3]),
    headB: null,
    expected: null,
  },
  {
    headA: null,
    headB: null,
    expected: null,
  },
  {
    headA: ListNode.from([42]),
    headB: ListNode.from([42]),
    expected: null,
  },
];

describe("getIntersectionNode", () => {
  testCases.forEach(({ headA, headB, expected }, index) => {
    test(`case ${index}`, () => {
      const result = getIntersectionNode(headA, headB);
      expect(result).toStrictEqual(expected);
    });
  });
});
