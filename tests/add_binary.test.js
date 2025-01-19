import assert from "node:assert";
import { describe, it } from "node:test";
import { addBinary } from "../src/add_binary.js";

describe("addBinary", { concurrency: true, timeout: 5000 }, () => {
	it("should return 100 for input '11', '1'", () => {
		const a = "11";
		const b = "1";
		const expected = "100";

		const actual = addBinary(a, b);

		assert.strictEqual(actual, expected);
	});

	it("should return 10101 for input '1010', '1011'", () => {
		const a = "1010";
		const b = "1011";
		const expected = "10101";

		const actual = addBinary(a, b);

		assert.strictEqual(actual, expected);
	});

	it("should return 0 for input '0', '0'", () => {
		const a = "0";
		const b = "0";
		const expected = "0";

		const actual = addBinary(a, b);

		assert.strictEqual(actual, expected);
	});

	it("should return '1' for input '0', '1'", () => {
		const a = "0";
		const b = "1";
		const expected = "1";

		const actual = addBinary(a, b);

		assert.strictEqual(actual, expected);
	});

	it("should return '1100' for input '110', '110'", () => {
		const a = "110";
		const b = "110";
		const expected = "1100";

		const actual = addBinary(a, b);

		assert.strictEqual(actual, expected);
	});

	it("should return '11111111' for input '11110000', '1111'", () => {
		const a = "11110000";
		const b = "1111";
		const expected = "11111111";

		const actual = addBinary(a, b);

		assert.strictEqual(actual, expected);
	});

	it("should handle empty strings as inputs", () => {
		const a = "";
		const b = "101";
		const expected = "101";

		const actual = addBinary(a, b);

		assert.strictEqual(actual, expected);
	});

	it("should handle very large binary strings", () => {
		const a = "1".repeat(1000);
		const b = "1".repeat(1000);
		const expected = `${"1".repeat(1000)}0`;

		const actual = addBinary(a, b);

		assert.strictEqual(actual, expected);
	});
});
