import assert from "node:assert";
import { describe, it } from "node:test";
import { removeDuplicates } from "../src/remove_dups_from_sorted_arr.js";

describe("removeDuplicates", () => {
  it("should return 2 for the input [1, 1, 2]", () => {
    const nums = [1, 1, 2];
    const result = removeDuplicates(nums);
    assert.strictEqual(result, 2);
    assert.deepStrictEqual(nums.slice(0, result), [1, 2]);
  });

  it("should return 5 for the input [0, 0, 1, 1, 1, 2, 2, 3, 3, 4]", () => {
    const nums = [0, 0, 1, 1, 1, 2, 2, 3, 3, 4];
    const result = removeDuplicates(nums);
    assert.strictEqual(result, 5);
    assert.deepStrictEqual(nums.slice(0, result), [0, 1, 2, 3, 4]);
  });

  it("should return 1 for the input [1, 1, 1, 1, 1]", () => {
    const nums = [1, 1, 1, 1, 1];
    const result = removeDuplicates(nums);
    assert.strictEqual(result, 1);
    assert.deepStrictEqual(nums.slice(0, result), [1]);
  });

  it("should return 3 for the input [1, 2, 2, 3, 3, 4]", () => {
    const nums = [1, 2, 2, 3, 3, 4];
    const result = removeDuplicates(nums);
    assert.strictEqual(result, 4);
    assert.deepStrictEqual(nums.slice(0, result), [1, 2, 3, 4]);
  });

  it("should return 4 for the input [10, 20, 30, 30, 30, 40]", () => {
    const nums = [10, 20, 30, 30, 30, 40];
    const result = removeDuplicates(nums);
    assert.strictEqual(result, 4);
    assert.deepStrictEqual(nums.slice(0, result), [10, 20, 30, 40]);
  });

  it("should return 1 for the input [5]", () => {
    const nums = [5];
    const result = removeDuplicates(nums);
    assert.strictEqual(result, 1);
    assert.deepStrictEqual(nums.slice(0, result), [5]);
  });
});
