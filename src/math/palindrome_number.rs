struct Solution;

impl Solution {
    pub fn is_palindrome(x: i32) -> bool {
        if x < 0 || (x % 10 == 0 && x != 0) {
            return false;
        }

        let mut x = x;
        let mut reversed = 0;

        while x > reversed {
            reversed = reversed * 10 + x % 10;
            x /= 10;
        }

        x == reversed || x == reversed / 10
    }
}

#[cfg(test)]
mod tests {
    use super::Solution;
    use rstest::rstest;

    #[rstest]
    #[case(121, true)]
    #[case(-121, false)]
    #[case(10, false)]
    fn test_is_palindrome(#[case] x: i32, #[case] expected: bool) {
        assert_eq!(Solution::is_palindrome(x), expected);
    }
}
