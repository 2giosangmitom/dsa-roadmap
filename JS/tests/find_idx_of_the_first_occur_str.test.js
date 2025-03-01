import { test, expect } from "vitest";
import { strStr } from "../src/find_idx_of_the_first_occur_str.js";

const testCases = [
  { haystack: "sadbutsad", needle: "sad", expected: 0 },
  { haystack: "leetcode", needle: "leeto", expected: -1 },
  { haystack: "a", needle: "a", expected: 0 },
  { haystack: "xyz", needle: "abc", expected: -1 },
  { haystack: "abcabc", needle: "abc", expected: 0 },
];

testCases.forEach(({ haystack, needle, expected }) => {
  test(`returns ${expected} for "${needle}" in "${haystack}"`, () => {
    const result = strStr(haystack, needle);
    expect(result).toBe(expected);
  });
});
