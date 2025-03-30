import { describe, expect, test } from "vitest";
import { calculate } from "./solutions_224.js";

const testCases = [
	{ s: "1 + 1", expected: 2 },
	{ s: "1 - 0", expected: 1 },
	{ s: "1 - (2 + 3) + 4", expected: 0 },
	{ s: "1 - (2 - (3 + 4))", expected: 6 },
	{ s: "- (3 + (2 - 1))", expected: -4 },
];

describe("calculate", () => {
	testCases.forEach(({ s, expected }, index) => {
		test(`case ${index}`, () => {
			const actual = calculate(s);

			expect(actual).toBe(expected);
		});
	});
});
