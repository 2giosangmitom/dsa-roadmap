struct Solution;

impl Solution {
    pub fn is_valid_sudoku(board: Vec<Vec<char>>) -> bool {
        let mut row_set = [[false; 9]; 9];
        let mut col_set = [[false; 9]; 9];
        let mut cell_set = [[false; 9]; 9];

        for (i, r) in board.iter().enumerate() {
            for (j, c) in r.iter().enumerate() {
                let k = c.to_digit(10);
                if let Some(num) = k {
                    let num = num as usize;
                    if row_set[i][num - 1]
                        || col_set[j][num - 1]
                        || cell_set[3 * (i / 3) + j / 3][num - 1]
                    {
                        return false;
                    }
                    row_set[i][num - 1] = true;
                    col_set[j][num - 1] = true;
                    cell_set[3 * (i / 3) + j / 3][num - 1] = true;
                }
            }
        }

        true
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use rstest::rstest;

    #[rstest]
    #[case(vec![vec!['5','3','.','.','7','.','.','.','.'],
                vec!['6','.','.','1','9','5','.','.','.'],
                vec!['.','9','8','.','.','.','.','6','.'],
                vec!['8','.','.','.','6','.','.','.','3'],
                vec!['4','.','.','8','.','3','.','.','1'],
                vec!['7','.','.','.','2','.','.','.','6'],
                vec!['.','6','.','.','.','.','2','8','.'],
                vec!['.','.','.','4','1','9','.','.','5'],
                vec!['.','.','.','.','8','.','.','7','9']
           ], true)]
    #[case(vec![vec!['8','3','.','.','7','.','.','.','.'],
                vec!['6','.','.','1','9','5','.','.','.'],
                vec!['.','9','8','.','.','.','.','6','.'],
                vec!['8','.','.','.','6','.','.','.','3'],
                vec!['4','.','.','8','.','3','.','.','1'],
                vec!['7','.','.','.','2','.','.','.','6'],
                vec!['.','6','.','.','.','.','2','8','.'],
                vec!['.','.','.','4','1','9','.','.','5'],
                vec!['.','.','.','.','8','.','.','7','9']
           ], false)]
    fn test_is_valid_sudoku(#[case] board: Vec<Vec<char>>, #[case] expected: bool) {
        assert_eq!(Solution::is_valid_sudoku(board), expected);
    }
}
