/**
 * @param {number[]} nums
 * @return {number}
 */
function removeDuplicates (nums) {
  let k = 0

  let count = 0
  let prev = nums[0]
  for (let i = 0; i < nums.length; i++) {
    if (prev === nums[i]) {
      count++
    } else {
      count = 1
      prev = nums[i]
    }

    if (count <= 2) {
      nums[k++] = nums[i]
    }
  }

  return k
}

export { removeDuplicates }
