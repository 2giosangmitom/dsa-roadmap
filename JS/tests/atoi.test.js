import { test, expect } from "vitest";
import { myAtoi } from "../src/atoi.js";

const testCases = [
  { input: "42", expected: 42 },
  { input: "   -042", expected: -42 },
  { input: "1337c0d3", expected: 1337 },
  { input: "0-1", expected: 0 },
  { input: "words and 987", expected: 0 },
  { input: "-91283472332", expected: -2147483648 },
  { input: "91283472332", expected: 2147483647 },
  { input: "", expected: 0 },
  { input: "+1", expected: 1 },
  { input: "-1", expected: -1 },
  { input: ".", expected: 0 },
  { input: "+-2", expected: 0 },
  { input: "   ", expected: 0 },
  { input: "2147483648", expected: 2147483647 },
  { input: "-2147483649", expected: -2147483648 },
  { input: "4193 with words", expected: 4193 },
  { input: "with words 4193", expected: 0 },
  { input: "   -5x42", expected: -5 },
  { input: "   00000000000123", expected: 123 },
];

testCases.forEach(({ input, expected }, index) => {
  test(`test case ${index + 1}`, () => {
    const result = myAtoi(input);
    expect(result).toBe(expected);
  });
});
