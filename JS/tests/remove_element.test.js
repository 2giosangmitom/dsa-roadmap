import assert from "node:assert";
import { describe, it } from "node:test";
import { removeElement } from "../src/remove_element.js";

describe("removeElement", { concurrency: true, timeout: 1000 }, () => {
  it("should return 2 and modify the array to [2, 2, _, _] for the input [3, 2, 2, 3] and val = 3", () => {
    const nums = [3, 2, 2, 3];
    const val = 3;
    const result = removeElement(nums, val);
    assert.strictEqual(result, 2);
    assert.deepStrictEqual(nums.slice(0, result), [2, 2]);
  });

  it("should return 5 and modify the array to [0, 1, 3, 0, 4] for the input [0, 1, 2, 2, 3, 0, 4, 2] and val = 2", () => {
    const nums = [0, 1, 2, 2, 3, 0, 4, 2];
    const val = 2;
    const result = removeElement(nums, val);
    assert.strictEqual(result, 5);
    assert.deepStrictEqual(nums.slice(0, result), [0, 1, 3, 0, 4]);
  });

  it("should return 0 and modify the array to [] for the input [1, 1, 1, 1] and val = 1", () => {
    const nums = [1, 1, 1, 1];
    const val = 1;
    const result = removeElement(nums, val);
    assert.strictEqual(result, 0);
    assert.deepStrictEqual(nums.slice(0, result), []);
  });

  it("should return 4 and modify the array to [0, 1, 3, 4] for the input [0, 1, 2, 3, 4, 2, 2] and val = 2", () => {
    const nums = [0, 1, 2, 3, 4, 2, 2];
    const val = 2;
    const result = removeElement(nums, val);
    assert.strictEqual(result, 4);
    assert.deepStrictEqual(nums.slice(0, result), [0, 1, 3, 4]);
  });

  it("should return 9 and modify the array to [1, 2, 3, 4, 5, 6, 8, 9, 10] for the input [1, 2, 3, 4, 5, 6, 7, 8, 9, 10] and val = 7", () => {
    const nums = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
    const val = 7;
    const result = removeElement(nums, val);
    assert.strictEqual(result, 9);
    assert.deepStrictEqual(nums.slice(0, result), [1, 2, 3, 4, 5, 6, 8, 9, 10]);
  });

  it("should return 10 and modify the array to [1, 2, 3, 4, 5, 6, 7, 8, 9, 10] for the input [1, 2, 3, 4, 5, 6, 7, 8, 9, 10] and val = 0", () => {
    const nums = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];
    const val = 0;
    const result = removeElement(nums, val);
    assert.strictEqual(result, 10);
    assert.deepStrictEqual(
      nums.slice(0, result),
      [1, 2, 3, 4, 5, 6, 7, 8, 9, 10],
    );
  });

  it("should return 1 and modify the array to [5] for the input [5] and val = 0", () => {
    const nums = [5];
    const val = 0;
    const result = removeElement(nums, val);
    assert.strictEqual(result, 1);
    assert.deepStrictEqual(nums.slice(0, result), [5]);
  });
});
