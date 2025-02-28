import { describe, it, expect } from "vitest";
import { myPow, myPow2 } from "../src/pow.js";

const testCases = [
  { x: 2.0, n: 10, expected: 1024.0 },
  { x: 2.1, n: 3, expected: 9.261 },
  { x: 2.0, n: -2, expected: 0.25 },
  { x: -2.0, n: 4, expected: 16.0 },
  { x: -2.0, n: 3, expected: -8.0 },
  { x: 1.0, n: 0, expected: 1.0 },
  { x: 0.99999, n: 1000, expected: 0.99005 },
  { x: 1.5, n: -3, expected: 0.2963 },
  { x: 2.0, n: -31, expected: 0.0 },
  { x: 0.99999, n: -9999, expected: 1.10516 },
  { x: 1.00001, n: 9999, expected: 1.10516 },
];

describe("pow", () => {
  testCases.forEach(({ x, n, expected }) => {
    it(`should return ${expected} for x = ${x} and n = ${n}`, () => {
      const result = myPow(x, n);
      expect(Number(result.toFixed(5))).toBe(expected);
    });
  });
});

describe("pow2", () => {
  testCases.forEach(({ x, n, expected }) => {
    it(`should return ${expected} for x = ${x} and n = ${n}`, () => {
      const result = myPow2(x, n);
      expect(Number(result.toFixed(5))).toBe(expected);
    });
  });
});
