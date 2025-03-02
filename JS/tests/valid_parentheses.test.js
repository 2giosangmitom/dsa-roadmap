import { test, expect } from "vitest";
import { isValid } from "../src/valid_parentheses.js";

const testCases = [
  { input: "()", expected: true },
  { input: "()[]{}", expected: true },
  { input: "(]", expected: false },
  { input: "([]))", expected: false },
  { input: "([)]", expected: false },
  { input: "{[]}", expected: true },
  { input: "{[}", expected: false },
  { input: "", expected: true },
  { input: "((((((((((((((((((((((((((", expected: false },
  { input: "(((((()))))))", expected: false },
];

testCases.forEach(({ input, expected }, i) => {
  test(`case ${i}`, () => {
    expect(isValid(input)).toBe(expected);
  });
});
