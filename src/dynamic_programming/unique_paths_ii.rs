struct Solution;

impl Solution {
    pub fn unique_paths_with_obstacles(obstacle_grid: Vec<Vec<i32>>) -> i32 {
        let m = obstacle_grid.len();
        let n = obstacle_grid[0].len();
        let mut dp = vec![vec![0; n]; m];
        for i in 0..m {
            if obstacle_grid[i][0] == 1 {
                break;
            }
            dp[i][0] = 1;
        }
        for j in 0..n {
            if obstacle_grid[0][j] == 1 {
                break;
            }
            dp[0][j] = 1;
        }
        for i in 1..m {
            for j in 1..n {
                if obstacle_grid[i][j] == 1 {
                    dp[i][j] = 0;
                } else {
                    dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
                }
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
    #[case(vec![vec![0, 0, 0], vec![0, 1, 0], vec![0, 0, 0]], 2)]
    #[case(vec![vec![0, 1], vec![0, 0]], 1)]
    fn test_unique_paths_with_obstacles(
        #[case] obstacle_grid: Vec<Vec<i32>>,
        #[case] expected: i32,
    ) {
        assert_eq!(
            Solution::unique_paths_with_obstacles(obstacle_grid),
            expected
        );
    }
}
