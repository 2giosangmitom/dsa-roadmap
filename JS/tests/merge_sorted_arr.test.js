import { test, expect } from "vitest";
import { merge } from "../src/merge_sorted_arr.js";

const testCases = [
  {
    arr1: [1, 2, 3, 0, 0, 0],
    arr2: [4, 5, 6],
    m: 3,
    n: 3,
    expected: [1, 2, 3, 4, 5, 6],
  },
  {
    arr1: [1, 2, 3, 0, 0, 0],
    arr2: [2, 5, 6],
    m: 3,
    n: 3,
    expected: [1, 2, 2, 3, 5, 6],
  },
  {
    arr1: [0],
    arr2: [1],
    m: 0,
    n: 1,
    expected: [1],
  },
  {
    arr1: [1, 3, 5, 7, 9, 0, 0, 0, 0],
    arr2: [2, 4, 6, 8],
    m: 5,
    n: 4,
    expected: [1, 2, 3, 4, 5, 6, 7, 8, 9],
  },
  {
    arr1: [1, 3, 5, 7, 9, 0, 0, 0, 0, 0],
    arr2: [2, 4, 6, 8, 10],
    m: 5,
    n: 5,
    expected: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10],
  },
];

testCases.forEach((testCase, index) => {
  test(`test case ${index + 1}: should merge arrays correctly`, () => {
    merge(testCase.arr1, testCase.m, testCase.arr2, testCase.n);
    expect(testCase.arr1).toEqual(testCase.expected);
  });
});
