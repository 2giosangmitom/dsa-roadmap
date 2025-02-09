import { moveZeroes } from "../src/move_zeroes.js";
import assert from "node:assert";
import { describe, it } from "node:test";

describe("moveZeroes", { concurrency: true, timeout: 1000 }, () => {
  it("should modify [0,1,0,3,12] to [1,3,12,0,0]", () => {
    const nums = [0, 1, 0, 3, 12];
    const expected = [1, 3, 12, 0, 0];

    moveZeroes(nums);

    assert.deepStrictEqual(nums, expected);
  });

  it("should modify [0] to [0]", () => {
    const nums = [0];
    const expected = [0];

    moveZeroes(nums);

    assert.deepStrictEqual(nums, expected);
  });

  it("should modify [1] to [1]", () => {
    const nums = [1];
    const expected = [1];

    moveZeroes(nums);

    assert.deepStrictEqual(nums, expected);
  });

  it("should modify [2,1] to [2,1]", () => {
    const nums = [2, 1];
    const expected = [2, 1];

    moveZeroes(nums);

    assert.deepStrictEqual(nums, expected);
  });

  it("should modify [1,2,3] to [1,2,3]", () => {
    const nums = [1, 2, 3];
    const expected = [1, 2, 3];

    moveZeroes(nums);

    assert.deepStrictEqual(nums, expected);
  });
});
