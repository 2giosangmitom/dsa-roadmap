/**
 * @param {number[]} nums
 * @return {number}
 */
function longestConsecutive(nums) {
	const numSet = new Set(nums);
	let longest = 0;

	for (const num of numSet) {
		if (!numSet.has(num - 1)) {
			let currentStreak = 1;

			let k = num + 1;
			while (numSet.has(k)) {
				currentStreak++;
				k++;
			}

			longest = Math.max(currentStreak, longest);
		}
	}

	return longest;
}

export { longestConsecutive };
