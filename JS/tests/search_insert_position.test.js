import assert from "node:assert";
import { describe, it } from "node:test";
import { searchInsert } from "../src/search_insert_position.js";

describe("searchInsert", { concurrency: true, timeout: 1000 }, () => {
  it("should return 2 for input [1, 3, 5, 6] and target 5", () => {
    const nums = [1, 3, 5, 6];
    const target = 5;
    const result = searchInsert(nums, target);
    assert.strictEqual(result, 2);
  });

  it("should return 1 for input [1, 3, 5, 6] and target 2", () => {
    const nums = [1, 3, 5, 6];
    const target = 2;
    const result = searchInsert(nums, target);
    assert.strictEqual(result, 1);
  });

  it("should return 4 for input [1, 3, 5, 6] and target 7", () => {
    const nums = [1, 3, 5, 6];
    const target = 7;
    const result = searchInsert(nums, target);
    assert.strictEqual(result, 4);
  });

  it("should return 0 for input [1, 3, 5, 6] and target 0", () => {
    const nums = [1, 3, 5, 6];
    const target = 0;
    const result = searchInsert(nums, target);
    assert.strictEqual(result, 0);
  });

  it("should return 0 for input [1] and target 0", () => {
    const nums = [1];
    const target = 0;
    const result = searchInsert(nums, target);
    assert.strictEqual(result, 0);
  });

  it("should return 1 for input [1] and target 2", () => {
    const nums = [1];
    const target = 2;
    const result = searchInsert(nums, target);
    assert.strictEqual(result, 1);
  });

  it("should return 3 for input [2, 4, 6, 8, 10] and target 7", () => {
    const nums = [2, 4, 6, 8, 10];
    const target = 7;
    const result = searchInsert(nums, target);
    assert.strictEqual(result, 3);
  });

  it("should return 5 for input [2, 4, 6, 8, 10] and target 11", () => {
    const nums = [2, 4, 6, 8, 10];
    const target = 11;
    const result = searchInsert(nums, target);
    assert.strictEqual(result, 5);
  });
});
