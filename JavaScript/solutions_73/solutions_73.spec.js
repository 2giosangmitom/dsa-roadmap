import { describe, expect, test } from "vitest";
import { setZeroes } from "./solutions_73.js";

const testCases = [
	{
		matrix: [
			[1, 1, 1],
			[1, 0, 1],
			[1, 1, 1],
		],
		expected: [
			[1, 0, 1],
			[0, 0, 0],
			[1, 0, 1],
		],
	},
	{
		matrix: [
			[0, 1, 2, 0],
			[3, 4, 5, 2],
			[1, 3, 1, 5],
		],
		expected: [
			[0, 0, 0, 0],
			[0, 4, 5, 0],
			[0, 3, 1, 0],
		],
	},
];

describe("setZeroes", () => {
	testCases.forEach(({ matrix, expected }, index) => {
		test(`case ${index}`, () => {
			const actual = Array.from(matrix);
			setZeroes(actual);
			expect(actual).toStrictEqual(expected);
		});
	});
});
