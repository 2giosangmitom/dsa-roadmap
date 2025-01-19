import assert from "node:assert";
import { describe, it } from "node:test";
import { plusOne } from "../src/plus_one.js";

describe("plusOne", { concurrency: true, timeout: 5000 }, () => {
	it("should return [1,2,4] for input [1,2,3]", () => {
		const digits = [1, 2, 3];
		const expected = [1, 2, 4];

		const actual = plusOne(digits);

		assert.deepStrictEqual(actual, expected);
	});

	it("should return [1,3,0] for input [1,2,9]", () => {
		const digits = [1, 2, 9];
		const expected = [1, 3, 0];

		const actual = plusOne(digits);

		assert.deepStrictEqual(actual, expected);
	});

	it("should return [9,9,9] for input [9,9,8]", () => {
		const digits = [9, 9, 8];
		const expected = [9, 9, 9];

		const actual = plusOne(digits);

		assert.deepStrictEqual(actual, expected);
	});

	it("should return [1,0,0,0] for input [9,9,9]", () => {
		const digits = [9, 9, 9];
		const expected = [1, 0, 0, 0];

		const actual = plusOne(digits);

		assert.deepStrictEqual(actual, expected);
	});
});
