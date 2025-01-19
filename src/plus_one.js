/**
 * @param {number[]} digits
 * @return {number[]}
 */
function plusOne(digits) {
	let carry = 1;
	let i = digits.length - 1;

	while (i >= 0 && carry !== 0) {
		const sum = digits[i] + carry;
		digits[i] = Math.trunc(sum % 10);
		carry = Math.trunc(sum / 10);
		i--;
	}

	if (carry !== 0) {
		digits.unshift(carry);
	}

	return digits;
}

export { plusOne };
