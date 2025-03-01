import { nextPermutation } from "../src/next_permutation.js";
import { test, expect } from "vitest";

const testCases = [
  {
    input: [1, 2, 3],
    expected: [1, 3, 2],
  },
  {
    input: [3, 2, 1],
    expected: [1, 2, 3],
  },
  {
    input: [1, 1, 5],
    expected: [1, 5, 1],
  },
  {
    input: [0],
    expected: [0],
  },
  {
    input: [1, 1, 2, 4],
    expected: [1, 1, 4, 2],
  },
  {
    input: [1, 3, 2],
    expected: [2, 1, 3],
  },
  {
    input: [1, 3, 2, 4, 3, 2, 1],
    expected: [1, 3, 3, 1, 2, 2, 4],
  },
];

testCases.forEach(({ input, expected }, index) => {
  test(`test case ${index + 1}`, () => {
    nextPermutation(input);
    expect(input).toEqual(expected);
  });
});
