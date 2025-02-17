import assert from "node:assert";
import { describe, it } from "node:test";
import { TreeNode } from "../lib/binary_tree.js";

describe("TreeNode", { concurrency: true, timeout: 1000 }, () => {
  it("should create correct Tree with [0, null, 1, 2]", () => {
    const tree = TreeNode.of(0, null, 1, 2);
    const expected = new TreeNode(0, null, new TreeNode(1, new TreeNode(2)));

    assert.deepStrictEqual(tree, expected);
  });

  it("should create correct Tree with [1, 2, 3, null, null, 4, 5]", () => {
    const tree = TreeNode.of(1, 2, 3, null, null, 4, 5);
    const expected = new TreeNode(
      1,
      new TreeNode(2),
      new TreeNode(3, new TreeNode(4), new TreeNode(5)),
    );

    assert.deepStrictEqual(tree, expected);
  });

  it("should create correct Tree with [1, null, 2, 3]", () => {
    const tree = TreeNode.of(1, null, 2, 3);
    const expected = new TreeNode(1, null, new TreeNode(2, new TreeNode(3)));

    assert.deepStrictEqual(tree, expected);
  });

  it("should create correct Tree with [1, 2, null, 3, null, 4, null]", () => {
    const tree = TreeNode.of(1, 2, null, 3, null, 4, null);
    const expected = new TreeNode(
      1,
      new TreeNode(2, new TreeNode(3, new TreeNode(4))),
    );

    assert.deepStrictEqual(tree, expected);
  });

  it("should create correct Tree with [1]", () => {
    const tree = TreeNode.of(1);
    const expected = new TreeNode(1);

    assert.deepStrictEqual(tree, expected);
  });

  it("should return null for an empty array", () => {
    const tree = TreeNode.of();
    const expected = null;

    assert.deepStrictEqual(tree, expected);
  });
});
