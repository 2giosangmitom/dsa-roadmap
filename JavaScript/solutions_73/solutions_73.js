/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
function setZeroes(matrix) {
	const col_set = new Set();
	const row_set = new Set();

	for (let i = 0; i < matrix.length; i++) {
		for (let j = 0; j < matrix[0].length; j++) {
			if (matrix[i][j] === 0) {
				if (!col_set.has(j)) {
					col_set.add(j);
				}

				if (!row_set.has(i)) {
					row_set.add(i);
				}
			}
		}
	}

	for (const row of row_set) {
		matrix[row].fill(0);
	}

	for (const col of col_set) {
		for (let i = 0; i < matrix.length; i++) {
			matrix[i][col] = 0;
		}
	}
}

/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
function setZeroes2(matrix) {
	let firstRowHasZero = false;
	let firstColHasZero = false;

	const cols = matrix.length;
	const rows = matrix[0].length;

	for (let i = 0; i < rows; i++) {
		if (matrix[0][i] === 0) {
			firstColHasZero = true;
			break;
		}
	}

	for (let i = 0; i < cols; i++) {
		if (matrix[i][0] === 0) {
			firstRowHasZero = true;
			break;
		}
	}

	for (let i = 1; i < cols; i++) {
		for (let j = 1; j < rows; j++) {
			if (matrix[i][j] === 0) {
				matrix[0][j] = 0;
				matrix[i][0] = 0;
			}
		}
	}

	for (let i = 1; i < cols; i++) {
		for (let j = 1; j < rows; j++) {
			if (matrix[0][j] === 0 || matrix[i][0] === 0) {
				matrix[i][j] = 0;
			}
		}
	}

	if (firstRowHasZero) {
		for (let i = 0; i < cols; i++) {
			matrix[i][0] = 0;
		}
	}

	if (firstColHasZero) {
		for (let i = 0; i < rows; i++) {
			matrix[0][i] = 0;
		}
	}
}

export { setZeroes, setZeroes2 };
