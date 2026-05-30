struct Solution;

impl Solution {
    pub fn check_powers_of_three(mut n: i32) -> bool {
        while n > 0 {
            if n % 3 == 2 {
                return false;
            }
            n /= 3;
        }
        true
    }
}

#[cfg(test)]
mod tests {
    use super::Solution;
    use rstest::rstest;

    #[rstest]
    #[case(12, true)]
    #[case(91, true)]
    #[case(21, false)]
    fn test_check_powers_of_three(#[case] n: i32, #[case] expected: bool) {
        assert_eq!(Solution::check_powers_of_three(n), expected);
    }
}
