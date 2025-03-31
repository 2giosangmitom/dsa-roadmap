/**
 * @param {number[]} nums
 * @param {number} k
 * @return {void} Do not return anything, modify nums in-place instead.
 */
function rotate(nums, k) {
	k %= nums.length;

	const reverse_array = (left, right) => {
		while (left < right) {
			const temp = nums[left];
			nums[left] = nums[right];
			nums[right] = temp;
			left++;
			right--;
		}
	};

	if (k !== 0) {
		reverse_array(0, nums.length - 1);
		reverse_array(0, k - 1);
		reverse_array(k, nums.length - 1);
	}
}

export { rotate };
