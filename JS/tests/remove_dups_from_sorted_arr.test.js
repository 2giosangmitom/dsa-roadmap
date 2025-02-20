import { expect, test } from "vitest";
import { removeDuplicates } from "../src/remove_dups_from_sorted_arr.js";

const testCases = [
  {
    input: [1, 1, 2],
    expectedLength: 2,
    expectedArray: [1, 2],
  },
  {
    input: [0, 0, 1, 1, 1, 2, 2, 3, 3, 4],
    expectedLength: 5,
    expectedArray: [0, 1, 2, 3, 4],
  },
  {
    input: [1, 1, 1, 1, 1],
    expectedLength: 1,
    expectedArray: [1],
  },
  {
    input: [1, 2, 2, 3, 3, 4],
    expectedLength: 4,
    expectedArray: [1, 2, 3, 4],
  },
  {
    input: [10, 20, 30, 30, 30, 40],
    expectedLength: 4,
    expectedArray: [10, 20, 30, 40],
  },
  {
    input: [5],
    expectedLength: 1,
    expectedArray: [5],
  },
];

testCases.forEach(({ input, expectedLength, expectedArray }) => {
  test(`should return ${expectedLength} for input ${JSON.stringify(input)}`, () => {
    const nums = [...input];
    const result = removeDuplicates(nums);
    expect(result).toBe(expectedLength);
    expect(nums.slice(0, result)).toEqual(expectedArray);
  });
});
