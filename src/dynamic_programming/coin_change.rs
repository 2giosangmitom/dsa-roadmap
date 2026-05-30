struct Solution;

impl Solution {
    pub fn coin_change(coins: Vec<i32>, amount: i32) -> i32 {
        let amount = amount as usize;
        let mut dp = vec![amount + 1; amount + 1];
        dp[0] = 0;
        for i in 1..=amount {
            for &coin in &coins {
                if coin as usize <= i {
                    dp[i] = dp[i].min(dp[i - coin as usize] + 1);
                }
            }
        }
        if dp[amount] > amount {
            -1
        } else {
            dp[amount] as i32
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use rstest::rstest;

    #[rstest]
    #[case(vec![1, 2, 5], 11, 3)]
    #[case(vec![2], 3, -1)]
    #[case(vec![1], 0, 0)]
    fn test_coin_change(#[case] coins: Vec<i32>, #[case] amount: i32, #[case] expected: i32) {
        assert_eq!(Solution::coin_change(coins, amount), expected);
    }
}
