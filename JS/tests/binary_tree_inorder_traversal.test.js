import assert from "node:assert";
import { describe, it } from "node:test";
import { TreeNode } from "../lib/binary_tree.js";
import { inorderTraversal } from "../src/binary_tree_inorder_traversal.js";

describe("inorderTraversal", { concurrency: true, timeout: 1000 }, () => {
  it("should return an empty array for an empty tree", () => {
    assert.deepStrictEqual(inorderTraversal(null), []);
  });

  it("should return the correct inorder traversal for a single-node tree", () => {
    const root = TreeNode.of(1);
    assert.deepStrictEqual(inorderTraversal(root), [1]);
  });

  it("should return the correct inorder traversal for a tree with two levels", () => {
    const root = TreeNode.of(1, 2, 3);
    assert.deepStrictEqual(inorderTraversal(root), [2, 1, 3]);
  });

  it("should return the correct inorder traversal for a tree with multiple levels", () => {
    const root = TreeNode.of(1, 2, 3, 4, 5);
    assert.deepStrictEqual(inorderTraversal(root), [4, 2, 5, 1, 3]);
  });

  it("should handle a skewed tree (all left children)", () => {
    const root = TreeNode.of(4, 3, null, 2, null, 1);
    assert.deepStrictEqual(inorderTraversal(root), [1, 2, 3, 4]);
  });

  it("should handle a skewed tree (all right children)", () => {
    const root = TreeNode.of(1, null, 2, null, 3, null, 4);
    assert.deepStrictEqual(inorderTraversal(root), [1, 2, 3, 4]);
  });

  it("should handle a complex unbalanced tree", () => {
    const root = TreeNode.of(1, 2, 3, null, 4, 5);
    assert.deepStrictEqual(inorderTraversal(root), [2, 4, 1, 5, 3]);
  });
});
