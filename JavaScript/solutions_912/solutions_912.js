/**
 * @param {number[]} nums
 * @return {number[]}
 */
function sortArray(nums) {
	quickSort(nums, 0, nums.length - 1);
	return nums;
}

/**
 * @param {number[]} nums
 * @param {number} left
 * @param {number} right
 */
function quickSort(nums, left, right) {
	if (left >= right) return;

	const pivotValue = nums[right];
	let pivotIndex = left;

	for (let i = left; i < right; i++) {
		if (nums[i] <= pivotValue) {
			[nums[i], nums[pivotIndex]] = [nums[pivotIndex], nums[i]];
			pivotIndex++;
		}
	}

	[nums[pivotIndex], nums[right]] = [nums[right], nums[pivotIndex]];

	quickSort(nums, left, pivotIndex - 1);
	quickSort(nums, pivotIndex + 1, right);
}

/**
 * @param {number[]} nums
 * @param {number} left
 * @param {number} mid
 * @param {number} right
 */
function merge(nums, left, mid, right) {
	const arr_left = nums.slice(left, mid + 1);
	const arr_right = nums.slice(mid + 1, right + 1);

	let i = 0;
	let j = 0;
	let k = left;

	while (i < arr_left.length && j < arr_right.length) {
		if (arr_left[i] <= arr_right[j]) {
			nums[k] = arr_left[i];
			i++;
		} else {
			nums[k] = arr_right[j];
			j++;
		}
		k++;
	}

	while (i < arr_left.length) {
		nums[k++] = arr_left[i++];
	}

	while (j < arr_right.length) {
		nums[k++] = arr_right[j++];
	}
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

export { sortArray, mergeSort };
