/**
 * @param {number[]} nums
 * @return {number[]}
 */
function nextGreaterElements(nums) {
	const candidates = [];
	const result = new Array(nums.length);

	const checkCandidate = (index) => {
		while (
			candidates.length !== 0 &&
			nums[candidates[candidates.length - 1]] <= nums[index]
		) {
			candidates.pop();
		}

		if (candidates.length === 0) {
			result[index] = -1;
		} else {
			result[index] = nums[candidates[candidates.length - 1]];
		}
	};

	for (let i = 2 * nums.length - 1; i >= 0; i--) {
		checkCandidate(i % nums.length);
		candidates.push(i % nums.length);
	}

	return result;
}

export { nextGreaterElements };
