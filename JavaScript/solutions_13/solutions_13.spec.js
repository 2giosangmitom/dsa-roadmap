import { romanToInt } from "./solutions_13.js";
import { describe, test, expect } from "vitest";

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
