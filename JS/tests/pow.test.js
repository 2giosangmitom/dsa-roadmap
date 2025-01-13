import assert from "node:assert";
import { describe, it } from "node:test";
import { myPow } from "../src/pow.js";

describe("pow", () => {
  it("should return 1024.00000 for x = 2.00000 and n = 10", () => {
    const result = myPow(2.0, 10);
    assert.strictEqual(result.toFixed(5), "1024.00000");
  });

  it("should return 9.26100 for x = 2.10000 and n = 3", () => {
    const result = myPow(2.1, 3);
    assert.strictEqual(result.toFixed(5), "9.26100");
  });

  it("should return 0.25000 for x = 2.00000 and n = -2", () => {
    const result = myPow(2.0, -2);
    assert.strictEqual(result.toFixed(5), "0.25000");
  });

  it("should return 16.00000 for x = -2.00000 and n = 4", () => {
    const result = myPow(-2.0, 4);
    assert.strictEqual(result.toFixed(5), "16.00000");
  });

  it("should return -8.00000 for x = -2.00000 and n = 3", () => {
    const result = myPow(-2.0, 3);
    assert.strictEqual(result.toFixed(5), "-8.00000");
  });

  it("should return 1.00000 for x = 1.00000 and n = 0", () => {
    const result = myPow(1.0, 0);
    assert.strictEqual(result.toFixed(5), "1.00000");
  });

  it("should handle very small fractional base for x = 0.99999 and n = 1000", () => {
    const result = myPow(0.99999, 1000);
    assert.strictEqual(result.toFixed(5), "0.99005");
  });

  it("should handle negative exponent for x = 1.50000 and n = -3", () => {
    const result = myPow(1.5, -3);
    assert.strictEqual(result.toFixed(5), "0.29630");
  });

  it("should handle large negative exponent for x = 2.00000 and n = -31", () => {
    const result = myPow(2.0, -31);
    assert.strictEqual(result.toFixed(5), "0.00000");
  });

  it("should return a small positive value for x = 0.99999 and n = -9999", () => {
    const result = myPow(0.99999, -9999);
    assert.strictEqual(result.toFixed(5), "1.10516");
  });

  it("should return a large positive value for x = 1.00001 and n = 9999", () => {
    const result = myPow(1.00001, 9999);
    assert.strictEqual(result.toFixed(5), "1.10516");
  });
});
