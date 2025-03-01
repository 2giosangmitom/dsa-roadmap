import { test, expect } from "vitest";
import { addBinary } from "../src/add_binary.js";

const testCases = [
  { a: "11", b: "1", expected: "100" },
  { a: "1010", b: "1011", expected: "10101" },
  { a: "0", b: "0", expected: "0" },
  { a: "0", b: "1", expected: "1" },
  { a: "110", b: "110", expected: "1100" },
  { a: "11110000", b: "1111", expected: "11111111" },
  { a: "", b: "101", expected: "101" },
  {
    a: "1".repeat(1000),
    b: "1".repeat(1000),
    expected: `${"1".repeat(1000)}0`,
  },
];

testCases.forEach(({ a, b, expected }, index) => {
  test(`test case ${index + 1}`, () => {
    const actual = addBinary(a, b);
    expect(actual).toBe(expected);
  });
});
