import { expect, describe, it, test } from "vitest";
import { sortArray } from "../src/sort.js";

const testCases = [
  {
    input: [3, 1, 2],
    expected: [1, 2, 3],
  },
  {
    input: [],
    expected: [],
  },
  {
    input: [-3, -1, -2],
    expected: [-3, -2, -1],
  },
  {
    input: [1, 2, 3],
    expected: [1, 2, 3],
  },
  {
    input: [3, -1, 2, -5, 0],
    expected: [-5, -1, 0, 2, 3],
  },
  {
    input: [4, 2, 2, 3, 1],
    expected: [1, 2, 2, 3, 4],
  },
  {
    input: [7, 7, 7, 7, 7],
    expected: [7, 7, 7, 7, 7],
  },
];

describe("merge sort", () => {
  testCases.forEach(({ input, expected }, index) => {
    test(`${index}`, () => {
      const actual = sortArray(input);
      expect(actual).toStrictEqual(expected);
    });
  });

  it("should handle large array correctly", () => {
    const nums = Array.from({ length: 20000 }, () =>
      Math.floor(Math.random() * 100000)
    );
    const expected = [...nums].sort((a, b) => a - b);
    expect(sortArray(nums)).toEqual(expected);
  });
});
