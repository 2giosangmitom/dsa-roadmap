import { describe, expect, test } from "vitest";
import { permute } from "./solutions_46.js";

const testCases = [
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
		nums: [0, 1],
		expected: [
			[0, 1],
			[1, 0],
		],
	},
	{ nums: [1], expected: [[1]] },
];

describe("permute", () => {
	testCases.forEach(({ nums, expected }, index) => {
		test(`case ${index}`, () => {
			const actual = permute(nums);

			expect(actual.sort((a, b) => (a.join() < b.join() ? -1 : 1))).toEqual(
				expected,
			);
		});
	});
});
