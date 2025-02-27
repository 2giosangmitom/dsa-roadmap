/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
function moveZeroes (nums) {
  let slow = 0
  let fast = 0

  while (fast < nums.length) {
    if (nums[fast] !== 0) {
      const temp = nums[fast]
      nums[fast] = nums[slow]
      nums[slow] = temp
      slow++
    }
    fast++
  }
}

export { moveZeroes }
