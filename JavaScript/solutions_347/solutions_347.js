/**
 * @param {Object} freq
 * @param {number[]} keys
 * @param {number} n
 * @param {number} index
 */
function heapify(freq, keys, n, index) {
	let max = index;
	const leftChild = 2 * index + 1;
	const rightChild = 2 * index + 2;

	if (leftChild < n && freq[keys[leftChild]] > freq[keys[max]]) {
		max = leftChild;
	}

	if (rightChild < n && freq[keys[rightChild]] > freq[keys[max]]) {
		max = rightChild;
	}

	if (index !== max) {
		[keys[index], keys[max]] = [keys[max], keys[index]];
		heapify(freq, keys, n, max);
	}
}

/**
 * @param {number[]} nums
 * @param {number} k
 * @return {number[]}
 */
function topKFrequent(nums, k) {
	const freq = {};

	for (const num of nums) {
		freq[num] = (freq[num] || 0) + 1;
	}

	const result = [];
	const keys = Object.keys(freq).map(Number);

	// Build max heap
	for (let i = Math.trunc(keys.length / 2) - 1; i >= 0; i--) {
		heapify(freq, keys, keys.length, i);
	}

	// Extract top K elements
	for (let i = 0; i < k; i++) {
		result.push(keys[0]);
		[keys[0], keys[keys.length - 1]] = [keys[keys.length - 1], keys[0]];
		keys.pop();
		heapify(freq, keys, keys.length, 0);
	}

	return result;
}

export { topKFrequent };
