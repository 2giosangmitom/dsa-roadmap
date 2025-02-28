import { test, expect } from "vitest";
import { maxProfit } from "../src/best_time_to_buy.js";

test("should return 5 for input [7,1,5,3,6,4]", () => {
  const prices = [7, 1, 5, 3, 6, 4];
  const expected = 5;

  const actual = maxProfit(prices);

  expect(actual).toBe(expected);
});

test("should return 0 for input [7,6,4,3,1] (no profit possible)", () => {
  const prices = [7, 6, 4, 3, 1];
  const expected = 0;

  const actual = maxProfit(prices);

  expect(actual).toBe(expected);
});

test("should return 4 for input [1,2,3,4,5] (increasing prices)", () => {
  const prices = [1, 2, 3, 4, 5];
  const expected = 4;

  const actual = maxProfit(prices);

  expect(actual).toBe(expected);
});

test("should return 0 for input [5] (single price)", () => {
  const prices = [5];
  const expected = 0;

  const actual = maxProfit(prices);

  expect(actual).toBe(expected);
});

test("should return 0 for empty input []", () => {
  const prices = [];
  const expected = 0;

  const actual = maxProfit(prices);

  expect(actual).toBe(expected);
});
