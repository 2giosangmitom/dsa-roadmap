/**
 * @param {number[]} nums
 * @param {number} k
 * @return {void} Do not return anything, modify nums in-place instead.
 */
function rotate(nums, k) {
  k %= nums.length;

  if (k != 0) {
    const rotated = new Array(nums.length);

    for (let i = 0; i < nums.length; i++) {
      rotated[i] = nums[(nums.length + i - k) % nums.length];
    }

    for (let i = 0; i < nums.length; i++) {
      nums[i] = rotated[i];
    }
  }
}

/**
 * @param {number[]} nums
 * @param {number} k
 * @return {void} Do not return anything, modify nums in-place instead.
 */
function rotate2(nums, k) {
  k %= nums.length;

  const reverse_array = (left, right) => {
    while (left < right) {
      let temp = nums[left];
      nums[left] = nums[right];
      nums[right] = temp;
      left++;
      right--;
    }
  };

  if (k != 0) {
    reverse_array(0, nums.length - 1);
    reverse_array(0, k - 1);
    reverse_array(k, nums.length - 1);
  }
}

export { rotate, rotate2 };
