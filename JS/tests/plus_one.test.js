import { test, expect } from "vitest";
import { plusOne } from "../src/plus_one.js";

const testCases = [
  {
    input: [1, 2, 3],
    expected: [1, 2, 4],
    description: "should return [1,2,4] for input [1,2,3]",
  },
  {
    input: [1, 2, 9],
    expected: [1, 3, 0],
    description: "should return [1,3,0] for input [1,2,9]",
  },
  {
    input: [9, 9, 8],
    expected: [9, 9, 9],
    description: "should return [9,9,9] for input [9,9,8]",
  },
  {
    input: [9, 9, 9],
    expected: [1, 0, 0, 0],
    description: "should return [1,0,0,0] for input [9,9,9]",
  },
];

testCases.forEach(({ input, expected, description }) => {
  test(description, () => {
    const actual = plusOne(input);
    expect(actual).toEqual(expected);
  });
});
