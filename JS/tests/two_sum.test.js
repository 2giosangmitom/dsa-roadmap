import { test, expect } from "vitest";
import { twoSum } from "../src/two_sum.js";

const testCases = [
  {
    nums: [2, 7, 11, 15],
    target: 9,
    expected: [0, 1],
  },
  {
    nums: [3, 2, 4],
    target: 6,
    expected: [1, 2],
  },
  {
    nums: [5, 10, 15],
    target: 20,
    expected: [0, 2],
  },
  {
    nums: [1, 5, -3, -2],
    target: -5,
    expected: [2, 3],
  },
  {
    nums: [0, 8, 5, -8],
    target: -8,
    expected: [0, 3],
  },
  {
    nums: [9, 14, 2, 8, -5],
    target: 9,
    expected: [1, 4],
  },
  {
    nums: [1, 2, 3, 4000, 5000],
    target: 9000,
    expected: [3, 4],
  },
  {
    nums: [-10, 7, 8, 2, 12],
    target: 20,
    expected: [2, 4],
  },
  {
    nums: [-6, 1, -7, 3, 8],
    target: -13,
    expected: [0, 2],
  },
  {
    nums: [1, 2],
    target: 3,
    expected: [0, 1],
  },
  {
    nums: [-3, 3],
    target: 0,
    expected: [0, 1],
  },
];

testCases.forEach(({ nums, target, expected }) => {
  test(`should return ${expected} for nums=${JSON.stringify(nums)} and target=${target}`, () => {
    const result = twoSum(nums, target);
    expect(result).toEqual(expected);
  });
});
