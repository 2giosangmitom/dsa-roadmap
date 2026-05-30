struct Solution;

impl Solution {
    pub fn solve_sudoku(board: &mut Vec<Vec<char>>) {
        let mut rows = [0i32; 9];
        let mut cols = [0i32; 9];
        let mut boxes = [0i32; 9];
        for r in 0..9 {
            for c in 0..9 {
                if board[r][c] != '.' {
                    let val = board[r][c] as u8 - b'1';
                    let bit = 1 << val;
                    rows[r] |= bit;
                    cols[c] |= bit;
                    boxes[(r / 3) * 3 + (c / 3)] |= bit;
                }
            }
        }
        Self::backtrack(board, &mut rows, &mut cols, &mut boxes);
    }

    fn backtrack(
        board: &mut Vec<Vec<char>>,
        rows: &mut [i32; 9],
        cols: &mut [i32; 9],
        boxes: &mut [i32; 9],
    ) -> bool {
        for r in 0..9 {
            for c in 0..9 {
                if board[r][c] == '.' {
                    let b = (r / 3) * 3 + (c / 3);
                    for val in 0..9 {
                        let bit = 1 << val;
                        if rows[r] & bit == 0 && cols[c] & bit == 0 && boxes[b] & bit == 0 {
                            board[r][c] = (val as u8 + b'1') as char;
                            rows[r] |= bit;
                            cols[c] |= bit;
                            boxes[b] |= bit;
                            if Self::backtrack(board, rows, cols, boxes) {
                                return true;
                            }
                            board[r][c] = '.';
                            rows[r] ^= bit;
                            cols[c] ^= bit;
                            boxes[b] ^= bit;
                        }
                    }
                    return false;
                }
            }
        }
        true
    }
}

#[cfg(test)]
mod tests {
    use super::Solution;
    use rstest::rstest;

    fn is_valid(board: &[Vec<char>]) -> bool {
        let mut rows = [0i32; 9];
        let mut cols = [0i32; 9];
        let mut boxes = [0i32; 9];
        for r in 0..9 {
            for c in 0..9 {
                if board[r][c] == '.' {
                    return false;
                }
                let val = board[r][c] as u8 - b'1';
                let bit = 1 << val;
                if rows[r] & bit != 0
                    || cols[c] & bit != 0
                    || boxes[(r / 3) * 3 + (c / 3)] & bit != 0
                {
                    return false;
                }
                rows[r] |= bit;
                cols[c] |= bit;
                boxes[(r / 3) * 3 + (c / 3)] |= bit;
            }
        }
        true
    }

    #[rstest]
    #[case(vec![
        vec!['5','3','.','.','7','.','.','.','.'],
        vec!['6','.','.','1','9','5','.','.','.'],
        vec!['.','9','8','.','.','.','.','6','.'],
        vec!['8','.','.','.','6','.','.','.','3'],
        vec!['4','.','.','8','.','3','.','.','1'],
        vec!['7','.','.','.','2','.','.','.','6'],
        vec!['.','6','.','.','.','.','2','8','.'],
        vec!['.','.','.','4','1','9','.','.','5'],
        vec!['.','.','.','.','8','.','.','7','9'],
    ])]
    fn test_solve_sudoku(#[case] mut board: Vec<Vec<char>>) {
        Solution::solve_sudoku(&mut board);
        assert!(is_valid(&board));
    }
}
