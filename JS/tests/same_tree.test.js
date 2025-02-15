import assert from "node:assert";
import { describe, it } from "node:test";
import { TreeNode } from "../lib/binary_tree.js";
import { isSameTree, isSameTree2 } from "../src/same_tree.js";

function runTest(name, callback) {
  describe(name, { concurrency: true, timeout: 1000 }, () => {
    it("should return true for [1,2,3] [1,2,3]", () => {
      const t1 = TreeNode.of(1, 2, 3);
      const t2 = TreeNode.of(1, 2, 3);

      assert.strictEqual(callback(t1, t2), true);
    });

    it("should return false for [1,2] [1,null,2]", () => {
      const t1 = TreeNode.of(1, 2);
      const t2 = TreeNode.of(1, null, 2);

      assert.strictEqual(callback(t1, t2), false);
    });

    it("should return false for [1,2,1] [1,1,2]", () => {
      const t1 = TreeNode.of(1, 2, 1);
      const t2 = TreeNode.of(1, 1, 2);

      assert.strictEqual(callback(t1, t2), false);
    });

    it("should return true for empty trees", () => {
      const t1 = null;
      const t2 = null;

      assert.strictEqual(callback(t1, t2), true);
    });

    it("should return false for one empty tree and one non-empty tree", () => {
      const t1 = null;
      const t2 = TreeNode.of(1);

      assert.strictEqual(callback(t1, t2), false);
    });

    it("should return true for single-node trees with the same value", () => {
      const t1 = TreeNode.of(1);
      const t2 = TreeNode.of(1);

      assert.strictEqual(callback(t1, t2), true);
    });

    it("should return false for single-node trees with different values", () => {
      const t1 = TreeNode.of(1);
      const t2 = TreeNode.of(2);

      assert.strictEqual(callback(t1, t2), false);
    });

    it("should return false for trees with the same values but different structures", () => {
      const t1 = TreeNode.of(1, 2, null, 3);
      const t2 = TreeNode.of(1, null, 2, null, 3);

      assert.strictEqual(callback(t1, t2), false);
    });
  });
}

runTest("isSameTree", isSameTree);
runTest("isSameTree2", isSameTree2);
