import assert from "node:assert";
import { describe, it } from "node:test";
import { longestCommonPrefix } from "../src/longest_common_prefix.js";

describe("longestCommonPrefix", { concurrency: true, timeout: 1000 }, () => {
	it('should return "fl" for the input ["flower", "flow", "flight"]', () => {
		const strs = ["flower", "flow", "flight"];
		const result = longestCommonPrefix(strs);
		assert.strictEqual(result, "fl");
	});

	it('should return "" for the input ["dog", "racecar", "car"]', () => {
		const strs = ["dog", "racecar", "car"];
		const result = longestCommonPrefix(strs);
		assert.strictEqual(result, "");
	});

	it('should return "ap" for the input ["apple", "apricot", "ap"]', () => {
		const strs = ["apple", "apricot", "ap"];
		const result = longestCommonPrefix(strs);
		assert.strictEqual(result, "ap");
	});

	it('should return "root" for the input ["root", "rooting", "rooted"]', () => {
		const strs = ["root", "rooting", "rooted"];
		const result = longestCommonPrefix(strs);
		assert.strictEqual(result, "root");
	});

	it('should return "ab" for the input ["abacus", "abbreviation", "abnormal"]', () => {
		const strs = ["abacus", "abbreviation", "abnormal"];
		const result = longestCommonPrefix(strs);
		assert.strictEqual(result, "ab");
	});

	it('should return "" for the input array containing only empty strings', () => {
		const strs = ["", "", ""];
		const result = longestCommonPrefix(strs);
		assert.strictEqual(result, "");
	});

	it('should return "a" for the input ["a"]', () => {
		const strs = ["a"];
		const result = longestCommonPrefix(strs);
		assert.strictEqual(result, "a");
	});
});
