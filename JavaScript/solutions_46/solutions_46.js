/**
 * @param {number[]} nums
 * @return {number[][]}
 */
function permute(nums) {
	if (nums.length === 1) return [nums];

	const head = nums[0];
	const tail = nums.slice(1);

	const result = [];

	const tailPerms = permute(tail);
	for (const perm of tailPerms) {
		for (let i = 0; i <= perm.length; i++) {
			const newPerm = perm.slice(0, i).concat(head).concat(perm.slice(i));
			result.push(newPerm);
		}
	}

	return result;
}

export { permute };
