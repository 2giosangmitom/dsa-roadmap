import assert from "node:assert";
import { describe, it } from "node:test";
import { closestPrimes } from "../src/closest_prime.js";

describe("closestPrimes", { concurrency: true, timeout: 1000 }, () => {
	it("should return [11, 13] for input (10, 19)", () => {
		const expected = [11, 13];
		const actual = closestPrimes(10, 19);
		assert.deepStrictEqual(actual, expected);
	});

	it("should return [17, 19] for input (15, 23)", () => {
		const expected = [17, 19];
		const actual = closestPrimes(15, 23);
		assert.deepStrictEqual(actual, expected);
	});

	it("should return [29, 31] for input (25, 35)", () => {
		const expected = [29, 31];
		const actual = closestPrimes(25, 35);
		assert.deepStrictEqual(actual, expected);
	});

	it("should return [-1, -1] for input (20, 21) with no primes", () => {
		const expected = [-1, -1];
		const actual = closestPrimes(20, 21);
		assert.deepStrictEqual(actual, expected);
	});

	it("should return [101, 103] for input (100, 110)", () => {
		const expected = [101, 103];
		const actual = closestPrimes(100, 110);
		assert.deepStrictEqual(actual, expected);
	});

	it("should return [-1, -1] for input (0, 1) with no primes", () => {
		const expected = [-1, -1];
		const actual = closestPrimes(0, 1);
		assert.deepStrictEqual(actual, expected);
	});

	it("should return [2, 3] for input (1, 5)", () => {
		const expected = [2, 3];
		const actual = closestPrimes(1, 5);
		assert.deepStrictEqual(actual, expected);
	});
});
