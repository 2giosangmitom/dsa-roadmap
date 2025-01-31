import assert from "node:assert";
import { describe, it } from "node:test";
import { merge } from "../src/merge_sorted_arr.js";

describe("merge sorted array", { concurrency: true, timeout: 1000 }, () => {
	it("should change array to [1,2,3,4,5,6]", () => {
		const arr1 = [1, 2, 3, 0, 0, 0];
		const arr2 = [4, 5, 6];
		const expected = [1, 2, 3, 4, 5, 6];

		merge(arr1, 3, arr2, 3);

		assert.deepStrictEqual(arr1, expected);
	});

	it("should change array to [1,2,2,3,5,6]", () => {
		const arr1 = [1, 2, 3, 0, 0, 0];
		const arr2 = [2, 5, 6];
		const expected = [1, 2, 2, 3, 5, 6];

		merge(arr1, 3, arr2, 3);

		assert.deepStrictEqual(arr1, expected);
	});

	it("should change array to [1]", () => {
		const arr1 = [0];
		const arr2 = [1];
		const expected = [1];

		merge(arr1, 0, arr2, 1);

		assert.deepStrictEqual(arr1, expected);
	});

	it("should change array to [1,2,3,4,5,6,7,8,9]", () => {
		const arr1 = [1, 3, 5, 7, 9, 0, 0, 0, 0];
		const arr2 = [2, 4, 6, 8];
		const expected = [1, 2, 3, 4, 5, 6, 7, 8, 9];

		merge(arr1, 5, arr2, 4);

		assert.deepStrictEqual(arr1, expected);
	});

	it("should change array to [1,2,3,4,5,6,7,8,9,10]", () => {
		const arr1 = [1, 3, 5, 7, 9, 0, 0, 0, 0, 0];
		const arr2 = [2, 4, 6, 8, 10];
		const expected = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10];

		merge(arr1, 5, arr2, 5);

		assert.deepStrictEqual(arr1, expected);
	});
});
