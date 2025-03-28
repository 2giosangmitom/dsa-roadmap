import { describe, test, expect } from "vitest";
import { combine, combine2 } from "./solutions_77.js";

const testCases = [
  {
    n: 4,
    k: 2,
    expected: [
      [1, 2],
      [1, 3],
      [1, 4],
      [2, 3],
      [2, 4],
      [3, 4],
    ],
  },
  { n: 1, k: 1, expected: [[1]] },
  {
    n: 4,
    k: 3,
    expected: [
      [1, 2, 3],
      [1, 2, 4],
      [1, 3, 4],
      [2, 3, 4],
    ],
  },
  {
    n: 5,
    k: 2,
    expected: [
      [1, 2],
      [1, 3],
      [1, 4],
      [1, 5],
      [2, 3],
      [2, 4],
      [2, 5],
      [3, 4],
      [3, 5],
      [4, 5],
    ],
  },
];

describe("combine", () => {
  testCases.forEach(({ n, k, expected }, index) => {
    test(`case ${index}`, () => {
      const actual = combine(n, k);
      expect(actual).toStrictEqual(expected);
    });
  });
});

describe("combine2", () => {
  testCases.forEach(({ n, k, expected }, index) => {
    test(`case ${index}`, () => {
      const actual = combine2(n, k);
      expect(actual).toStrictEqual(expected);
    });
  });
});
