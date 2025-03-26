import { describe, expect, test } from "vitest";
import { nextGreaterElements } from "./solutions_503.js";

const testCases = [
	{ nums: [1, 2, 1], expected: [2, -1, 2] },
	{ nums: [1, 2, 3, 4, 3], expected: [2, 3, 4, -1, 4] },
	{ nums: [10, 1, 2, 3], expected: [-1, 2, 3, 10] },
	{ nums: [9, 10, 8, 1, 2, 3, 4, 5], expected: [10, -1, 9, 2, 3, 4, 5, 9] },
	{ nums: [1, 2, 3, 4, 5], expected: [2, 3, 4, 5, -1] },
	{
		nums: [10, 9, 8, 7, 6, 5, 4, 3, 2, 1],
		expected: [-1, 10, 10, 10, 10, 10, 10, 10, 10, 10],
	},
];

describe("nextGreaterElements", () => {
	testCases.forEach(({ nums, expected }, index) => {
		test(`case ${index}`, () => {
			const actual = nextGreaterElements(nums);
			expect(actual).toStrictEqual(expected);
		});
	});
});
