import { describe, expect, test } from "vitest";
import { twoSum } from "./solutions_1.js";

const cases = [
  { nums: [2, 7, 11, 15], target: 9, expected: [0, 1] },
  { nums: [3, 2, 4], target: 6, expected: [1, 2] },
  { nums: [], target: 0, expected: [] },
  { nums: [3, 2, 4], target: 6, expected: [1, 2] },
  { nums: [1, 5, -3, -2], target: -5, expected: [2, 3] },
  { nums: [0, 8, 5, -8], target: -8, expected: [0, 3] },
  { nums: [1, 2, 3, 4000, 5000], target: 9000, expected: [3, 4] },
  { nums: [-6, 1, -7, 3, 8], target: -13, expected: [0, 2] },
  { nums: [-10, 7, 8, 2, 12], target: 20, expected: [2, 4] },
  { nums: [-3, 3], target: 0, expected: [0, 1] },
];

describe("twoSum", () => {
  cases.forEach(({ nums, target, expected }, index) => {
    test(`case ${index}`, () => {
      const actual = twoSum(nums, target);
      expect(actual).toStrictEqual(expected);
    });
  });
});
