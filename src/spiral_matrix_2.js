/**
 * @param {number} n
 * @return {number[][]}
 */
function generateMatrix(n) {
  const res = Array.from({ length: n }, () => new Array(n));
  let k = 1;

  for (let i = 0; i < Math.ceil(n / 2); i++) {
    // Fill the top row (left to right)
    for (let j = i; j < n - i; j++) {
      res[i][j] = k++;
    }

    // Fill the right column (top to bottom)
    for (let j = i + 1; j < n - i; j++) {
      res[j][n - 1 - i] = k++;
    }

    // Fill the bottom row (right to left)
    for (let j = n - 2 - i; j >= i; j--) {
      res[n - 1 - i][j] = k++;
    }

    // Fill the left column (bottom to top)
    for (let j = n - 2 - i; j > i; j--) {
      res[j][i] = k++;
    }
  }

  return res;
}

export { generateMatrix };
