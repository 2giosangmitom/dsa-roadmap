import assert from "node:assert";
import { describe, it } from "node:test";
import { sortArray } from "../src/sort.js";

describe("sortArray", { concurrency: true, timeout: 1000 }, () => {
	it("should return a sorted array for [3, 1, 2]", () => {
		const expected = [1, 2, 3];
		const actual = sortArray([3, 1, 2]);
		assert.deepStrictEqual(actual, expected);
	});

	it("should return an empty array for []", () => {
		const expected = [];
		const actual = sortArray([]);
		assert.deepStrictEqual(actual, expected);
	});

	it("should handle negative numbers [-3, -1, -2]", () => {
		const expected = [-3, -2, -1];
		const actual = sortArray([-3, -1, -2]);
		assert.deepStrictEqual(actual, expected);
	});

	it("should return the same array for already sorted input [1, 2, 3]", () => {
		const expected = [1, 2, 3];
		const actual = sortArray([1, 2, 3]);
		assert.deepStrictEqual(actual, expected);
	});

	it("should handle mixed positive and negative numbers [3, -1, 2, -5, 0]", () => {
		const expected = [-5, -1, 0, 2, 3];
		const actual = sortArray([3, -1, 2, -5, 0]);
		assert.deepStrictEqual(actual, expected);
	});

	it("should handle duplicate numbers [4, 2, 2, 3, 1]", () => {
		const expected = [1, 2, 2, 3, 4];
		const actual = sortArray([4, 2, 2, 3, 1]);
		assert.deepStrictEqual(actual, expected);
	});
});
