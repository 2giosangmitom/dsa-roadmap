import assert from "node:assert";
import { describe, it } from "node:test";
import { canAliceWin } from "../src/stone_removal_game.js";

describe("Stone Removal Game", { concurrency: true, timeout: 1000 }, () => {
	it("should return true when n = 12", () => {
		const result = canAliceWin(12);
		assert.strictEqual(result, true);
	});

	it("should return false when n = 1", () => {
		const result = canAliceWin(1);
		assert.strictEqual(result, false);
	});

	it("should return true when n = 10", () => {
		const result = canAliceWin(10);
		assert.strictEqual(result, true);
	});

	it("should return true when n = 11", () => {
		const result = canAliceWin(11);
		assert.strictEqual(result, true);
	});

	it("should return false when n = 20", () => {
		const result = canAliceWin(20);
		assert.strictEqual(result, false);
	});

	it("should return false when n = 19", () => {
		const result = canAliceWin(19);
		assert.strictEqual(result, false);
	});

	it("should return true when n = 30", () => {
		const result = canAliceWin(30);
		assert.strictEqual(result, true);
	});

	it("should return true when n = 29", () => {
		const result = canAliceWin(29);
		assert.strictEqual(result, true);
	});

	it("should return true when n = 50", () => {
		const result = canAliceWin(50);
		assert.strictEqual(result, true);
	});

	it("should return true when n = 49", () => {
		const result = canAliceWin(49);
		assert.strictEqual(result, true);
	});
});
