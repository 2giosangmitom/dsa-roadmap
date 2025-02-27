/**
 * @param {TreeNode} p
 * @param {TreeNode} q
 * @return {boolean}
 */
function isSameTree(p, q) {
  if (!p && !q) {
    return true;
  }

  if (!p || !q) {
    return false;
  }

  return (
    p.val === q.val &&
    isSameTree(p.left, q.left) &&
    isSameTree(p.right, q.right)
  );
}

/**
 * @param {TreeNode} p
 * @param {TreeNode} q
 * @return {boolean}
 */
function isSameTree2(p, q) {
  const stack1 = [];
  const stack2 = [];

  let curr1 = p;
  let curr2 = q;

  while (curr1 || curr2 || stack1.length > 0 || stack2.length > 0) {
    while (curr1) {
      stack1.push(curr1);
      curr1 = curr1.left;
    }

    while (curr2) {
      stack2.push(curr2);
      curr2 = curr2.left;
    }

    // One of two nodes is null
    if (stack1.length !== stack2.length) {
      return false;
    }

    curr1 = stack1.pop();
    curr2 = stack2.pop();

    if (curr1.val !== curr2.val) {
      return false;
    }

    curr1 = curr1.right;
    curr2 = curr2.right;
  }

  return true;
}

export { isSameTree, isSameTree2 };
