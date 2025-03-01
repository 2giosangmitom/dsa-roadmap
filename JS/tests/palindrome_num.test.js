import { test, expect } from "vitest";
import { isPalindrome } from "../src/palindrome_num.js";

const testCases = [
  { input: 7, expected: true },
  { input: 121, expected: true },
  { input: -121, expected: false },
  { input: 123, expected: false },
  { input: 123454321, expected: true },
  { input: 123456789, expected: false },
  { input: 0, expected: true },
  { input: 22, expected: true },
  { input: 23, expected: false },
  { input: 1221, expected: true },
  { input: 12321, expected: true },
  { input: 10, expected: false },
  { input: 100000000000001, expected: true },
  { input: 1000000000000021, expected: false },
];

testCases.forEach(({ input, expected }, index) => {
  test(`test case ${index + 1}`, () => {
    expect(isPalindrome(input)).toBe(expected);
  });
});
