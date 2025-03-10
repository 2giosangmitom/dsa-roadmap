import { canAliceWin } from "./solutions_3360.js";
import { test, expect } from "vitest";

const testCases = [
  { n: 12, expected: true },
  { n: 1, expected: false },
  { n: 10, expected: true },
  { n: 11, expected: true },
  { n: 20, expected: false },
  { n: 19, expected: false },
  { n: 30, expected: true },
  { n: 29, expected: true },
  { n: 50, expected: true },
  { n: 49, expected: true },
];

testCases.forEach(({ n, expected }, index) => {
  test(`case ${index}`, () => {
    const result = canAliceWin(n);
    expect(result).toBe(expected);
  });
});
