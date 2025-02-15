import assert from "node:assert";
import { describe, it } from "node:test";
import { twoSum } from "../src/two_sum.js";

describe("Two Sum", { concurrency: true, timeout: 1000 }, () => {
  it("should return [0, 1] for [2, 7, 11, 15] and target 9", () => {
    const nums = [2, 7, 11, 15];
    const target = 9;

    const result = twoSum(nums, target);

    assert.deepStrictEqual(result, [0, 1]);
  });

  it("should return [1, 2] for [3, 2, 4] and target 6", () => {
    const nums = [3, 2, 4];
    const target = 6;

    const result = twoSum(nums, target);

    assert.deepStrictEqual(result, [1, 2]);
  });

  it("should return [0, 2] for [5, 10, 15] and target 20", () => {
    const nums = [5, 10, 15];
    const target = 20;

    const result = twoSum(nums, target);

    assert.deepStrictEqual(result, [0, 2]);
  });

  it("should return [2, 3] for [1, 5, -3, -2] and target -5", () => {
    const nums = [1, 5, -3, -2];
    const target = -5;

    const result = twoSum(nums, target);

    assert.deepStrictEqual(result, [2, 3]);
  });

  it("should return [0, 3] for [0, 8, 5, -8] and target -8", () => {
    const nums = [0, 8, 5, -8];
    const target = -8;

    const result = twoSum(nums, target);

    assert.deepStrictEqual(result, [0, 3]);
  });

  it("should return [1, 4] for [9, 14, 2, 8, -5] and target 9", () => {
    const nums = [9, 14, 2, 8, -5];
    const target = 9;

    const result = twoSum(nums, target);

    assert.deepStrictEqual(result, [1, 4]);
  });

  it("should return [3, 4] for [1, 2, 3, 4000, 5000] and target 9000", () => {
    const nums = [1, 2, 3, 4000, 5000];
    const target = 9000;

    const result = twoSum(nums, target);

    assert.deepStrictEqual(result, [3, 4]);
  });

  it("should return [2, 4] for [-10, 7, 8, 2, 12] and target 20", () => {
    const nums = [-10, 7, 8, 2, 12];
    const target = 20;

    const result = twoSum(nums, target);

    assert.deepStrictEqual(result, [2, 4]);
  });

  it("should return [0, 2] for [-6, 1, -7, 3, 8] and target -13", () => {
    const nums = [-6, 1, -7, 3, 8];
    const target = -13;

    const result = twoSum(nums, target);

    assert.deepStrictEqual(result, [0, 2]);
  });

  it("should return [0, 1] for [1, 2] and target 3", () => {
    const nums = [1, 2];
    const target = 3;

    const result = twoSum(nums, target);

    assert.deepStrictEqual(result, [0, 1]);
  });

  it("should return [0, 1] for [-3, 3] and target 0", () => {
    const nums = [-3, 3];
    const target = 0;

    const result = twoSum(nums, target);

    assert.deepStrictEqual(result, [0, 1]);
  });
});
