/**
 * @param {number} x
 * @param {number} n
 * @returns {number}
 */
function myPow(x, n) {
	if (x === 0) return 0;
	if (n === 0) return 1;

	const pow = Math.abs(n);

	let ans = myPow(x, Math.trunc(pow / 2));
	ans = ans * ans;

	if (pow % 2 === 1) {
		ans = ans * x;
	}

	return n < 0 ? 1 / ans : ans;
}

export { myPow };
