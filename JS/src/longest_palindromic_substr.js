/**
 * @param {string} s
 * @returns {string}
 */
function longestPalindrome(s) {
	if (s.length === 1) return s[0];

	let start = 0;
	let maxLen = 1;

	for (let i = 0; i < s.length; ++i) {
		const lenOdd = expandCenter(s, i, i);
		const lenEven = expandCenter(s, i, i + 1);

		const len = Math.max(lenOdd, lenEven);
		if (len > maxLen) {
			maxLen = len;
			start = i - Math.trunc((len - 1) / 2);
		}
	}

	return s.substring(start, start + maxLen);
}

/**
 * @param {string} s
 * @param {number} l
 * @param {number} r
 * @returns {number}
 */
function expandCenter(s, l, r) {
	while (l >= 0 && r < s.length && s[l] === s[r]) {
		l--;
		r++;
	}
	return r - l - 1;
}

export { longestPalindrome };
