import { subsets } from "./solutions_78.js";
import { describe, expect, test } from "vitest";

const testCases = [
	{
		nums: [1, 2, 3],
		expected: [[], [1], [2], [3], [1, 2], [1, 3], [2, 3], [1, 2, 3]],
	},
	{
		nums: [],
		expected: [[]],
	},
	{
		nums: [0],
		expected: [[], [0]],
	},
];

describe("subsets", () => {
	testCases.forEach(({ nums, expected }, index) => {
		test(`case ${index}`, () => {
			const actual = subsets(nums);

			expect(
				actual.sort((a, b) => {
					if (a.length !== b.length) {
						return a.length - b.length;
					}
					return a.join("") < b.join("") ? -1 : 1;
				}),
			).toStrictEqual(expected);
		});
	});
});
