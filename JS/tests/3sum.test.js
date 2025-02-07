import { threeSum } from "../src/3sum.js";
import { describe, it } from "node:test";
import assert from "node:assert";

describe("3sum", { concurrency: true, timeout: 1000 }, () => {
  it("should return [[-1,-1,2],[-1,0,1]] for input [-1,0,1,2,-1,-4]", () => {
    const nums = [-1, 0, 1, 2, -1, -4];
    const expected = [
      [-1, -1, 2],
      [-1, 0, 1],
    ];
    const actual = threeSum(nums);
    assert.deepStrictEqual(actual, expected);
  });

  it("should return [] for input []", () => {
    const nums = [];
    const expected = [];
    const actual = threeSum(nums);
    assert.deepStrictEqual(actual, expected);
  });

  it("should return [] for input [0]", () => {
    const nums = [0];
    const expected = [];
    const actual = threeSum(nums);
    assert.deepStrictEqual(actual, expected);
  });

  it("should return [[0,0,0]] for input [0,0,0]", () => {
    const nums = [0, 0, 0];
    const expected = [[0, 0, 0]];
    const actual = threeSum(nums);
    assert.deepStrictEqual(actual, expected);
  });

  it("should return [[-2,0,2],[-2,1,1]] for input [-2,0,1,1,2]", () => {
    const nums = [-2, 0, 1, 1, 2];
    const expected = [
      [-2, 0, 2],
      [-2, 1, 1],
    ];
    const actual = threeSum(nums);
    assert.deepStrictEqual(actual, expected);
  });

  it("should return correct result for input with multiple triplets", () => {
    const nums = [-4, -2, -2, -2, 0, 1, 2, 2, 2, 3, 3, 4, 4, 6, 6];
    const expected = [
      [-4, -2, 6],
      [-4, 0, 4],
      [-4, 1, 3],
      [-4, 2, 2],
      [-2, -2, 4],
      [-2, 0, 2],
    ];
    const actual = threeSum(nums);
    assert.deepStrictEqual(actual, expected);
  });
});
