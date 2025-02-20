import { expect, test } from "vitest";
import { mySqrt } from "../src/sqrt.js";

const testCases = [
  { input: 4, expected: 2 },
  { input: 8, expected: 2 },
  { input: 0, expected: 0 },
  { input: 1, expected: 1 },
  { input: 10, expected: 3 },
  { input: 1000, expected: 31 },
  { input: 100000, expected: 316 },
  { input: 2147395599, expected: 46339 },
  { input: 2147483647, expected: 46340 },
];

testCases.forEach(({ input, expected }) => {
  test(`should return ${expected} for input ${input}`, () => {
    const actual = mySqrt(input);
    expect(actual).toBe(expected);
  });
});
