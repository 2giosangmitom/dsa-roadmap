struct Solution;

impl Solution {
    pub fn min_path_sum(grid: Vec<Vec<i32>>) -> i32 {
        let m = grid.len();
        let n = grid[0].len();
        let mut dp = vec![vec![0; n]; m];
        dp[0][0] = grid[0][0];
        for i in 1..m {
            dp[i][0] = dp[i - 1][0] + grid[i][0];
        }
        for j in 1..n {
            dp[0][j] = dp[0][j - 1] + grid[0][j];
        }
        for i in 1..m {
            for j in 1..n {
                dp[i][j] = grid[i][j] + dp[i - 1][j].min(dp[i][j - 1]);
            }
        }
        dp[m - 1][n - 1]
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use rstest::rstest;

    #[rstest]
    #[case(vec![vec![1, 3, 1], vec![1, 5, 1], vec![4, 2, 1]], 7)]
    #[case(vec![vec![1, 2, 3], vec![4, 5, 6]], 12)]
    fn test_min_path_sum(#[case] grid: Vec<Vec<i32>>, #[case] expected: i32) {
        assert_eq!(Solution::min_path_sum(grid), expected);
    }
}
