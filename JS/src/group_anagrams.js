/**
 * @param {string[]} strs
 * @return {string[][]}
 */
function groupAnagrams(strs) {
	const map = {};

	for (const s of strs) {
		const key = s.split("").sort().join("");
		if (key in map) {
			map[key].push(s);
		} else {
			const newGroup = [s];
			map[key] = newGroup;
		}
	}

	/** @type {string[][]} */
	const result = [];
	for (const v of Object.values(map)) {
		result.push(v);
	}

	return result;
}

export { groupAnagrams };
