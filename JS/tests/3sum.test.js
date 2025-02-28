import { threeSum } from "../src/3sum.js";
import { test, expect } from "vitest";

const testCases = [
  {
    nums: [-1, 0, 1, 2, -1, -4],
    expected: [
      [-1, -1, 2],
      [-1, 0, 1],
    ],
  },
  {
    nums: [],
    expected: [],
  },
  {
    nums: [0],
    expected: [],
  },
  {
    nums: [0, 0, 0],
    expected: [[0, 0, 0]],
  },
  {
    nums: [-2, 0, 0, 2, 2],
    expected: [[-2, 0, 2]],
  },
  {
    nums: [-2, 0, 1, 1, 2],
    expected: [
      [-2, 0, 2],
      [-2, 1, 1],
    ],
  },
];

testCases.forEach(({ nums, expected }, index) => {
  test(`${index}`, () => {
    const actual = threeSum(nums);
    expect(actual).toStrictEqual(expected);
  });
});
