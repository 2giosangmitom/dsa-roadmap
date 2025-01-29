import assert from "node:assert";
import { describe, it } from "node:test";
import { isPowerOfTwo } from "../src/power_of_two.js";

describe("isPowerOfTwo", { concurrency: true, timeout: 5000 }, () => {
	it("should return true for 16", () => {
		assert.equal(isPowerOfTwo(16), true);
	});

	it("should return false for 3", () => {
		assert.equal(isPowerOfTwo(3), false);
	});

	it("should return false for negative number", () => {
		assert.equal(isPowerOfTwo(-16), false);
	});

  it("should return false for 0", () => {
		assert.equal(isPowerOfTwo(), false);
	});
});
