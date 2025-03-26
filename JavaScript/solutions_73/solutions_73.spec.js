import { describe, expect, test } from "vitest";
import { setZeroes, setZeroes2 } from "./solutions_73.js";

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
	{
		matrix: [
			[1, 2, 3],
			[4, 0, 6],
			[7, 8, 9],
		],
		expected: [
			[1, 0, 3],
			[0, 0, 0],
			[7, 0, 9],
		],
	},
	{
		matrix: [
			[1, 1, 1, 1],
			[1, 0, 1, 1],
			[1, 1, 1, 1],
			[1, 1, 1, 0],
		],
		expected: [
			[1, 0, 1, 0],
			[0, 0, 0, 0],
			[1, 0, 1, 0],
			[0, 0, 0, 0],
		],
	},
	{
		matrix: [
			[0, 0, 0],
			[0, 0, 0],
			[0, 0, 0],
		],
		expected: [
			[0, 0, 0],
			[0, 0, 0],
			[0, 0, 0],
		],
	},
	{
		matrix: [
			[1, 1, 1],
			[1, 1, 1],
			[1, 1, 1],
		],
		expected: [
			[1, 1, 1],
			[1, 1, 1],
			[1, 1, 1],
		],
	},
];

describe("setZeroes", () => {
	testCases.forEach(({ matrix, expected }, index) => {
		test(`case ${index}`, () => {
			const actual = Array.from(matrix, (v) => Array.from(v));
			setZeroes(actual);
			expect(actual).toStrictEqual(expected);
		});
	});
});

describe("setZeroes2", () => {
	testCases.forEach(({ matrix, expected }, index) => {
		test(`case ${index}`, () => {
			const actual = Array.from(matrix, (v) => Array.from(v));
			setZeroes2(actual);
			expect(actual).toStrictEqual(expected);
		});
	});
});
