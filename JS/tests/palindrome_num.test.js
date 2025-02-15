import assert from "node:assert";
import { describe, it } from "node:test";
import { isPalindrome } from "../src/palindrome_num.js";

describe("isPalindrome", { concurrency: true, timeout: 1000 }, () => {
  it("should return true for a single-digit number", () => {
    assert.strictEqual(isPalindrome(7), true);
  });

  it("should return true for a positive palindrome number", () => {
    assert.strictEqual(isPalindrome(121), true);
  });

  it("should return false for a negative number", () => {
    assert.strictEqual(isPalindrome(-121), false);
  });

  it("should return false for a non-palindrome number", () => {
    assert.strictEqual(isPalindrome(123), false);
  });

  it("should return true for a large palindrome number", () => {
    assert.strictEqual(isPalindrome(123454321), true);
  });

  it("should return false for a large non-palindrome number", () => {
    assert.strictEqual(isPalindrome(123456789), false);
  });

  it("should return true for 0", () => {
    assert.strictEqual(isPalindrome(0), true);
  });

  it("should return true for a two-digit palindrome number", () => {
    assert.strictEqual(isPalindrome(22), true);
  });

  it("should return false for a two-digit non-palindrome number", () => {
    assert.strictEqual(isPalindrome(23), false);
  });

  it("should return true for a number with even digits that is a palindrome", () => {
    assert.strictEqual(isPalindrome(1221), true);
  });

  it("should return true for a number with odd digits that is a palindrome", () => {
    assert.strictEqual(isPalindrome(12321), true);
  });

  it("should return false for a number that ends with 0 but is not 0", () => {
    assert.strictEqual(isPalindrome(10), false);
  });

  it("should return true for a very large palindrome number", () => {
    assert.strictEqual(isPalindrome(100000000000001), true);
  });

  it("should return false for a very large non-palindrome number", () => {
    assert.strictEqual(isPalindrome(1000000000000021), false);
  });
});
