struct Solution;

impl Solution {
    pub fn change(amount: i32, coins: Vec<i32>) -> i32 {
        let amount = amount as usize;
        let mut dp = vec![0; amount + 1];
        dp[0] = 1;
        for coin in coins {
            for i in coin as usize..=amount {
                dp[i] += dp[i - coin as usize];
            }
        }
        dp[amount]
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use rstest::rstest;

    #[rstest]
    #[case(5, vec![1, 2, 5], 4)]
    #[case(3, vec![2], 0)]
    #[case(10, vec![10], 1)]
    fn test_change(#[case] amount: i32, #[case] coins: Vec<i32>, #[case] expected: i32) {
        assert_eq!(Solution::change(amount, coins), expected);
    }
}
