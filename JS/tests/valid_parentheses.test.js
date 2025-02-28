import { test, expect } from "vitest";
import { isValid } from "../src/valid_parentheses.js";

const testCases = [
  { input: "()", expected: true, description: "simple parentheses" },
  {
    input: "()[]{}",
    expected: true,
    description: "multiple different brackets",
  },
  { input: "(]", expected: false, description: "mismatched brackets" },
  { input: "([]))", expected: false, description: "nested brackets" },
  { input: "([)]", expected: false, description: "crossed brackets" },
  { input: "{[]}", expected: true, description: "nested different brackets" },
  { input: "{[}", expected: false, description: "incomplete nested brackets" },
  { input: "", expected: true, description: "empty string" },
  {
    input: "((((((((((((((((((((((((((",
    expected: false,
    description: "unbalanced open brackets",
  },
  {
    input: "(((((()))))))",
    expected: false,
    description: "multiple nested parentheses",
  },
];

testCases.forEach(({ input, expected, description }) => {
  test(`should return ${expected} for ${description}: "${input}"`, () => {
    expect(isValid(input)).toBe(expected);
  });
});
