/**
 * @param {string[][]} board
 * @return {boolean}
 */
function isValidSudoku(board) {
  const row_sets = Array.from({ length: 9 }, () => new Set());
  const col_sets = Array.from({ length: 9 }, () => new Set());
  const subgrid_sets = Array.from({ length: 3 }, () =>
    Array.from({ length: 3 }, () => new Set()),
  );

  for (let i = 0; i < 9; i++) {
    for (let j = 0; j < 9; j++) {
      let num = board[i][j];
      if (num === ".") continue;

      if (row_sets[i].has(num)) {
        return false;
      }

      if (col_sets[j].has(num)) {
        return false;
      }

      if (subgrid_sets[Math.trunc(i / 3)][Math.trunc(j / 3)].has(num)) {
        return false;
      }

      row_sets[i].add(num);
      col_sets[j].add(num);
      subgrid_sets[Math.trunc(i / 3)][Math.trunc(j / 3)].add(num);
    }
  }

  return true;
}

export { isValidSudoku };
