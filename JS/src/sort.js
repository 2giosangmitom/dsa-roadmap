/**
 * @param {number[]} nums
 * @return {number[]}
 */
function sortArray(nums) {
	const res = Array.from(nums);

	mergeSort(res, 0, res.length - 1);

	return res;
}

/**
 * @param {number[]} nums
 * @param {number} left
 * @param {number} right
 */
function mergeSort(nums, left, right) {
	if (left < right) {
		const mid = Math.trunc((left + right) / 2);
		mergeSort(nums, left, mid);
		mergeSort(nums, mid + 1, right);
		merge(nums, left, mid, right);
	}
}

/**
 * @param {number[]} nums
 * @param {number} left
 * @param {number} mid
 * @param {number} right
 */
function merge(nums, left, mid, right) {
	const l = nums.slice(left, mid + 1);
	const r = nums.slice(mid + 1, right + 1);

	let i = 0;
	let j = 0;
	let k = left;

	while (i < l.length && j < r.length) {
		if (l[i] <= r[j]) {
			nums[k] = l[i];
			i++;
		} else {
			nums[k] = r[j];
			j++;
		}
		k++;
	}

	while (i < l.length) {
		nums[k++] = l[i++];
	}

	while (j < r.length) {
		nums[k++] = r[j++];
	}
}

export { sortArray };
