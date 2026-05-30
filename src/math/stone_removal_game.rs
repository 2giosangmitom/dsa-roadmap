struct Solution;

impl Solution {
    pub fn can_win_nim(n: i32) -> bool {
        n % 4 != 0
    }
}

#[cfg(test)]
mod tests {
    use super::Solution;
    use rstest::rstest;

    #[rstest]
    #[case(4, false)]
    #[case(1, true)]
    #[case(2, true)]
    fn test_can_win_nim(#[case] n: i32, #[case] expected: bool) {
        assert_eq!(Solution::can_win_nim(n), expected);
    }
}
