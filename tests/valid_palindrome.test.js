import assert from "node:assert";
import { describe, it } from "node:test";
import { isPalindrome } from "../src/valid_palindrome.js";

describe("valid palindrome", { concurrency: true, timeout: 5000 }, () => {
	it("should return true for input 'A man, a plan, a canal: Panama'", () => {
		const s = "A man, a plan, a canal: Panama";
		const expected = true;
		const actual = isPalindrome(s);
		assert.equal(actual, expected);
	});

	it("should return true for input 'racecar'", () => {
		const s = "racecar";
		const expected = true;
		const actual = isPalindrome(s);
		assert.equal(actual, expected);
	});

	it("should return false for input 'hello'", () => {
		const s = "hello";
		const expected = false;
		const actual = isPalindrome(s);
		assert.equal(actual, expected);
	});

	it("should return true for input ' ' (empty string)", () => {
		const s = " ";
		const expected = true;
		const actual = isPalindrome(s);
		assert.equal(actual, expected);
	});

	it("should return true for input 'No lemon, no melon'", () => {
		const s = "No lemon, no melon";
		const expected = true;
		const actual = isPalindrome(s);
		assert.equal(actual, expected);
	});

	it("should return false for input '123abc321'", () => {
		const s = "123abc321";
		const expected = false;
		const actual = isPalindrome(s);
		assert.equal(actual, expected);
	});
});
