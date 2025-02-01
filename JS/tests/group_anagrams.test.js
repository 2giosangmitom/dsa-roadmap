import assert from "node:assert";
import { describe, it } from "node:test";
import { groupAnagrams } from "../src/group_anagrams.js";

describe("groupAnagrams", { concurrency: true, timeout: 1000 }, () => {
	it("should group anagrams correctly for ['eat', 'tea', 'tan', 'ate', 'nat', 'bat']", () => {
		const input = ["eat", "tea", "tan", "ate", "nat", "bat"];
		const output = groupAnagrams(input);

		const expected = [["bat"], ["tan", "nat"], ["eat", "tea", "ate"]];
		assert.deepStrictEqual(
			output.map((group) => group.sort()).sort(),
			expected.map((group) => group.sort()).sort(),
		);
	});

	it("should return [['']] for ['']", () => {
		const input = [""];
		const output = groupAnagrams(input);
		assert.deepStrictEqual(output, [[""]]);
	});

	it("should return [['a']] for ['a']", () => {
		const input = ["a"];
		const output = groupAnagrams(input);
		assert.deepStrictEqual(output, [["a"]]);
	});

	it("should group anagrams correctly for ['abc', 'cba', 'bca', 'xyz', 'zyx']", () => {
		const input = ["abc", "cba", "bca", "xyz", "zyx"];
		const output = groupAnagrams(input);

		const expected = [
			["abc", "cba", "bca"],
			["xyz", "zyx"],
		];
		assert.deepStrictEqual(
			output.map((group) => group.sort()).sort(),
			expected.map((group) => group.sort()).sort(),
		);
	});

	it("should handle an input with no anagrams", () => {
		const input = ["hello", "world", "java", "python"];
		const output = groupAnagrams(input);
		assert.strictEqual(output.length, 4);
	});
});
