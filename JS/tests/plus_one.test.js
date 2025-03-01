import { test, expect } from "vitest";
import { plusOne } from "../src/plus_one.js";

const testCases = [
  {
    input: [1, 2, 3],
    expected: [1, 2, 4],
  },
  {
    input: [1, 2, 9],
    expected: [1, 3, 0],
  },
  {
    input: [9, 9, 8],
    expected: [9, 9, 9],
  },
  {
    input: [9, 9, 9],
    expected: [1, 0, 0, 0],
  },
];

testCases.forEach(({ input, expected }, index) => {
  test(`test case ${index + 1}`, () => {
    const actual = plusOne(input);
    expect(actual).toEqual(expected);
  });
});
