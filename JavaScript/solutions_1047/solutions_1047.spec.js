import { describe, expect, test } from "vitest";
import { removeDuplicates } from "./solutions_1047.js";

const testCases = [
	{ s: "abbaca", expected: "ca" },
	{ s: "azxxzy", expected: "ay" },
	{ s: "aacabba", expected: "c" },
];

describe("removeDuplicates", () => {
	testCases.forEach(({ s, expected }, index) => {
		test(`case ${index}`, () => {
			const actual = removeDuplicates(s);

			expect(actual).toBe(expected);
		});
	});
});
