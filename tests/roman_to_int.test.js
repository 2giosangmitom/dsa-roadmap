import assert from "node:assert";
import { describe, it } from "node:test";
import { romanToInt } from "../src/roman_to_int.js";

describe("romanToInt", { concurrency: true, timeout: 5000 }, () => {
	it('should return 3 for the input "III"', () => {
		const result = romanToInt("III");
		assert.strictEqual(result, 3);
	});

	it('should return 58 for the input "LVIII"', () => {
		const result = romanToInt("LVIII");
		assert.strictEqual(result, 58);
	});

	it('should return 1994 for the input "MCMXCIV"', () => {
		const result = romanToInt("MCMXCIV");
		assert.strictEqual(result, 1994);
	});

	it('should return 9 for the input "IX"', () => {
		const result = romanToInt("IX");
		assert.strictEqual(result, 9);
	});

	it('should return 40 for the input "XL"', () => {
		const result = romanToInt("XL");
		assert.strictEqual(result, 40);
	});

	it('should return 90 for the input "XC"', () => {
		const result = romanToInt("XC");
		assert.strictEqual(result, 90);
	});

	it('should return 400 for the input "CD"', () => {
		const result = romanToInt("CD");
		assert.strictEqual(result, 400);
	});

	it('should return 900 for the input "CM"', () => {
		const result = romanToInt("CM");
		assert.strictEqual(result, 900);
	});

	it('should return 3999 for the input "MMMCMXCIX"', () => {
		const result = romanToInt("MMMCMXCIX");
		assert.strictEqual(result, 3999);
	});

	it('should return 1 for the input "I"', () => {
		const result = romanToInt("I");
		assert.strictEqual(result, 1);
	});

	it('should return 4 for the input "IV"', () => {
		const result = romanToInt("IV");
		assert.strictEqual(result, 4);
	});

	it('should return 5 for the input "V"', () => {
		const result = romanToInt("V");
		assert.strictEqual(result, 5);
	});

	it('should return 100 for the input "C"', () => {
		const result = romanToInt("C");
		assert.strictEqual(result, 100);
	});

	it('should return 500 for the input "D"', () => {
		const result = romanToInt("D");
		assert.strictEqual(result, 500);
	});

	it('should return 1000 for the input "M"', () => {
		const result = romanToInt("M");
		assert.strictEqual(result, 1000);
	});
});
