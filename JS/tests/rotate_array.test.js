import { rotate, rotate2 } from "../src/rotate_array.js";
import { describe, expect, it } from "vitest";

const cases = [
  { nums: [1, 2, 3, 4, 5, 6, 7], k: 3, expected: [5, 6, 7, 1, 2, 3, 4] },
  { nums: [1, 2, 3], k: 1, expected: [3, 1, 2] },
  { nums: [1, 2, 3, 4, 5], k: 5, expected: [1, 2, 3, 4, 5] },
  { nums: [1, 2, 3, 4, 5], k: 6, expected: [5, 1, 2, 3, 4] },
  { nums: [1, 2, 3, 4, 5], k: 0, expected: [1, 2, 3, 4, 5] },
  { nums: [], k: 3, expected: [] },
  { nums: [42], k: 5, expected: [42] },
  { nums: [1, 1, 1, 1], k: 2, expected: [1, 1, 1, 1] },
  { nums: [-1, -100, 3, 99], k: 2, expected: [3, 99, -1, -100] },
];

describe("rotate", () => {
  cases.forEach(({ nums, k, expected }, i) => {
    it(`case ${i}`, () => {
      const cpy = Array.from(nums);
      rotate(cpy, k);
      expect(cpy).toStrictEqual(expected);
    });
  });
});

describe("rotate2", () => {
  cases.forEach(({ nums, k, expected }, i) => {
    it(`case ${i}`, () => {
      const cpy = Array.from(nums);
      rotate2(cpy, k);
      expect(cpy).toStrictEqual(expected);
    });
  });
});
