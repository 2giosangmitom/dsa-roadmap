import { describe, expect, test } from "vitest";
import { topKFrequent } from "./solutions_347.js";

const testCases = [
	{ nums: [1, 1, 1, 2, 2, 3], k: 2, expected: [1, 2] },
	{ nums: [1], k: 1, expected: [1] },
	{ nums: [2, 3, 4, 1, 4, 0, 4, -1, -2, -1], k: 2, expected: [4, -1] },
	{
		nums: [6, 0, 1, 4, 9, 7, -3, 1, -4, -8, 4, -7, -3, 3, 2, -3, 9, 5, -4, 0],
		k: 6,
		expected: [-3, 0, 1, 4, 9, -4],
	},
];

describe("topKFrequent", () => {
	testCases.forEach(({ nums, k, expected }, index) => {
		test(`case ${index}`, () => {
			const actual = topKFrequent(nums, k);
			expect(actual.sort((a, b) => a - b)).toStrictEqual(
				expected.sort((a, b) => a - b),
			);
		});
	});
});
