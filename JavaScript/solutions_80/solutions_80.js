/**
 * @param {number[]} nums
 * @return {number}
 */
function removeDuplicates(nums) {
	let j = 0;
	let count = 0;

	for (let i = 0; i < nums.length; i++) {
		if (i === 0 || (i > 0 && nums[i - 1] === nums[i])) {
			count++;
		} else {
			count = 1;
		}

		if (count <= 2) {
			nums[j++] = nums[i];
		}
	}

	return j;
}

export { removeDuplicates };
