import { TreeNode } from "../lib/binary_tree.js";

/**
 * @param {TreeNode} root
 * @return {number[]}
 */
function inorderTraversal(root) {
  if (!root) return [];

  /** @type {number[]} */
  const res = [];

  /** @type {TreeNode[]} */
  const stack = [];

  let current = root;

  while (stack.length > 0 || current !== null) {
    while (current) {
      stack.push(current);
      current = current.left;
    }

    current = stack.pop();
    res.push(current.val);

    current = current.right;
  }

  return res;
}

export { inorderTraversal };
