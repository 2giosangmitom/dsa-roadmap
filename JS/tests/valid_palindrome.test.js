import { describe, it, expect } from "vitest";
import { isPalindrome, isPalindrome2 } from "../src/valid_palindrome.js";

const testCases = [
  {
    input: "A man, a plan, a canal: Panama",
    expected: true,
    description:
      "should return true for palindrome with spaces and punctuation",
  },
  {
    input: "racecar",
    expected: true,
    description: "should return true for simple palindrome",
  },
  {
    input: "hello",
    expected: false,
    description: "should return false for non-palindrome",
  },
  {
    input: " ",
    expected: true,
    description: "should return true for empty string",
  },
  {
    input: "No lemon, no melon",
    expected: true,
    description: "should return true for case-insensitive palindrome",
  },
  {
    input: "123abc321",
    expected: false,
    description: "should return false for alphanumeric non-palindrome",
  },
];

describe("isPalindrome", () => {
  it.each(testCases)("$description", ({ input, expected }) => {
    expect(isPalindrome(input)).toBe(expected);
  });
});

describe("isPalindrome2", () => {
  it.each(testCases)("$description", ({ input, expected }) => {
    expect(isPalindrome2(input)).toBe(expected);
  });
});
