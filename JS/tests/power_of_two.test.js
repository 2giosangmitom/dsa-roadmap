import { test, expect } from "vitest";
import { isPowerOfTwo } from "../src/power_of_two.js";

const testCases = [
  { input: 16, expected: true },
  { input: 3, expected: false },
  { input: -1, expected: false },
  { input: 0, expected: false },
  { input: 1, expected: true },
  { input: 64, expected: true },
  { input: 100, expected: false },
];

testCases.forEach(({ input, expected }, index) => {
  test(`test case ${index + 1}`, () => {
    const result = isPowerOfTwo(input);
    expect(result).toBe(expected);
  });
});
