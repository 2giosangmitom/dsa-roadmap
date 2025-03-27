/**
 * @param {string} s
 * @return {number}
 */
function romanToInt(s) {
	const pairs = {
		I: 1,
		V: 5,
		X: 10,
		L: 50,
		C: 100,
		D: 500,
		M: 1000,
	};

	let result = 0;

	for (let i = 0; i < s.length; i++) {
		if (i + 1 < s.length && pairs[s[i]] < pairs[s[i + 1]]) {
			result -= pairs[s[i]];
		} else {
			result += pairs[s[i]];
		}
	}

	return result;
}

export { romanToInt };
