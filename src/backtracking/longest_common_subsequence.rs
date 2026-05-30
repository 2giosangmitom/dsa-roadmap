struct Solution;

impl Solution {
    pub fn longest_common_subsequence(text1: String, text2: String) -> i32 {
        let s1 = text1.as_bytes();
        let s2 = text2.as_bytes();
        let m = s1.len();
        let n = s2.len();
        let mut dp = vec![vec![0; n + 1]; m + 1];
        for i in 1..=m {
            for j in 1..=n {
                if s1[i - 1] == s2[j - 1] {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = dp[i - 1][j].max(dp[i][j - 1]);
                }
            }
        }
        dp[m][n]
    }
}

#[cfg(test)]
mod tests {
    use super::Solution;
    use rstest::rstest;

    #[rstest]
    #[case("abcde".to_string(), "ace".to_string(), 3)]
    #[case("abc".to_string(), "abc".to_string(), 3)]
    #[case("abc".to_string(), "def".to_string(), 0)]
    fn test_longest_common_subsequence(
        #[case] text1: String,
        #[case] text2: String,
        #[case] expected: i32,
    ) {
        assert_eq!(Solution::longest_common_subsequence(text1, text2), expected);
    }
}
