struct Solution;

impl Solution {
    pub fn unique_paths(m: i32, n: i32) -> i32 {
        let m = m as usize;
        let n = n as usize;
        let mut dp = vec![vec![0; n]; m];
        for row in dp.iter_mut().take(m) {
            row[0] = 1;
        }
        for cell in dp[0].iter_mut().take(n) {
            *cell = 1;
        }
        for i in 1..m {
            for j in 1..n {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
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
    #[case(3, 7, 28)]
    #[case(3, 2, 3)]
    fn test_unique_paths(#[case] m: i32, #[case] n: i32, #[case] expected: i32) {
        assert_eq!(Solution::unique_paths(m, n), expected);
    }
}
