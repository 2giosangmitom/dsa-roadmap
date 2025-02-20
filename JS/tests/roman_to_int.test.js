import { test, expect } from "vitest";
import { romanToInt } from "../src/roman_to_int.js";

const testCases = [
  { input: "III", expected: 3 },
  { input: "LVIII", expected: 58 },
  { input: "MCMXCIV", expected: 1994 },
  { input: "IX", expected: 9 },
  { input: "XL", expected: 40 },
  { input: "XC", expected: 90 },
  { input: "CD", expected: 400 },
  { input: "CM", expected: 900 },
  { input: "MMMCMXCIX", expected: 3999 },
  { input: "I", expected: 1 },
  { input: "IV", expected: 4 },
  { input: "V", expected: 5 },
  { input: "C", expected: 100 },
  { input: "D", expected: 500 },
  { input: "M", expected: 1000 },
];

testCases.forEach(({ input, expected }) => {
  test(`should return ${expected} for the input "${input}"`, () => {
    const result = romanToInt(input);
    expect(result).toBe(expected);
  });
});
