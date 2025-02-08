import { maxArea, maxArea2 } from "../src/container_with_most_water.js";
import assert from "node:assert";
import { describe, it } from "node:test";

function runTests(name, callback) {
  describe(name, { concurrency: true, timeout: 1000 }, () => {
    it("should return 24 for input [2, 7, 8, 3, 7, 6]", () => {
      const height = [2, 7, 8, 3, 7, 6];
      const expected = 24;

      const actual = callback(height);

      assert.strictEqual(actual, expected);
    });

    it("should return 49 for input [1,8,6,2,5,4,8,3,7]", () => {
      const height = [1, 8, 6, 2, 5, 4, 8, 3, 7];
      const expected = 49;

      const actual = callback(height);

      assert.strictEqual(actual, expected);
    });

    it("should return 1 for input [1, 1]", () => {
      const height = [1, 1];
      const expected = 1;

      const actual = callback(height);

      assert.strictEqual(actual, expected);
    });

    it("should return 0 for input [1]", () => {
      const height = [1];
      const expected = 0;

      const actual = callback(height);

      assert.strictEqual(actual, expected);
    });

    it("should return 0 for input [0, 1, 0]", () => {
      const height = [0, 1, 0];
      const expected = 0;

      const actual = callback(height);

      assert.strictEqual(actual, expected);
    });
  });
}

runTests("maxArea", maxArea);
runTests("maxArea2", maxArea2);
