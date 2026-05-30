struct Solution;

impl Solution {
    pub fn exist(board: Vec<Vec<char>>, word: String) -> bool {
        let mut board = board;
        let word = word.as_bytes();
        for r in 0..board.len() {
            for c in 0..board[0].len() {
                if Self::dfs(&mut board, r as i32, c as i32, word, 0) {
                    return true;
                }
            }
        }
        false
    }

    fn dfs(board: &mut Vec<Vec<char>>, r: i32, c: i32, word: &[u8], idx: usize) -> bool {
        if idx == word.len() {
            return true;
        }
        if r < 0 || r >= board.len() as i32 || c < 0 || c >= board[0].len() as i32 {
            return false;
        }
        if board[r as usize][c as usize] as u8 != word[idx] {
            return false;
        }
        let temp = board[r as usize][c as usize];
        board[r as usize][c as usize] = '#';
        let found = Self::dfs(board, r + 1, c, word, idx + 1)
            || Self::dfs(board, r - 1, c, word, idx + 1)
            || Self::dfs(board, r, c + 1, word, idx + 1)
            || Self::dfs(board, r, c - 1, word, idx + 1);
        board[r as usize][c as usize] = temp;
        found
    }
}

#[cfg(test)]
mod tests {
    use super::Solution;
    use rstest::rstest;

    #[rstest]
    #[case(
        vec![
            vec!['A','B','C','E'],
            vec!['S','F','C','S'],
            vec!['A','D','E','E'],
        ],
        "ABCCED".to_string(),
        true,
    )]
    #[case(
        vec![
            vec!['A','B','C','E'],
            vec!['S','F','C','S'],
            vec!['A','D','E','E'],
        ],
        "SEE".to_string(),
        true,
    )]
    #[case(
        vec![
            vec!['A','B','C','E'],
            vec!['S','F','C','S'],
            vec!['A','D','E','E'],
        ],
        "ABCB".to_string(),
        false,
    )]
    fn test_exist(#[case] board: Vec<Vec<char>>, #[case] word: String, #[case] expected: bool) {
        assert_eq!(Solution::exist(board, word), expected);
    }
}
