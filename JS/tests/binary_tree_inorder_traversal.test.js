import { test, expect } from "vitest";
import { TreeNode } from "../lib/binary_tree.js";
import { inorderTraversal } from "../src/binary_tree_inorder_traversal.js";

test("should return an empty array for an empty tree", () => {
  const root = null;

  const result = inorderTraversal(root);

  expect(result).toEqual([]);
});

test("should return the correct inorder traversal for a single-node tree", () => {
  const root = TreeNode.of(1);

  const result = inorderTraversal(root);

  expect(result).toEqual([1]);
});

test("should return the correct inorder traversal for a tree with two levels", () => {
  const root = TreeNode.of(1, 2, 3);

  const result = inorderTraversal(root);

  expect(result).toEqual([2, 1, 3]);
});

test("should return the correct inorder traversal for a tree with multiple levels", () => {
  const root = TreeNode.of(1, 2, 3, 4, 5);

  const result = inorderTraversal(root);

  expect(result).toEqual([4, 2, 5, 1, 3]);
});

test("should handle a skewed tree (all left children)", () => {
  const root = TreeNode.of(4, 3, null, 2, null, 1);

  const result = inorderTraversal(root);

  expect(result).toEqual([1, 2, 3, 4]);
});

test("should handle a skewed tree (all right children)", () => {
  const root = TreeNode.of(1, null, 2, null, 3, null, 4);

  const result = inorderTraversal(root);

  expect(result).toEqual([1, 2, 3, 4]);
});

test("should handle a complex unbalanced tree", () => {
  const root = TreeNode.of(1, 2, 3, null, 4, 5);

  const result = inorderTraversal(root);

  expect(result).toEqual([2, 4, 1, 5, 3]);
});
