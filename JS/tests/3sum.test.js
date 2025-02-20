import { threeSum } from "../src/3sum.js";
import { test, expect } from "vitest";

test("should return [[-1,-1,2],[-1,0,1]] for input [-1,0,1,2,-1,-4]", () => {
  const nums = [-1, 0, 1, 2, -1, -4];
  const expected = [
    [-1, -1, 2],
    [-1, 0, 1],
  ];

  const actual = threeSum(nums);

  expect(actual).toStrictEqual(expected);
});

test("should return [] for input []", () => {
  const nums = [];
  const expected = [];

  const actual = threeSum(nums);

  expect(actual).toStrictEqual(expected);
});

test("should return [] for input [0]", () => {
  const nums = [0];
  const expected = [];

  const actual = threeSum(nums);

  expect(actual).toStrictEqual(expected);
});

test("should return [] for input [0,0,0]", () => {
  const nums = [0, 0, 0];
  const expected = [[0, 0, 0]];

  const actual = threeSum(nums);

  expect(actual).toStrictEqual(expected);
});

test("should return [[-2,0,2]] for input [-2,0,0,2,2]", () => {
  const nums = [-2, 0, 0, 2, 2];
  const expected = [[-2, 0, 2]];

  const actual = threeSum(nums);

  expect(actual).toStrictEqual(expected);
});

test("should return [[-2,0,2],[-2,1,1]] for input [-2,0,1,1,2]", () => {
  const nums = [-2, 0, 1, 1, 2];
  const expected = [
    [-2, 0, 2],
    [-2, 1, 1],
  ];

  const actual = threeSum(nums);

  expect(actual).toStrictEqual(expected);
});
