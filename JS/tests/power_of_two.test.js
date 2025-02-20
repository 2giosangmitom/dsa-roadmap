import { test, expect } from "vitest";
import { isPowerOfTwo } from "../src/power_of_two.js";

test("should return true for 16", () => {
  const input = 16;

  const result = isPowerOfTwo(input);

  expect(result).toBe(true);
});

test("should return false for 3", () => {
  const input = 3;

  const result = isPowerOfTwo(input);

  expect(result).toBe(false);
});

test("should return false for negative number", () => {
  const input = -1;

  const result = isPowerOfTwo(input);

  expect(result).toBe(false);
});

test("should return false for 0", () => {
  const input = 0;

  const result = isPowerOfTwo(input);

  expect(result).toBe(false);
});

test("should return true for 1", () => {
  const input = 1;

  const result = isPowerOfTwo(input);

  expect(result).toBe(true);
});

test("should return true for 64", () => {
  const input = 64;

  const result = isPowerOfTwo(input);

  expect(result).toBe(true);
});

test("should return false for 100", () => {
  const input = 100;

  const result = isPowerOfTwo(input);

  expect(result).toBe(false);
});
