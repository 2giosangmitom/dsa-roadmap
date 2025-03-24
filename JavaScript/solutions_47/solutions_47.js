/**
 * @param {number[]} nums
 * @return {number[][]}
 */
function permuteUnique(nums) {
	if (nums.length === 1) return [nums];

	const set = {};

	const head = nums[0];
	const tail = nums.slice(1);

	const result = [];

	const tailPerms = permuteUnique(tail);
	for (const perm of tailPerms) {
		for (let i = 0; i <= perm.length; i++) {
			const newPerm = perm.slice(0, i).concat(head).concat(perm.slice(i));

			if (!set[newPerm]) {
				result.push(newPerm);
				set[newPerm] = true;
			}
		}
	}

	return result;
}

export { permuteUnique };
