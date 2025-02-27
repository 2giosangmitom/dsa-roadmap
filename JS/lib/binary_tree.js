class TreeNode {
  /**
   * @param {number} val
   * @param {TreeNode} left
   * @param {TreeNode} right
   */
  constructor (val, left, right) {
    this.val = val || 0
    this.left = left || null
    this.right = right || null
  }

  /**
   * @param {number[] | null[]} nums
   * @returns {TreeNode}
   */
  static of (...nums) {
    if (nums.length === 0) return null

    const root = new TreeNode(nums[0])
    const queue = [root]
    let i = 1

    while (i < nums.length) {
      const current = queue.pop()

      if (nums[i] !== null) {
        current.left = new TreeNode(nums[i])
        queue.unshift(current.left)
      }

      i++
      if (i < nums.length && nums[i] !== null) {
        current.right = new TreeNode(nums[i])
        queue.unshift(current.right)
      }
      i++
    }

    return root
  }
}

export { TreeNode }
