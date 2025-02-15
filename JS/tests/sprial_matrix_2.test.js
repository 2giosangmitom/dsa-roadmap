import assert from "node:assert";
import { describe, it } from "node:test";
import { generateMatrix } from "../src/spiral_matrix_2.js";

describe("spiral matrix 2", { concurrency: true, timeout: 1000 }, () => {
  it("should return [[1,2,3],[8,9,4],[7,6,5]] for input 3", () => {
    const n = 3;
    const expected = [
      [1, 2, 3],
      [8, 9, 4],
      [7, 6, 5],
    ];

    const actual = generateMatrix(n);

    assert.deepStrictEqual(actual, expected);
  });

  it("should return [[1]] for input 1", () => {
    const n = 1;
    const expected = [[1]];

    const actual = generateMatrix(n);

    assert.deepStrictEqual(actual, expected);
  });

  it("should return [[1,2],[4,3]] for input 2", () => {
    const n = 2;
    const expected = [
      [1, 2],
      [4, 3],
    ];

    const actual = generateMatrix(n);

    assert.deepStrictEqual(actual, expected);
  });

  it("should return a correct 4x4 spiral matrix for input 4", () => {
    const n = 4;
    const expected = [
      [1, 2, 3, 4],
      [12, 13, 14, 5],
      [11, 16, 15, 6],
      [10, 9, 8, 7],
    ];

    const actual = generateMatrix(n);

    assert.deepStrictEqual(actual, expected);
  });

  it("should return a correct 5x5 spiral matrix for input 5", () => {
    const n = 5;
    const expected = [
      [1, 2, 3, 4, 5],
      [16, 17, 18, 19, 6],
      [15, 24, 25, 20, 7],
      [14, 23, 22, 21, 8],
      [13, 12, 11, 10, 9],
    ];

    const actual = generateMatrix(n);

    assert.deepStrictEqual(actual, expected);
  });

  it("should return an empty array for input 0", () => {
    const n = 0;
    const expected = [];

    const actual = generateMatrix(n);

    assert.deepStrictEqual(actual, expected);
  });
});
