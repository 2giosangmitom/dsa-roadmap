/**
 * @param {number[]} nums
 * @return {void} Do not return anything, modify nums in-place instead.
 */
function nextPermutation(nums) {
  let left = nums.length - 2;

  while (left >= 0 && nums[left] >= nums[left + 1]) {
    left--;
  }

  if (left < 0) {
    for (let i = 0; i < Math.trunc(nums.length / 2); i++) {
      let temp = nums[nums.length - 1 - i];
      nums[nums.length - 1 - i] = nums[i];
      nums[i] = temp;
    }
  } else {
    let right = nums.length - 1;
    while (nums[right] <= nums[left]) {
      right--;
    }

    let temp = nums[right];
    nums[right] = nums[left];
    nums[left] = temp;

    const rev = nums.splice(left + 1, nums.length - left - 1);
    nums.push(...rev.reverse());
  }
}

export { nextPermutation };
