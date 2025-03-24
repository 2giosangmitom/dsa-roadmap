import { describe, expect, it } from "vitest";
import { permuteUnique } from "./solutions_47.js";

const testCases = [
	{ nums: [1], expected: [[1]] },
	{
		nums: [1, 2],
		expected: [
			[1, 2],
			[2, 1],
		],
	},
	{
		nums: [1, 2, 3],
		expected: [
			[1, 2, 3],
			[1, 3, 2],
			[2, 1, 3],
			[2, 3, 1],
			[3, 1, 2],
			[3, 2, 1],
		],
	},
	{
		nums: [1, 1, 2],
		expected: [
			[1, 1, 2],
			[1, 2, 1],
			[2, 1, 1],
		],
	},
	{
		nums: [1, 2, 2],
		expected: [
			[1, 2, 2],
			[2, 1, 2],
			[2, 2, 1],
		],
	},
];

describe("permuteUnique", () => {
	testCases.forEach(({ nums, expected }, index) => {
		it(`case ${index}`, () => {
			const result = permuteUnique(nums);
			expect(result.sort((a, b) => (a.join() < b.join() ? -1 : 1))).toEqual(
				expected,
			);
		});
	});
});
