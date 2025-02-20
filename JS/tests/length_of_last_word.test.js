import { test, expect } from "vitest";
import { lengthOfLastWord } from "../src/length_of_last_word.js";

const testCases = [
  { input: "Hello World", expected: 5 },
  { input: "   ", expected: 0 },
  { input: "   Leading spaces   Test   ", expected: 4 },
  { input: "abc def ghi", expected: 3 },
  { input: "a", expected: 1 },
  { input: "Hello  ", expected: 5 },
  { input: "      ", expected: 0 },
  { input: "a b c d e f g h i j k l m n o p q r s t u v w x y z", expected: 1 },
  { input: "The quick brown fox jumps", expected: 5 },
  { input: "Hello  World", expected: 5 },
  { input: "   This is a test   ", expected: 4 },
];

testCases.forEach(({ input, expected }) => {
  test(`returns ${expected} for '${input}'`, () => {
    expect(lengthOfLastWord(input)).toBe(expected);
  });
});
