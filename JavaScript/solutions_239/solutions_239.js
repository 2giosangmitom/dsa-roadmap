/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number[]}
 */
function maxSlidingWindow(nums, k) {
	/** @type {number[][]} */
	const deque = [];
	const result = [];
	let left = 0;

	for (let right = 0; right < nums.length; right++) {
		while (deque.length !== 0 && deque[deque.length - 1][0] <= nums[right]) {
			deque.pop();
		}

		deque.push([nums[right], right]);

		if (right - left + 1 === k) {
			if (deque.length !== 0 && deque[0][1] < left) {
				deque.shift();
			}

			result.push(deque[0][0]);
			left++;
		}
	}

	return result;
}

export { maxSlidingWindow };
