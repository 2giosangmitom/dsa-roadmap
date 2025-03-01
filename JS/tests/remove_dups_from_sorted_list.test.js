import { test, expect } from "vitest";
import { ListNode } from "../lib/linked_list.js";
import { deleteDuplicates } from "../src/remove_dups_from_sorted_list.js";

const testCases = [
  {
    input: [1, 1, 2],
    expected: [1, 2],
  },
  {
    input: [1, 1, 2, 3, 3],
    expected: [1, 2, 3],
  },
  {
    input: [1, 1, 1],
    expected: [1],
  },
  {
    input: [1, 2, 3, 4],
    expected: [1, 2, 3, 4],
  },
  {
    input: null,
    expected: null,
  },
  {
    input: [-3, -3, -2, -1, -1, 0],
    expected: [-3, -2, -1, 0],
  },
  {
    input: [-2, -1, 0, 1, 2, 2],
    expected: [-2, -1, 0, 1, 2],
  },
];

testCases.forEach(({ input, expected }, index) => {
  test(`test case ${index + 1}`, () => {
    const list = input === null ? null : ListNode.of(...input);
    const expectedList = expected === null ? null : ListNode.of(...expected);
    const actual = deleteDuplicates(list);

    if (actual === null) {
      expect(actual).toBe(expectedList);
    } else {
      expect(actual.toString()).toBe(expectedList.toString());
    }
  });
});
