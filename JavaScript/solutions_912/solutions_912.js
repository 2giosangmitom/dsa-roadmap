// Choose an algorithm and test :)

/**
 * @param {number[]} nums
 * @param {number} left
 * @param {number} right
 */
function quickSort(nums, left, right) {
	if (left >= right) return;

	const pivotValue = nums[right];
	let pivotIndex = left;

	for (let i = left; i <= right; i++) {
		if (nums[i] <= pivotValue) {
			const temp = nums[i];
			nums[i] = nums[pivotIndex];
			nums[pivotIndex] = temp;
			if (i !== right) pivotIndex++;
		}
	}

	quickSort(nums, left, pivotIndex - 1);
	quickSort(nums, pivotIndex + 1, right);
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

		// Merge two halfs
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
}

/**
 * @param {number[]} nums
 * @param {number} n
 * @param {number} index
 */
function heapify(nums, n, index) {
	const leftChild = index * 2 + 1;
	const rightChild = index * 2 + 2;

	let max = index;

	if (leftChild < n && nums[leftChild] > nums[max]) {
		max = leftChild;
	}

	if (rightChild < n && nums[rightChild] > nums[max]) {
		max = rightChild;
	}

	if (index !== max) {
		const tmp = nums[index];
		nums[index] = nums[max];
		nums[max] = tmp;
		heapify(nums, n, max);
	}
}

/**
 * @param {number[]} nums
 */
function heapSort(nums) {
	const n = nums.length;

	for (let i = Math.trunc(nums.length / 2) - 1; i >= 0; i--) {
		heapify(nums, n, i);
	}

	for (let i = nums.length - 1; i > 0; i--) {
		const tmp = nums[0];
		nums[0] = nums[i];
		nums[i] = tmp;
		heapify(nums, i, 0);
	}
}

export { quickSort, mergeSort, heapSort };
