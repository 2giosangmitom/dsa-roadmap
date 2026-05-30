struct Solution;

impl Solution {
    pub fn maximal_square(matrix: Vec<Vec<char>>) -> i32 {
        let m = matrix.len();
        let n = matrix[0].len();
        let mut dp = vec![vec![0; n]; m];
        let mut max_side = 0;
        for i in 0..m {
            for j in 0..n {
                if matrix[i][j] == '1' {
                    if i == 0 || j == 0 {
                        dp[i][j] = 1;
                    } else {
                        dp[i][j] = dp[i - 1][j].min(dp[i][j - 1]).min(dp[i - 1][j - 1]) + 1;
                    }
                    max_side = max_side.max(dp[i][j]);
                }
            }
        }
        max_side * max_side
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use rstest::rstest;

    #[rstest]
    #[case(
        vec![
            vec!['1', '0', '1', '0', '0'],
            vec!['1', '0', '1', '1', '1'],
            vec!['1', '1', '1', '1', '1'],
            vec!['1', '0', '0', '1', '0'],
        ],
        4
    )]
    #[case(vec![vec!['0', '1'], vec!['1', '0']], 1)]
    #[case(vec![vec!['0']], 0)]
    fn test_maximal_square(#[case] matrix: Vec<Vec<char>>, #[case] expected: i32) {
        assert_eq!(Solution::maximal_square(matrix), expected);
    }
}
