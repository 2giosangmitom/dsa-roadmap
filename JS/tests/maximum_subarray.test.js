import { describe, it, expect } from "vitest";
import { maxSubArray, maxSubArray2 } from "../src/maximum_subarray.js";

const testCases = [
  {
    name: "should return the largest sum for a mixed array",
    input: [-2, 1, -3, 4, -1, 2, 1, -5, 4],
    expected: 6,
  },
  {
    name: "should return the element itself for a single-element array",
    input: [1],
    expected: 1,
  },
  {
    name: "should return the sum of the entire array if it's the largest subarray",
    input: [5, 4, -1, 7, 8],
    expected: 23,
  },
  {
    name: "should handle an array with all negative numbers",
    input: [-3, -4, -1, -2],
    expected: -1,
  },
  {
    name: "should handle an array with all positive numbers",
    input: [2, 4, 6, 8],
    expected: 20,
  },
  {
    name: "should handle an array with zeros",
    input: [0, -3, 5, 9, 0, -2],
    expected: 14,
  },
  {
    name: "should handle an array with one large negative number and many positives",
    input: [1, 2, 3, -100, 4, 5, 6],
    expected: 15,
  },
];

describe("maxSubArray", () => {
  testCases.forEach(({ name, input, expected }) => {
    it(name, () => {
      expect(maxSubArray(input)).toBe(expected);
    });
  });
});

describe("maxSubArray2", () => {
  testCases.forEach(({ name, input, expected }) => {
    it(name, () => {
      expect(maxSubArray2(input)).toBe(expected);
    });
  });
});
