import { describe, expect, it } from "vitest";
import { Solution } from "./solutions_528.js";

describe("Random Pick with Weight", () => {
	const testCases = [
		{ w: [1, 3, 2], desc: "Basic case" },
		{ w: [10, 90], desc: "Highly skewed distribution" },
		{ w: [5, 5, 5, 5], desc: "Equal weights" },
		{ w: [1, 1, 1, 1, 1, 1, 1, 1, 1, 1], desc: "Many equal weights" },
		{ w: [1000, 1], desc: "Extremely unbalanced weights" },
		{ w: [1], desc: "Single element" },
	];

	for (const { w, desc } of testCases) {
		it(`Should always return valid indices (${desc})`, () => {
			const solution = new Solution(w);
			const n = w.length;

			for (let i = 0; i < 1000; i++) {
				const index = solution.pickIndex();
				expect(index).toBeGreaterThanOrEqual(0);
				expect(index).toBeLessThan(n);
			}
		});

		it(`Should match expected probability distribution (${desc})`, () => {
			const solution = new Solution(w);
			const count = Array(w.length).fill(0);
			const totalRuns = 100000;

			for (let i = 0; i < totalRuns; i++) {
				count[solution.pickIndex()]++;
			}

			const totalWeight = w.reduce((sum, num) => sum + num, 0);
			const expectedRatio = w.map((weight) => weight / totalWeight);
			const actualRatio = count.map((c) => c / totalRuns);

			for (let i = 0; i < w.length; i++) {
				expect(actualRatio[i]).toBeCloseTo(expectedRatio[i], 1);
			}
		});
	}
});
