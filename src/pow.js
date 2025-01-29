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
		ans *= x;
	}

	return n < 0 ? 1 / ans : ans;
}

/**
 * @param {number} x
 * @param {number} n
 * @returns {number}
 */
function myPow2(x, n) {
	if (x === 0) return 0;
	if (n === 0) return 1;

	let p = Math.abs(n);
	let res = 1;

	while (p !== 0) {
		if (p % 2 === 1) {
			res *= x;
		}
		x *= x;
		p = Math.trunc(p / 2);
	}

	return n < 0 ? 1 / res : res;
}

export { myPow, myPow2 };
