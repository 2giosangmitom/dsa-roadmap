import { describe, it, expect } from "vitest";
import { isPalindrome, isPalindrome2 } from "../src/valid_palindrome.js";

const testCases = [
  {
    input: "A man, a plan, a canal: Panama",
    expected: true,
  },
  {
    input: "racecar",
    expected: true,
  },
  {
    input: "hello",
    expected: false,
  },
  {
    input: " ",
    expected: true,
  },
  {
    input: "No lemon, no melon",
    expected: true,
  },
  {
    input: "123abc321",
    expected: false,
  },
];

describe("isPalindrome", () => {
  testCases.forEach(({ input, expected }, i) => {
    it(`case ${i}`, () => {
      expect(isPalindrome(input)).toBe(expected);
    });
  });
});

describe("isPalindrome2", () => {
  testCases.forEach(({ input, expected }, i) => {
    it(`case ${i}`, () => {
      expect(isPalindrome2(input)).toBe(expected);
    });
  });
});
