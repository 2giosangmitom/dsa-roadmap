import assert from "node:assert";
import { describe, it } from "node:test";
import { multiply } from "../src/multiply_strings.js";

describe("multiply strings", { concurrency: true, timeout: 1000 }, () => {
  it("should return '6' for input '2' and '3'", () => {
    const result = multiply("2", "3");
    assert.strictEqual(result, "6");
  });

  it("should return '56088' for input '123' and '456'", () => {
    const result = multiply("123", "456");
    assert.strictEqual(result, "56088");
  });

  it("should return '0' for input '0' and '12345'", () => {
    const result = multiply("0", "12345");
    assert.strictEqual(result, "0");
  });

  it("should return '0' for input '12345' and '0'", () => {
    const result = multiply("12345", "0");
    assert.strictEqual(result, "0");
  });

  it("should return '1' for input '1' and '1'", () => {
    const result = multiply("1", "1");
    assert.strictEqual(result, "1");
  });

  it("should return '99980001' for input '9999' and '9999'", () => {
    const result = multiply("9999", "9999");
    assert.strictEqual(result, "99980001");
  });

  it("should return '987654321987654321' for input '987654321' and '1000000001'", () => {
    const result = multiply("987654321", "1000000001");
    assert.strictEqual(result, "987654321987654321");
  });

  it("should return '100000000000000000000' for input '10000000000' and '10000000000'", () => {
    const result = multiply("10000000000", "10000000000");
    assert.strictEqual(result, "100000000000000000000");
  });
});
