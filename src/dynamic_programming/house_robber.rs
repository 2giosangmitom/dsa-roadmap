struct Solution;

impl Solution {
    pub fn rob(nums: Vec<i32>) -> i32 {
        let n = nums.len();
        if n == 1 {
            return nums[0];
        }
        let mut dp = vec![0; n];
        dp[0] = nums[0];
        dp[1] = nums[0].max(nums[1]);
        for i in 2..n {
            dp[i] = dp[i - 1].max(dp[i - 2] + nums[i]);
        }
        dp[n - 1]
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use rstest::rstest;

    #[rstest]
    #[case(vec![1, 2, 3, 1], 4)]
    #[case(vec![2, 7, 9, 3, 1], 12)]
    fn test_rob(#[case] nums: Vec<i32>, #[case] expected: i32) {
        assert_eq!(Solution::rob(nums), expected);
    }
}
