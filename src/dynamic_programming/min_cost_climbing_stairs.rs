struct Solution;

impl Solution {
    pub fn min_cost_climbing_stairs(cost: Vec<i32>) -> i32 {
        let n = cost.len();
        let mut dp = vec![0; n];
        dp[0] = cost[0];
        dp[1] = cost[1];
        for i in 2..n {
            dp[i] = cost[i] + dp[i - 1].min(dp[i - 2]);
        }
        dp[n - 1].min(dp[n - 2])
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use rstest::rstest;

    #[rstest]
    #[case(vec![10, 15, 20], 15)]
    #[case(vec![1, 100, 1, 1, 1, 100, 1, 1, 100, 1], 6)]
    fn test_min_cost_climbing_stairs(#[case] cost: Vec<i32>, #[case] expected: i32) {
        assert_eq!(Solution::min_cost_climbing_stairs(cost), expected);
    }
}
