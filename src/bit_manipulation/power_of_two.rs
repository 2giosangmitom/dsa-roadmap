struct Solution;

impl Solution {
    pub fn is_power_of_two(n: i32) -> bool {
        n > 0 && (n & (n - 1)) == 0
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use rstest::rstest;

    #[rstest]
    #[case(1, true)]
    #[case(16, true)]
    #[case(3, false)]
    fn test_is_power_of_two(#[case] n: i32, #[case] expected: bool) {
        assert_eq!(Solution::is_power_of_two(n), expected);
    }
}
