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

export { setZeroes };
