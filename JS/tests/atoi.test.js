import assert from "node:assert";
import { describe, it } from "node:test";
import { myAtoi } from "../src/atoi.js";

describe("myAtoi", { concurrency: true, timeout: 1000 }, () => {
  it('should return 42 for the input "42"', () => {
    const result = myAtoi("42");
    assert.strictEqual(result, 42);
  });

  it('should return -42 for the input "   -042"', () => {
    const result = myAtoi("   -042");
    assert.strictEqual(result, -42);
  });

  it('should return 1337 for the input "1337c0d3"', () => {
    const result = myAtoi("1337c0d3");
    assert.strictEqual(result, 1337);
  });

  it('should return 0 for the input "0-1"', () => {
    const result = myAtoi("0-1");
    assert.strictEqual(result, 0);
  });

  it('should return 0 for the input "words and 987"', () => {
    const result = myAtoi("words and 987");
    assert.strictEqual(result, 0);
  });

  it('should return -2147483648 for the input "-91283472332" (out of bounds)', () => {
    const result = myAtoi("-91283472332");
    assert.strictEqual(result, -2147483648);
  });

  it('should return 2147483647 for the input "91283472332" (out of bounds)', () => {
    const result = myAtoi("91283472332");
    assert.strictEqual(result, 2147483647);
  });

  it("should return 0 for an empty string", () => {
    const result = myAtoi("");
    assert.strictEqual(result, 0);
  });

  it('should return 1 for the input "+1"', () => {
    const result = myAtoi("+1");
    assert.strictEqual(result, 1);
  });

  it('should return -1 for the input "-1"', () => {
    const result = myAtoi("-1");
    assert.strictEqual(result, -1);
  });

  it('should return 0 for the input "."', () => {
    const result = myAtoi(".");
    assert.strictEqual(result, 0);
  });

  it('should return 0 for the input "+-2"', () => {
    const result = myAtoi("+-2");
    assert.strictEqual(result, 0);
  });

  it('should return 0 for the input "   "', () => {
    const result = myAtoi("   ");
    assert.strictEqual(result, 0);
  });

  it('should return 2147483647 for the input "2147483648" (boundary case)', () => {
    const result = myAtoi("2147483648");
    assert.strictEqual(result, 2147483647);
  });

  it('should return -2147483648 for the input "-2147483649" (boundary case)', () => {
    const result = myAtoi("-2147483649");
    assert.strictEqual(result, -2147483648);
  });

  it('should return 4193 for the input "4193 with words"', () => {
    const result = myAtoi("4193 with words");
    assert.strictEqual(result, 4193);
  });

  it('should return 0 for the input "with words 4193"', () => {
    const result = myAtoi("with words 4193");
    assert.strictEqual(result, 0);
  });

  it('should return -5 for the input "   -5x42"', () => {
    const result = myAtoi("   -5x42");
    assert.strictEqual(result, -5);
  });

  it('should return 123 for the input "   00000000000123"', () => {
    const result = myAtoi("   00000000000123");
    assert.strictEqual(result, 123);
  });
});
