/**
 * @param {number} n
 * @return {boolean}
 */
function canAliceWin(n) {
	if (n < 10) return false;

	let remaining = n - 10;
	let decrement = 9;
	let isAliceTurn = true;

	while (remaining >= decrement) {
		remaining -= decrement--;
		isAliceTurn = !isAliceTurn;
	}

	return isAliceTurn;
}

export { canAliceWin };
