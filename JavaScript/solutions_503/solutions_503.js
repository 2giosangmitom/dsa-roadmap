/**
 * @param {number[]} nums
 * @return {number[]}
 */
function nextGreaterElements(nums) {
	// The monotonic stack to stores all next greater elements's index
	const candidates = [];
	const result = new Array(nums.length);

	// Loop through the array twice to handle the circular nature
	for (let i = 2 * nums.length - 1; i >= 0; i--) {
		const currentIndex = i % nums.length;

		// Pop elements from the stack while the element at the top of the stack
		// not greater than current element
		while (
			candidates.length !== 0 &&
			nums[candidates[candidates.length - 1]] <= nums[currentIndex]
		) {
			candidates.pop();
		}

		// The stack becomes empty if the no candidates is greater than current element
		// so assign -1 to the current result
		if (candidates.length === 0) {
			result[currentIndex] = -1;
		} else {
			// The top element of the stack is the next greater element of current element
			result[currentIndex] = nums[candidates[candidates.length - 1]];
		}

		// Push the current index to the stack
		candidates.push(currentIndex);
	}

	return result;
}

export { nextGreaterElements };
