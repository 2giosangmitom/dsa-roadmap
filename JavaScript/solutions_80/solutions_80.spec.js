import { describe, expect, test } from "vitest";
import { removeDuplicates } from "./solutions_80.js";

const testCases = [
	{ nums: [1, 1, 1, 2, 2, 3], expected: 5, expectedNums: [1, 1, 2, 2, 3] },
	{
		nums: [-4, -4, 1, 2, 3, 3],
		expected: 6,
		expectedNums: [-4, -4, 1, 2, 3, 3],
	},
	{ nums: [0, 0, 0, 0, 0], expected: 2, expectedNums: [0, 0] },
	{ nums: [1, 2, 3, 4, 5], expected: 5, expectedNums: [1, 2, 3, 4, 5] },
	{
		nums: [-1, -1, -1, 0, 0, 1, 1, 2, 2, 2, 3, 3, 4],
		expected: 11,
		expectedNums: [-1, -1, 0, 0, 1, 1, 2, 2, 3, 3, 4],
	},
	{ nums: [], expected: 0, expectedNums: [] },
	{ nums: [5], expected: 1, expectedNums: [5] },
];

describe("removeDuplicates", () => {
	testCases.forEach(({ nums, expected, expectedNums }, i) => {
		test(`case ${i}`, () => {
			const actual = removeDuplicates(nums);
			expect(actual).toBe(expected);
			expect(nums.slice(0, actual)).toEqual(expectedNums);
		});
	});
});
