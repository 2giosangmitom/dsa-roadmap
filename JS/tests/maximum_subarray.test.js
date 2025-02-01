import assert from "node:assert";
import { describe, it } from "node:test";
import { maxSubArray, maxSubArray2 } from "../src/maximum_subarray.js";

/**
 * @param {Function} callback
 * @param {string} name
 */
function runTests(callback, name) {
	describe(name, { concurrency: true, timeout: 1000 }, () => {
		it("should return the largest sum for a mixed array", () => {
			const nums = [-2, 1, -3, 4, -1, 2, 1, -5, 4];
			const result = callback(nums);
			assert.strictEqual(result, 6);
		});

		it("should return the element itself for a single-element array", () => {
			const nums = [1];
			const result = callback(nums);
			assert.strictEqual(result, 1);
		});

		it("should return the sum of the entire array if it's the largest subarray", () => {
			const nums = [5, 4, -1, 7, 8];
			const result = callback(nums);
			assert.strictEqual(result, 23);
		});

		it("should handle an array with all negative numbers", () => {
			const nums = [-3, -4, -1, -2];
			const result = callback(nums);
			assert.strictEqual(result, -1);
		});

		it("should handle an array with all positive numbers", () => {
			const nums = [2, 4, 6, 8];
			const result = callback(nums);
			assert.strictEqual(result, 20);
		});

		it("should handle an array with zeros", () => {
			const nums = [0, -3, 5, 9, 0, -2];
			const result = callback(nums);
			assert.strictEqual(result, 14);
		});

		it("should handle an array with one large negative number and many positives", () => {
			const nums = [1, 2, 3, -100, 4, 5, 6];
			const result = callback(nums);
			assert.strictEqual(result, 15);
		});
	});
}

runTests(maxSubArray, "maxSubArray");
runTests(maxSubArray2, "maxSubArray2");
