/**
 * @param {number[]} nums
 * @return {number[][]}
 */
function subsets(nums) {
	if (nums.length === 0) {
		return [nums];
	}

	/** @type {number[]} */
	const result = [];
	const head = nums[0];
	const tail = nums.slice(1);
	const tailSubsets = subsets(tail);

	for (const tailSub of tailSubsets) {
		result.push([head, ...tailSub]);
		result.push(tailSub);
	}

	return result;
}

export { subsets };
