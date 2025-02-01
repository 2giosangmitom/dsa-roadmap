/**
 * @param {number[]} nums
 * @return {number}
 */
function maxSubArray(nums) {
	let result = nums[0];
	let temp = nums[0];

	for (let i = 1; i < nums.length; i++) {
		temp += nums[i];
		if (temp < nums[i]) {
			temp = nums[i];
		}
		result = Math.max(result, temp);
	}

	return result;
}

/**
 * @param {number[]} nums
 * @return {number}
 */
function maxSubArray2(nums) {
	return findMax(nums, 0, nums.length - 1);
}

/**
 * @param {number[]} nums
 * @param {number} left
 * @param {number} right
 * @returns {number}
 */
function findMax(nums, left, right) {
	if (left === right) return nums[left];

	const mid = Math.trunc((left + right) / 2);

	const leftSum = findMax(nums, left, mid);
	const rightSum = findMax(nums, mid + 1, right);
	const crossSum = (() => {
		let temp = nums[mid];
		let leftMaxSum = nums[mid];
		for (let i = mid - 1; i >= left; i--) {
			temp += nums[i];
			leftMaxSum = Math.max(leftMaxSum, temp);
		}

		temp = nums[mid + 1];
		let rightMaxSum = nums[mid + 1];
		for (let i = mid + 2; i <= right; i++) {
			temp += nums[i];
			rightMaxSum = Math.max(rightMaxSum, temp);
		}

		return leftMaxSum + rightMaxSum;
	})();

	return Math.max(leftSum, rightSum, crossSum);
}

export { maxSubArray, maxSubArray2 };
