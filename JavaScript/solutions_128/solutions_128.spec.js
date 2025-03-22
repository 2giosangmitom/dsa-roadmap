import { describe, expect, test } from "vitest";
import { longestConsecutive } from "./solutions_128.js";

const testCases = [
	{ nums: [100, 4, 200, 1, 3, 2], expected: 4 },
	{ nums: [0, 3, 7, 2, 5, 8, 4, 6, 0, 1], expected: 9 },
	{ nums: [1, 0, 1, 2], expected: 3 },
	{ nums: [0, 0], expected: 1 },
	{ nums: [-6, -1, -1, 9, -8, -6, -6, 4, 4, -3, -8, -1], expected: 1 },
];

describe("longestConsecutive", () => {
	testCases.forEach(({ nums, expected }, i) => {
		test(`case ${i}`, () => {
			const actual = longestConsecutive(nums);
			expect(actual).toBe(expected);
		});
	});
});
