import { describe, expect, test } from "vitest";
import { romanToInt } from "./solutions_13.js";

const testCases = [
	{ s: "III", expected: 3 },
	{ s: "LVIII", expected: 58 },
	{ s: "MCMXCIV", expected: 1994 },
];

describe("romanToInt", () => {
	testCases.forEach(({ s, expected }, index) => {
		test(`case ${index}`, () => {
			const actual = romanToInt(s);
			expect(actual).toBe(expected);
		});
	});
});
