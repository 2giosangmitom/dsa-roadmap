import assert from "node:assert";
import { describe, it } from "node:test";
import { strStr } from "../src/find_idx_of_the_first_occur_str.js";

describe("strStr", () => {
  it('should return 0 when "sad" is found in "sadbutsad" at index 0', () => {
    const haystack = "sadbutsad";
    const needle = "sad";
    const result = strStr(haystack, needle);
    assert.strictEqual(result, 0);
  });

  it('should return 6 when "sad" is found in "sadbutsad" at index 6', () => {
    const haystack = "sadbutsad";
    const needle = "sad";
    const result = strStr(haystack, needle);
    assert.strictEqual(result, 0);
  });

  it('should return -1 when "leeto" is not found in "leetcode"', () => {
    const haystack = "leetcode";
    const needle = "leeto";
    const result = strStr(haystack, needle);
    assert.strictEqual(result, -1);
  });

  it('should return 0 when "a" is found in "a"', () => {
    const haystack = "a";
    const needle = "a";
    const result = strStr(haystack, needle);
    assert.strictEqual(result, 0);
  });

  it('should return -1 when "abc" is not found in "xyz"', () => {
    const haystack = "xyz";
    const needle = "abc";
    const result = strStr(haystack, needle);
    assert.strictEqual(result, -1);
  });

  it('should return 2 when "abc" is found in "abcabc" at index 2', () => {
    const haystack = "abcabc";
    const needle = "abc";
    const result = strStr(haystack, needle);
    assert.strictEqual(result, 0);
  });
});
