/**
 * @param {string} s
 * @return {number}
 */
function calculate(s) {
	let result = 0; // Stores the running sum of evaluated expressions
	let currentNum = 0; // Stores the number being built
	let sign = 1; // Tracks the current sign (1 for '+', -1 for '-')
	const stack = []; // Stack to manage nested expressions

	for (let i = 0; i < s.length; i++) {
		const char = s[i];

		if (char >= "0" && char <= "9") {
			// Build the current number from consecutive digits
			currentNum = currentNum * 10 + (char.charCodeAt(0) - "0".charCodeAt(0));
		} else if (char === "+" || char === "-") {
			// Apply the previous number and update the sign for the next number
			result += currentNum * sign;
			sign = char === "+" ? 1 : -1;
			currentNum = 0;
		} else if (char === "(") {
			// Push the current result and sign onto the stack before entering a nested expression
			stack.push(result, sign);
			result = 0;
			sign = 1;
		} else if (char === ")") {
			// Apply the last computed number before exiting the nested expression
			result += currentNum * sign;
			result *= stack.pop(); // Retrieve the sign before '('
			result += stack.pop(); // Retrieve the result before '('
			currentNum = 0;
		}
	}

	// Add any remaining number in the expression
	return result + currentNum * sign;
}

export { calculate };
