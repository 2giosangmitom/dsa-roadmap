import { expect, test } from "vitest";
import { reverse } from "../src/reverse_integer.js";

const testCases = [
  { input: 123, expected: 321 },
  { input: -123, expected: -321 },
  { input: 120, expected: 21 },
  { input: 0, expected: 0 },
  { input: 1534236469, expected: 0 },
  { input: -1534236469, expected: 0 },
  { input: -2147483412, expected: -2143847412 },
  { input: 1463847412, expected: 2147483641 },
  { input: -2147483648, expected: 0 },
];

testCases.forEach(({ input, expected }, index) => {
  test(`test case ${index + 1}`, () => {
    const result = reverse(input);
    expect(result).toBe(expected);
  });
});
