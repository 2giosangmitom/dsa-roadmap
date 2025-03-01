import { test, expect } from "vitest";
import { TreeNode } from "../lib/binary_tree.js";
import { inorderTraversal } from "../src/binary_tree_inorder_traversal.js";

const testCases = [
  {
    root: null,
    expected: [],
  },
  {
    root: TreeNode.of(1),
    expected: [1],
  },
  {
    root: TreeNode.of(1, 2, 3),
    expected: [2, 1, 3],
  },
  {
    root: TreeNode.of(1, 2, 3, 4, 5),
    expected: [4, 2, 5, 1, 3],
  },
  {
    root: TreeNode.of(4, 3, null, 2, null, 1),
    expected: [1, 2, 3, 4],
  },
  {
    root: TreeNode.of(1, null, 2, null, 3, null, 4),
    expected: [1, 2, 3, 4],
  },
  {
    root: TreeNode.of(1, 2, 3, null, 4, 5),
    expected: [2, 4, 1, 5, 3],
  },
];

testCases.forEach(({ root, expected }, index) => {
  test(`test case ${index + 1}`, () => {
    const result = inorderTraversal(root);
    expect(result).toEqual(expected);
  });
});
