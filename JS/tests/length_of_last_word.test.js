import assert from "node:assert";
import { describe, it } from "node:test";
import { lengthOfLastWord } from "../src/length_of_last_word.js";

describe("lengthOfLastWord", { concurrency: true, timeout: 1000 }, () => {
  it("should return 5 for input 'Hello World'", () => {
    const s = "Hello World";
    const expected = 5;

    const actual = lengthOfLastWord(s);

    assert.strictEqual(actual, expected);
  });

  it("should return 0 for input ' ' (string with only spaces)", () => {
    const s = "   ";
    const expected = 0;

    const actual = lengthOfLastWord(s);

    assert.strictEqual(actual, expected);
  });

  it("should return 4 for input '   Leading spaces   Test   '", () => {
    const s = "   Leading spaces   Test   ";
    const expected = 4;

    const actual = lengthOfLastWord(s);

    assert.strictEqual(actual, expected);
  });

  it("should return 3 for input 'abc def ghi'", () => {
    const s = "abc def ghi";
    const expected = 3;

    const actual = lengthOfLastWord(s);

    assert.strictEqual(actual, expected);
  });

  it("should return 1 for input 'a'", () => {
    const s = "a";
    const expected = 1;

    const actual = lengthOfLastWord(s);

    assert.strictEqual(actual, expected);
  });

  it("should return 5 for input 'Hello  ' (trailing spaces)", () => {
    const s = "Hello  ";
    const expected = 5;

    const actual = lengthOfLastWord(s);

    assert.strictEqual(actual, expected);
  });

  it("should return 0 for input '   ' (multiple spaces)", () => {
    const s = "      ";
    const expected = 0;

    const actual = lengthOfLastWord(s);

    assert.strictEqual(actual, expected);
  });

  it("should return 1 for input 'a b c d e f g h i j k l m n o p q r s t u v w x y z'", () => {
    const s = "a b c d e f g h i j k l m n o p q r s t u v w x y z";
    const expected = 1;

    const actual = lengthOfLastWord(s);

    assert.strictEqual(actual, expected);
  });

  it("should return 6 for input 'The quick brown fox jumps'", () => {
    const s = "The quick brown fox jumps";
    const expected = 5;

    const actual = lengthOfLastWord(s);

    assert.strictEqual(actual, expected);
  });

  it("should return 2 for input 'Hello  World'", () => {
    const s = "Hello  World";
    const expected = 5;

    const actual = lengthOfLastWord(s);

    assert.strictEqual(actual, expected);
  });

  it("should return 4 for input '   This is a test   '", () => {
    const s = "   This is a test   ";
    const expected = 4;

    const actual = lengthOfLastWord(s);

    assert.strictEqual(actual, expected);
  });
});
