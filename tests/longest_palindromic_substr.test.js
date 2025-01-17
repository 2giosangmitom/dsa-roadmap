import assert from "node:assert";
import { describe, it } from "node:test";
import { lengthOfLongestSubstring } from "../src/longest_substr.js";

describe(
	"lengthOfLongestSubstring",
	{ concurrency: true, timeout: 5000 },
	() => {
		it('should return 3 for the input "abcabcbb"', () => {
			const input = "abcabcbb";

			const result = lengthOfLongestSubstring(input);

			assert.strictEqual(result, 3);
		});

		it('should return 1 for the input "bbbbb"', () => {
			const input = "bbbbb";

			const result = lengthOfLongestSubstring(input);

			assert.strictEqual(result, 1);
		});

		it('should return 3 for the input "pwwkew"', () => {
			const input = "pwwkew";

			const result = lengthOfLongestSubstring(input);

			assert.strictEqual(result, 3);
		});

		it("should return 0 for an empty string", () => {
			const input = "";

			const result = lengthOfLongestSubstring(input);

			assert.strictEqual(result, 0);
		});

		it("should return 1 for a single character string", () => {
			const input = "a";

			const result = lengthOfLongestSubstring(input);

			assert.strictEqual(result, 1);
		});

		it('should return 3 for the input "dvdf"', () => {
			const input = "dvdf";

			const result = lengthOfLongestSubstring(input);

			assert.strictEqual(result, 3);
		});

		it('should return 2 for the input "abba"', () => {
			const input = "abba";

			const result = lengthOfLongestSubstring(input);

			assert.strictEqual(result, 2);
		});
	},
);
