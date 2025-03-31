import { describe, expect, test } from "vitest";
import { rotate } from "./solutions_189.js";

const testCases = [
	{ nums: [1, 2, 3, 4, 5, 6, 7], k: 3, expected: [5, 6, 7, 1, 2, 3, 4] },
	{ nums: [1, 2, 3, 4, 5], k: 7, expected: [4, 5, 1, 2, 3] },
	{ nums: [1, 2, 3, 4], k: 4, expected: [1, 2, 3, 4] },
	{ nums: [1], k: 10, expected: [1] },
	{ nums: [], k: 5, expected: [] },
];

describe("rotate", () => {
	testCases.forEach(({ nums, k, expected }, index) => {
		test(`case ${index}`, () => {
			const actual = [...nums];
			rotate(actual, k);
			expect(actual).toEqual(expected);
		});
	});
});
