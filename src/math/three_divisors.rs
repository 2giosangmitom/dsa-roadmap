struct Solution;

impl Solution {
    pub fn is_three(n: i32) -> bool {
        if n < 4 {
            return false;
        }
        let root = (n as f64).sqrt() as i32;
        if root * root != n {
            return false;
        }
        Self::is_prime(root)
    }

    fn is_prime(n: i32) -> bool {
        if n < 2 {
            return false;
        }
        let mut i = 2;
        while i * i <= n {
            if n % i == 0 {
                return false;
            }
            i += 1;
        }
        true
    }
}

#[cfg(test)]
mod tests {
    use super::Solution;
    use rstest::rstest;

    #[rstest]
    #[case(2, false)]
    #[case(4, true)]
    #[case(9, true)]
    #[case(16, false)]
    fn test_is_three(#[case] n: i32, #[case] expected: bool) {
        assert_eq!(Solution::is_three(n), expected);
    }
}
