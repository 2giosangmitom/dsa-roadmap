import { nextPermutation } from "../src/next_permutation.js";
import { describe, it } from "node:test";
import assert from "node:assert";

describe("nextPermutation", { concurrency: true, timeout: 1000 }, () => {
  it("should modify the array to [1,3,2]", () => {
    const nums = [1, 2, 3];
    const expected = [1, 3, 2];

    nextPermutation(nums);

    assert.deepStrictEqual(nums, expected);
  });

  it("should modify the array to [1,2,3]", () => {
    const nums = [3, 2, 1];
    const expected = [1, 2, 3];

    nextPermutation(nums);

    assert.deepStrictEqual(nums, expected);
  });

  it("should modify the array to [1,5,1]", () => {
    const nums = [1, 1, 5];
    const expected = [1, 5, 1];

    nextPermutation(nums);

    assert.deepStrictEqual(nums, expected);
  });

  it("should modify the array to [0]", () => {
    const nums = [0];
    const expected = [0];

    nextPermutation(nums);

    assert.deepStrictEqual(nums, expected);
  });

  it("should modify the array to [1,1,4,2]", () => {
    const nums = [1, 1, 2, 4];
    const expected = [1, 1, 4, 2];

    nextPermutation(nums);

    assert.deepStrictEqual(nums, expected);
  });

  it("should modify the array to [2,1,3]", () => {
    const nums = [1, 3, 2];
    const expected = [2, 1, 3];

    nextPermutation(nums);

    assert.deepStrictEqual(nums, expected);
  });

  it("should modify the array to [1, 3, 3, 1, 2 ,2, 4]", () => {
    const nums = [1, 3, 2, 4, 3, 2, 1];
    const expected = [1, 3, 3, 1, 2, 2, 4];

    nextPermutation(nums);

    assert.deepStrictEqual(nums, expected);
  });
});
