import { describe, expect, test } from "vitest";
import { maxSlidingWindow } from "./solutions_239.js";

const testCases = [
	{ nums: [1, 3, -1, -3, 5, 3, 6, 7], k: 3, expected: [3, 3, 5, 5, 6, 7] },
	{ nums: [1], k: 1, expected: [1] },
	{ nums: [9, 11], k: 2, expected: [11] },
	{ nums: [4, -2], k: 2, expected: [4] },
	{ nums: [1, 3, 1, 2, 0, 5], k: 3, expected: [3, 3, 2, 5] },
	{
		nums: [10, 9, 8, 7, 6, 5, 4, 3, 2, 1],
		k: 4,
		expected: [10, 9, 8, 7, 6, 5, 4],
	},
	{
		nums: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10],
		k: 5,
		expected: [5, 6, 7, 8, 9, 10],
	},
	{ nums: [100, 200, 300, 400], k: 2, expected: [200, 300, 400] },
	{ nums: [7, 2, 4], k: 2, expected: [7, 4] },
	{ nums: [3, 1, -1, -3, 5, 3, 6, 7], k: 4, expected: [3, 5, 5, 6, 7] },
	{ nums: [1, 3, 1, 2, 0, 5, 2, 8], k: 3, expected: [3, 3, 2, 5, 5, 8] },
	{ nums: [10, -1, -2, -3, -4, -5], k: 2, expected: [10, -1, -2, -3, -4] },
	{
		nums: [1, 3, 1, 2, 0, 5, 2, 8, 9, 10],
		k: 5,
		expected: [3, 5, 5, 8, 9, 10],
	},
	{
		nums: [4, 2, 12, 3, -1, -3, 5, 3, 6, 7],
		k: 3,
		expected: [12, 12, 12, 3, 5, 5, 6, 7],
	},
	{
		nums: [1, -1, -2, 3, 5, 6, 7, 8, 9, 10],
		k: 4,
		expected: [3, 5, 6, 7, 8, 9, 10],
	},
	{ nums: [2, 3, 4, 2, 6, 2, 5, 1], k: 3, expected: [4, 4, 6, 6, 6, 5] },
	{ nums: [1, 1, 1, 1, 1, 1], k: 2, expected: [1, 1, 1, 1, 1] },
	{
		nums: [10, 9, 8, 7, 6, 5, 4, 3, 2, 1],
		k: 2,
		expected: [10, 9, 8, 7, 6, 5, 4, 3, 2],
	},
	{ nums: [3, 3, 3, 3, 3, 3], k: 3, expected: [3, 3, 3, 3] },
	{ nums: [-10, -20, -30, -40, -50], k: 2, expected: [-10, -20, -30, -40] },
];

describe("maxSlidingWindow", () => {
	testCases.forEach(({ nums, k, expected }, index) => {
		test(`case ${index}`, () => {
			const actual = maxSlidingWindow(nums, k);

			expect(actual).toStrictEqual(expected);
		});
	});
});
