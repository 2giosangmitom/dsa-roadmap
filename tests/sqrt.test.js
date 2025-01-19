import assert from "node:assert";
import { describe, it } from "node:test";
import { mySqrt } from "../src/sqrt.js";

describe("mySqrt", { concurrency: true, timeout: 5000 }, () => {
	it("should return 2 for input 4", () => {
		const x = 4;
		const expected = 2;

		const actual = mySqrt(x);

		assert.strictEqual(actual, expected);
	});

	it("should return 2 for input 8", () => {
		const x = 8;
		const expected = 2;

		const actual = mySqrt(x);

		assert.strictEqual(actual, expected);
	});

	it("should return 0 for input 0", () => {
		const x = 0;
		const expected = 0;

		const actual = mySqrt(x);

		assert.strictEqual(actual, expected);
	});

	it("should return 1 for input 1", () => {
		const x = 1;
		const expected = 1;

		const actual = mySqrt(x);

		assert.strictEqual(actual, expected);
	});

	it("should return 3 for input 10", () => {
		const x = 10;
		const expected = 3;

		const actual = mySqrt(x);

		assert.strictEqual(actual, expected);
	});

	it("should return 31 for input 1000", () => {
		const x = 1000;
		const expected = 31;

		const actual = mySqrt(x);

		assert.strictEqual(actual, expected);
	});

	it("should return 316 for input 100000", () => {
		const x = 100000;
		const expected = 316;

		const actual = mySqrt(x);

		assert.strictEqual(actual, expected);
	});

	it("should return 46339 for input 2147395599", () => {
		const x = 2147395599;
		const expected = 46339;

		const actual = mySqrt(x);

		assert.strictEqual(actual, expected);
	});

	it("should return 46340 for input 2147483647", () => {
		const x = 2147483647;
		const expected = 46340;

		const actual = mySqrt(x);

		assert.strictEqual(actual, expected);
	});
});
