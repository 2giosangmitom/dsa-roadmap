import assert from "node:assert";
import { describe, it } from "node:test";
import { isPalindrome, isPalindrome2 } from "../src/valid_palindrome.js";

function runTests(name, callback) {
  describe(name, { concurrency: true, timeout: 1000 }, () => {
    it("should return true for input 'A man, a plan, a canal: Panama'", () => {
      const s = "A man, a plan, a canal: Panama";
      const expected = true;
      const actual = callback(s);
      assert.equal(actual, expected);
    });

    it("should return true for input 'racecar'", () => {
      const s = "racecar";
      const expected = true;
      const actual = callback(s);
      assert.equal(actual, expected);
    });

    it("should return false for input 'hello'", () => {
      const s = "hello";
      const expected = false;
      const actual = callback(s);
      assert.equal(actual, expected);
    });

    it("should return true for input ' ' (empty string)", () => {
      const s = " ";
      const expected = true;
      const actual = callback(s);
      assert.equal(actual, expected);
    });

    it("should return true for input 'No lemon, no melon'", () => {
      const s = "No lemon, no melon";
      const expected = true;
      const actual = callback(s);
      assert.equal(actual, expected);
    });

    it("should return false for input '123abc321'", () => {
      const s = "123abc321";
      const expected = false;
      const actual = callback(s);
      assert.equal(actual, expected);
    });
  });
}

runTests("isPalindrome", isPalindrome);
runTests("isPalindrome2", isPalindrome2);
