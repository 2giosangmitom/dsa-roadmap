import { test, expect } from "vitest";
import { maxProfit } from "../src/best_time_to_buy.js";

const testCases = [
  { prices: [7, 1, 5, 3, 6, 4], expected: 5 },
  { prices: [7, 6, 4, 3, 1], expected: 0 },
  { prices: [1, 2, 3, 4, 5], expected: 4 },
  { prices: [5], expected: 0 },
  { prices: [], expected: 0 },
];

testCases.forEach(({ prices, expected }, index) => {
  test(`test case ${index + 1}`, () => {
    const actual = maxProfit(prices);
    expect(actual).toBe(expected);
  });
});
