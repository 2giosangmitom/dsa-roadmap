import { expect, describe, it } from "vitest";
import {
  sortArray,
  bubbleSort,
  insertionSort,
  sortMethod,
} from "../src/sort.js";

const testCases = [
  {
    name: "should return a sorted array for [3, 1, 2]",
    input: [3, 1, 2],
    expected: [1, 2, 3],
  },
  {
    name: "should return an empty array for []",
    input: [],
    expected: [],
  },
  {
    name: "should handle negative numbers [-3, -1, -2]",
    input: [-3, -1, -2],
    expected: [-3, -2, -1],
  },
  {
    name: "should return the same array for already sorted input [1, 2, 3]",
    input: [1, 2, 3],
    expected: [1, 2, 3],
  },
  {
    name: "should handle mixed positive and negative numbers [3, -1, 2, -5, 0]",
    input: [3, -1, 2, -5, 0],
    expected: [-5, -1, 0, 2, 3],
  },
  {
    name: "should handle duplicate numbers [4, 2, 2, 3, 1]",
    input: [4, 2, 2, 3, 1],
    expected: [1, 2, 2, 3, 4],
  },
  {
    name: "should handle array with all identical elements [7, 7, 7, 7, 7]",
    input: [7, 7, 7, 7, 7],
    expected: [7, 7, 7, 7, 7],
  },
];

describe("merge sort", () => {
  it.each(testCases)("$name", ({ input, expected }) => {
    expect(sortArray(input)).toEqual(expected);
  });

  it("should handle large array correctly", () => {
    const nums = Array.from({ length: 20000 }, () =>
      Math.floor(Math.random() * 100000),
    );
    const expected = [...nums].sort((a, b) => a - b);
    expect(sortArray(nums)).toEqual(expected);
  });
});

describe("bubble sort", () => {
  it.each(testCases)("$name", ({ input, expected }) => {
    expect(bubbleSort(input)).toEqual(expected);
  });

  it("should handle large array correctly", () => {
    const nums = Array.from({ length: 20000 }, () =>
      Math.floor(Math.random() * 100000),
    );
    const expected = [...nums].sort((a, b) => a - b);
    expect(bubbleSort(nums)).toEqual(expected);
  });
});

describe("insertion sort", () => {
  it.each(testCases)("$name", ({ input, expected }) => {
    expect(insertionSort(input)).toEqual(expected);
  });

  it("should handle large array correctly", () => {
    const nums = Array.from({ length: 20000 }, () =>
      Math.floor(Math.random() * 100000),
    );
    const expected = [...nums].sort((a, b) => a - b);
    expect(insertionSort(nums)).toEqual(expected);
  });
});

describe("sort method", () => {
  it.each(testCases)("$name", ({ input, expected }) => {
    expect(sortMethod(input)).toEqual(expected);
  });

  it("should handle large array correctly", () => {
    const nums = Array.from({ length: 20000 }, () =>
      Math.floor(Math.random() * 100000),
    );
    const expected = [...nums].sort((a, b) => a - b);
    expect(sortMethod(nums)).toEqual(expected);
  });
});
