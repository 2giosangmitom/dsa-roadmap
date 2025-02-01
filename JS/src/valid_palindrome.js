/**
 * @param {string} s
 * @return {boolean}
 */
function isPalindrome(s) {
	s = s.replace(/[^a-z]|\s/gi, "").toLowerCase();

	for (let i = 0; i < s.length; i++) {
		if (s[i] !== s[s.length - i - 1]) {
			return false;
		}
	}

	return true;
}

export { isPalindrome };
