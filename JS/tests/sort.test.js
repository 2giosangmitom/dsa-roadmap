import assert from "node:assert";
import { describe, it } from "node:test";
import {
  sortArray,
  bubbleSort,
  insertionSort,
  sortMethod,
} from "../src/sort.js";

function runTests(name, callback) {
  describe(name, { concurrency: true, timeout: 1000 }, () => {
    it("should return a sorted array for [3, 1, 2]", () => {
      assert.deepStrictEqual(callback([3, 1, 2]), [1, 2, 3]);
    });

    it("should return an empty array for []", () => {
      assert.deepStrictEqual(callback([]), []);
    });

    it("should handle negative numbers [-3, -1, -2]", () => {
      assert.deepStrictEqual(callback([-3, -1, -2]), [-3, -2, -1]);
    });

    it("should return the same array for already sorted input [1, 2, 3]", () => {
      assert.deepStrictEqual(callback([1, 2, 3]), [1, 2, 3]);
    });

    it("should handle mixed positive and negative numbers [3, -1, 2, -5, 0]", () => {
      assert.deepStrictEqual(callback([3, -1, 2, -5, 0]), [-5, -1, 0, 2, 3]);
    });

    it("should handle duplicate numbers [4, 2, 2, 3, 1]", () => {
      assert.deepStrictEqual(callback([4, 2, 2, 3, 1]), [1, 2, 2, 3, 4]);
    });

    it("should handle large array correctly", () => {
      const nums = Array.from({ length: 20000 }, () =>
        Math.floor(Math.random() * 100000),
      );
      const expected = [...nums].sort((a, b) => a - b);
      assert.deepStrictEqual(callback(nums), expected);
    });

    it("should handle array with all identical elements [7, 7, 7, 7, 7]", () => {
      assert.deepStrictEqual(callback([7, 7, 7, 7, 7]), [7, 7, 7, 7, 7]);
    });
  });
}

runTests("merge sort", sortArray);
runTests("bubble sort", bubbleSort);
runTests("insertion sort", insertionSort);
runTests("sort method", sortMethod);
