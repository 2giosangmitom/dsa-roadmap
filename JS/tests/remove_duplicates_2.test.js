import assert from "node:assert";
import { describe, it } from "node:test";
import { removeDuplicates } from "../src/remove_duplicates_2.js";

describe("removeDuplicates2", { concurrency: true, timeout: 1000 }, () => {
  it("should return 7 for input [0,0,1,1,1,1,2,3,3]", () => {
    const nums = [0, 0, 1, 1, 1, 1, 2, 3, 3];
    const expected = 7;
    const expected_nums = [0, 0, 1, 1, 2, 3, 3];

    const actual = removeDuplicates(nums);

    assert.strictEqual(actual, expected);
    assert.deepStrictEqual(nums.slice(0, expected), expected_nums);
  });

  it("should return 5 for input [1,1,1,2,2,3]", () => {
    const nums = [1, 1, 1, 2, 2, 3];
    const expected = 5;
    const expected_nums = [1, 1, 2, 2, 3];

    const actual = removeDuplicates(nums);

    assert.strictEqual(actual, expected);
    assert.deepStrictEqual(nums.slice(0, expected), expected_nums);
  });

  it("should return 6 for input [0,0,1,1,1,2,2,3,3,3]", () => {
    const nums = [0, 0, 1, 1, 1, 2, 2, 3, 3, 3];
    const expected = 8;
    const expected_nums = [0, 0, 1, 1, 2, 2, 3, 3];

    const actual = removeDuplicates(nums);

    assert.strictEqual(actual, expected);
    assert.deepStrictEqual(nums.slice(0, expected), expected_nums);
  });

  it("should return 0 for empty input []", () => {
    const nums = [];
    const expected = 0;
    const expected_nums = [];

    const actual = removeDuplicates(nums);

    assert.strictEqual(actual, expected);
    assert.deepStrictEqual(nums.slice(0, expected), expected_nums);
  });

  it("should return 1 for input [1]", () => {
    const nums = [1];
    const expected = 1;
    const expected_nums = [1];

    const actual = removeDuplicates(nums);

    assert.strictEqual(actual, expected);
    assert.deepStrictEqual(nums.slice(0, expected), expected_nums);
  });

  it("should return 2 for input [1,1]", () => {
    const nums = [1, 1];
    const expected = 2;
    const expected_nums = [1, 1];

    const actual = removeDuplicates(nums);

    assert.strictEqual(actual, expected);
    assert.deepStrictEqual(nums.slice(0, expected), expected_nums);
  });

  it("should return 3 for input [1,1,1]", () => {
    const nums = [1, 1, 1];
    const expected = 2;
    const expected_nums = [1, 1];

    const actual = removeDuplicates(nums);

    assert.strictEqual(actual, expected);
    assert.deepStrictEqual(nums.slice(0, expected), expected_nums);
  });
});
