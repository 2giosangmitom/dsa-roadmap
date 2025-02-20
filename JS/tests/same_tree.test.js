import { describe, it, expect } from "vitest";
import { TreeNode } from "../lib/binary_tree.js";
import { isSameTree, isSameTree2 } from "../src/same_tree.js";

const testCases = [
  {
    name: "should return true for [1,2,3] [1,2,3]",
    t1: TreeNode.of(1, 2, 3),
    t2: TreeNode.of(1, 2, 3),
    expected: true,
  },
  {
    name: "should return false for [1,2] [1,null,2]",
    t1: TreeNode.of(1, 2),
    t2: TreeNode.of(1, null, 2),
    expected: false,
  },
  {
    name: "should return false for [1,2,1] [1,1,2]",
    t1: TreeNode.of(1, 2, 1),
    t2: TreeNode.of(1, 1, 2),
    expected: false,
  },
  {
    name: "should return true for empty trees",
    t1: null,
    t2: null,
    expected: true,
  },
  {
    name: "should return false for one empty tree and one non-empty tree",
    t1: null,
    t2: TreeNode.of(1),
    expected: false,
  },
  {
    name: "should return true for single-node trees with the same value",
    t1: TreeNode.of(1),
    t2: TreeNode.of(1),
    expected: true,
  },
  {
    name: "should return false for single-node trees with different values",
    t1: TreeNode.of(1),
    t2: TreeNode.of(2),
    expected: false,
  },
  {
    name: "should return false for trees with the same values but different structures",
    t1: TreeNode.of(1, 2, null, 3),
    t2: TreeNode.of(1, null, 2, null, 3),
    expected: false,
  },
];

describe("isSameTree", () => {
  it.each(testCases)("$name", ({ t1, t2, expected }) => {
    expect(isSameTree(t1, t2)).toEqual(expected);
  });
});
