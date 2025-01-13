import assert from "node:assert";
import { describe, it } from "node:test";
import { reverse } from "../src/reverse_integer.js";

describe("reverse integer", { concurrency: true, timeout: 5000 }, () => {
	it("should reverse a positive number", () => {
		const input = 123;

		const result = reverse(input);

		assert.strictEqual(result, 321);
	});

	it("should reverse a negative number", () => {
		const input = -123;

		const result = reverse(input);

		assert.strictEqual(result, -321);
	});

	it("should remove leading zeros after reversing", () => {
		const input = 120;

		const result = reverse(input);

		assert.strictEqual(result, 21);
	});

	it("should return 0 when the input is 0", () => {
		const input = 0;

		const result = reverse(input);

		assert.strictEqual(result, 0);
	});

	it("should return 0 if the reversed number exceeds 32-bit integer range", () => {
		const largePositiveInput = 1534236469;
		const largeNegativeInput = -1534236469;

		const result1 = reverse(largePositiveInput);
		const result2 = reverse(largeNegativeInput);

		assert.strictEqual(result1, 0);
		assert.strictEqual(result2, 0);
	});

	it("should handle large negative numbers within bounds", () => {
		const input = -2147483412;

		const result = reverse(input);

		assert.strictEqual(result, -2143847412);
	});

	it("should return the correct reversed number within 32-bit bounds", () => {
		const input = 1463847412;

		const result = reverse(input);

		assert.strictEqual(result, 2147483641);
	});

	it("should return 0 if the reversed number goes out of bounds", () => {
		const input = -2147483648;

		const result = reverse(input);

		assert.strictEqual(result, 0);
	});
});
