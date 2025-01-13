import { describe, it } from "node:test";
import assert from "node:assert";
import { isValid } from "../src/valid_parentheses.js";

describe("isValid", () => {
  it('should return true for the input "()"', () => {
    const s = "()";
    const result = isValid(s);
    assert.strictEqual(result, true);
  });

  it('should return true for the input "()[]{}"', () => {
    const s = "()[]{}";
    const result = isValid(s);
    assert.strictEqual(result, true);
  });

  it('should return false for the input "(]"', () => {
    const s = "(]";
    const result = isValid(s);
    assert.strictEqual(result, false);
  });

  it('should return true for the input "([])"', () => {
    const s = "([])";
    const result = isValid(s);
    assert.strictEqual(result, true);
  });

  it('should return false for the input "([)]"', () => {
    const s = "([)]";
    const result = isValid(s);
    assert.strictEqual(result, false);
  });

  it('should return true for the input "{[]}"', () => {
    const s = "{[]}";
    const result = isValid(s);
    assert.strictEqual(result, true);
  });

  it('should return false for the input "{[}"', () => {
    const s = "{[}";
    const result = isValid(s);
    assert.strictEqual(result, false);
  });

  it("should return true for an empty string", () => {
    const s = "";
    const result = isValid(s);
    assert.strictEqual(result, true);
  });

  it('should return false for an unbalanced set of parentheses "((((((((((((((((((((((((((("', () => {
    const s = "(((((((((((((((((((((((((((";
    const result = isValid(s);
    assert.strictEqual(result, false);
  });

  it('should return true for "(((((())))))"', () => {
    const s = "(((((())))))";
    const result = isValid(s);
    assert.strictEqual(result, true);
  });
});
