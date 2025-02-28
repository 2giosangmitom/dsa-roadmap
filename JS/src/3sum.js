/**
 * @param {number} left
 * @param {number[]} nums
 * @param {number} target
 * @return {number[][]}
 */
function twoSum(left, nums, target) {
  const result = [];
  let right = nums.length - 1;

  while (left < right) {
    const sum = nums[left] + nums[right];

    if (sum === target) {
      result.push([nums[left], nums[right]]);
      left++;
      while (left < right && nums[left] === nums[left - 1]) {
        left++;
      }
    } else if (sum < target) {
      left++;
    } else {
      right--;
    }
  }

  return result;
}

/**
 * @param {number[]} nums
 * @return {number[][]}
 */
function threeSum(nums) {
  nums = nums.sort((a, b) => a - b);

  const res = [];

  for (let i = 0; i < nums.length; i++) {
    if (nums[i] > 0) {
      break;
    }
    if (i > 0 && nums[i] === nums[i - 1]) {
      continue;
    }

    const pairs = twoSum(i + 1, nums, -nums[i]);
    for (const pair of pairs) {
      res.push([nums[i], ...pair]);
    }
  }

  return res;
}

export { threeSum };
