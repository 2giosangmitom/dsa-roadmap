struct Solution;

impl Solution {
    pub fn is_ugly(n: i32) -> bool {
        if n <= 0 {
            return false;
        }
        let mut n = n;
        for factor in [2, 3, 5] {
            while n % factor == 0 {
                n /= factor;
            }
        }
        n == 1
    }
}

#[cfg(test)]
mod tests {
    use super::Solution;
    use rstest::rstest;

    #[rstest]
    #[case(6, true)]
    #[case(1, true)]
    #[case(14, false)]
    fn test_is_ugly(#[case] n: i32, #[case] expected: bool) {
        assert_eq!(Solution::is_ugly(n), expected);
    }
}
