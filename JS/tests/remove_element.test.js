import { assert, test } from "vitest";
import { removeElement } from "../src/remove_element.js";

const testCases = [
  {
    nums: [3, 2, 2, 3],
    val: 3,
    expectedResult: 2,
    expectedArray: [2, 2],
  },
  {
    nums: [0, 1, 2, 2, 3, 0, 4, 2],
    val: 2,
    expectedResult: 5,
    expectedArray: [0, 1, 3, 0, 4],
  },
  {
    nums: [1, 1, 1, 1],
    val: 1,
    expectedResult: 0,
    expectedArray: [],
  },
  {
    nums: [0, 1, 2, 3, 4, 2, 2],
    val: 2,
    expectedResult: 4,
    expectedArray: [0, 1, 3, 4],
  },
  {
    nums: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10],
    val: 7,
    expectedResult: 9,
    expectedArray: [1, 2, 3, 4, 5, 6, 8, 9, 10],
  },
  {
    nums: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10],
    val: 0,
    expectedResult: 10,
    expectedArray: [1, 2, 3, 4, 5, 6, 7, 8, 9, 10],
  },
  {
    nums: [5],
    val: 0,
    expectedResult: 1,
    expectedArray: [5],
  },
];

testCases.forEach(({ nums, val, expectedResult, expectedArray }, index) => {
  test(`test case ${index + 1}`, () => {
    const result = removeElement(nums, val);
    assert.strictEqual(result, expectedResult);
    assert.deepStrictEqual(nums.slice(0, result), expectedArray);
  });
});
